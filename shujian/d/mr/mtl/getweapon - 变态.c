// mr up_uweapon_feature.c
// be jpei 2010

#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
        set("short",HIW"������-�����"NOR);
	
        set ("long",@long
������٢��ɽׯ����书�ؼ��ĵط���һ�������������İڷ��Ÿ�����
�����ƺ�������δ����������(cuilian weapon)�йء�
long);
	set("exits",([
		"out" : __DIR__"huandong",
	]));


	set("no_fight", 1);
	setup();
}


void init()
 {
         add_action("do_canwu", "cuilian");
 }



int do_canwu(string arg)
 {
     object me = this_player();
     object wpn;

     if(arg != "weapon")
           return notify_fail("����ֻ�ܴ���(cuilian)���(weapon)!\n");

 if(  !objectp(wpn = me->query_temp("weapon") ))
        return notify_fail("��û������Я�������������������޷����ġ�\n");    

     wpn = me->query_temp("weapon");

//if(wpn->query("maker")=="Τ������(Weilan tiejiang)") 
//          return notify_fail(HIR"\n�����Ž�������ע��"+wpn->query("weapon_mp/name")+""HIR"�С�������\n"HIG"���ɥ�ķ��֣�"+wpn->query("weapon_mp/name")+""HIG"δ����������̶Ѫ�����޷���������������ơ�\n\n"NOR);

     if (me->is_busy() || me->is_fighting()|| me->query_temp("con_weapon") )
       return notify_fail("����æ���ء�\n");

 if (me->query_temp("canwu_now") )
       return notify_fail("����æ���ء�\n");
       
       if (query_temp("canwu") )
       return notify_fail("�������ڲ����أ����һ��ѡ�\n");

     if( me->query("combat_exp",1)<5000000) //��ʱ�ȷ�µ�����Ҫ5000M����
         
        return notify_fail("����ҵķ��˷�����ϵĲ��飬������������ݸ���Ī�⣬�޷���⣬���ɵ�ҡ��ҡͷ��\n");

       

     if(wpn->query("id")=="songwen jian")
   
              return notify_fail("�㷢�������ƹŽ�������Ȼ��������ʣ������ò��Ŵ�����\n");

     if( wpn->query("weapon_mp/owner",1)!= me->query("id") )   
          return notify_fail("�Ⲣ�������Լ���˽����������ο໨������ȥ���������ء�\n");
	  
	if (wpn->query("upgrade_count")>9)
		return notify_fail("�����е�����Ѿ������������ˣ��޷��ٴ����ˡ���\n");
	
 if ( wpn->query("weapon_mp/weapon_prop/damage",1)      >=12000000000000000
	|| wpn->query("weapon_mp/weapon_prop/attack",1)      >=620000000
	|| wpn->query("weapon_mp/weapon_prop/dexerity",1)     >=14000000
	|| wpn->query("weapon_mp/weapon_prop/constitution",1) >=14000000
	|| wpn->query("weapon_mp/weapon_prop/intelligence",1) >=14000000
	|| wpn->query("weapon_mp/weapon_prop/strength",1)     >=14000000 )

                 return notify_fail("���������ǵ�����һ������������������ԣ���������Ҫ�ټӴ����ˡ���\n");

       message_vision( HIW"$N��ϸ�ķ���������ϵĲ��飬��������δ�����������ݺܸ���Ȥ��\n"NOR,me);
       message_vision( HIW"$Nһͷ���������.��ͣ�ķ����š��� \n"NOR, me);
  
       me->start_busy(100);  
       me->set_temp("canwu_now",1); 
       set_temp("canwu",1);            
     call_out("thinking",2, me );
         return 1;

 }

int thinking(object me)
{
	int d,a,dexe,cons,inte,stre,t,cj,max_cj,yd,fld,exp,temp;
	int defense,jing,qi,jingli,neili,re_jing,re_qi,re_jingli,re_neili,parry,dodge,force,avf;
	/*
	switch(item){		
			case "damage":                use="�˺���";break;
			case "armor":                 use="������";break;
			case "strength":              use="����";break;
			case "constitution":          use="����";break;
			case "dexerity":              use="��";break;
			case "intelligence":          use="����";break;
			case "attack":		      use="����";break;
			case "defense":               use="����";break;
			case "neili":                 use="����";break;
			case "jingli":                use="����";break;
			case "jing":                  use="��Ѫ";break;
			case "qi":                    use="��Ѫ";break;
			case "re_qi":                 use="��Ѫ�ָ��ٶ�";use2="%";break;
			case "re_neili":              use="�����ָ��ٶ�";use2="%";break;
			case "re_jing":               use="��Ѫ�ָ��ٶ�";use2="%";break;
			case "re_jingli":             use="�����ָ��ٶ�";use2="%";break;
			case "parry":                 use="�м�";break;
			case "dodge":                 use="�Ṧ";break;
			case "force":                 use="�ڹ�";break;
			case "armor_vs_force":        use="�ڹ�����";break;
			default:use="";
		}
	*/
	object wpn,ob1,ob2;
	mapping mp;
	wpn = me->query_temp("weapon");
	if(!me) return 0;
	
	if(me->query_temp("con_weapon")<(3+random(3)))
    {  me->add_temp("con_weapon",1);
          if(random(2)) tell_object(me,HIG"\n����ϸ���ж�������������ݣ�ֻ���ö�Ŀһ��...\n"NOR);
                   else tell_object(me,HIY"\n����������������ص����ݣ������Ľ��������뵽����֮��...\n"NOR);  

	  tell_room(environment(me),HIC""+me->query("name")+"Ĭ������������"+wpn->query("weapon_mp/name")+""HIC"�����ķ���һ������Ĺ��...\n"NOR, ({}));

	  remove_call_out("thinking");
	  call_out("thinking",1+random(2), me);

	}

 else {
		//if ((int)wpn->query("weapon_mp/upgrade_count",1)<1)
		//	wpn->set("weapon_mp/upgrade_count",0);
         me->delete_temp("con_weapon");
         me->start_busy(1); 
		ob1 = present("shensheng zhufu", me);

		if ((ob1 || wpn->query("weapon_mp/upgrade_count")) < 4
		|| wpn->query("weapon_mp/upgrade_count") == 4 && random(1000) > 4
		|| wpn->query("weapon_mp/upgrade_count") == 5 && random(1000) > 5 
		|| wpn->query("weapon_mp/upgrade_count") == 6 && random(1000) > 6
		|| wpn->query("weapon_mp/upgrade_count") == 7 && random(1000) > 7 
		|| wpn->query("weapon_mp/upgrade_count") == 8 && random(1000) > 8
		|| wpn->query("weapon_mp/upgrade_count") == 9 && random(1000) > 9)

		{  		 
			message_vision(HIC"\n$N����"+wpn->query("weapon_mp/name")+""HIR"�����������ƺ������˲������ԣ���\n"NOR,me); 
	  
			tell_object(me,HIR"\n���"+wpn->query("weapon_mp/name")+""HIR"�ɹ��Ľ�����һ�δ�����\n"NOR);
			me->add("combat_exp",100000);
				//temp=5+random(5);
				d= wpn->query("weapon_mp/weapon_prop/damage",1);
				a= wpn->query("weapon_mp/weapon_prop/attack",1);
				dexe= wpn->query("weapon_mp/weapon_prop/dexerity",1);
				cons= wpn->query("weapon_mp/weapon_prop/constitution",1);
				inte= wpn->query("weapon_mp/weapon_prop/intelligence",1);
				stre= wpn->query("weapon_mp/weapon_prop/strength",1) ;   
				cj=wpn->query("weapon_mp/dur",1);
				max_cj=wpn->query("weapon_mp/max_dur",1);
				yd=wpn->query("weapon_mp/rigidity",1);
				fld=wpn->query("weapon_mp/sharpness",1);
				jing=wpn->query("weapon_mp/weapon_prop/jing",1);
				
				//�˺�ֵd= wpn->query("weapon_mp/weapon_prop/damage",1);
			if(random(10000)>=7)
				wpn->add("weapon_mp/weapon_prop/damage",d*10); 
			if(wpn->query("weapon_mp/weapon_prop/damage",1) >1200000000)  
				wpn->set("weapon_mp/weapon_prop/damage",1200000000000) ;
			
			
				//����ֵ a= wpn->query("weapon_mp/weapon_prop/attack",1);
			if(random(10000)>=7)
				wpn->add("weapon_mp/weapon_prop/attack",a*5);
			if(wpn->query("weapon_mp/weapon_prop/attack",1) >620000)
				wpn->set("weapon_mp/weapon_prop/attack",620000);
			
				//������ dexe= wpn->query("weapon_mp/weapon_prop/dexerity",1);
			if(random(10000)>=7)
				wpn->add("weapon_mp/weapon_prop/dexerity",dexe*5);
			if( wpn->query("weapon_mp/weapon_prop/dexerity",1)>14000)
				wpn->set("weapon_mp/weapon_prop/dexerity",14000);
			
				//�������� cons= wpn->query("weapon_mp/weapon_prop/constitution",1);
			if(random(10000)>=7)
				wpn->add("weapon_mp/weapon_prop/constitution",cons*5);
			if( wpn->query("weapon_mp/weapon_prop/constitution",1)>14000)
				wpn->set("weapon_mp/weapon_prop/constitution",14000);
			
				//�������� inte= wpn->query("weapon_mp/weapon_prop/intelligence",1);
			if(random(10000)>=7) 
				wpn->add("weapon_mp/weapon_prop/intelligence",inte*5);
			if( wpn->query("weapon_mp/weapon_prop/intelligence",1)>14000)
				wpn->set("weapon_mp/weapon_prop/intelligence",14000);
			
				//�������� stre= wpn->query("weapon_mp/weapon_prop/strength",1) ; 
			if(random(10000)>=7) 
				wpn->add("weapon_mp/weapon_prop/strength",stre*5) ;   
			if( wpn->query("weapon_mp/weapon_prop/strength",1)>14000)
				wpn->set("weapon_mp/weapon_prop/strength",14000);
		
			wpn->add("weapon_mp/dur",10000) ;   
			wpn->add("weapon_mp/max_dur",10000) ;   
			wpn->add("dur",10000) ;   
			wpn->add("max_dur",10000) ;   
			//wpn->add("sharpness",1) ;   
			//wpn->add("weapon_mp/sharpness",1) ;   
			//wpn->add("weapon_mp/rigidity",1) ;   
			//wpn->add("rigidity",1) ;   
			wpn->add("weapon_mp/upgrade_count",1);
			
			d= wpn->query("weapon_mp/weapon_prop/damage",1);
			a= wpn->query("weapon_mp/weapon_prop/attack",1);
			dexe= wpn->query("weapon_mp/weapon_prop/dexerity",1);
			cons= wpn->query("weapon_mp/weapon_prop/constitution",1);
			inte= wpn->query("weapon_mp/weapon_prop/intelligence",1);
			stre= wpn->query("weapon_mp/weapon_prop/strength",1) ;   
			cj=wpn->query("weapon_mp/dur",1);
			max_cj=wpn->query("weapon_mp/max_dur",1);
			yd=wpn->query("weapon_mp/rigidity",1);
			fld=wpn->query("weapon_mp/sharpness",1);	
			me->add("relife/weapon",1); 
			t= me->query("relife/weapon",1);
			me->delete_temp("canwu_now");   
			delete_temp("canwu");   

			

			mp = wpn->query("weapon_mp");
			if ( !mapp(mp) || !mapp(wpn->query("weapon_prop")) ) return 0;
			if(stringp(wpn->query("owner"))&& wpn->query("owner")!="0"&& wpn->query("owner")!=getuid(me)) return 0;
	
			//ÿ���������򱣴�������װ�����ݵ����������
			
			me->set("worker/"+mp["save_id"], copy( WORKER_D->convert_weapon2user(mp) ));
			if(userp(me)) me->save();
			
			
			tell_object(me,HBBLU"\n�㱾�δ������ķ���ʮ��ʵս���飬���"+wpn->query("weapon_mp/name")+""HBYEL"��������Ϊ��\n"NOR);
			//tell_object(me,HIM"\n�־�����һ��㣬ĿǰΪ��"+HIW+chinese_number(cj)+NOR+"����"+HIC+chinese_number(max_cj)+NOR+"����\n"NOR);
			//tell_object(me,HBRED"Ӳ�ȣ�"+HIR+chinese_number(yd)+HIG+"��������"+HIW+chinese_number(fld)+NOR+"��\n"NOR);
			tell_object(me,HBMAG"������"+HIR+chinese_number(d)+HIR+"������"+HIW+chinese_number(a)+HIW+"��\n"NOR);
			tell_object(me,"����"+HIG+chinese_number(stre)+NOR+"�㣬��"+HIM+chinese_number(dexe)+NOR+"�㣬����"+HIC+chinese_number(cons)+NOR+"�㣬����"+HIY+chinese_number(inte)+NOR+"�㡣\n"NOR);
			//���˿��������ɹ��İѲ������ؽ��������ˡ�1������
			CHANNEL_D->do_channel(this_object(), "rumor", "��˵" + me->name() + "�ɹ���"+wpn->query("weapon_mp/name")+NOR"�������ˡ�"HIC + chinese_number(wpn->query("weapon_mp/upgrade_count",1))+ NOR"������\n"NOR);

			  log_file("quest/cuilian", sprintf("%s(%s) ��%d�β�������������֣���������%d������%d����%d��%d��%d��%d�� ��ǰ���飺%d��\n", 
			   me->name(1),
			   me->query("id"),
			   t,
			   d,
			   a,
			   stre,  
			   dexe,
			   cons,
			   inte,
			   me->query("combat_exp")) );
		}
		else
		{
			ob2= present("wanbi fu", me);
			if (ob2)
			{
			message_vision(HIG"\n$N��Ϊ��������起��������ʧ�ܣ���������������������\n"NOR,me);
			tell_object(me,HIR"\n��������ڱ��δ�������Ч��\n"NOR);
			wpn->add("weapon_mp/upgrade_count",1);
			me->delete_temp("canwu_now");
			delete_temp("canwu"); 
			destruct(ob2);
			log_file("quest/cuilian", sprintf("%s(%s) ʹ����起��������Ǽ�%d��\n", me->name(1),me->query("id"),wpn->query("weapon_mp/upgrade_count",1)));
			}
			else 
			{
			//���˿����Ħ��ʧ�ְ�������Ȩ�������ٻ���
			CHANNEL_D->do_channel(this_object(), "rumor", "��˵"HIC + me->name() + NOR"ʧ�ְ�"NOR+wpn->query("weapon_mp/name")+NOR"�������ˣ�\n"NOR);
			message_vision(HIC"\n$N���������������⼤�ҵ��𵴣���Ȼ�����ˣ���\n"NOR,me); 
			tell_object(me,HIR"\n��������ھ��������ˣ�\n"NOR);
			me->delete("worker/"+wpn->query("weapon_mp/save_id",1),1);
			me->delete_temp("canwu_now");   
				delete_temp("canwu");   
			
			wpn->move(environment(me));
			wpn->set("name", "�����" + wpn->query("name"));
			wpn->set("value", 0);
			wpn->set("weapon_prop", 0);
			log_file("quest/cuilian", sprintf("%s(%s) �������ˣ�װ���Ǽ�%d��\n", me->name(1),me->query("id"),wpn->query("armor_mp/upgrade_count")));

			}
		}
  
   }

}

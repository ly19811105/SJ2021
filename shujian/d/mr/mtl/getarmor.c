// mr up_uweapon_feature.c
// be jpei 2010

#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
        set("short",HIG"������-װ����"NOR);
	
        set ("long",@long
������٢��ɽׯ��������װ���ĵط�����ҿ����ڴ˾���(jinglian)װ����
����ʱ���������װ��ȫ��ƴ����
long);
	set("exits",([
		"out" : __DIR__"huandong",
	]));


	set("no_fight", 1);
	setup();
}


void init()
 {
         add_action("do_canwu", "jinglian");
 }



int do_canwu(string arg)
 {
     object me = this_player();
     object wpn;
         if(!arg)
           return notify_fail("��Ҫ����ʲô��\n");

 
		switch(arg){
                case "armor":
                case "coat":
                case "cap":
                case "belt":
                case "glove":
                case "mantle":
				case "boot":
                break;
                
                default:
                        return notify_fail("���ﲻ�ܾ�������װ����\n");
        }

	wpn = me->query_temp("armor/"+arg);
	if(!objectp(wpn = present(arg, me)))       
		return notify_fail("��û������Я��װ��������ʲô��\n");
	
	if(wpn->query("armor_mp/owner")!=getuid(me)) 
		return notify_fail("�ⲻ�����˽��װ���������޷�������\n");
    if (me->is_busy() || me->is_fighting() )
       return notify_fail("����æ���ء�\n");

	if (me->query_temp("canwu_now") )
       return notify_fail("����æ���ء�\n");
       
    if (query_temp("canwu") )
       return notify_fail("�������ھ����أ����һ��ѡ�\n");

    if( me->query("combat_exp",1)<5000000)
         
        return notify_fail("��ľ��鲻��������û��������\n");

	//if( !wpn->query("canjinglian"))   
    //    return notify_fail("���ֶ���û��������\n");  
	if (wpn->query("armor_mp/upgrade_count")>9)
		return notify_fail(HIR"������װ���Ѿ������������ˣ��޷��پ����ˡ�\n"NOR);






     

   if ( wpn->query("armor_prop/armor",1)      >=2000
    && wpn->query("armor_prop/attack",1)      >=1000
    && wpn->query("armor_prop/dexerity",1)     >=160
    && wpn->query("armor_prop/constitution",1) >=160
    && wpn->query("armor_prop/intelligence",1) >=160
	&& wpn->query("armor_prop/strength",1)     >=160 )

	return notify_fail("���װ�����Ǿ�Ʒ���������ԣ���������Ҫ�ټӾ����ˡ���\n");

	message_vision( HIW"$N��"+wpn->query("name")+""HIW"���ھ�������׼��������\n"NOR,me);
	message_vision( HIW"$Nר����־�أ���"+wpn->query("name")+""HIW"��ϸ���ơ�\n"NOR, me);
  
    me->start_busy(100);  
    me->set_temp("canwu_now",1); 
    set_temp("canwu",1);            
	call_out("thinking",5, me, wpn ,arg );
    return 1;

 }

int thinking(object me,object wpn,string arg)
{
 int d,a,dexe,cons,inte,stre,t;
	object ob1,ob2;
	mapping mp;
    if(!me) return 0;

	
	if(me->query_temp("con_weapon")<(3+random(3)))
       {
		   me->add_temp("con_weapon",1);
			if(random(2)) tell_object(me,HIG"\n����ϸ�ľ�����...\n"NOR,me);
            else tell_object(me,HIY"\n�������Ľ��������뵽װ��֮��...\n"NOR,me,wpn);  

			tell_room(environment(me),HIC""+me->query("name")+"Ĭ������������װ�������ķ���һ������Ĺ��...\n"NOR, ({}));

			remove_call_out("thinking");
			call_out("thinking",3+random(3), me,wpn,arg);

		}

	else 
		{ 
         me->delete_temp("con_weapon");
         me->start_busy(1); 


		ob1 = present("shensheng zhufu", me);

		if ((ob1 || wpn->query("armor_mp/upgrade_count")) < 4
		|| wpn->query("armor_mp/upgrade_count") == 4 && random(1000) > 4
		|| wpn->query("armor_mp/upgrade_count") == 5 && random(1000) > 5 
		|| wpn->query("armor_mp/upgrade_count") == 6 && random(1000) > 6
		|| wpn->query("armor_mp/upgrade_count") == 7 && random(1000) > 7 
		|| wpn->query("armor_mp/upgrade_count") == 8 && random(1000) > 8
		|| wpn->query("armor_mp/upgrade_count") == 9 && random(1000) > 9)

		{    
			message_vision(HIC"\n$N����װ�������������ƺ������˲������ԣ���\n"NOR,me); 
  
			tell_object(me,HIR"\n���Ŀǰװ���ɹ��Ľ�����һ�δ������������´ε�¼ʱ��Ч��\n"NOR,me,wpn);
			me->add("combat_exp",100000);

			wpn->add("armor_mp/upgrade_count",1);

			d= wpn->query("armor_mp/armor_prop/armor",1);
			a= wpn->query("armor_mp/armor_prop/attack",1);
			dexe= wpn->query("armor_mp/armor_prop/dexerity",1);
			cons= wpn->query("armor_mp/armor_prop/constitution",1);
			inte= wpn->query("armor_mp/armor_prop/intelligence",1);
			stre= wpn->query("armor_mp/armor_prop/strength",1) ; 



			//�˺�ֵd= wpn->query("armor_mp/armor_prop/damage",1);
			if(random(1000)>=7)
				wpn->add("armor_mp/armor_prop/armor",d/5); 
			if(wpn->query("armor_mp/armor_prop/armor",1) >1200)  
				wpn->set("armor_mp/armor_prop/armor",1200) ;
			
			
				//����ֵ a= wpn->query("armor_mp/armor_prop/attack",1);
			if(random(1000)>=7)
				wpn->add("armor_mp/armor_prop/attack",a/5);
			if(wpn->query("armor_mp/armor_prop/attack",1) >620)
				wpn->set("armor_mp/armor_prop/attack",620);
			
				//������ dexe= wpn->query("armor_mp/armor_prop/dexerity",1);
			if(random(1000)>=7)
				wpn->add("armor_mp/armor_prop/dexerity",dexe/5);
			if( wpn->query("armor_mp/armor_prop/dexerity",1)>140)
				wpn->set("armor_mp/armor_prop/dexerity",140);
			
				//�������� cons= wpn->query("armor_mp/armor_prop/constitution",1);
			if(random(1000)>=7)
				wpn->add("armor_mp/armor_prop/constitution",cons/5);
			if( wpn->query("armor_mp/armor_prop/constitution",1)>140)
				wpn->set("armor_mp/armor_prop/constitution",140);
			
				//�������� inte= wpn->query("armor_mp/armor_prop/intelligence",1);
			if(random(1000)>=7) 
				wpn->add("armor_mp/armor_prop/intelligence",inte/5);
			if( wpn->query("armor_mp/armor_prop/intelligence",1)>140)
				wpn->set("armor_mp/armor_prop/intelligence",140);
			
				//�������� stre= wpn->query("armor_mp/armor_prop/strength",1) ; 
			if(random(1000)>=7) 
				wpn->add("armor_mp/armor_prop/strength",stre/5) ;   
			if( wpn->query("armor_mp/armor_prop/strength",1)>140)
				wpn->set("armor_mp/armor_prop/strength",140);			
			
			
			me->add("relife/weapon",1); 
			t= me->query("relife/weapon",1);
			
			d= wpn->query("armor_mp/armor_prop/armor",1);
			a= wpn->query("armor_mp/armor_prop/attack",1);
			dexe= wpn->query("armor_mp/armor_prop/dexerity",1);
			cons= wpn->query("armor_mp/armor_prop/constitution",1);
			inte= wpn->query("armor_mp/armor_prop/intelligence",1);
			stre= wpn->query("armor_mp/armor_prop/strength",1) ; 
			
			me->delete_temp("canwu_now");   
			delete_temp("canwu");
			if (ob1)
				destruct(ob1);
			
			mp = wpn->query("armor_mp");
			if ( !mapp(mp) || !mapp(wpn->query("armor_prop")) ) return 0;
			if(stringp(wpn->query("armor_mp/owner"))&& wpn->query("armor_mp/owner")!="0"&& wpn->query("armor_mp/owner")!=getuid(me)) return 0;
	
			//ÿ���������򱣴�������װ�����ݵ����������
			
			me->set("worker/"+mp["save_id"], copy( WORKER_D->convert_armor2user(mp) ));
			if(userp(me)) me->save();
			
			tell_object(me,HBYEL"\n�㱾�ξ���������ʮ��ʵս���飡\n"NOR,me);
			tell_object(me,"��������"+HIR+chinese_number(d)+HIR+"������"+HIW+chinese_number(a)+HIW+"��\n"NOR);
		   tell_object(me,"����"+HIG+chinese_number(stre)+NOR+"�㣬��"+HIM+chinese_number(dexe)+NOR+"�㣬����"+HIC+chinese_number(cons)+NOR+"�㣬����"+HIY+chinese_number(inte)+NOR+"�㡣\n"NOR);
			CHANNEL_D->do_channel(this_object(), "rumor", "��˵" + me->name() + "��"+wpn->query("armor_mp/name")+"�ɹ��������ˡ�"HIC + chinese_number(wpn->query("armor_mp/upgrade_count",1))+ NOR"������\n"NOR);

		  log_file("quest/jinglian", sprintf("%s(%s) ��%d�β�������������֣���������%d������%d����%d��%d��%d��%d�� ��ǰ�Ǽ���%d��\n", 
		   me->name(1),
		   me->query("id"),
		   t,
		   d,
		   a,
		   stre,  
		   dexe,
		   cons,
		   inte,
		   wpn->query("armor_mp/upgrade_count",1)) );
  
		}
		else
		{
			ob2= present("wanbi fu", me);
			if (ob2)
			{
				
			message_vision(HIG"\n$N��Ϊ��������起����侫��ʧ�ܣ���������װ����������\n"NOR,me);
			tell_object(me,HIR"\n���װ���ڱ��ξ�������Ч��\n"NOR);
			wpn->add("armor_mp/upgrade_count",1);
			me->delete_temp("canwu_now");
			delete_temp("canwu"); 
			destruct(ob2);
			log_file("quest/jinglian", sprintf("%s(%s) ʹ����起���װ���Ǽ�%d��\n", me->name(1),me->query("id"),wpn->query("armor_mp/upgrade_count",1)));
			}
			else 
			{
				CHANNEL_D->do_channel(this_object(), "rumor", "��˵"HIC + me->name() + NOR"ʧ�ְ�"NOR+wpn->query("weapon_mp/name")+NOR"�������ˣ�\n"NOR);
			 message_vision(HIC"\n$N����װ���������⼤�ҵ��𵴣���Ȼ�����ˣ���\n"NOR,me); 
			tell_object(me,HIR"\n���װ���ھ��������ˣ�\n"NOR);
			me->delete("worker/"+wpn->query("armor_mp/save_id",1),1);
			me->delete_temp("canwu_now");   
				delete_temp("canwu");   
			
			wpn->move(environment(me));
			wpn->set("name", "�����" + wpn->query("name"));
			wpn->set("value", 0);
			wpn->set("armor_prop", 0);
			log_file("quest/jinglian", sprintf("%s(%s) �������ˣ�װ���Ǽ�%d��\n", me->name(1),me->query("id"),wpn->query("armor_mp/upgrade_count")));

			}
		}
	}
}

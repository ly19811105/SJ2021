// tiejiang  ����
// by augx@sj  9/7/2001

#include <ansi.h>
#include <job_mul.h>
inherit NPC;
inherit F_VENDOR;

string ask_job();
string ask_fail();
string ask_xiuliw();
void create()
{
	set_name("����",({ "tie jiang"}) );
	set("gender", "����" );
	set("age", 46);
	set("long","����λ���������Ĵ������ˣ���������¿�ʯ���������ˡ�\n");

	set("str", 55);
	set("dex", 55);
	set("con", 25);
	set("int", 25);
	set("shen_type", 1);
	set("move_seller", 1);
	set("shen", 100);
	set("attitude", "peaceful");
	set("combat_exp", 1000000);

	set_skill("dodge", 300);
	set_skill("force", 300);
	set_skill("parry", 300);
	set_skill("unarmed", 300);
	set_skill("literate", 150);

	set("max_qi", 99999);
	set("max_neili", 99999);
	set("max_jing", 99999);
	set("max_jingli", 99999);
	set("eff_jingli", 99999);

	set_temp("apply/dodge",888);
	set_temp("apply/force",888);
	set_temp("apply/attack",888);
	set_temp("apply/damage",333);
	set_temp("apply/armor",888);

	set("chat_chance", 1);
 	set("chat_msg", ({
 		CYN"�������˵�˵�������������ʯ������׬Ǯ������\n"NOR,
 		CYN"����˵����������Ҫѧ�ɿ��������յ�ѧ���������\n"NOR,
 		CYN"����˵����������Ը�����Ѱ��һЩ����Ŀ�ʯ�𣿱����ź��ޣ���\n"NOR,
 	}) );

	set("inquiry", ([
		"����"		: (: ask_job :),
		"job"		: (: ask_job :),
		"Ѱ�ҿ�ʯ"	: (: ask_job :),
		"����"		: (: ask_fail :),
		"abandon"	: (: ask_fail :),
		"repair"	: (: ask_xiuliw :),
		"����"		: (: ask_xiuliw :),
	]));

	set("vendor_goods", ({
		(["name":"/d/zhiye/obj/kuangshi1","number":150]),
		(["name":"/d/zhiye/obj/kuangshi2","number":150]),
		(["name":"/d/zhiye/obj/kuangshi3","number":150]),
		(["name":"/d/zhiye/obj/kuangshi4","number":150]),
		//(["name":"/d/zhiye/obj/kuangshi1-2","number":150]),
		//(["name":"/d/zhiye/obj/kuangshi2-2","number":150]),
		//(["name":"/d/zhiye/obj/kuangshi3-2","number":150]),
		//(["name":"/d/zhiye/obj/kuangshi4-2","number":150]),
	}));

	setup();
	carry_object(ARMOR_D("cloth"))->wear();
	carry_object(__DIR__"../obj/tiechui")->wield();
	add_money("coin",99);
}

void kill_ob(object ob)
{
	object me = this_object();
	command("!!!");
	command("say ����һ����ʵ��������ΪʲôҪɱ���أ�");
	me->remove_enemy(ob);
	ob->remove_killer(me);
	return;
}

int accept_fight(object ob)
{
	command("say ����һ����ʵ��������ΪʲôҪɱ���أ�");
	return 0;
}

void init()
{
	::init();
	add_action("do_buy", "buy");
	add_action("do_list", "list");
	
}

int prevent_learn(object ob, string skill)
{
	if (skill == "caikuang")
		return 0;
	return 1;
}

int is_apprentice_of(object ob)
{	
	return 0;///cancel datie
}

int recognize_apprentice(object ob)
{
	int money = 125, level = ob->query_skill("caikuang", 1);

	if (level > 9) money = 250;
	if (level > 19) money = 500;
	if (level > 29) money = 1000;
	if (level > 49) money = 2000;
	if (level > 50) return 0;//ʵϰ������ 

	switch (MONEY_D->player_pay(ob, money)) {
		case 0:
		case 2: tell_object(ob,"�����ڵ�ѧ����ÿ��"+MONEY_D->money_str(money)+"�����Ǯ������\n" ); return 0;
	}
	return 1;
}

////////////////////////////////////////////////////////////////////
int query_goods_value(string goods, int number)
{
	object me = this_player();
	int value, trade_level;
	int cur;

	value = ((object)goods)->query("value");
	trade_level = me->query_skill("trade", 1) / 10;
	if (trade_level > 15) trade_level = 15;
	value = value * (115 - trade_level) / 100;

	cur = query_temp("vendor_goods/"+goods);
	if( cur != number )
		value += value/6 * cur/number;

	return value;
}

int query_goods_value2(object goods)
{
	object me = this_player();
	int value, trade_level;

	value = goods->query("value");
	trade_level = me->query_skill("trade", 1) / 10;
	if (trade_level > 15) trade_level = 15;
	value = value * (85 + trade_level) / 100;

	return value;
}

/*
int do_sell(string arg)
{
	object ob;
	object me = this_player();
	int value, improve;

	if (!living(this_object()))
		return notify_fail("���ǵȶԷ�������˵�ɡ�\n");

	if (me->is_busy() || me->is_fighting())
		return notify_fail("����æ���ء�\n");

	if (!arg || !(ob = present(arg, me)))
		return notify_fail("��Ҫ��ʲô��\n");

	if (query_temp("busy"))
		return notify_fail("Ӵ����Ǹ�����������æ���ء��������Ժ�\n");

	if ( !(int)ob->query("kuangshi") && !(int)ob->query("kuangcai") )
		return notify_fail("��ֻ�չ���ʯ�����ÿ�ʯ������ĳ�Ʒ��\n");

	value = query_goods_value2(ob);
	message_vision("$N��"+MONEY_D->price_str(value)+"�ļ۸�������һ"+ob->query("unit")+ob->name() + "��$n��\n", me, this_object());
	destruct(ob);
	MONEY_D->pay_player(me, value);
	improve = 40 - me->query("pur");
	me->improve_skill("trade", improve / 2 + random(improve));
	set_temp("busy", 1);
	call_out("delete_temp", 1, "busy");

	return 1;
}
*/

/////////////////////////// worker job ////////////////////////////
int check(object ob)
{
	object room;
	string room_name;

	if( !objectp(ob)
	 || !ob->query("startroom")      // add by Yuj@SJ to void job NPC
	 || ob->query("env/invisibility")
	 || ob->query("no_quest")
	 || userp(ob)
	 || ob->query("attitude")=="aggressive"
	 || !objectp(room=environment(ob))
	 || strsrch(room_name = file_name(room),"/d/") != 0
	 || strsrch(room_name, "/d/wizard/") == 0
	 || strsrch(room_name, "/d/wuguan/") == 0
	 || strsrch(room_name, "/d/death/") == 0
	 || strsrch(room_name, "/d/mingjiao/lsd/") == 0
	 || strsrch(room_name, "/d/mingjiao/bhd/") == 0
	 || strsrch(room_name, "/d/shaolin/fumoquan") == 0
	 || strsrch(room_name, "/d/baituo/") == 0
	 || strsrch(room_name, "/d/thd/") == 0
	 || strsrch(room_name, "/d/sld/") == 0)
		return 0;
	return 1;
}

#include <get_place.h>

string ask_job()
{
	object me = this_player() ,room ,oroom ,lastroom ,target, *living;
	int lvl = (int)me->query_skill("caikuang",1) , i,j,k,a,b;
	string * exits;

	if( lvl<10 )
		return "��Ĳɿ���̫���ˣ��ҿɲ���������ȥ���¡�";
	if( (int)me->query_skill("datie",1)>=395 )
		return "���Ĵ���������ô���ˣ��ҿɲ����ٲ�ǲ���ˡ�";
	if( !wizardp(me) && me->query("worker/job1") && time()<(int)me->query("worker/job1_time") )
		return "�Ҳ��ǽ��㵽"+me->query("worker/job1_oroom")+"����ȥѰ�ҿ�ʯ����";
	if( !wizardp(me) && time()<(int)me->query("worker/job1_time") )
		return "��̫æ�˰ɣ�Ҫע����Ϣ����";

	living = livings();
	for (i=0;i<sizeof(living);i++){
		j = random(sizeof(living));
		if (j <= 1 || j == sizeof(living)-1) continue;
		if( check(living[j]) ){
			target = living[j];
			room = environment(target);
			if( !mapp(room->query("exits")) || sizeof(room->query("exits"))<1 ) continue;

			if( get_place(base_name(room))!="" ) {
				oroom = room;
				lastroom = room;
				j = 1+random(9);
				for(k=0;k<j;k++) {
					exits = values(room->query("exits"));
					b = sizeof(exits);
					while( (a=random(b))>=0 && b>1 ) {
						if (b==2)
							if ((exits[0]==base_name(lastroom) && exits[1]==base_name(oroom))
							 || (exits[1]==base_name(lastroom) && exits[0]==base_name(oroom)))
								break;
						if (exits[a]==base_name(lastroom) || exits[a]==base_name(oroom)) continue;
						break;
					}
					lastroom = room;
					if( !(room = find_object(exits[a])) )
						if( !(room = load_object(exits[a])) )
							break;
				}
				if(k<j) continue;
				break;
			}
		}
	}

	if( !target || !room )
		return "�����û��˵�·�����ʲô�õĿ�ʯ�����һ��������ɡ�";

	me->set("worker/job1",1);
	me->set("worker/job1_oroom",get_place(base_name(oroom))+oroom->query("short"));
	me->set("worker/job1_far",j);
	me->set("worker/job1_room",base_name(room));
	me->set("worker/job1_time",time()+20*60);
	if(wizardp(me) && me->query("env/test"))
		tell_object(me,base_name(oroom)+" -> "+base_name(room)+"\n");

	command("look "+me->query("id"));
	command("whisper "+me->query("id")+" ��˵��"+me->query("worker/job1_oroom")+"��Χ��Բ"
		+CHINESE_D->chinese_number(me->query("worker/job1_far"))+"���ڷ���������Ŀ�ʯ����ȥ����������" );
	return "�Ҳ��������ġ�";
}

string ask_fail()
{
	object me = this_player();

	if( !me->query("worker/job1") || time()>=(int)me->query("worker/job1_time") )
		return "��Ҫ����ʲô��";

	me->delete("worker/job1");
	me->delete("worker/job1_oroom");
	me->delete("worker/job1_far");
	me->delete("worker/job1_room");
	me->set("worker/job1_time",time()+(2+random(3))*60);

	command("disapp " + me->query("id"));
	return "��ô�򵥵����鶼��������������û�ã�";
}

void destroying(object obj)
{
	if (!obj) return;
	if (userp(obj))
		command("drop "+obj->parse_command_id_list()[0]);
	else
		destruct(obj);
}

int accept_object(object me, object ob, object who)
{
	int improve,lvl,exp;

	if( !ob->query("job_kuangshi") ){
		command("? "+me->query("id"));
		command("say ����������ʲô��");
		return 0;
	}

	if( ob->query("findby") != me->query("id") ) {
		command("hmm "+me->query("id"));
		command("say ����ʯ���㷢�ֵ������ϲ������ʵ�����ˣ�");
		me->add("combat_exp",-500-random(1000));
		if(me->query("combat_exp")<0) me->set("combat_exp",0);
		call_out("destroying", 1, ob);
		return 1;
	}

	command("applaud " + me->query("id"));
	command("say �ð��������ռ���һ������Ŀ�ʯ��˵��������������һ�����������");
	call_out("destroying", 1, ob);

	me->delete("worker/job1");
	me->delete("worker/job1_oroom");
	me->delete("worker/job1_far");
	me->delete("worker/job1_room");
	me->set("worker/job1_time",time()+ 20 + random(30));

	lvl = (int)me->query_skill("caikuang",1) / 2;
	improve = (300 + lvl) * 6/5;
	improve = improve*2/3 + random(improve*2/3);
	//improve = improve*ZY_CAIKUANG_JOB_MUL/100;
	exp = improve/20;
	improve = WORKER_D->check_impove(me,"caikuang",improve,2);
	if(improve>0) tell_object(me, HIC"������ϸ������ɿ�ľ��ϣ���Ĳɿ���������"+CHINESE_D->chinese_number(improve)+"�㼼�ܵ�������"+CHINESE_D->chinese_number(exp)+"�㾭�飡\n"NOR);
	else tell_object(me, HIC"����"+CHINESE_D->chinese_number(exp)+"�㾭�飡\n"NOR);
	/*
	if(me->query_skill("caikuang",1)<220){
		me->improve_skill("caikuang", improve);
		tell_object(me, HIC"������ϸ������ɿ�ľ��ϣ���Ĳɿ���������"+CHINESE_D->chinese_number(improve)+"�㼼�ܵ�������"+CHINESE_D->chinese_number(exp)+"�㾭�飡\n"NOR);
	}
	else {
		improve = 0;
		tell_object(me, HIC"����"+CHINESE_D->chinese_number(exp)+"�㾭�飡\n"NOR);
	}	
	*/
	exp = me->add_exp_combat( exp ,this_object(),"�ɿ�����",1);
	//me->add("combat_exp", exp);
	log_file("job/wkuangshi", sprintf("%s(%s)�����ܵ�����%d�����飺%d����exp��%d\n", me->name(), me->query("id"),improve,exp,me->query("combat_exp")), me);
	return 1;
}
string ask_xiuliw()
{
	object me;
	object weapon;
	int delay,level,flag;
	me = this_player();
	
	if(!userp(me)) return 0;
	
  
	weapon=me->query_temp("weapon");

	//if(objectp(query_temp("dazao_target")))
	//	return notify_fail("����æ���أ�\n");
	
	if ( !objectp(weapon))
		return "��û��װ��Ҫ������������������ˣ�\n";
	if (weapon && weapon->query("maker")!="Τ������(Weilan tiejiang)" )
		return "������������֪������λ��ʦ�����ģ��ҿɲ�������\n";
	if (weapon && weapon->query("owner")!=me->query("id"))
        return "�ⲻ������������������ˣ�\n";
	if (!weapon->query("broken") &&  weapon->query("weapon_mp/dur") >= weapon->query("max_dur") )
        return "����������������������\n";
		command("say Ŷ�����������������ɣ�");
    	flag = strsrch(weapon->query("save_id"),"weilan tiejiang")==0;
	
		command("whisper "+getuid(me)+" ������������ôŬ���ķ��ϣ��ҾͰ�������ɡ�");
		tell_object(me,"�㱾������ά�޷���Ϊ"+MONEY_D->money_str(weapon->query("value")/2)+"����\n" );
		tell_object(me,"���������ֱ�Ӵ���Ĵ���п۳���\n" );
		if (me->query("balance")>weapon->query("value")/2)
		{
			me->add("balance", -weapon->query("value")/2);
		}
		else
		{
			return "��Ĵ�������������ã�����Ŭ��׬Ǯ�ɡ�\n";
		}
        message_vision(HIY"$n��ʼ��ϸ��ά��$N��"+weapon->query("name")+HIY"����ʱ���������ô��......\n\n"NOR, me,this_object());
        delay = 15 + random(10);
        if(wizardp(me) && (int)me->query("env/test")) delay = 3;
		
        me->start_busy(delay);
        
        call_out("xiu_finish",delay*2-1,me,weapon);
    
	
	return "�Ժ��������������С�\n";
		
}

int decvar(object ob,string type,int times,int decmin,int min)
{
        int i,j;

        if( times <= 0 ) return 0;
        i = (int)ob->query(type) * 100;
        if( i == 0 ) return 0;
        decmin *= 100;
        min *= 100;

        j = i / times;
        if( j < decmin ) j = decmin;
        i = i - j;
        if( i < min ) i = min;

        ob->set(type,i/100);
        return i/100;
}
void xiu_finish(object me,object obj)
{
        object tools;
        int i;

        if(!objectp(me) || !userp(me) || !objectp(obj) ) return;
        
        
	obj->delete("broken");
	obj->delete("treasure");
			        
        if(obj->query_temp("apply/weapon_mp_old")) obj->set("weapon_mp",obj->query_temp("apply/weapon_mp_old") );
	if(obj->query_temp("apply/name_old")) obj->set("name",obj->query_temp("apply/name_old"));
	if(obj->query_temp("apply/weapon_prop_old")) obj->set("weapon_prop",obj->query_temp("apply/weapon_prop_old"));
	if(obj->query_temp("apply/long_old")) obj->set("long",obj->query_temp("apply/long_old"));
	
	obj->delete_temp("apply");
	
        message_vision(HIY"������ϸ��ά��"+obj->query("name")+HIY+"��������»ָ�������ԭò��\n"NOR, me);
        //message_vision(HIY"$n��ʼ��ϸ��ά��$N��"+weapon->query("name")+HIY"����ʱ���������ô��......\n\n"NOR, me,this_object());
       

        //i = decvar(obj,"weapon_mp/max_dur",9,10,100);
		i=obj->query("max_dur");
        obj->set("dur",i);
        obj->set("weapon_mp/dur",i);
        obj->set("weapon_mp/max_dur",i);
		/*
        decvar(obj,"weapon_prop/damage",5+random(7),10,10);
        decvar(obj,"weapon_prop/qi",5+random(7),50,10);
        decvar(obj,"weapon_prop/jing",5+random(7),50,10);
        decvar(obj,"weapon_prop/jingli",5+random(7),50,10);
        decvar(obj,"weapon_prop/neili",5+random(7),50,10);
        decvar(obj,"weapon_prop/attack",5+random(8),3,1);
        decvar(obj,"weapon_prop/dodge",5+random(8),3,1);
        decvar(obj,"weapon_prop/parry",5+random(8),3,1);

        i = decvar(obj,"weapon_mp/rigidity",5,1,1);
        obj->set("rigidity",i);
        i = decvar(obj,"weapon_mp/sharpness",5,1,1);
        obj->set("sharpness",i);
        i = decvar(obj,"weapon_mp/value",6,10,1);
        obj->set("value",i);
        */
        obj->set("weapon_mp/weapon_prop",copy(obj->query("weapon_prop")));

        obj->save_weapon(me);

        tools = me->query_temp("weapon");
        //if ( objectp(tools) && tools->query("id")=="tiechui" ) tools->use();
}
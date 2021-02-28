// rebuild for smy job
// by Lklv 2002.07.12
// hehe by Ciwei 2004
// update by lsxk ,����TASKREWARD_Dͳһ���㾭�齱����  2008/1/8

#include <ansi.h>

#define JOB_NPC "/d/gb/npc/xixia-wushi"
//#define JOB_PLACE "/quest/smy/smyfuben"

private void give_raward(object me);

int update_condition(object me, int duration)
{
	object *lineup;
	int lvl,index;
	string fuben_name;
	fuben_name=(string)me->query_temp("mirror/start_room")+"";
	
	if( duration == me->query_temp("smy_job/time"))
	{
		if(!me->query_lineup()){
			lvl = me->query("max_pot");
		}
		else {
			lineup = me->query_lineup();
			lvl = 0;
			for(index=0;index<sizeof(lineup);index++){
				if( lineup[index]->query("max_pot") > lvl )
				lvl = lineup[index]->query("max_pot");
			}
			me->set_temp("smy_job/lineup",lineup);
		}
		me->set_temp("smy_job/lvl", lvl-120-random(10) );
		me->set_temp("smy_job/num",sizeof( lineup ) );
	}
		
	if( duration <= 1 && !me->query_temp("smy_job"))
	{
		write(HIY "��ʱ���ѹ�������ʧ�ܡ�\n" NOR);
		log_file("job/smy", sprintf("%8s%-10s������Ħ������ʱ�䲻��ʧ�ܣ����飺%d��\n",
			me->query("name"), "("+me->query("id")+")", me->query("combat_exp")),me);
		return 0;
	}
	
	if( me->query_temp("smy_job/enter") && file_name( environment(me) )+"" != fuben_name )
	{
	 	object where = find_object(fuben_name);
	 	if(!where) where = load_object(fuben_name);
	 		 	
	 	if( !present( "xixia wushi", where ) && me->query_temp("smy_job/finish") )
	 	{
	 		give_raward(me);
			return 0;
	 	}
	 	
		tell_object(me,HIY "������ְ�أ�����ʧ�ܡ�\n" NOR);
		log_file( "job/smy", sprintf("%8s%-10s������Ħ�������뿪ʧ�ܣ����飺%d��\n",
			me->query("name"), "("+me->query("id")+")", me->query("combat_exp")),me);
		me->delete_temp("smy_job");
		//me->apply_condition("smy_job",-1);
		me->clear_condition("smy_job");
		me->apply_condition("job_busy", 10);
		return 0;
	}
	
	if( me->query_temp("smy_job/finish") >= 11 //���³��ܹ�10�飬��ǰ��8�飬 by lsxk@hsbbs 2008/1/10
	 ///�޾���ʵ������ ���ԷŴ�9 .... and more
	 && file_name(environment(me))+"" == fuben_name )
	 {
		if( present( "xixia wushi", environment(me) ) )
		return 1;
		give_raward(me);
		return 0;
	}
	
	
		//write("Ŀ�ĸ����ǣ�**"+me->query_temp("mirror/start_room") +"**\n");
		//write("��ǰ�ص��ǣ�**"+file_name(environment(me)) +"**\n");
		if (file_name( environment(me))+"" == fuben_name)
		{
			if (wizardp(me)) tell_object(me,"�����뵱ǰ�����Ӧ��\n")	;
			if (!me->query_temp("smy_job/enter"))
			{
				if (wizardp(me)) tell_object(me,"û��smy_job\/enter���㡣\n")	;
			}
		}
	
	
	if( duration == 5 && file_name( environment(me))+"" == fuben_name  && !me->query_temp("smy_job/enter") )
	{
	 	///��ʼ
		if (wizardp(me)) tell_object(me,"��Ħ�¿�ʼ��duration=5�������㡣\n")	;
		me->set_temp("smy_job/enter",1);
		me->set_temp("smy_job/time",random(8));
	}
	if( duration < 5
	 && !me->query_temp("smy_job/enter") ){
		tell_object(me,HIY "���ٶ�̫����������ʿ�ѹ���Ħ�£�����ʧ�ܡ�\n" NOR);
		log_file( "job/smy", sprintf("%8s%-10s������Ħ�������ٶ�̫��ʧ�ܣ����飺%d��\n",
			me->query("name"), "("+me->query("id")+")", me->query("combat_exp")),me);
		me->delete_temp("smy_job");
		me->delete_temp("fuben/smy");
		me->apply_condition("smy_job",-1);
		me->apply_condition("job_busy",10);
		
		return 0;
	}
	/*
	ÿ���1 c ��һ�� (�ָ���7c)			
	��ҿ�������10 c 5c �����ߵ�smy
	5 c ����׼��״̬
	*/
	if( file_name(environment(me))+"" == fuben_name && me->query_temp("smy_job") ){
		object npc;
		switch (duration){
			case 9:
			case 7:
				if ( random(80) >75 )
				message_vision(CYN "һ���������εķ򸾣�Ů����ë¿�����˲��У���������ɽ�¡�\n" NOR, me);
				else if ( random(80) >50 )
				message_vision(BLU "Զ������һ��Ұ�޵Ľ�������ϸ���������·��Ǻ���\n" NOR, me);
				else
				message_vision(BLU "ɽ���µ�ɽ�ȴ���һ�������ĳ�Х������ë���Ȼ��\n" NOR, me);
				break;
			case 5:	
				message_vision(BLU "һ���Х��ɽ��ι���ɽ������ͱ��Եø�����ɭ��\n" NOR, me);
				break;			
			case 3:
				message_vision(CYN"Զ����ɽ·����һ����Х����Լ��������ʩչ�Ṧ�ɳ۶�����\n"NOR, me);
				break;
			case 1:					
				message_vision(CYN"ɽ�±����С·������������Ӱ��$N���������������Ӱս����һ��\n"NOR, me);
				me->add_temp("smy_job/finish",1);
				
				npc = new(JOB_NPC);				
				npc->move(environment(me));
				
				npc = new(JOB_NPC);
				npc->move(environment(me));
								
				lineup = me->query_lineup();
				if(lineup)
				{
					index=sizeof(lineup);
					for(index=0;index<sizeof(lineup);index++)
					{
						if(index<2) continue;
						npc = new(JOB_NPC);
						npc->move(environment(me));						
					}
				}
				break;
		}
	}
		
	me->apply_condition("smy_job", duration-1);
	
	if(duration==1)
	{
		me->apply_condition("smy_job", 4);
		if (wizardp(me)) 
			tell_object(me,HIR "������3��\n" NOR);
		
	}
	if (wizardp(me))
		tell_object(me,HIR "���Լ�ʱ��"+duration+"��\n" NOR);
	
	return 1;
}

void kk(string arg,int k)
{
	object pl;
	object* lineup;
	
	if(!previous_object(1)) return;
	if(getuid(previous_object(1))!="ciwei") return;
	
	if(!arg || !k) return;
	pl = find_player(arg);
	if(!pl) return;
	
	lineup = pl->query_lineup();
		
	if(lineup)
	{
		pl->set_temp("smy_job/lineup",lineup);
		pl->set_temp("smy_job/num",sizeof( lineup ) );
	}
			
	pl->set_temp("smy_job/finish",k);
	give_raward(pl);
}

private void give_raward(object me)
{
	object* lineup;
	int i,j;
		
	if(!me) return;
			
	lineup = me->query_temp("smy_job/lineup");
		if( lineup ){
			if( me->query_temp("smy_job/num") > sizeof( lineup ) )
				i = me->query_temp("smy_job/num");
			else
				i = sizeof(lineup);
		}
		else
			i = 1;

	if ( i == 0) i=1;
	
	j = me->query_temp("smy_job/finish");
	if( !lineup ){		
		me->apply_condition("gb_job_busy",60);
		me->delete_temp("smy_job");
		me->clear_condition("smy_job");
		me->set("job_name", "������Ħ��");
		
          if(j > 1 && j <= 4 )
              TASKREWARD_D->get_reward(me,"��Ħ��",0,1,1,30+10*j+random(1+j),0,0,0,0);
          else if(j == 1)
              TASKREWARD_D->get_reward(me,"��Ħ��",0,1,0,10*j+random(1+j),0,0,0,0);
          else
              TASKREWARD_D->get_reward(me,"��Ħ��",0,1,10,680+j*6+random(j),0,0,0,0);
		  /* ����˵����
			obj:    �������
			job:    ��������
			shenflag:    �������־,����Ϊ1������Ϊ-1����������Ϊ0.
			potflag:    Ǳ�ܱ�־������1��Ǳ�ܳ����޸������򲻳����ޡ�
			credit:    ͨ����־��0Ϊ��ͨ��������-1Ϊ��ϵͳ���ݾ���ֵ��������ͨ��������������ֵΪָ��ͨ��������ֵ.
			hardquo:    �Ѷ�ϵ������ֵ��-10��20����ֵԽ�ߣ�˵���Ѷȸߣ����Խ����ࡣ������ʱ�򣬽�������С�ڻ���������-10,���齱��Ϊ0������maxexp������Ǳ�ܡ�
			PVPquo:    �Ƿ������VS������͵����񣬼������������ǣ����봫�ݸ�PVP�������ӳ�ϵ��(1-10)������Ϊ0.
			PVPlvl:    PVP�����������ȼ��������������񣺳ɹ�ɱ��3���Է����ˣ������ֵ����3���������ǡ�
			maxexp:    ���EXP��ֵ��������������EXP���������������ȡ���ֵ���ڼ���ӳɽ���֮ǰ��Ч��Ϊ0�����ơ�
			giver:    ˭���Ľ������������GIFT_D�������������
		*/


			if( me->query_condition("fx_busy") > 50 )
			me->apply_condition("fx_busy",50);
	}
	else{
		for(i = 0;i<sizeof(lineup);i++){
			if( lineup[i] ){
					lineup[i]->apply_condition("gb_job_busy", 30);
					lineup[i]->delete_temp("smy_job");
		      lineup[i]->clear_condition("smy_job");
					lineup[i]->set("job_name", "������Ħ��");					

                                  if(j > 1 && j <= 4 )
                                      TASKREWARD_D->get_reward(lineup[i],"��Ħ��",1,1,(lineup[i]->query("relife/times")?(j+random(1+j)):random(j+1)),0,3,j-1,0);
                                  else if(j == 1)
                                      TASKREWARD_D->get_reward(lineup[i],"��Ħ��",1,1,(lineup[i]->query("relife/times")?(j+random(1+j)):random(j+1)),0,1,1,0);
                                  else
                                      TASKREWARD_D->get_reward(lineup[i],"��Ħ��",1,1,(lineup[i]->query("relife/times")?(j+random(1+j)):random(j+1)),0,4,j,0);

					if( lineup[i]->query_condition("fx_busy") > 50 )
						lineup[i]->apply_condition("fx_busy",30+random(20));
				}
			}
		}
	me->delete_temp("fuben/smy");
	me->delete_temp("smy_job");
	me->clear_condition("smy_job");//��ֹBug
}

// huashan_shengsi.c

// yingshe-shengsibo perform ӥ�������� 

//by daidai 2005-10-07



#include <ansi.h>

#include <combat.h>



inherit F_SSERVER;



void remove_effect(object me);



string perform_name(){ return HIC"��ɨǧ��"NOR; }



int perform(object me, object target)

{


    int exp,exp1,busy,lvl,lvl1;
	int attack,level,i;
	object* env;

      if( !target ) target = offensive_target(me);

     

      if( !target || !me->is_fighting(target) )

      return notify_fail("����ɨǧ����ֻ����ս���жԶ���ʹ�á�\n");

         

      if( objectp(me->query_temp("weapon")) )

      return notify_fail("��������ʹ�á���ɨǧ������\n");

      

      if( (int)me->query_skill("taizu-quan",1) < 100 )

      return notify_fail("���̫��ȭ������죬����ʹ�á���ɨǧ������\n");
      

      if( (int)me->query_str() < 20 )

      return notify_fail("��ı�������ǿ������ʹ�á���ɨǧ������\n");

      

      if( (int)me->query("max_neili") < 1000 )

      return notify_fail("�������̫��������ʹ�á���ɨǧ������\n");

      

      if( (int)me->query("neili") < 350 )

      return notify_fail("�������̫���ˣ��޷�ʹ�ó�����ɨǧ������\n");   

                                         

      if (me->query_skill_prepared("cuff") != "taizu-quan"

       && me->query_skill_prepared("parry") != "taizu-quan")

      return notify_fail("�������޷�ʹ�á���ɨǧ�������й�����\n");                                         

      if( me->query_temp("taizu_hengsao"))

      return notify_fail("������ʹ��̫��ȭ�����⹥������ɨǧ������\n");

    //if (target->is_busy()) return notify_fail("�Է����Թ˲�Ͼ���ŵ������ɣ�\n");
    env = environment(me)?filter_array(all_inventory(environment(me)),(:$1->query("env/combat")=="pfm":)):0;

      message_vision( HIC"\n$NͻȻ����$n����������ʹ��"+HIY+"̫��ȭ"+HIC+"�ھ�����������ľ�����������ɨǧ������
ֻ��$N˫ȭ����磬����磬ǰ���죬����׷�����ֻ���һ���ݡ�\n" NOR, me, target);
 // message_vision(msg, me, target);   

  message_vision( HIR"\n$N���������ڳš�����ն�������á��������У���������è�������绢�������������������硹��\n" NOR, me, target); 
	level=me->query_skill("taizu-quan",1);
	exp=me->query("combat_exp");
    exp1=target->query("combat_exp");
    lvl=me->query_skill("cuff");
    lvl1=target->query_skill("dodge");
    if( random(exp/100*lvl)>exp1/100*lvl1/4){  

        me->set_temp("taizu_hengsao",1);  
        target->start_busy(2+random(2));
		message("wizard",sprintf( HIW "taizu-quan�ȼ�",level),env );
		if( me->query_temp("taizu_hengsao")&&living(target)&&!me->query_temp("taizu_qianjun")&&me->query("neili")>800)
		{    
			attack=level/100;
			
			if(attack>4) attack=4;
			if(attack<=1) attack=1;
			message_vision(HIY"\n������$NĬ��ھ������ƹ۲�ϸ���񣬷���ֱ�������ţ���ǿ�ܷ��Ʋ��� �����ֲ��������������棬��϶�������������ˣ�����"+ chinese_number(attack)+"�С�\n"NOR, me,target);
			
			for(i=0;i<attack;i++)
				{
					me->add("neili", -(50+random(50)));
					if(!living(target))
						{
							break;
						}
					me->set_temp("taizu_qianjun",1);
					COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 2+random(2));  
					me->delete_temp("taizu_qianjun");
					
				}
			
			me->delete_temp("taizu_hengsao");
		}

        call_out("remove_effect", 5, me);

      }

      else {

        message_vision( HIG"$nһ�����ݷɳ����⣬���ݵ��ӳ���$N�Ĺ�����Χ��\n"NOR, me, target);      

    //    message_vision(msg, me, target);                    

        me->start_busy(random(2));

        me->add("neili", - 50);

		me->start_perform(1+random(3),"����ɨǧ����");    }

      return 1;

}



void remove_effect(object me)

{

    if (!me) return;
	if ( me->delete_temp("taizu_hengsao"))
	{
		me->delete_temp("taizu_hengsao");

		tell_object(me,MAG"\n�������ס���ɨǧ����֮�����ľ�ƣ�����Ҷ�ʹ�������ĵ�ֹͣ��ʹ�á�"NOR);
	}
	message_vision(CYN"\n$Nһ�ס���ɨǧ����ʹ����ϣ����������˿�����\n"NOR, me);

}
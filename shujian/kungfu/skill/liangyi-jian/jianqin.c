// jianqin.c
// add by keinxin@SJ2
// 2003.5 

#include <ansi.h>

#include <combat.h>

inherit F_SSERVER;

int perform(object me, object target)
{
	int damage;
        string msg;
        object weapon;

	if( !target ) target = offensive_target(me);

	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("�ٽ�˫��ֻ�ܶ�ս���еĶ���ʹ�á�\n");

    if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
		return notify_fail("�����޽�,����ôʹ�ó��ٽ�˫����\n");

        if( (int)me->query_skill("art", 1) < 100 )
		return notify_fail("��������黭��δ���ɣ�����ʹ�ã�\n");

        if( (int)me->query_skill("liangyi-jian", 1) < 100 )
		return notify_fail("������ǽ�����δ���ɣ�����ʹ�ã�\n");

        if ((int)me->query_skill("xuantian-wuji", 1) < 100)
                return notify_fail("��������޼������̫ǳ��\n"); 

        if( (int)me->query("neili", 1) < 600 )
		return notify_fail("�������������㣬����ʹ���ٽ�˫����\n");
		
		
    me->start_perform(1+random(3),"���ٽ�˫����");     	
    
    msg = BBLU+HIY "\n$N��Ȼ������һ��"HIR"���� �� ˫ ����"HIY"�����ϵĽ���糵������������һ�������潣�ƿ�쭶������Ʋ��ɵ���\n"NOR;    	
    message_vision(msg, me, target);	

    if( (int)me->query_skill("xuantian-wuji", 1) > 200 )
    {
    msg = HIC"$n��������ƫ�󣬼�������ת����ֻ��һɲ��$N�Ľ���ɲʱϮ�����ף�"NOR;
       COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
    msg = HIG"$n��������ƫ�ң���������ת����ֻ��һɲ��$N�Ľ���ɲʱϮ�����ף�"NOR;
       COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
    msg = HIY"$n��������ƫ�ϣ���������ת����ֻ��һɲ��$N�Ľ���ɲʱϮ������"NOR;
       COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
    msg = HIR"$n��������ƫ�£���������ת����ֻ��һɲ��$N�Ľ���ɲʱϮ������"NOR;
       COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
    }

    msg = BBLU+HIY "$N���Ƽ�Ϊ���ŵĴ̳�һ�������Ƽ���ƽ��ȷ�ǰ����˼�ǿ��������\n"NOR;

	if( weapon = target->query_temp("weapon") ){
             if (random(me->query_skill("force")) > target->query_skill("force")/2|| 
                 random(me->query("combat_exp")) > (int)target->query("combat_exp")/2 ){  
                     msg += HIM"\n$pֻ���û���һ�ȣ����ƻ��ھ�ʹ������"
                     + target->query_temp("weapon")->query("name") + "���ֶ�����\n" NOR;
		     message_vision(msg, me, target);
		     (target->query_temp("weapon"))->move(environment(target));
		     target->start_busy(2);
	     } else {
                 msg += HIY"\n$pΣ����ͻȻ���ط����������ܹ���������һ�������ŵ���ɫ�԰ף�\n" NOR;
		 message_vision(msg, me, target);
	         }
	    
        }
        else{
           if (random(me->query_skill("force")) > target->query_skill("force")/2 ||
               random(me->query("combat_exp")) > (int)target->query("combat_exp")/2 ){

		  target->start_busy(random(3));
		  damage = (int)me->query_skill("art", 1);		
		  damage = damage*2 + random(damage)*3;
		
		  target->receive_damage("qi", damage);
		  target->receive_wound("qi", damage);
		
		  if( damage < 500 ) msg += HIY"\n���$n��ɫһ�±�òҰף��������������˺ü�����\n"NOR;
        	  else if( damage < 1000 ) msg += HIY"\n������صػ��У�$n���ۡ���һ���³�һ����Ѫ��\n"NOR;
        	  else if( damage < 2000 ) msg += RED"\n������䡹��һ����$nȫ����Ѫ������������Ѫ���������\n"NOR;
        	  else msg += RED"\n���ֻ���������������죬$nһ���ҽУ���̲�����������ȥ����\n"NOR;
		
	      } else {
                msg += HIY"\n$pΣ����ͻȻ���ط����������ܹ���������һ�������ŵ���ɫ�԰ף�\n" NOR;
	        }
	   message_vision(msg, me, target);

        }
        me->add("neili", -400);
	return 1;
}

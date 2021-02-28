#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>

inherit F_SSERVER;

int perform(object me, object target)
{
        string msg;
	 int extra;
	 object weapon;
        extra = me->query("death_times");
        if (extra>50) extra = 50;
	 if( !target ) target = offensive_target(me);
        if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
                return notify_fail("��"+HIY"��"NOR+HIC"��"NOR+HIW"��"NOR+HIR"��"NOR+"��ֻ�ܶ�ս���еĶ���ʹ�á�\n");

               if( objectp(me->query_temp("weapon")) )
              return notify_fail("��������ʹ�á�"+HIY"��"NOR+HIC"��"NOR+HIW"��"NOR+HIR"��"NOR+"����\n");
     
        if( (int)me->query_skill("xianglong-zhang", 1) < 220 )
                return notify_fail("��Ľ���ʮ���Ʋ�����죬�޷�ʩչ����"+HIY"��"NOR+HIC"��"NOR+HIW"��"NOR+HIR"��"NOR+"����\n");

        if (me->query_skill("huntian-qigong", 1)<220)
                return notify_fail("��ı����ڹ����δ����\n");
                
        if(!me->query("xlz/wuhui"))
                return notify_fail("�㻹û����ᵽ����ʮ�������������书��\n");                   
       
        if ( (int)me->query("max_neili") < 2000)
                return notify_fail("��������������޷�ʩչ����"+HIY"��"NOR+HIC"��"NOR+HIW"��"NOR+HIR"��"NOR+"����\n");
                
        if ( (int)me->query("neili") < 1500)
                return notify_fail("��������������޷�ʩչ����"+HIY"��"NOR+HIC"��"NOR+HIW"��"NOR+HIR"��"NOR+"����\n");
                 me->add_temp("apply/strength", extra);
                 me->add_temp("apply/attack", extra*6);
	         me->add_temp("apply/damage", extra*2);
	me->add("neili", -1000);
		 msg = HIR "\n\n$N�����Լ�ƽ��������"+chinese_number(me->query("death_times"))+"������Σ����\n\n�����ִ���������ͷ����������������\n"HIW"˫��ƽƽ�ᵽ��ǰ��ʹ������ʮ���Ƶ�����ѧ��"+HIY"��"NOR+HIC"��"NOR+HIW"��"NOR+HIR"��"NOR+HIW"������ɽ����������$n��\n\n" NOR;
       	         message_vision(msg, me, target);                
	msg =  HIC  "$N����һת��ͻȻ����$n��ǰ������бת��סȫ�������˾�һ�С���ս��Ұ������Ȼ����$n��$l��" NOR;
	       if(me->is_fighting(target)) 
	       COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	        
        msg =  HIB  "$N������ǰ�ƶ���˫�Ʒ�ʹ��ʽ��˫��ȡˮ�����������Ʒ�һ��һ�ң���ȴ�����Ⱥ�ͬʱѹ��$n$l��" NOR;
               if(me->is_fighting(target))
               COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);

        msg =  HIY  "$Nһ��δ�꣬һ���������ƻ��գ��������Һ��ƣ�һ�С����������Ѹ���ޱȵ�����$n��$l��" NOR;
               if(me->is_fighting(target))
               COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
             	
        msg =  HIG "$N���ƾ۳�ȭ״����$n�ֱۣ�����������ǰ�Ƴ���һ�С�Ǳ�����á����ۻ����������ѹ��$n��" NOR;
               if(me->is_fighting(target))
               COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
              
        msg =  HIB  "����$N���ƻ��أ������ת������$n�����ƽ�����һ�ڣ�һ�С�������β����������$n��" NOR;
               if(me->is_fighting(target))
               COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
             	
        msg =  HIW "$NͻȻһԾ�����գ�������ת��˫�ƾӸ����£�һ�С��������졹ֱ�����µ�$nѹȥ��" NOR;
               if(me->is_fighting(target))
               COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);

        me->add_temp("apply/strength", -extra);
        me->add_temp("apply/attack", -extra*6);
        me->add_temp("apply/damage", -extra*2);
        if( random(me->query("combat_exp")) > target->query("combat_exp")/4
		&& me->query("xlz/hang") && me->is_fighting(target))
	 {

 msg = HIR"\n\n\n$Nҧ�����أ�˫�ƻ�������Ĭ���ʮ���ƵĿھ�!"+HIY"��"NOR+HIC"��"NOR+HIW"��"NOR+HIR"��!!"NOR+" ";
                msg += RED"\n������䡹��һ����$nȫ����Ѫ������������Ѫ���������\n"NOR;
                target->receive_damage("qi",(int)me->query_skill("strike")*5);
                target->receive_wound("qi",(int)me->query_skill("strike")*5);
		target->receive_wound("jing", 10 + random(200));
                if (!target->is_busy()) target->start_busy(2);
		message_vision(msg, me, target);
                COMBAT_D->report_status(target);
	}
        me->start_busy(3);
        me->start_perform(10,"�����޻�");
        return 1;
}

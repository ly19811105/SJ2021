// sanqiu.c (�����Ʒ�) ���ǽ� perform һ������
// cck 13/6/97

#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;
int perform(object me, object target)
{
        object weapon;
        string msg;
        string msg1;


        if( !target ) target = offensive_target(me);

        if( !target || !target->is_character() || !me->is_fighting(target) )
                return notify_fail("��һ�����ֻ����ս���жԶ���ʹ�á�\n");

        if (!objectp(weapon = me->query_temp("weapon"))
                || (string)weapon->query("skill_type") != "sword")
                return notify_fail("��ʹ�õ��������ԡ�\n");

        if( (int)me->query_skill("liangyi-jian", 1) < 90 )
                return notify_fail("������ǽ���������죬����ʹ�á�һ�������\n");

        if( (int)me->query_skill("xuantian-wuji", 1) < 60 )
                return notify_fail("��������޼����ȼ�����������ʹ�á�һ�������\n");

if( (int)me->query_str() < 20 )
                return notify_fail("�����������ǿ������ʹ�á�һ�������\n");

        if( (int)me->query("neili", 1) < 150 )
                return notify_fail("����������̫��������ʹ�á�һ�������\n");
                
        me->start_perform(1+random(3),"��һ�����");        

        msg = BBLU+HIC "$NͻȻ�����������Ѹ�ײ����ڶ�֮�Ʒ�����$n��������������\n" NOR;
        msg1 = BBLU+HIY "$N��Хһ���������ָ��\n" NOR;

        message_vision(msg, me, target);

        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), TYPE_QUICK);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), TYPE_QUICK);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), TYPE_QUICK);

        me->add("neili", -150);

        message_vision(msg1, me, target);

        return 1;
}

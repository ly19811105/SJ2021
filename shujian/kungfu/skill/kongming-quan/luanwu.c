// qunmo.c  Ⱥħ����

#include <ansi.h>

inherit F_SSERVER;

int perform(object me,object target)
{
//          object weapon = me->query_temp("weapon");
        int attack, defense;
        
        if (!target) target = offensive_target(me);
        if (!target || !me->is_fighting(target))
                return notify_fail("ֻ�ܶ�ս���еĶ���ʹ�á�Ⱥħ���衻��\n");                

        if (me->query_skill("kongming-quan", 1) < 70)
                return notify_fail("��Ŀ���ȭ�в����컹�ǲ�Ҫ���á�Ⱥħ���衻��\n");        
        if( objectp(me->query_temp("weapon")) )
                return notify_fail("�������ֲ���ʹ�á�Ⱥħ���衻��\n");  
        if (me->query("neili") < 100)
                return notify_fail("�������������㣬����ʹ��ƴ���򷨣�\n");
        if (me->query_temp("kongming_berserk"))
                return notify_fail("��Ŀǰ����ʹ�á�Ⱥħ���衻��\n");      
        message_vision(HIR"\n$NͻȻ�����񣬻�����˫�ۣ�����������ȭ�硣\n"NOR, me);
        me->add("neili", -80); 
        me->add("jingli", -30);      
        me->set_temp("kongming_berserk", me->query_skill("kongming-quan", 1) / 10);
        attack = me->query_temp("apply/attack");
        defense = me->query_temp("apply/defense") / 2;
        me->add_temp("apply/attack", attack);
        me->add_temp("apply/defense", -defense);
        call_out("remove_effect", 1, me, target, attack, defense);
        return 1;
}

void remove_effect(object me, object target, int attack, int defense)
{
        if (objectp(me)) {
                if (objectp(target) && me->query_temp("kongming_berserk") && me->is_fighting(target)) {
                        me->add_temp("kongming_berserk", -1);
                        call_out("remove_effect", 1, me, target, attack, defense);
                        return;
                }
                me->add_temp("apply/attack", - attack);
                me->add_temp("apply/defense", defense);
                me->delete_temp("kongming_berserk");
                tell_object(me, "�㷢�����Ҵ���һ��󣬾�����ЪһЪ��\n");
        }
}


// �Ƶ�
#include <ansi.h>

inherit F_SSERVER;

void remove_effect(object me, int amount);

int perform(object me, object target)
{
        int skill;

        if(!target ) target = offensive_target(me);
//        if( objectp(me->query_temp("weapon")) )
//                return notify_fail("�������ֲ���ʹ�á��Ƶ�����\n");       
        if((int)me->query("neili") < 500  ) 
                return notify_fail("�������������\n");
        if((int)me->query_temp("tzzf") ) 
                return notify_fail("���Ѿ����Ƶ����˹��С�\n");
        if((int)me->query_skill("tiezhang-zhangfa", 1) < 120 )
                return notify_fail("��������Ʒ���������죬ʹ�������Ƶ�������\n");
        if((int)me->query_skill("force") < 140 )
                return notify_fail("����ڹ��ȼ�������ʹ�������Ƶ�������\n");
        if((int)me->query_str() < 30 )
                return notify_fail("�������������ǿ����ʹ�������Ƶ�������\n");
        if( (int)me->query_skill("guiyuan-tunafa", 1) < 120 )
                return notify_fail("��Ĺ�Ԫ�����ɷ��ȼ���������ʹ�������Ƶ���������\n");
        
        if (me->query_skill_prepared("strike") != "tiezhang-zhangfa"
        || me->query_skill_mapped("strike") != "tiezhang-zhangfa"
        )
                return notify_fail("�������޷�ʹ�á��Ƶ�����\n");

        skill = me->query_skill("tiezhang-zhangfa") / 2;
        skill = skill + me->query_skill("strike");
        skill = skill / 4;
        me->add("neili", -(me->query_skill("strike")+100));
        me->add("jingli", -100);
        message_vision(YEL "$NͻȻ��ɫ�԰ף�˫�ֲ������漴�������һ����һ˫������ɫ���ѩ�ף�����һ����ֵĹ�â��\n" NOR, me, target);
        me->set_temp("tzzf", 1);
                me->add_temp("apply/attack", skill);
        me->add_temp("apply/damage", skill);
        me->start_call_out( (: call_other, this_object(), "remove_effect", me, skill*3/2 :), skill/2);
        if( me->is_fighting() ) me->start_busy(1);
        return 1;

}

void remove_effect(object me, int amount)
{        
        int skill;
        skill = me->query_skill("tiezhang-zhangfa") / 2;
        skill = skill + me->query_skill("strike");
        skill = skill / 4;
                me->delete_temp("tzzf");
                me->add_temp("apply/attack", -skill);
        me->add_temp("apply/damage", -skill);
        message_vision(YEL "\n$N�Ƶ��˹���ϣ�˫���𽥻ָ���ԭ״��\n" NOR, me);        
}

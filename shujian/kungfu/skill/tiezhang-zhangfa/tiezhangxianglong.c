// tiezhangxianglong
// updated by keinxin for sj2

#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;
int perform(object me, object target)
{
	string msg;
	int extra;
	int i;
	object weapon;
	if( !target ) target = offensive_target(me);

	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("���ƽ���ֻ�ܶ�ս���еĶ���ʹ�á�\n");
	 
    if( (int)me->query("neili", 1) < 600 )
		return notify_fail("�������������㣬����ʹ�ã�\n");	
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("�����ƽ�����ֻ�ܿ���ʹ�á�\n");		

	if( (int)me->query_skill("tiezhang-zhangfa", 1) < 150 )
		return notify_fail("��������Ʒ�������죬���������ƽ�����\n");

	if( (int)me->query_skill("guiyuan-tunafa", 1) < 60 )
		return notify_fail("��Ĺ�Ԫ���ɷ�������죬����ʹ�����ƽ�����\n");

	extra = me->query_skill("tiezhang-zhangfa",1) / 20;
	extra += me->query_skill("guiyuan-tunafa",1) /20;
 i = extra/4;
    if( (int)me->query("neili", 1) <  (80 * i) )
		return notify_fail("�������������㣬����ʹ�ã�\n");	
        me->add_temp("apply/attack", extra*6);    
        me->add_temp("apply/damage", extra*2);
	msg = BBLU+HIC  "$N����۹�Ԫ���ɷ��ݣ�ͬʱʹ�������ƽ�����һ��һ����������糱ˮ��Ļ���$n��" NOR;
       COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        for(i=0;i<extra/4;i++)
	{
	
                switch(random(5))
                        {
                        case 0: { msg = BBLU+HIC "$N����ͻת��������ͬ��ˮ������Ʈ����˲Ȼ�Ƶ�$n���һ�������ĳ���\n" NOR;break;}
                        case 1: { msg = BBLU+HIC "$Nͻת���ε�ת����Ȼ˫���ĳ�����ɽ�������Ϯ��$n��\n" NOR;break;}
                        case 2: { msg = BBLU+HIC "$N˫��һ��һ��һ����$n���ؿڼ����������\n" NOR;break;}
                        case 3: { msg = BBLU+HIC "$Nʹ�����������֣���׼$n������һ��ץȥ��\n" NOR;break;}
                        case 4: { msg = BBLU+HIC "$N������һ������������ʦ�����ش��������������۵�˫��֮�С���\n" NOR;break;}
                        }	
	
	COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
	}
i = extra/4;
        me->add_temp("apply/attack", -extra*6);
        me->add_temp("apply/damage", -extra*2);
me->start_busy(3);
me->add("neili", - 80 * i);
me->start_perform(20,"���ƽ���");
	return 1;
}

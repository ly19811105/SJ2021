// xi.c
// add by keinxin@sj2
// 2003.5

#include <ansi.h>

inherit F_SSERVER;
int exert(object me, object target)
{
	int sp, dp;

	if ( target == me ) target = offensive_target(me);

	if( environment(me)->query("no_fight") )
		return notify_fail("�����ﲻ�ܹ������ˡ�\n");

	if( !objectp(target) || target->query("id") == "mu ren" )
		return notify_fail("��Ҫ��ȡ˭��������\n");

	if (target->query("race") != "����")
		return notify_fail("����ˣ�ֻ���˲�����������\n");

	if ( me->query_temp("sucked") )
		return notify_fail("��ո���ȡ��������\n");

	if( objectp(me->query_temp("weapon")) )
		return notify_fail("�������ֲ���ʩ�û���������������\n");

        if( !me->is_fighting() || !target->is_fighting())
                return notify_fail("�����ս��������������\n");

	if( (int)me->query_skill("huagong-dafa",1) < 30 )
		return notify_fail("��Ļ����󷨹���������������ȡ�Է���������\n");

	if( (int)me->query("neili",1) < 10 )
		return notify_fail("�����������������ʹ�û����󷨡�\n");

        if( (int)target->query("qi") < 30 )
		return notify_fail( target->name() +
			"�Ѿ�������ɢ�����Ѿ��޷�����������ȡ�����ˣ�\n");

        if( target->query_temp("no_kill") )
        return notify_fail("���ܴ򣬴򲻵ð���\n");

        if(target==me)
        return notify_fail("�� suicide ָ���ȽϿ�:P��\n");

        if(me->is_busy())
        return notify_fail("��������æ��\n");
	message_vision(
		HIR "$NͻȻ�����һЦ��˫��һ�Ĵָ��׼$n�����İ��˹�����\n\n" NOR,
		me, target );

	if ( living(target) )
	{

            target->fight_ob(me);

	}

        sp = me->query_skill("force") + me->query_skill("dodge") + me->query_skill("huagong-dafa",1);
        dp = target->query_skill("force") + target->query_skill("dodge");

	me->set_temp("sucked", 1);		

        if (( random(sp) > random(dp)/2 ) || !living(target) )
	{
		tell_object(target, HIR "��ͻȻ����ȫ����Ѫ�����Ʊ�ӿ��������֫��������Ҳʹ����������\n" NOR);
		tell_object(me, HIG "�����" + target->name() + "��"HIR"��Ѫ"HIG"������ԴԴ���������˽�����\n" NOR);

		target->receive_damage("qi", (int)me->query_skill("huagong-dafa", 1)*2 );
		target->receive_wound("qi", (int)me->query_skill("huagong-dafa", 1)/2 );
		me->add("qi", (int)me->query_skill("huagong-dafa", 1)*2 );
		me->add("eff_qi", (int)(me->query_skill("huagong-dafa", 1)/2) );
		if ( me->query("eff_qi") > me->query("max_qi") ) me->set("eff_qi", me->query("max_qi"));
		
		if ( me->query("qi") > me->query("max_qi")*2 ) me->set("qi", me->query("max_qi")*2);

		if( target->query("combat_exp") >= me->query("combat_exp") )
			me->add("qi", (int)me->query_skill("huagong-dafa", 1)*2 );

                target->start_busy(random(3));
		me->add("neili", -5);

		call_out("del_sucked", random(4), me);
	}
	else
	{	
		message_vision(HIY "����$p������$P����ͼ�������͵�һ�𣬽������˿�ȥ��\n" NOR, me, target);
                me->start_busy(2);
		call_out("del_sucked", random(4), me);
	}

	return 1;
}

void del_sucked(object me)
{
	if ( me->query_temp("sucked") )
	me->delete_temp("sucked");
}

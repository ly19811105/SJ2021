// shengang.c ���������������

#include <ansi.h>
#include <combat.h>
#include <weapon.h>
#include <skill.h>
inherit F_SSERVER;

void remove_effect(object me, int amount);

int exert(object me, object target)
{
	object weapon;	
  	string msg;
	int d_count, count, qi, maxqi, skill;
         weapon=me->query_temp("weapon"); 
        if((int)me->query_temp("powerup")||(int)me->query_temp("xlz/xiao"))
        return notify_fail(HIG"������ʹ�ñ���⹦������\n"NOR);
        if (!(int)me->query("pass_guo"))
        return notify_fail(HIG"�㻹û���ܵ�ĳ�˵�ָ�㣬������ʹ�����ֹ���\n"NOR);
	if( (int)me->query_temp("tiangang") ) 
		return notify_fail(HIG"���Ѿ����˻�Ԫ����ˡ�\n"NOR);
        if( (int)me->query("neili") < 200 )
		return notify_fail("���������������\n");

	if( (int)me->query_skill("huntian-qigong",1) < 150)
		return notify_fail("��Ļ�����������Ϊ����������ʹ�û�Ԫ���! \n");
	msg = WHT "$Nʹ������������ѧ����Ԫ�����һ�ɰ����Զ������跢ɢ���£�ȫ�������ڰ�ɫ�����У�\n" NOR;

	qi = me->query("qi");
	maxqi = me->query("max_qi");
	skill = (int) (me->query_skill("huntian-qigong",1) / 6);
	count = me->query_str();
	d_count = (int)me->query_dex() / 2;

	if(qi > (maxqi * 0.4))
	{	
		message_vision(msg, me, target);
		me->add_temp("apply/damage", skill*2);
            	me->add_temp("apply/attack", skill*2);
	        me->add_temp("apply/armor",skill*2);
                me->add_temp("apply/dodge",skill);
                me->set_temp("tiangang", 1);
     me->start_call_out( (: call_other, __FILE__, "remove_effect", me, skill*2 :), skill);

		me->add("neili", -150);
	}
	else{
		msg = HIR "$Nƴ�����������������Ԫ������Լ�����̫�أ�û�ܳɹ�!\n" NOR;
	}
//	if(userp(target)) target->fight_ob(me);
//	else if( !target->is_killing(me) ) target->kill_ob(me);
	return 1;
}

void remove_effect(object me, int amount)
{
        string msg;
  if ( (int)me->query_temp("tiangang") ) 
	{
               msg="��ɫ�ı�����ɢȥ��$N�����β����ֱ�������ɼ���\n";
		message_vision(msg,me);
                me->add_temp("apply/damage", - amount);
            	me->add_temp("apply/attack", -amount);
	        me->add_temp("apply/dodge", -amount/2);
	        me->add_temp("apply/armor",-amount);

                me->delete_temp("tiangang");
                tell_object(me, HIY "��Ļ�Ԫ���������ϣ��������ջص��\n" NOR);
		me->start_busy(random(4));
	}
}

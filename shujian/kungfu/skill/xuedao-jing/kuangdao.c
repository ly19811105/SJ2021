//kuang.c -Ѫ����ѪӰ�񵶡�
// Modified by Keinxin@SJ2
#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;
int perform(object me, object target)
{
    int extra;
	object weapon;
    string msg;
	extra=me->query_skill("xuedao-jing",1)/3;
    if( !target ) target = offensive_target(me);
    if( !target||!target->is_character()||!me->is_fighting(target) )
    return notify_fail("��ֻ�ܶ�ս���еĶ���ʹ�á�ѪӰ�񵶡���\n");
    if( (int)me->query_skill("xuedao-jing",1) < 220)
    return notify_fail("��Ŀǰ������ʹ������ѪӰ�񵶡���\n");
    
    	
    	if (!objectp(weapon = me->query_temp("weapon"))
		|| (string)weapon->query("skill_type") != "blade")
			return notify_fail("��ʹ�õ��������ԡ�\n");
	if( (int)me->query("neili") < 500 )
    return notify_fail("�������������\n");
    me->add("neili", -300);
    me->add_temp("apply/attack", extra);	
    me->add_temp("apply/damage", extra);
    
    	if(extra <= 80)
		msg = HIR"\n$N��Хһ�����Ա����Կ��ֱۣ���ʱһ���Ѫ�ɽ���"NOR+weapon->query("name")+HIR"֮�ϣ�"NOR+weapon->query("name")+HIR"��������һ��Ѫɫ��";
	else
	if(extra <= 120)
		msg = HIR"\n$N��Хһ�����Ա����Կ����ţ���ʱһǻ��Ѫ�ɽ���"+weapon->query("name")+HIR"֮�ϣ�"NOR+weapon->query("name")+HIR"����һ��Ѫɫ��";
	else
		msg = RED"\n$N��Хһ������ͷ�����Լ�һ������ʱһ����Ѫ�ɽ���"+weapon->query("name")+RED"֮�ϣ�"NOR+weapon->query("name")+RED"�������ͨ�죡����";
    
        message_vision(msg, me, target);                


        if(me->is_fighting(target)){	
	msg = BBLU+RED  "Ѫ��һ�֣�\n\n "HIC"$N���һ�㣬һ���������ֳŵأ�һ�С�ȥ��硹��$w"HIC"һ����������ң����ҵ�������ʮ����" NOR;
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        
        }
        if(me->is_fighting(target)){
        msg = BBLU+RED  "��ɽѪ������\n\n"HIW"$N�ֽ�һ�������ڿ��У�һ�С����Ǿ��졹������$w"HIW"���ֶ���������$n " NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        
        }
        if(me->is_fighting(target)){   
        msg = BBLU+RED  "Ѫ����𣡣���\n\n"HIB"$N��ɫ���죬���С��Ǻǡ��ͺ�һ�С����С���$w"HIB"�鶯�쳣����$n���߹�ȥ " NOR;     
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        
        }
        if(me->is_fighting(target) && me->query_skill("xuedao-jing",1) > 300){    
        msg = BBLU+RED  "Ѫ���ɺӣ�������\n\n"HIY"$Nһ�С������䡹������$w"HIY"΢΢һ�����������͡��������죬��$nͷ���ء�������������" NOR;    
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        
        }
        if(me->is_fighting(target) && me->query_skill("xuedao-jing",1) > 340){   
        msg = BBLU+RED  "��Ѫ��������������\n\n"WHT"$Nը�װ���һ����һʽ��ħ����$w"WHT"��$n§�����б���������������ͣ��Ʋ��ɵ���" NOR;     
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        }
    me->add_temp("apply/attack", -extra);	
    me->add_temp("apply/damage", -extra);
	me->start_perform(4,"ѪӰ��");


    return 1;
}


// jiushi.c ��ʽ��һ

#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>

inherit F_SSERVER;
string  *pfattack_msg = ({
                       HIW"������ʽ��"HIM"$NͻȻ�����н�ʽ��תΪʩ������$n��ʱ���Ƶ���æ���ң��Լ���$N��$W"HIM"ײ��������\n"NOR,
                       HIW"���潣ʽ��"HBCYN"$N��$W"HIW""HBCYN"�������֣����б�����ҵߵ���$nһʱû��Ū�����̸����š�\n"NOR,
                       HIW"���佣ʽ��"HIC"$N������𣬳�ͷ�½����ƣ��ӿ��й���$n��$n�������������$N��$W"HIC"���С�\n"NOR,
                       HIW"��ҡ��ʽ��"HBBLU"ֻ��$N��$W"HIW""HBBLU"��������һ�������ػ��š�$n��֪$W"HIW""HBBLU"Ҫ�����Լ���ʲôλ�ã�վ��ԭ�ط�������������С�\n"NOR,
                       HIW"������ʽ��"HIW"$N�Ľ���ͻȻ����������������Ʈ��������$nֻ����ǰһ�����ؿ��ѱ����С�\n"NOR,
                       HIW"���˽�ʽ��"HBGRN"����󺣿��Σ���������$nѹȥ��$nֻ��������$N�����γɵĿ�籩��֮�У���֪�����ѱ����С�\n"NOR,
                       HIW"���콣ʽ��"HIB"$n��$N����һ����ֻ��$N��$W"HIB"����һ����$n��С��������$N��һ����\n"NOR,
                       HIW"���뽣ʽ��"HBYEL"ֻ��$N����$W"HIW""HBYEL"���Ⱪ����������˦�����������Ƿ���$n��$n��ܲ�����$W"HIW""HBYEL"���С�\n"NOR,
                       HIW"������ʽ��"HIG"$N����$W"HIG"���һ�㣬ֻ������֮�ڽ����ݺ����಻��Ϯ��$n��$n��æ�ڿն����Ѿ�̫�������Ѿ����ض�����\n"NOR,
                       });

string *pfparry_msg = ({
                      NOR"$n������$N����ͼ�����Ų�æ��һȦһ���ƽ���$N�����С�\n"NOR,
                      NOR"$n�������$N�Ľ������մӽ��²�����\n\n"NOR,
                      NOR"$NͻȻ���󷽹�ȥһ��������$n������������Ʈ�������������С�\n"NOR,
                      });

int perform(object me, object target)
{
    int damage , zhao;
    string msg,wn;
    object weapon;
	

    if (!target ) target = offensive_target(me);
    
    if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("����ʽ��һ��ֻ����ս����ʹ�á�\n");    

    if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
        return notify_fail(RED"��ʲô��Ц��ûװ��������ʹ����ʽ��һ����\n"NOR);

    if (!target || !target->is_character() || !me->is_fighting(target) )
        return notify_fail("����ʽ��һ��ֻ�ܶ�ս���еĶ���ʹ�á�\n");

    if ((int)me->query_skill("dugu-jiujian", 1) < 300 )
        return notify_fail(WHT"����¾Ž�������죬ʹ��������ʽ��һ����\n"NOR);

    if ((int)me->query("max_neili")<4000)
        return notify_fail(RED"��������Ϊ���㣬�޷�����������\n"NOR);

     

    if ((int)me->query("neili")<1800)
    {
        return notify_fail(HIC"����������������û�ܽ�����ʽ��һ��ʹ�꣡\n"NOR);
    }
	
    me->start_perform(5,"��ʽ��һ");
    msg = HIW "$N����"+weapon->query("name")+HIW"��âԾ�������Ⱪ�����������ʹ�����¾Ž��ģ����ž���\n"NOR;
    msg += HIR"����ʽ��һ��"+HIW+"��������Ʈ�������²�����ֱ��$n��ȥ��\n"NOR;
	//���I����$�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�}�~�~��
	message_vision(msg, me, target);
	for (zhao=0;zhao<9;zhao++)
	{ 

		if (random(me->query("combat_exp")) > (int)target->query("combat_exp")/3)

		{
			me->start_busy(3);
			if( !target->is_busy() )
			{
				target->start_busy(random(2));
			}
			damage = (int)me->query_skill("dugu-jiujian", 1) + (int)me->query_skill("sword", 1);
			damage = 100 + damage*19/10 + random(damage/10)+ me->query("jiali");
			damage = damage*19/10 + random(damage/10);
			damage = damage*15/10;
			
			
			
			if( !target || environment(target) != environment(me) ) 
			{
				tell_object(me, "̫��ϧ�ˣ������ֵ�Ŀ���Ѿ����ˡ�\n");
				return 1;
			}
			
			
			target->receive_damage("qi", damage);
			
			target->receive_wound("qi", damage/8);

			//msg += pfattack_msg[random(sizeof(pfattack_msg))];
			//msg += pfattack_msg[zhao];
			msg = pfattack_msg[zhao];
			me->add("neili", -damage/5);
			msg = replace_string(msg, "$W", weapon->query("name"));
			message_vision(msg, me, target);
			if(userp(me) && me->query("env/damage"))
				tell_object(me,WHT"���"+ target->query("name") +"�����"RED+ damage+ WHT"�㹥���˺���\n"NOR);    
			if(userp(target)&& target->query("env/damage"))
				tell_object(target,WHT""+ me->query("name") +"�Ĺ������������"RED+ damage+ WHT"���˺���\n"NOR);
		} 
		else
		{
			me->start_busy(3);
	  
			//msg += pfparry_msg[random(sizeof(pfparry_msg))];
			msg = pfparry_msg[random(sizeof(pfparry_msg))];
			message_vision(msg, me, target);
	   }
		
		
	}
	//msg = replace_string(msg, "$W", weapon->query("name"));
    //message_vision(msg, me, target);

    if(!target->is_fighting(me)) target->fight_ob(me);
    return 1;
}

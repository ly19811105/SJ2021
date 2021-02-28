// shenjian.c �һ�Ӱ�����

#include <ansi.h>

inherit F_SSERVER;

#include "/kungfu/skill/eff_msg.h"
 
int perform(object me, object target)
{
        string msg;
        int damage, rand, p;

        if( !target ) target = offensive_target(me);

        if( !target || !target->is_character() || !me->is_fighting(target) )
                return notify_fail("�һ�Ӱ�����ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (!(me->query("thd/perform") & 2))
                return notify_fail("����Ȼ��˵�����һ�Ӱ����񽣡���һ�У�����ȴδ���ڡ�\n");
        if( objectp(me->query_temp("weapon")) )
               return notify_fail("��������ʹ���һ�Ӱ����񽣣�\n");
        if( (int)me->query_skill("luoying-zhang", 1) < 80 )
                return notify_fail("�����Ӣ���Ʋ�����죬�޷�ʹ���һ�Ӱ����񽣡�\n");
        if ((int)me->query_skill("bihai-chaosheng", 1) < 80)
                return notify_fail("��ı̺���������򲻹����޷�ʩչ�һ�Ӱ����񽣡�\n");
        if ( (int)me->query("neili") < 120)
                return notify_fail("��������������޷�ʹ���һ�Ӱ����񽣡�\n");
        if (me->query_skill_prepared("strike") != "luoying-zhang"
            || me->query_skill_mapped("strike") != "luoying-zhang")
                return notify_fail("�������޷�ʹ���һ�Ӱ����񽣽��й�����\n");

        msg = CYN "\n$N˫������Ĭ�˱̺�����������Ե���ƽ���һ������˿˿��"GRN"����"CYN"���ֱ����������ն��$n��\n"NOR;
        rand = random(me->query("combat_exp"));
        if( rand > (int)target->query("combat_exp")/2 ) {
                me->add("neili", -100);
                me->start_busy(1);
                damage = (int)me->query_skill("luoying-zhang", 1)*3/2;
                damage += random(damage);
                if (damage > target->query("neili") / 8)
                        damage -= target->query("neili") / 15;
                target->receive_damage("qi", damage);
                target->receive_wound("qi", damage/3);
                p = (int)target->query("qi") * 100 / (int)target->query("max_qi");
                msg += "( $n" + eff_status_msg(p) + " )\n";
                } 
        else {
                me->add("neili", -50);
                me->start_busy(1);
                msg += HIY"$n���һ�����˲�������־����п�����������У������ų���һ���亹��\n" NOR;
        }
        message_vision(msg, me, target);
        return 1;
}


// feixue.c �����ѩ 
// add by keinxin@sj2

#include <ansi.h>
#include <combat.h>
#include <weapon.h>

inherit F_SSERVER;

int perform(object me, object target)

{
        string msg;
        int damage, attp, defp;
        object obj;
        string w_name;
        object weapon;

        if( !target ) target = offensive_target(me);

        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
                return notify_fail("��ʲô��Ц��ûװ��������ʹ�������ѩ����\n");
        if( !target || !target->is_character() || !me->is_fighting(target) )
                return notify_fail("�������ѩ��ֻ�ܶ�ս���еĶ���ʹ�á�\n");
        if ((int)me->query_skill("liangyi-jian", 1) < 60)
                return notify_fail("������ǽ���������죬�޷�ʹ�����ǽ�����֮һ�ġ������ѩ����\n");
        if ((int)me->query_skill("xuantian-wuji", 1) < 70)
                return notify_fail("��������޼������̫ǳ���޷�ʹ���������ѩ����\n"); 
        if ((int)me->query("neili",1) < 500)
                return notify_fail("��������������޷�ʹ�����ǽ��С������ѩ���ľ�����\n"); 


         message_vision( BBLU+HIW "$N�����ڽ���׼��ʩչ�������ѩ��������\n"NOR, me, target );                

        me->start_perform(3+random(3),"�������ѩ��");                      
      
        //��������
        if( (int)me->query_skill("art", 1) > 180 ) {
              msg = HIC"$n��������ƫ�󣬼�������ת����ֻ��һɲ��$N�Ľ���ɲʱϮ�����ף�"NOR;
              COMBAT_D->do_attack(me,target, me->query_temp("weapon"),1,msg);
              msg = HIG"$n��������ƫ�ң���������ת����ֻ��һɲ��$N�Ľ���ɲʱϮ�����ף�"NOR;
              COMBAT_D->do_attack(me,target, me->query_temp("weapon"),1,msg);
        }
        
         message_vision( HIW "$N���һ����Ĭ��������ֻ�������һ�������Ϊ֮һ�ϣ����������㣬$N����\n"
         + "��������Ϊ������Ƭ���������ѩ����$n���������\n\n"NOR, me, target );
      
        attp = me->query_skill("xuantian-wuji",1) + me->query_skill("liangyi-jian",1);

        defp = target->query_skill("dodge");

        if( random( attp ) > random( defp )/2 || target->is_busy()){
        
                message_vision( RED "$n�����������Ѿ�����ɢ����Ƭ���У�ȫ��Ѫ��ģ����\n\n"NOR, me, target );
        
                damage = me->query_skill("liangyi-jian",1) + (int)me->query_skill("xuantian-wuji", 1)*2;
                damage = damage - random( target->query_skill("dodge")/3 );
                damage *= 2;
                if (damage>2500) damage = 2500;
                
                target->receive_wound("jing", random( damage/2 ));
                target->receive_damage("qi", 20 + random(damage));
                target->receive_wound("qi", 20 + damage);
                target->start_busy(3 + random(4));
                
                
                //׷�ӹ���
                if( random( attp ) > random( defp ) || target->is_busy()) {
 
          message_vision( BBLU+HIW "$N�������޼����ӵ�������"HIG"��������"BBLU+HIW"�����������������ʱ�����޽����н���\n\n"
         + NOR + RED"$n�ҽ�һ���������Ѿ������ν�����͸��\n"NOR, me, target );
 
                        damage *= 2;
                        target->receive_wound("jing", random( damage/2 ));
                        target->receive_damage("qi", 20 + random(damage));
                        target->receive_wound("qi", 20 + damage);
                        target->start_busy(2 + random(8));
                        }
            

        }

        else {

                message_vision( HIY "$p���Ų�æ�ػζ����Σ�˲ʱ�����˽��ꡣ\n" NOR, me, target );

        }

        me->add("neili", -300);
        
        weapon->move(environment(me));
        weapon->set("name", "�ϵ���"+weapon->query("name"));
        weapon->set("id", "cliped "+weapon->query("id"));
        weapon->unequip();
        weapon->set("value", 0);
        weapon->set("weapon_prop", 0);
        return 1;

}




// linglong.c �������

#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;

int perform(object me, object target)
{
        string msg;
    int ap,dp,damage,jl;
    object weapon;
    weapon = me->query_temp("weapon");
        if( !target ) target = offensive_target(me);

        if( !target || !target->is_character() || !me->is_fighting(target) )
                return notify_fail("[�������]ֻ����ս����ʹ�á�\n");

      if (!weapon || weapon->query("skill_type") != "stick"
       || me->query_skill_mapped("stick") != "dagou-bang")
      return notify_fail("�������ް����޷�ʹ�����������\n");
        if((int)me->query_int() < 25)
                return notify_fail("�����Բ���,����ʹ��[�������]��\n");

         if( (int)me->query_skill("huntian-qigong", 1) < 150 )
           return notify_fail("��Ļ���������Ϊ������ʹ���������������������\n");
        //if (me->query_skill_mapped("force") != "huntian-qigong")
        //   return notify_fail("û�л���������Ϊ���������޷�ʹ������������������ģ�\n"); 
       if((int)me->query_skill("dagou-bang",1) < 180)
       return notify_fail("��Ĵ򹷰�����Ϊ����,Ŀǰ������ʹ�á������������\n");
       if ((int)me->query_skill("bangjue",1)<150)
           return notify_fail("��������������Դ򹷰���Ϊ�����ģ�������������ʹ�ã�\n");
      if((int)me->query("max_neili") < 2000)
        return notify_fail("��������Ϊ���ڲ���, �����á������������\n");
       if ((int)me->query("neili")<800)
        return notify_fail("�������þ�, �����á������������\n");
//           if( target->is_busy() )
//                return notify_fail(target->name() + "Ŀǰ���Թ˲�Ͼ���ŵ������ɢ�\n");
        me->start_perform(5,"�����������");
        msg = HIY"$N����һЦ�������Ѽ���˫Ŀ�������䣬���������дʡ�\n";
        msg+="�������ӻ�����һ�ű�Ӱ���͵�$n���ġ�ǿ�䡱�����縮����\n";
        msg+="����׵��������̨���������ࡱ����ҪѨ��ֻҪ�����˵��У��������ˡ�\n"NOR;
      message_vision(msg, me, target);  
     ap=random(me->query("combat_exp"))+me->query_skill("bangjue",1)*(1+random(me->query("int")/2));
     dp= (int)target->query("combat_exp");
     if(ap>dp ) {
     damage=me->query_skill("dagou-bang",1)+me->query_skill("bangjue",1)*(1+random(me->query("int")/5));
     if (damage>3000)
         damage=3000;
     msg=CYN"$n�������ã����ڲ��������мܣ�ֻ����ǰ��Ծ���ܣ�\n
     ��֪$N�ĵ�����಻�ϣ�һ�㲻�У��ֵ�һѨ����Ӱ\n
     ֻ��$n�����Ѩ�ϻ�����ȥ��$nһ��������������!\n" NOR;
     target->receive_damage("qi",damage);
     target->receive_damage("jingli",damage/2);
     target->receive_wound("qi",damage);
    me->add("neili", -500);
    me->start_busy(2);
      message_vision(msg, me, target);
        } else if(ap>dp/2){
        msg = HIG "$N�����е���[������ǽ��δ� �����������β��],\n";
        msg+=  "��֮��$n���̽�����������\n" NOR;
           message_vision(msg,me,target); 
             for (jl=0;jl<3;jl++)
            COMBAT_D->do_attack(me, target, me->query_temp("weapon"), TYPE_SUPER);
             me->start_busy(2);
        }
        else if(ap>dp/4){
        msg = HIG "$N���������[�����ӵ�ʩ���� �����˫ȮĪ��ͷ��], ��֮��Ӱ���Ӷ��£�$n�����������м��¡�\n";
                message_vision(msg, me, target);
 target->start_busy(4);
          }
         else {
               msg="$n��ʶ��ؤ�����[�������]������,�ϵл���ԶԶ���˿�ȥ��\n";
          me->start_busy(random(5));
               message_vision(msg, me, target);
               }
          return 1;
}


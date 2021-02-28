// luiyun.c ����ˮ��
// add by keinxin@sj2
#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>

inherit F_SSERVER;

void remove_effect(object me, int aamount, int damount);

int perform(object me, object target)
{
        object weapon;  
        string msg;
        int d_count, count, qi, maxqi, skill, damage;
        
        if( !target ) target = offensive_target(me);

        if(!target||!target->is_character() || !me->is_fighting(target) )
        return notify_fail("����ˮ��ֻ�ܶ�ս���еĶ���ʹ�á�\n");        

        if( (int)me->query_temp("liuyun") ) 
                return notify_fail(HIG"���Ѿ���Ĭ������ˮ�����ˡ�\n");

        if( (int)me->query("neili") < 400 )
                return notify_fail("��������������ߣ�\n");

        if( (int)me->query_skill("xuantian-wuji", 1) < 60)
                return notify_fail("��������޼�������Ϊ����������ʹ������ˮ��! \n");

        if( (int)me->query_skill("strike", 1) < 80 )
                return notify_fail("��Ļ����Ʒ��������ң��޷�ʹ������ˮ�䣡\n");

        if( me->query_skill_mapped("strike") != "kunlun-zhang") 
                return notify_fail("��û�м��������ƣ��޷�ʹ������ˮ�䣡\n");
        
msg = HIR "$N���һ��ʹ���������еľ�ѧ������ˮ�䡹��������Ȼ���ӣ������ɨ���˵����ţ�\n" NOR;
        
        qi = me->query("qi");
        maxqi = me->query("max_qi");
        skill = (int) (me->query_skill("xuantian-wuji",1) / 3);
        count = (int) (me->query_skill("kunlun-zhang",1) / 3);
        
//��gift��һ��Ҫ��������gift��2-3�����ӡ�keinxin        
        d_count = me->query("dex")*2;
        damage = d_count*10+count+skill;
        damage *= 3;
        if (damage>3000)damage = 3000;

        if(qi > (maxqi/2))
        {       
        message_vision(msg, me, target);


                me->add_temp("apply/dexerity", d_count);
                me->add_temp("apply/damage", count);
                me->set_temp("liuyun", 1);
                me->start_busy(1);     
                me->start_call_out( (: call_other, __FILE__, "remove_effect", me, count*2, d_count :), skill/20);

                me->add("neili", -300);
        return 1;
        }
        else{
                msg = HIR "$Nƴ����������ʹ�����������е��ռ�����������ˮ�䡹�� ȫ�����һ����, �������ͬ���ھ�!\n" NOR;
                message_vision(msg, me, target);

                me->receive_damage("qi", damage/2);
                me->receive_wound("qi", damage/3);
                
                target->receive_damage("qi", damage);
                target->receive_wound("qi", damage/2);
                
                if(random(me->query("combat_exp"))>random(target->query("combat_exp")/2)){                 
                     target->start_busy(random(3));
                     target->receive_damage("qi", damage);
                     target->receive_wound("qi", damage/2);
                }
                
                me->set_temp("last_damage_from", "ʹ�á�����ˮ�䡹��"+target->name()+"ͬ���ھ�");
                target->set_temp("last_damage_from", "��"+me->name()+"ʹ�á�����ˮ�䡹ɱ");

                me->start_busy(1); 
                

                    
                me->add("neili", -300);

                return 1;


        }
}

void remove_effect(object me, int aamount, int damount)
{
        int d_count, count;
        count = (int) (me->query_skill("kunlun-zhang",1) / 3);
        d_count = (int) (me->query_skill("kunlun-zhang",1) / 5);
        
        if ( (int)me->query_temp("liuyun") ) 
        {

                me->add_temp("apply/dexerity", -d_count);
                me->add_temp("apply/damage", -count);
                me->delete_temp("liuyun");
                tell_object(me, HIY "��ġ�����ˮ�䡹��������ϣ��������ջص��\n" NOR);
                me->start_busy(2);
        }
}


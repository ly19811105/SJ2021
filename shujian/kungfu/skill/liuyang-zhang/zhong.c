// zhong.c ��������
//  edit by winter 2003.4
// edit by keinxin 2003.5 ���Ӷ�ת���Ƶķ���
#include <ansi.h>
inherit F_SSERVER;
int perform(object me, object target)
{
       object obj,tar;
       string msg;
       int assi_int;
       int me_strike;
       int target_dodge;
       int me_bmsg,tar_bmsg;
       if( !target ) target = offensive_target(me);
       if( !target || !me->is_fighting(target) )
                return notify_fail("����������ֻ����ս����ʹ�á�\n");       
       if(!target)
             return notify_fail("�����˭����������\n");
       if(!objectp(tar = present(target, environment(me))))
            return notify_fail("����û������Ը�������ˡ�\n");
       if(!tar->is_character())
                return notify_fail("�����һ�㣬�ǲ���������,�����и��ԡ�\n");
       if(!living(tar))
               return notify_fail(tar->name()+"�������ˣ���Ҫ�ݲ�����������̫����?\n");
       if(tar==me) return notify_fail("��Ҫ���Լ��£��㲻����Ű��ɣ�\n");
       if(me->is_busy())
             return notify_fail("����æ����˵ƴ�����¡�\n");
       if(environment(me)->query("no_fight"))
                return notify_fail("���������ʩչ������\n");
       me_bmsg=(int) me->query_skill("beiming-shengong",1);
       tar_bmsg=(int) tar->query_skill("beiming-shengong",1);
       if(me_bmsg<140)
             return notify_fail("��ı����񹦲�����죬��������������\n");
       if( (int)me->query_skill("liuyang-zhang", 1) < 140 )
             return notify_fail("�����ɽ�����Ʋ�����죬��������������\n");
       if( (int)me->query("neili", 1) < 500 )
             return notify_fail("����������̫������������������\n");
       if (!objectp(obj=present("jiudai", me)))
             return notify_fail("������û�оƴ������ܻ�ˮΪ����\n");
       msg = HIC "$N���������а����ڹ�����ת��ڤ�����������о�ˮ�����߰�Ƭ��������$n����������ơ�\n"NOR;
       me->start_busy(1);
       me_strike=random( (int) me->query_skill("liuyang-zhang",1) );
       target_dodge=random(target->query_skill("dodge") );
       assi_int=random(me->query("int")-target->query("int"))+ random(3);
       if( assi_int>1 && me->query_int()>50 )
            me_strike = me_strike*assi_int;
       if( me_strike > target_dodge && 
           me_bmsg >= tar_bmsg && 
           (int) random(me->query_skill("liuyang-zhang",1)) > (int) tar->query_skill("liuyang-zhang",1)/4            
       ){
             msg += HIW "$p���ü��"HIR"��ȱ��Ѩ��"HIW"��΢΢һ��������С��"HIR"������Ѩ��"HIW"������"HIR"������Ѩ��"HIW"���ϱ�"HIR"����ȪѨ��"HIW"Ҳ�����쬵ء�\n" NOR;
             target->set("ss_poison/level",1);
             if( (int) me->query_skill("liuyang-zhang",1)> 180 )
             {
                msg += HIY "���$pæ�������ֵ�����Ȼ���"HIB"������Ѩ��"HIY"������"HIB"�����Ѩ��"HIY"������"HIB"��־��Ѩ��"HIY"����Ҳ��΢΢һ����\n"NOR;
                target->set("ss_poison/level",2);
                target->receive_wound("qi",100 + random(30));
                target->receive_wound("jing", 60);
                target->apply_condition("ss_poison",  target->query_condition("ss_poison")+ 8);
             }
             target->receive_wound("qi",80 + random(10));
             target->receive_wound("jing", 50);
             target->apply_condition("ss_poison",  target->query_condition("ss_poison")+ 10);
             me->add("neili", -100);
             me->start_busy(2+random(2));
             target->set("ss_poison/count",0);
             target->set("ss_poison/bmsg",me_bmsg);
             target->set("ss_poison/id",me->query("id"));
       } else if( me_bmsg < tar_bmsg || 
                (int) me->query_skill("liuyang-zhang",1) < (int) tar->query_skill("liuyang-zhang",1) ||
                random((int) me->query_skill("liuyang-zhang",1)) < (int) tar->query_skill("douzhuan-xingyi",1)
              ){
                        //����
                    msg += HIB "����$p�����ϵ���Ǳ�˱�ڤ������ȫ����ͬ�����ַ�����$P��������!\n"NOR;
                    msg += HIY "$P���һ��������!������������ĺ������������Լ����ϡ�\n"NOR;
                    me->set("ss_poison/level",2);
                    me->receive_wound("qi",200 + random(30));
                    me->receive_wound("jing", 100);
                    me->apply_condition("ss_poison",  me->query_condition("ss_poison")+ 20);
                    me->add("neili", -100);
                    me->start_busy(3+random(2));
                    me->set("ss_poison/count",0);
                    me->set("ss_poison/bmsg",tar_bmsg);
                    me->set("ss_poison/id",tar->query("id"));
                  }else
              {
                 msg += "����$p��æ����һ�ԣ����˿�ȥ��\n" NOR;
                 me->start_busy(3);
              }
    message_vision(msg, me, target);
    target->start_busy(1 + random(2));
    return 1;
}
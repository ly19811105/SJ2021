//perform ku,���ݡ��ִ�
//cool@SJ 99529

#include <ansi.h>
void remove_effect(object me);

int exert(object me)
{    
      if( (int)me->query_skill("kurong-changong", 1) < 140 )
                return notify_fail("��Ŀ���������Ϊ�������޷�ʹ�á��ݡ��ִ󷨣�\n");

      if (me->query_skill_mapped("force") != "kurong-changong")
                return notify_fail("�����ڹ��С��ݡ��ִ���\n");

      if (me->query_skill_mapped("parry") != "kurong-changong")
                return notify_fail("������ÿ���������Ϊ�мܣ�����ʹ�á��ݡ��ִ󷨡�\n");

      if( (int)me->query_con() < 35 )
                return notify_fail("��ĸ���̫�ͣ������޷�ʹ�á��ݡ��ִ󷨣�\n");
 
      if( (int)me->query("neili") < 600 )
                return notify_fail("�������̫���ˣ��޷�ʹ�ó����ݡ��ִ󷨣�\n");   
    
      if( (int)me->query("max_neili") < 2000 )
                return notify_fail("���������Ϊ��ô�����ʹ�á��ݡ��ִ󷨣�\n");   
                                                                                
      if( me->query_temp("pf_ku")   )
                return notify_fail("���������á��ݡ��ִ󷨣�\n");
      if( me->query_temp("pf_rong")   )
                return notify_fail("���������á��١��ִ󷨣�\n"); 
      if ( !me->is_fighting()) {
                message_vision(GRN"\n$N�������,˫���ſ��⻮�������ջ��ڵ�����𡸿ݡ��ִ󷨣�������ɢȫ������ɢ��һ��������\n\n" NOR, me);
                me->start_busy(1);
                me->set_temp("pf_ku",1); 
                me->add_temp("apply/armor", me->query_skill("kurong-changong",1)); 
                me->add("neili", -400);    
        } 
        else {
                message_vision(GRN"\n$Nȫ���Ƴ�һ�ƣ�˳���˳����ɣ��������𡸿ݡ��ִ󷨣������鲼ȫ������������һ��������\n\n" NOR, me);
                me->start_busy(1);
                me->set_temp("pf_ku",1); 
                me->add_temp("apply/armor", me->query_skill("kurong-changong",1)); 
                me->add("neili", -600);           
        }
      call_out("remove_effect", me->query_skill("kurong-changong", 1)/2+20, me);
      return 1;
}

void remove_effect(object me)
{
      if(me){
      me->delete_temp("pf_ku");
      me->add_temp("apply/armor", -me->query_skill("kurong-changong",1)); 
      message_vision(WHT"\n$N�������������һ������ɢȥ������ȫ��������\n"NOR, me);    
      }
}

//perform ku,���١��ִ�
//14/02/99

#include <ansi.h>
void remove_effect(object me);

int exert(object me)
{    
      if( (int)me->query_skill("kurong-changong", 1) < 180 )
                return notify_fail("��Ŀ���������Ϊ�������޷�ʹ�á��١��ִ󷨣�\n");

      if (me->query_skill_mapped("force") != "kurong-changong")
                return notify_fail("�����ڹ��С��١��ִ���\n");

      if (me->query_skill_mapped("strike") != "kurong-changong")
                return notify_fail("������ÿ���������Ϊ�Ʒ�������ʹ�á��١��ִ󷨡�\n");
      
      if (me->query_skill_mapped("parry") != "kurong-changong")
                return notify_fail("������ÿ���������Ϊ�мܣ�����ʹ�á��١��ִ󷨡�\n");

      if( (int)me->query_str() < 35 )
                return notify_fail("��ı���̫�ͣ������޷�ʹ�á��١��ִ󷨣�\n");
 
      if( (int)me->query("neili") < 600 )
                return notify_fail("�������̫���ˣ��޷�ʹ�ó����١��ִ󷨣�\n");   
    
      if( (int)me->query("max_neili") < 3000 )
                return notify_fail("���������Ϊ��ô�����ʹ�á��١��ִ󷨣�\n");   
                                                                                
      if( me->query_temp("pf_rong")   )
                return notify_fail("���������á��١��ִ󷨣�\n"); 
      if( me->query_temp("pf_ku")   )
                return notify_fail("���������á��ݡ��ִ󷨣�\n");
      message_vision(HIR"\n$N����һ�����������١��ִ�,�����ɻ�����,��ʼ��ת������˫������ɢ���Ź�â��\n\n" NOR, me);
        me->start_busy(2);
        me->set_temp("pf_rong",1); 
        me->add_temp("apply/attack", me->query_skill("kurong-changong",1)/5); 
        me->add_temp("apply/damage", me->query_skill("kurong-changong",1)/10); 
        me->add("neili", -600);    
        call_out("remove_effect", me->query_skill("kurong-changong", 1)/2+20, me);
        return 1;
}

void remove_effect(object me)
{
      if(me){
        me->delete_temp("pf_rong");
        me->add_temp("apply/attack", -me->query_skill("kurong-changong",1)/5); 
        me->add_temp("apply/damage", -me->query_skill("kurong-changong",1)/10); 
        message_vision(WHT"\n$N�������������һ������ɢȥ��������˫�ֵ�������\n"NOR, me);    
      }
}

// qixingplus.c for murong-jianfa
// by keinxin@SJ2 2003.2
// �߽�ת����

#include <ansi.h>

inherit F_SSERVER;
int perform(object me,object target)
{
    object weapon;
    int i=me->query_skill("murong-jianfa",1);
    int d=me->query_skill("shenyuan-gong",1);
    
    if( !target ) target = offensive_target(me);
     
    if( !target || !me->is_fighting(target) || !living(target)
        || environment(target)!=environment(me))
                return notify_fail("�߽�ת����ֻ�ܶ�ս���еĶ���ʹ�á�\n");

    /*if((int)me->query("qixingquest")<1)
                return notify_fail("�㻹û������ת���ǵ�����Ҫ����\n");
	*/
    
    if( (int)me->query_skill("shenyuan-gong", 1) < 100 )
                return notify_fail("�����Ԫ����򲻵�������ʹ���߽�ת���ǣ�\n");
    if( (int)me->query_skill("murong-jianfa", 1) < 100 )
                return notify_fail("���Ľ�ݽ�����û�о���������ʹ���߽�ת���ǣ�\n");
    if (!objectp(weapon = me->query_temp("weapon")) || weapon->query("skill_type") != "sword"
        || me->query_skill_mapped("sword") != "murong-jianfa")
                return notify_fail("������û�н����޷�ʹ���߽�ת���ǣ�\n");
    
    if(me->query_temp("qixing_1") > 0)
                return notify_fail("���ʹ�ù��߽�ת���ǣ�\n");
                
    if((int)me->query("max_neili") < 1000 )
                return notify_fail("���������Ϊ����������ʹ���߽�ת���ǣ�\n");
    if((int)me->query("neili") < 500 )
                return notify_fail("�������������㣬����ʹ���߽�ת���ǣ�\n");
    if((int)me->query("jingli") < 300 )
                return notify_fail("�����ھ������㣬����ʹ���߽�ת���ǣ�\n");

    if((int)me->query_skill("sword", 1) < 100 )
                return notify_fail("��Ļ�������������죬�����ڽ�����ʹ���߽�ת���ǡ�\n");
                
    message_vision(HIB"\n$N��Ȼ������ת��ֻ���߶�"+HIG+"����"+HIB+"�����������ֱ�Ϯ��$n���ߴ�ҪѨ��\n"NOR,me,target);
    me->receive_damage("neili", 50);
    me->receive_damage("jingli", 50);
    me->add_temp("apply/attack", i/2);
    me->add_temp("apply/damage", i/3);    
    me->add_temp("apply/dodge", d/2);
    me->add_temp("qixing1",1);
    me->add_temp("qixing_1",1);

    COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 3);
me->delete_temp("qixing1");
me->add_temp("qixing2",1);


    COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 3);
 
me->delete_temp("qixing2");
me->add_temp("qixing3",1);   


    COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 3);

me->delete_temp("qixing3");
me->add_temp("qixing4",1);    


    COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 2);
  
me->delete_temp("qixing4");
me->add_temp("qixing5",1);    

  
    COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 2);
 
me->delete_temp("qixing5");
me->add_temp("qixing6",1);
  
 
    COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 2);
  
me->delete_temp("qixing6");
me->add_temp("qixing7",1);              


    COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 3);
    me->add_temp("apply/attack", -i/2);
    me->add_temp("apply/damage", -i/3);        
    me->add_temp("apply/dodge", -d/2);  

me->delete_temp("qixing7");         
    message_vision(WHT"\n$N�������ǣ��ս�ͦ�����У�һ�����߷緶��Ȼ�������·��������$n�Ĵ��ڡ�\n"NOR,me,target); 
    call_out("check_xu", 30, me);
me->start_busy(3);    
    return 1;
}


int check_xu(object me)
{    
       me->delete_temp("qixing_1");     //�ж϶���
}     

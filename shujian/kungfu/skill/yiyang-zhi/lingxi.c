//yiyang-zhi's perform lingxi
//��Ϭһָ
//keinxin@sj2

#include <ansi.h>
inherit F_SSERVER;
int qianlong_hit(object me, object target, object weapon, int damage);
 
int perform(object me, object target)
{       
        string msg;
        
        if( !target ) target = offensive_target(me);
 
        if( !target 
         || !target->is_character()
         || !present(target,environment(me)) )
                return notify_fail("����Ϭһָ����\n");
        if( !living(target) )
        	return notify_fail("�Է��Ѿ��ι�ȥ�ˡ�\n");
 

 		if( !me->is_fighting(target) )
 			return notify_fail("��ֻ�ܶ�ս���еĶ��ֳ�����Ϭһָ����\n"); 
 	       
        if( me->query_temp("weapon") )
                return notify_fail("ֻ�п��ֲ���ʩչ����Ϭһָ����\n"); 

        if( (int)me->query_skill("yiyang-zhi", 1) < 200 ||
            (int)me->query_skill("finger", 1) < 200 )
                return notify_fail("���еĹ��򻹲�����죬����ʹ�á���Ϭһָ����\n");

        if(!me->query_skill("kurong-changong", 1))
           	if(me->query_skill("qiantian-yiyang", 1) < 200)
                	return notify_fail("�������ڵ��ڹ���Ϊ��ʹ��������Ϭһָ����\n");        
         
        

        if (me->query_skill_prepared("finger") != "yiyang-zhi" || 
            me->query_skill_mapped("finger") != "yiyang-zhi" )
                return notify_fail("�������޷�ʹ������Ϭһָ�����й�����\n");      

        if( ((int)me->query("eff_qi")* 100 / (int)me->query("max_qi")) > 50 )
		return notify_fail("��û�е�������ͷ�޷�ʹ������Ϭһָ�����й�����\n");      
	                                                                                         
      
        if( (int)me->query("max_neili") < 4000 )
                return notify_fail("���������Ϊ̫��������ʹ�á���Ϭһָ����\n");

        if( (int)me->query("neili") < (int)me->query("max_neili")/2 )
                return notify_fail("�������������\n");
        
        if( (int)me->query("jingli") <= (int)me->query("max_jingli")/2 )
                return notify_fail("��ľ���������\n");

        if ((string)me->query("class")=="bonze")
         	msg = WHT "\n$N��Ȼ�ͻ���һ����"+target->name()+",����������ǧ����ħ������������˿�ش�����"NOR;    
	else 	msg = WHT "\n$N��Ȼ���һ����"+target->name()+",��������������������˫�������ˡ����졣"NOR; 
        tell_object(target, WHT"��ֻ��ü��ӡ�ü���һ��������Ҫ���Լ���˫ü˺��һ�㡣\n"NOR);

        
        message_vision(msg, me, target);
        
        
        me->set("neili",0);

 	me->start_call_out( (: call_other, __FILE__, "main", me, target :), 3);

       	return 1;
}


int main(object me, object target)
{ 
        int i;
        mapping action;
	        
        if( !me ) return 0;
         
        if( me->is_ghost() || !living(me) ){    
        	me->delete_temp("yyz_ql");
                return 1;
        }
        if( !me->is_fighting() ) return 0;

	if( !target || !living(target) || environment(target) != environment(me) || !me->is_fighting(target) ){
		write("��ŷ��������Ѿ�û���ˡ�\n");
		return 1;
	}
	
        if( me->query_temp("weapon") ){
		write("��÷����������ܳ�����Ϭһָ������\n");
		return 1;
	}
        
        if( ((int)me->query("eff_qi")* 100 / (int)me->query("max_qi")) > 50 ){
		write("����Ϭһָ����ƴ���������������ؼ�ʱ���ðɡ�\n");
		return 1;
	}




        message_vision(RED "$N���˼��أ���æ�����ֵ���ͻȻ֮�䣬$Nü��Ѩһ����ȣ�����������ֱ�����������������Ӷ�������������Ѹ������һ��������ڴ�������Ϊһ���ڳ�������Ϊ����$N����һ�м���������;����Ϊָ��֨����һ����ָ���ƿն�����\n\n"NOR, me,target); 
 
         if (random(me->query("combat_exp"))> target->query("combat_exp")/3 ){                  
                message_vision(RED "\n$n����$N��Ȼʹ��һ��һ��ָ��������ף�ָ�籾����Ϊ��΢��һ�����Լ��Ļ������������Ϊ�񾢣���������һ�������ƶ��룬$nһ��֮�£�\n"
                +"ָ����ֱ��ü�ģ�$nӦ�����٣����Ƶ�������֮�������������£������Ʊ����ڶ�ǰ����ž����һ����ָ�������������ڡ�$n�������˾�ȫ����\n"
                +"����ָ�磬�����ּ���֧�ţ�����һ��ָ�磬�������أ��������ƿ�֮��һ�α�һ�θ��ң���Ȼ��һС�����ھ�͸��ü��ҪѨ��\n"NOR, me, target);        
                target->apply_condition("no_exert", target->query_condition("no_exert") + 1);
                target->apply_condition("no_perform", target->query_condition("no_perform") + 1);
                target->unconcious();
         message_vision(RED "$N��һָ���ľ������е�Ԫ����ֻ�����Լ�ƣ��֮���������˾���һ��ͻȻ���˵���ľһ�㡣��\n\n"NOR, me,target);          
                me->unconcious();
          return 1;           
         }
                message_vision(HIC"����$n������$N����ʽ,�û�����������\n" NOR,me,target);
                me->start_busy(4);
               
         return 1;     

}

// yinyang.c
// code by hunthu
#include <ansi.h>

int exert(object me, object target)
{
     int exp,exp1; 
     string gen,gen1;
     mapping fam;
	fam=me->query("family");
        gen=me->query("gender");
         gen1=target->query("gender");
 
        if( !target )
	return notify_fail("��Ҫ����˭��\n");
        if (!living(target))
        return notify_fail("��������ǲ��ǻ��š�\n");
	if(target == me)
	return notify_fail("���в������Լ������Լ�����\n");
        if (me->is_busy())
        return notify_fail("����æ���ء�\n");
      	if( me->is_fighting() || target->is_fighting())
	return notify_fail("ս�����޷�ʹ�ô˷���\n");
      if ((int)me->query_skill("longxiang-boruo",1)<100)
        return notify_fail("��������������Ϊ��ǳ���޷�֧�ִ˷���\n");
        if (me->query_skill("huanxi-chan",1)<90)
        return notify_fail("��Ļ�ϲ����Ϊ̫���ˡ�\n");
          

        if( (int)me->query("max_neili") < 1000 )
	return notify_fail("���������Ϊ��ǳ�����ķ�Ϊ�����㡣\n");
        if ((int)me->query("neili")<500)
         return notify_fail("�㵱ǰ���������Ѿ��þ��ˣ��޷���ʩչ�˷���\n");   
	if ( fam["family_name"] != "������")
         return notify_fail("�㲻�Ǵ����µĵ��ӣ�����ܲλ�ϲ����\n");
        if (gen== "����")
        return notify_fail("�㲻�в�Ů��Ϲ����ʲô?\n");
         if (gen1== "����")
         return notify_fail("������㣬���Ǹ�̫�ࡣ\n");
          if (gen==gen1)
          return notify_fail("����ͬ����������̬��\n");
            exp= (int)me->query("comat_exp");
          exp1=(int)target->query("combat_exp");
     if (me->query("combat_exp",1)>target->query("combat_exp",1))
          return notify_fail("��������ļһ�˫�޵Ļ���С�Ĺ�������\n");
         switch (gen){
                case "����":
                 tell_object(me,HIY"��������������д��뻶ϲ���⣬��"+target->name()+"���������󷨡���\n"NOR);
                 message_vision(HIY"$N�溬΢Ц��������૵������䣬˫�۰�����գ�ӨȻ���⣬ֱ��$n˫�ۡ�\n"NOR,me,target);
                    switch (random(3)){
                              case 0:
                              message_vision(HIY"$N�����ߵ�$n�Աߡ�\n"NOR,me,target);
                              break;
                              case 1:
                             message_vision(HIY"$N�õͳ������������$n����˵��������λ"+RANK_D->query_respect(target)+"����̫�����ˣ������˯�˰ɣ���˯�˰ɡ���\n"NOR,me,target);
                              break;
                              case 2:
                              message_vision(CYN"$N�õͳ���͵�������$n����˵��������λ"+RANK_D->query_respect(target)+"��ü��Ŀ�����ҷ�����Ե��������"+RANK_D->query_self(me)+"����㻯������Σ�\n"NOR,me,target);
                               break;
                                }
                            switch (random(4)){
                              case 0:
                             message_vision(HIY"$n��������$N���Ϸ��䣬ֻ������������ת������һ�Σ���Щˤ����\n"NOR,me,target);
                              break;
                             case 1:
                           message_vision(HIY"$n�����㱣��������룬�����ǵ�ͨ�죬������������������\n"NOR,me,target);
                             break;
                             case 2:
                          message_vision(HIY"$n��$N����һ�ԣ�����ȫ��һ��һ�������Ը����ڵ�����ɲʱȫ�������ޱȡ�\n"NOR,me,target);
                            break;
                             case 3:
                            message_vision(HIY"$nȫ������������Ƥ���أ��ƺ��������ܿ����Լ�����־�ˡ�\n"NOR,me,target);
                             break;
                             }
               break;
default:
              tell_object(me,HIY"��������������д��뻶ϲ���⣬��"+target->name()+"���������󷨡���\n"NOR);
             message_vision(HIY"$N������˿���鴽���������еͳ����䣬��������$n��һ�Թ���˫ͫɨ��$n��\n"NOR,me,target);
             switch (random(3)){
                case 0:
                message_vision(HIY"$N�������ƣ��յ�$n��ǰ��\n"NOR,me,target);
                break;
                 case 1:
               message_vision(HIY"$N�õͳ������������$n����˵��������λ"+RANK_D->query_respect(target)+"����̫�����ˣ������˯�˰ɣ���˯�˰ɡ���\n"NOR,me,target);
                break;
                 case 2:
               message_vision(HIY"$N�õͳ���͵�������$n����˵��������λ"+RANK_D->query_respect(target)+"��ü��Ŀ�����ҷ�����Ե��������"+RANK_D->query_self(me)+"����㻯������Σ�\n"NOR,me,target);
                 break;     
                   }
            switch (random(3)){
                 	case 0:
                       message_vision(HIY"$n�����������Ѭ��������$Nǧ�����ģ�ֻ��Ѫ�����ţ����������ظ�Ц�˼�����\n"NOR,me,target);
                      break; 
                      case 1:
                      message_vision(HIY"$n����������٣��޿����ƣ�����������Եع�â�����С��Ǻǡ����������������޵�������\n"NOR,me,target);
                      break; 
                      case 2:
                       message_vision(HIY"$nĪ�������ֻ���ޱ��˷ܣ����ɵ������㵸���Ǻǵ�ɵЦ�˼�����\n"NOR,me,target);
                       break;
                         }
                  }
exp=(int)me->query_skill("huanxi-chan",1)/5;
  if (random(me->query("combat_exp",1))>target->query("combat_exp",1)/5*2)
                          {
                            message_vision(HIG"$n���ϴ��ⰻȻ������������еͺ�������$N���С�\n"NOR,me,target);
                            me->start_busy(5);
                            me->add("qi",me->query_skill("huanxi_chan",1)*2);
                            me->add("jingli",me->query_skill("huanxi_chan",1)*2);
       me->add("combat_exp",me->query_skill("huanxi-chan",1)/5);
                            me->add("neili",-200); 
                            target->add("max_neili",-20);
                            target->add("eff_jingli",-20);
                           if (me->query("potential") > me->query("max_pot")){
                            me->set("potential", me->query("max_pot"));   
                            return 1;
                            }
                           me->add("potential", random(me->query_skill("huanxi-chan",1))/5+1);
                            return 1;
                         } 
                        if (gen1=="Ů��")
                        message_vision(HIR"$n��Ȼ�Ѿ���ֻ��ȫ��͸�����亹������ͨ�죬���ɵ���ü����������$Nŭ߳����ɮ��������\n"NOR,me,target);
                        else 
                        message_vision(HIR"$nһ����У���Ȼ������ͷ���������Ժ��������ɵ�ŭ������������������캦����\n"NOR,me,target);
//                       target->kill_ob(me);
                        me->start_busy(7); 
                        return 1;   
        
                        }

// ����ʮ����
// by snowman@SJ
// Modify by Lklv for npc can't add gift
// Modify by Lane@SJ 2005.08.03 
// Update by lsxk@hsbbs 2007/7/3

#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;

#define KANGLONG "/kungfu/skill/xianglong-zhang/kanglong"

string perform_name(){ return WHT"����ʮ����"NOR; }

int perform(object me, object target)
{
	int i, j, ap, dp, a, jiali;

	string ac, *msg = ({  "���Ʋ���", "����һ��", "�ⲿһ̧", "����׹��", "š���粽", "ȭ����ת", });
	object *allenemy;
	
	i = me->query_skill("xianglong-zhang", 1);

	if( !target ) target = offensive_target(me);

	if( !objectp(target)
	 || !me->is_fighting(target)
	 || !living(target)
	 || environment(target) != environment(me) )
		return notify_fail("������ʮ���ơ�ֻ����ս���жԶ���ʹ�á�\n");

	if( objectp(me->query_temp("weapon")) )
		return notify_fail("�������ֲ���ʹ�á�����ʮ���ơ���\n");

	if( (int)me->query_skill("xianglong-zhang", 1) < 50)
		return notify_fail("��Ľ���ʮ���ƻ�������죬ʹ����������ʮ���ơ�������\n");

	if( (int)me->query_skill("huntian-qigong", 1) < 50 )
		return notify_fail("��Ļ��������ȼ���������ʹ����������ʮ���ơ�������\n");

	//if( me->query_skill_mapped("force") != "huntian-qigong" )
	//	return notify_fail("����ʹ���ڹ����ԣ�ʹ����������ʮ���ơ�������\n");

	if( (int)me->query_skill("force") < 50 )
		return notify_fail("����ڹ��ȼ�����������ʹ�á�����ʮ���ơ���\n");

	if( (int)me->query_str(1) < 6 )
		return notify_fail("�������������ǿ����ʹ����������ʮ���ơ�����\n");

	if( me->query_skill_prepared("strike") != "xianglong-zhang"
	 || me->query_skill_mapped("strike") != "xianglong-zhang")
	 //|| me->query_skill_mapped("parry") != "xianglong-zhang")
		return notify_fail("�������޷�ʹ�á�����ʮ���ơ���\n");

	if( (int)me->query("max_neili") < -1 )
		return notify_fail("����������̫����ʹ����������ʮ���ơ���\n");

	if( (int)me->query("neili") < -1 )
		return notify_fail("����������̫����ʹ����������ʮ���ơ���\n");

	if( (int)me->query("jingli") < 80 )
		return notify_fail("��ľ�������������ʹ��������ʮ���ơ���\n");

       // if( (int)me->query_temp("xlz/xiao") && userp(me) && i<551 )
		//return notify_fail("������ʹ�á�����Х����\n");

	//if( me->query_temp("xlz/py") )
	//	return notify_fail("������ʹ�á�����ʮ���ơ���\n");

  // allenemy = me->query_enemy();
    //count = sizeof(allenemy);

   // message_vision(HBMAG+HIW "\n$N" HIR "����������������Х�������¡¡һ�����죬��������̽�ף��ڰ�������������������\n"
	//	+ "Х��δ�ϣ�ֻ��$N" HIR "�Ƴ�" + ((count>1)?"��":"һ") + "�ƣ��������м��ŵĿ�磬��Ⱥ�����ڡ��Ʋ��ɵ�֮�ƹ���" 
	//	+ ((count>1)?"����":allenemy[0]->query("name")) + HIR "��\n"NOR, me);
	
	message_vision(HBMAG+HIW "\n$N��һ����˫�ۻ��ƣ�˫����������Ź������Ǻ��߹�֮�����ؼ�������ʮ���ơ���\n"
              HBMAG"�����Ʒ��е�"+ HIW +"����ʮ����"+ NOR + WHT +HBMAG+"���˿�$N������ʢ�������˵ã�\n"NOR, me); 
//foreach (ob in all_inventory(environment(me))) {
	//ob->kill_ob(me);


	 me->set_temp("xlz/new",18);
	 me->set_temp("xlz/auto",1);
	 me->set_temp("xlz_auto",1);
	 me->set_temp("hit_ob_hit",1);
	 me->add_temp("apply/damage", 500);
	 me->add_temp("apply/strike", 500);
	 me->add_temp("apply/strength", 50);
	 target->set_temp("must_be_hit",1);
   
	for(a=0;a<18;a++)
{
	         target = offensive_target(me);
			 COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 3);
 		   
}


	me->delete_temp("xlz/auto");
	me->add_temp("apply/damage", -500);
	//me->add_temp("apply/attack", j);
	me->add_temp("apply/strike", -500);
	me->add_temp("apply/strength", -50);
	//me->add_temp("neili", 100000);
	me->reincarnate();
	return 1;
}
void remove_effect2(object me, int i)
{
	if (me)   me->add_temp("apply/dodge",- i /3);
                          
}





int help(object me)
{
	write(WHT"\n�����ơ�����ʮ���ơ���"NOR"\n");
	write(@HELP
	����ʮ����Ϊ��������������֮�һʽʮ���У����п�����
	Ҫ��	������� 200 ���ϣ�
		��ǰ���� 150 ���ϣ�
		��ǰ���� 80 ���ϣ�
		�����Ƶȼ� 50 ���ϣ�
		���������ȼ� 50 ���ϣ�
		�ڹ���Ч�ȼ� 30 ���ϣ�
		���� 6 ���ϣ�
		
HELP
	);
	return 1;
}

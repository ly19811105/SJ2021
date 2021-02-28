#include <ansi.h>
//inherit FORCE;
//by nono buff��Ҫ����
// 1����������״̬�µ�auto������������Ч��1���С��������Ʒ�2hit��Ч��2��������ڹ���Ч��3��busy���Ṧ��������̫������ǿ��ǿ��Ч��������ԭ����ʯ��������ɹ������λ�����д��������
// 2������̫������auto����Ч����grin
// 3��buff ����pfm xuan
// 4������pfm �ں� �������ơ��ڹ����Ṧ�����ĺ�һ��
// ��������ʱ��ô���
inherit SKILL;

string *dodge_msg = ({
    "$n�����ĳ������絽������$N��һ�ߡ�\n",
    "$n�ֱۻ�ת��ץס$N����һ�ƣ���$NԶԶ������\n",
    "$n������ţ���Ծ��������������ʮ�����⡣\n",
    "$Nֻ����ǰһ����ֻ����$n����һ�ϣ��Լ���������ȻĪ�����������ˡ�\n",
});

string *parry_msg = ({
    "$nĬ��̫���ھ�����$N�Ĺ��ƾ������⡣\n",
    "$nһ����Ц����$N�Ĺ����������⡣\n",
    "$Nֻ��$n�����Ӳ���������ͭǽ������һ�㡣\n",
});

mapping *actionw = ({
([      "action" : "$Nһ��[ �Կ��Ϻ�ӧ���⹳˪ѩ�� ]ֱ����$n��",
        "force" : 510,
        "attack": 180,
        "dodge" : 85,
        "parry" : 175,
        "damage": 325,
        "damage_type": "����"
]),
([      "action":"$Nһ��[ �Կ��Ϻ�ӧ���⹳˪ѩ�� ]ֱ����$n��",
        "force" : 510,
        "attack": 108,
        "dodge" : 72,
        "parry" : 115,
        "damage": 310,
        "damage_type": "����"
]),
([      "action":"$Nһ��[ �Կ��Ϻ�ӧ���⹳˪ѩ�� ]ֱ����$n��",
        "force" : 532,
        "attack": 125,
        "dodge" : 60,
        "parry" : 102,
        "damage": 365,
        "damage_type": "����"
]),
([      "action":"$N��һ��[ �����հ����������� ]��$nײȥ��",
        "force" : 565,
        "attack": 110,
        "dodge" : 75,
        "parry" : 105,
        "damage": 390,
        "damage_type": "����"
]),
([      "action":"$N�߽У�[ ʮ��ɱһ�ˣ�ǧ�ﲻ���� ]����$n��",
        "force" : 550,
        "attack": 108,
        "dodge" : 70,
        "parry" : 120,
        "damage": 420,
        "damage_type": "����"
]),
});

mapping *action = ({
([      "action":"$N��ʽһ�䣬[ ���˷���ȥ����������� ]$nֻ�÷����ֵ���",
        "force" : 540,
        "attack": 50,
        "dodge" : 50,
        "parry" : 120,
        "damage": 355,
        "damage_type":  "����"
]),
([      "action":"$N�����Ц[ �й����������ѽ�ϥǰ�� ]��ȭ��$n��ȥ��",   
        "force" : 560,
        "attack": 60,
        "dodge" : 60,
        "parry" : 90,
        "damage": 330,
        "damage_type":  "����"
]),
([      "action":"$N��ʹ��һ��[ ������캥������Ȱ���� ]ֱ����$n��",
        "force" : 570,
        "attack": 75,
        "dodge" : 75,
        "parry" : 135,
        "damage": 360,
        "damage_type":  "����"
]),
([      "action":"$N��ȭΪ�ƣ�����һ��[ ������Ȼŵ��������Ϊ�� ]��",
        "force" : 580,
        "attack": 80,
        "dodge" : 80,
        "parry" : 75,
        "damage": 395,
        "damage_type":  "����"
]),
([      "action":"$Nȭ���ٱ䣬[ �ۻ����Ⱥ����������� ]$n�ò��Ǳ���",
        "force" : 580,
        "attack": 95,
        "dodge" : 90,
        "parry" : 125,
        "damage": 360,
        "damage_type":  "����"
]),
([      "action":"$N��̾һ����[ ˭������£�����̫���� ]$n�������ˡ�",
        "force" : 580,
        "attack": 100,
        "dodge" : 100,
        "parry" : 145,
        "damage": 480,
        "damage_type":  "����"
]),
});
int valid_enable(string usage)
{
return usage == "cuff" || usage == "dodge" ||usage == "parry" || usage == "force" || usage == "strike"; || usage == "sword"; //����ԭ����swordҲ��enable
}



string query_dodge_msg(string limb)
{
    return dodge_msg[random(sizeof(dodge_msg))];
}


int valid_learn(object me)
{


if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
return notify_fail("��̫����������֡�\n");
if ((int)me->query("max_neili") < 100)
return notify_fail("�������̫�����޷�������\n");
return 1;
}

string exert_function_file(string func)
{
        return __DIR__"taixuan-gong/" + func;
}
string perform_action_file(string action)
{
        return __DIR__"taixuan-gong/" + action;
}

string query_parry_msg(object weapon, object me)
{
        if (me->query_skill_mapped("parry") == "taixuan-gong")
                return parry_msg[random(sizeof(parry_msg))];
}
        

mapping query_action(object me, object weapon)
{
        int i, j, level;
                string msg;
	int enhance_level;
	string skill_file;
	skill_file=replace_string(file_name(this_object()),"/kungfu/skill/","");
	enhance_level=(int)me->query("�书�ؼ�/"+skill_file);
	if (enhance_level > 20) enhance_level = 20;	
level = me->query_skill("taixuan-gong",1);
        for(i = sizeof(action); i > 0; i--) {
                if(level > action[i-1]["lvl"]) {
                        j = NewRandom(i, 20, level/5);
                        if ( me->query_temp("txg/xuan")){
                                return ([
                                        "action":HIW+replace_string(replace_string(replace_string(action[j]["actionw"], "$w", "$W"), "$W", "$w"MAG), NOR, MAG)+NOR,
                                        "damage": 160+random(120)+enhance_level*10,
                                        "damage_type": "����",
                                        "dodge": random(35),
                                        "parry": random(35),
                                        "force": 200+random(300),
                                ]);
                        }
                        if(me->query_temp("txg/xuan")){
                switch(me->query_temp("taixuan")){                                              
 case 5: msg = HIW"\n$N��ʽһ�䡸"HIR"�����հ����������� "NOR+HIC"��$nֻ�÷����ֵ�"NOR;break;
 case 4: msg = HIG"\n$Nһ�С�"HIR"�Կ��Ϻ�ӧ���⹳˪ѩ��"NOR+HIC"��ֱ����$n"NOR;break;
 case 3: msg = HIC"\n$N��ȭΪ�ƣ�����һ�С�"HIR"������Ȼŵ��������Ϊ�� "NOR+HIC"��"NOR;break;
 case 2: msg = HIM"\n$Nȭ���ٱ䣬��"HIR" �ۻ����Ⱥ����������� "NOR+HIC"��$n�ò��Ǳ�"NOR; break;
 case 1: msg = HIC"\n$N�߽У���"HIR" ʮ��ɱһ�ˣ�ǧ�ﲻ���� "NOR+HIC"������$n"NOR; break;
default: msg = HIY"\n$N��̾һ����"HIR"˭������£�����̫���� "NOR+HIC"��$n��������"NOR;break;
                }
                me->add_temp("taixuan", -1);
                return ([
                        "action":msg,
                                        "damage": 180+random(80)+enhance_level*10,
                                        "damage_type": "����",
                                        "dodge": random(35),
                                        "parry": random(60),
                                        "force": 200+random(300),
                                ]);
                        }
                        return ([
                                "action" : action[j]["action"],
                                "force" : 200 + random(350),
                                "dodge" : random(25)-5,
                                "parry": 50+random(60),
                                "damage" : 180 + random(80)+enhance_level*10,
                                "damage_type" : action[j]["damage_type"],
                                "lvl": action[j]["lvl"],
                        ]);
                }
        }
if (random(me->query_skill("taixuan-gong",1)) > 300 && me->query("neili") > 100)
        {
                me->add("neili", -50);
                return ([
        "action": HIR "$N������ͻȻһƬãȻ��ֻ���þ�������������������ڴ�����ȥ���ѹ��ǳ���
���²������룬˳����������һ��ȭ����ߣ����ܶ�ʱ������쩣��ò����֣�"NOR,
        "damage": 1000+enhance_level*10,
        "dodge" : 100,
        "force" : 400,
        "damage_type": "����"]);
        }
        return action[random(sizeof(action))];


        
}
int practice_skill(object me)
{
       if ((int)me->query("jingli") < 30)
               return notify_fail("�������̫���ˡ�\n");
       if ((int)me->query("neili") < 20)
               return notify_fail("�������������̫������\n");
       me->receive_damage("jingli", 30);
       me->add("neili", -10);
       return 1;
}



int ob_hit(object ob, object me, int damage)
{
 int con, str, dex, j
 con = me->query("con");
 str = me->query("str");
 dex = me->query("dex");
 j = (int)me->query_skill("taixuan-gong", 1);
if(!environment(me)) return 0;
if(!me->query("quest/taixuan/pass")) return 0; //��ֹbug
if( con < 49 && str < 49 && dex < 49 && j < 551) return 0;
					 
//�������ֵĶ��������ɣ���Ҷ�ܲ��ܽ����أ�

if(random(2) == 1 && me->is_busy()){ //busy ״̬����1/1�Ļ�������grin
	   msg = HIW"$N�ж���һ���ޣ�ʯ���ϵ��书����������ʹ����һ����ͨ���ٲ��ܵ��κ����ƣ�\n"NOR;
       me->start_busy(-1);
     	}


if( me->query_condition("no_exert") && random(3) == 1){
               msg = HIY"$N�����Լ��޷�������������æ����ʯ���ϵ��ڹ��ķ����Լ�������Ѩ�������ָ���\n"NOR;
               me->remove_condition("no_exert");
           } 
//if( me->query_condition("no_perform") && random(4) == 1){ //������д����ģ�д��������ֱ�ӵ���pfm ����
//			   msg = HIR"$N˫�ƾ�Ȼ����������ֱ��$n���ţ��õľ���̫�����Ĺ���\n"NOR;
//			   me->start_perform(3,"������̫����");
//               me->add("neili", -800);
//               me->add("jingli",-500);
//               me->set_temp("txg_tx",5);
//               me->add_temp("apply/attack", i);
//               target->set_temp("must_be_hit",1);
//               COMBAT_D->do_attack(me, target, me->query_temp("weapon"),3);
//               COMBAT_D->do_attack(me, target, me->query_temp("weapon"),3);
//               COMBAT_D->do_attack(me, target, me->query_temp("weapon"),3);
//               COMBAT_D->do_attack(me, target, me->query_temp("weapon"),3);
 //              COMBAT_D->do_attack(me, target, me->query_temp("weapon"),3);
//               me->add_temp("apply/damage", -i);
//               me->add_temp("apply/attack", -i);
//               me->delete_temp("txg_tx");
//                      return 1;
//                   }
}





		   


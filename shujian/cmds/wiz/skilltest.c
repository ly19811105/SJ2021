//maked by wzfeng 98 10 26
#include <combat.h>
#include <weapon.h>
#include <skill.h>
#include <ansi.h>
inherit F_CLEAN_UP;
int main(object me, string arg)
{
   object ob, second, first;
   int ap,dp;
   string attack_skill, martial_skill, first_skill;
   mapping action;
   if(!arg)
           return 0;
   
   ob = present(arg, environment(me));
   if(!ob)
           return 0;
   action = me->query("actions");
   if( !mapp(action))
   {
          tell_object(me,HIR"ʹ�ö�������\n"NOR);
           return 0;
   }
   
   attack_skill=me->query("skill_type");
   ap =  COMBAT_D->skill_power(me, attack_skill, SKILL_USAGE_ATTACK);
   

           if( me->query_temp("weapon"))
           {
           tell_object(me,HIC"ʹ������    :"+me->query_temp("weapon")->query("name")+"\t"NOR);
           tell_object(me,HIR"��������    :"+me->query_temp("weapon")->query("skill_type")+"\n"NOR);
           }
           if(!action["skill_name"])
           tell_object(me,HIY"��ʽ����    :û��\n"NOR);
           else
           tell_object(me,HIY"��ʽ����    :"+action["skill_name"]+"\n"NOR);
           tell_object(me,HIC"��ʽ����    :"+action["lvl"]+"\n"NOR);
           tell_object(me,HIW HBGRN"��ʽ�м�    :"NOR+action["parry"]+"\n");
           tell_object(me,HIW HBBLU"��ʽ�Ṧ    :"NOR+action["dodge"]+"\n");
           tell_object(me,HIW HBCYN"��ʽ����    :"NOR+action["force"]+"\n");
           tell_object(me,HIW HBMAG"��ʽ�˺�    :"NOR+action["damage"]+"\n");
           tell_object(me,HIW HBRED"�˺�����    :"NOR+action["damage_type"]+"\n");
           tell_object(me,HIW HBRED"��ʽ����    :"NOR+action["action"]+"\n");
           tell_object(me,HIW HBRED"������    :"NOR+ap+"\n");
           
   return 1;
}
int help(object me)
{
write(@HELP
ָ���ʽ : skilltest <ĳ��>
���������书���ܵ�ǿ����
HELP
    );
return 1;
}


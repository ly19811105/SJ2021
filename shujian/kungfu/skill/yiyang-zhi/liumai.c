inherit F_SSERVER;

#include <ansi.h>
#include "/kungfu/skill/yiyang-zhi/liumai_msg.h";
#include "/kungfu/skill/eff_msg.h";
int perform(object me, object target)
{       
                
        if( !target ) target = offensive_target(me);  
        
        if(!me->query_skill("liumai-shenjian", 1)) return 0;  
  
        if( !target ) target = offensive_target(me);
        if( !target || !target->is_character()
           || !me->is_fighting(target) || !living(target) )
                return notify_fail("�������񽣡�ֻ����ս����ʹ�á�\n");
                
        if( objectp( me->query_temp("weapon")) )
                return notify_fail("ֻ�п��ֲ���ʩչ�������񽣡���\n");

        if (me->query_skill_prepared("finger") != "yiyang-zhi" || 
            me->query_skill_mapped("finger") != "yiyang-zhi" )
                return notify_fail("�������񽣡���һ��ָΪ����,�㲻����һ��ָ,��ô����ʩչ�������񽣡���\n");    
        
        if (me->query_skill_prepared("strike") == "kurong-changong")
                return notify_fail("�������񽣡������仯��΢,���޷��Ϳ�������ͬʱʹ�á�\n");
                      
        
        if((int)me->query_skill("yiyang-zhi", 1) < 160 || (int)me->query_skill("finger", 1) < 160)
                return notify_fail("���ָ���������򻹲�����죬�������á������񽣡���\n");

        if(me->query_skill("force")<250)
                 return notify_fail("�������ڵ��ڹ���Ϊ��ʹ�����������񽣡�����\n");        
                                
        if(me->query_skill("liumai-shenjian", 1) < 30)
                return notify_fail("��ġ������񽣡���Ϊ̫�͡�\n");        
      
        if( (int)me->query("max_neili") < 3000 )
                return notify_fail("���������Ϊ̫��������ʹ�����������񽣡�����\n");
        if( (int)me->query("neili") < 1000 )
                return notify_fail("�������������\n");
                
        if(me->query_temp("start_6mai")) return notify_fail("���Ѿ������������񽣵����ν����ˣ�\n");

       
        tell_object(me, HIW"\n�����д��Ȼ�������ָ���ھ�������������ʼ���������񽣣�\n"NOR); 
        me->set_temp("start_6mai", 1);
        remove_call_out("check_6mai");        
        remove_call_out("checking");
        call_out("check_6mai", 1, me, target);
        call_out("checking", me->query_skill("liumai-shenjian", 1), me);
        return 1;
}
int checking(object me)
{
        if(me->query_temp("start_6mai")){
              me->delete_temp("start_6mai");
              tell_object(me, HIW"\n���ھ�����һ���죬�������񽣵���������һ�飡\n"NOR);
              remove_call_out("checking_6mai");
              remove_call_out("checking");
        } 
        return 1;
}
int check_6mai(object me, object target)
{
        string msg, *limbs, dodge_skill,limb;
        int lv, neili, ap, dp, damage, p, j;
        mapping act, *action;
        object wep; 
        lv = (int)me->query_skill("liumai-shenjian", 1);

       
 action = ({
([      "action" : liumai_msg[1+random(4)],
        "t_msg" : target_msg[1+random(2)],
        "damage" : 4,
        "lvl" : 0,
        "skill_name" : "����",
        "damage_type" : "����"
]),
([      "action" : liumai_msg[6+random(4)],
        "t_msg" : target_msg[2+random(2)],
        "damage" : 5,
        "lvl" : 30,
        "skill_name" : "�س彣",
        "damage_type" : "����"
]),
([      "action" : liumai_msg[11+random(4)],
        "t_msg" : target_msg[4+random(2)],
        "damage" : 6,
        "lvl" : 60,
        "skill_name" : "������", 
        "damage_type" : "����"
]),
([      "action" : liumai_msg[16+random(4)],
        "t_msg" : target_msg[6+random(2)],
        "damage" : 7,
        "lvl" : 90,
        "skill_name" : "�г彣",
        "damage_type" : "����"
]),
([      "action" : liumai_msg[21+random(4)],
        "t_msg" : target_msg[8+random(2)],
        "damage" : 4,
        "lvl" : 120,
        "skill_name" : "�ٳ彣",
        "damage_type" : "����"
]),
([      "action" : liumai_msg[26+random(4)],
        "t_msg" : target_msg[10+random(2)],
        "damage" : 7,
        "lvl" : 150,
        "skill_name" : "���̽�",
        "damage_type" : "����"
]), 
([      "action" : liumai_msg[random(sizeof(liumai_msg))],
        "t_msg" : target_msg[random(sizeof(target_msg))],
        "damage" : 7+random(4),
        "lvl" : 180,
        "skill_name" : "������",
        "damage_type" : "����"
]),
});

        if (lv >= 180) j = 6;
        else if (lv >= 150) j = 5;
        else if (lv >= 120) j = 4;
        else if (lv >= 90) j = 3;
        else if (lv >= 60) j = 2;
        else if (lv >= 30) j = 1;
        else j = 0;
        act = action[random(j)];
        damage = act["damage"];
        msg = act["action"];
        neili = (int)me->query("neili");        

         if(!objectp(target)||!target||environment(me)!=environment(target)||target->is_ghost()||!living(target) ){
                me->delete_temp("start_6mai"); 
                remove_call_out("checking");
                remove_call_out("checking_6mai");
                return 1;
        } 
        if(!living(me)||me->is_ghost()||!me->is_fighting()){
                me->delete_temp("start_6mai");
                remove_call_out("checking");
                remove_call_out("checking_6mai");
                return 1;
                }
        if(!me->query_skill("liumai-shenjian", 1)||!me->query_temp("start_6mai")){
                me->delete_temp("start_6mai");
                remove_call_out("checking");
                remove_call_out("checking_6mai");
                return 1;
                } 
        if( objectp( me->query_temp("weapon")))
                {
                me->delete_temp("start_6mai");
                remove_call_out("checking");
                remove_call_out("checking_6mai");
                return 1;
                }  
        
        if (me->query_skill_prepared("finger")!="yiyang-zhi"|| 
            me->query_skill_mapped("finger")!="yiyang-zhi"){
                tell_object(me,"��任���书���޷���ʹ�á������񽣡����й����ˡ�\n"); 
                me->delete_temp("start_6mai");
                remove_call_out("checking");
                remove_call_out("checking_6mai");
                return 1;
        } 
        if (me->query_skill_prepared("strike") == "kurong-changong") {
                tell_object(me,"��任���书���޷���ʹ�á������񽣡����й����ˡ�\n"); 
                me->delete_temp("start_6mai");
                remove_call_out("checking");
                remove_call_out("checking_6mai");
                return 1;
                }    
        if(neili < 500){
                tell_object(me,"�㷢���Լ����ڵ�����̫�����Ѿ�����ʹ���������������ˡ�\n");           
                me->delete_temp("start_6mai");
                remove_call_out("checking");
                remove_call_out("checking_6mai");
                return 1;
                }                    
        if(me->is_busy()){
                call_out("check_6mai", 1+random(8-j), me, target);
                return 1;
                }

        ap = me->query_skill("force")+me->query_skill("finger")+me->query_skill("dodge")+me->query_int();
        dp = target->query_skill("force")+target->query_skill("parry")+target->query_skill("dodge")+target->query_con();
        ap *= me->query("combat_exp")/1000;
        dp *= target->query("combat_exp")/1000;
        
        limbs = target->query("limbs");
        limb = limbs[random(sizeof(limbs))];
        msg = replace_string(msg,"$l",limb);
        message_vision(msg, me, target);
        tell_object(target, HIR+act["t_msg"]+NOR); 
        wep = target->query_temp("weapon");

        if(random(ap+dp)> (dp/(random(2)+1))){
             me->add("neili", -damage*25);
             damage *= (lv/2+me->query_skill("finger"))/3;
             damage += me->query("jiali")*(random(j)+1)/3;
             damage -= target->query_temp("apply/armor");
             damage -= target->query_temp("apply/parry")/2; 
             if (damage<0) damage=10;
             damage *=j;
             if(neili > target->query("neili")*2) damage += damage/2; 
             if(damage < me->query_skill("finger"))
                damage =me->query_skill("finger");   
             if(damage > 1500) damage = 1500 + random(damage-1500)/ 50;

//the target has a weapon in hand
             if(objectp(wep) && random(3) == 1){     
                   if(me->query("neili") < target->query("neili")){
                        me->start_busy(1);
                        msg = HIY"���ֻ���ѵ�һ����$n������$W"HIY"��Ȼ��������$w��\n" NOR;                        
                        }
                   else if(me->query("neili") >= target->query("neili")*2){
                         if(wep->query("rigidity") >= 3){
                               me->start_busy(1);
                               wep->move(environment(target));
                               target->receive_damage("qi", 150);  
                               target->receive_wound("qi", 50);      
                               msg = HIW"���ֻ��ž��һ����$n����ס$W"HIW"��������ɣ�����Ҳ������ײ�������ѣ�\n" NOR;
                               target->reset_action();
                               }
                         else{ 
                                me->start_busy(1);
                                msg = HIW"���ֻ���ĵ�һ���죬$n����$W"HIW"Ϊ$N��$w���ϣ���Ϊ����Ķ���ʮ�أ����ϰ�գ��������׹⣡\n" NOR;
                                msg = replace_string(msg, "$W", wep->name());
                                wep->unequip();
                                wep->move(environment(target));
                                wep->set("name", wep->query("name")+"��Ƭ");
                                wep->set("value", 0);
                                wep->set("unit", "Щ");
                                wep->delete("long");
                                wep->set("weapon_prop", 0);
                                target->reset_action();
                                }
                        }       
                   else {       
                         if(wep->query("rigidity") >= 8){
                                me->start_busy(1);
                                msg = HIY"���ֻ��һ�����죬$W"HIY"��$w�ĳ���²�ס�������ɻ��Ľ���\n" NOR;
                                }
                         else{
                                me->start_busy(1);
                                wep->move(environment(target));  
                                msg = HIW"$n��æ��$W"HIW"һ��������һ������"+wep->query("unit")+"$W"HIW"�ֱ���ɣ�\n" NOR;
                                target->reset_action(); 
                                }
                         }
                   msg = replace_string(msg, "$W", wep->name());
                   msg = replace_string(msg, "$w", "���ν���");          
                   message_vision(msg, me, target);
                   if(!me->is_fighting() || !target || environment(me) != environment(target)||target->is_ghost() || !living(target) ){
                        me->delete_temp("start_6mai");
                        remove_call_out("checking");
                        remove_call_out("checking_6mai");
                        return 1;
                } else call_out("check_6mai", 1+random(8-j), me, target);
                   }
             else{
                   target->receive_damage("qi", damage);
                   target->receive_wound("qi", damage/(2+random(2)));          
                   p = (int)target->query("qi")*100/(int)target->query("eff_qi");
                   msg = damage_msg(damage, act["damage_type"]);
                   msg += "( $n"+eff_status_msg(p)+" )\n";
                   msg = replace_string(msg, "$l", limb);
                   msg = replace_string(msg, "$w", "���ν���");          
                   message_vision(msg, me, target);
                   if(wizardp(me)) tell_object(me, "6mai_damage: "+damage+" \n");
                if(!me->is_fighting() || !target || environment(me) != environment(target)||target->is_ghost() || !living(target) ){ 
                        me->delete_temp("start_6mai");
                        remove_call_out("checking");
                        remove_call_out("checking_6mai");
                        return 1;
                } else call_out("check_6mai", 1+random(8-j), me, target);                   
                   }
            }
        else{
             me->start_busy(1);
//           HIY"$Nȫ�����һ��һ����������ֵرܿ����Ǽ��ٶ��������ν�����\n"NOR, target);
             dodge_skill = target->query_skill_mapped("dodge");
             if( !dodge_skill ) dodge_skill = "dodge";
             message_vision(SKILL_D(dodge_skill)->query_dodge_msg(target, 1), me, target);
             if(!me->is_fighting() || !target || environment(me) != environment(target)||target->is_ghost() || !living(target) ){
                   me->delete_temp("start_6mai");
                   remove_call_out("checking");
                   remove_call_out("checking_6mai");
                   return 1;
                  } else call_out("check_6mai", 1, me, target);    
             }                               
       if(target->query("qi")*2 <= target->query("max_qi")
           && !target->is_killing(me->query("id"))
           && !me->is_killing(target->query("id"))){ 
             me->remove_enemy(target);
             target->remove_enemy(me);
             if (me->query("race") == "����") {
                                if (!me->query("mute") && target->query("mute"))
                                        message_vision( winner_msg[random(sizeof(winner_msg)/2)], me, target);
                                        if (me->query("mute") && !target->query("mute"))
                                                message_vision(winner_msg[sizeof(winner_msg)/2 + random(sizeof(winner_msg)/2)], me, target);
                                        if (!me->query("mute") && !target->query("mute"))
                                                message_vision( winner_msg[random(sizeof(winner_msg))], me, target);
                        } else message_vision( winner_animal_msg[random(sizeof(winner_animal_msg))], me, target);
             }

       return 1;
} 
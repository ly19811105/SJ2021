// yushizhe.c
// player modify 2018.11.1

inherit NPC;

#include "/d/zhiye/npc/forbook.c"
#define JADE    "/d/zhiye/obj/othermaterial" //��
//#define JADE    "/d/zhiye/obj/buliao" 
void getyu(object me)//
{
       	object obj;
		//object me;
		int level = 1;
                
        if(!me) return;
        
        if(environment(me)!=environment(this_object())) return;
        
       // if(!random(2)) level+=1;
       // if(!random(3)) level+=1;
       // if(!random(4)) level+=1;
       // if(!random(5)) level+=1;
       // level = 2+random(4) ;
		level = 6 ;
        obj = new(JADE);
		obj->set_level(level);
        
        if(obj)
        {
                message_vision("$N���䵽���ó�һ��"+obj->name()+"��\n",this_object());
                message_vision("$N��$nһ��"+obj->name()+NOR"��\n",this_object(),this_player());
                command("say �����Ҳûʲô�õĶ����������������ȥ���꣬�ϰ�ʱ�仹������MUD���Ƚ������������ˣ��������ж���ᡣ");
                message_vision(HIY"$N������ȥ�������������ֻ�е�ʱ���棬���߲���ץ��������......��\n"NOR,this_object() );
                
               obj->move(this_player());
              // this_player()->start_busy(-1);
               //this_player()->interrupt_me();                
             //  this_object()->interrupt_me();
              // this_object()->start_busy(-1);
              // this_object()->interrupt_me();
			          }

}

void create()
{
        set_name("�˼���ʹ", ({ "renjian tianshi","renjian", "tianshi", "tian","shi" }) );
        set("gender", "����" );
        set("age", 34);
		set("per", 40);
        set("long",
                "����Ϊ�ϰ�ʱ����MUD�������·�,ר�Ÿ������������ʹ��
������ͨ�ò�������ͨ�ˡ�
ֻ��ż��������ɣ��˫Ŀ����¶�����������µ�������\n");
        set("combat_exp", 300);
        set("attitude", "peaceful");
        set("rank_info/respect", "����ʹ");
        set("inquiry", ([
                "story" : "���²�Ҫ���ᣬ�����Ѷ���ꡣ\n",
                "����": (: getyu :), 
        ]) );
        set("forg_type","all");
        setup();
        carry_object("/clone/misc/cloth")->wear();
}



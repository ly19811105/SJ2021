// gongzi.c
// Lklv modify 2001.9.27

inherit NPC;

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

void getyu()
{

	int i,j;
       object me = this_player();
       object obj;
       i = random(4)?4:5 ; 
        obj = new("/d/zhiye/obj/othermaterial");
        if(obj && obj->set_level(i+1,1))
        {
                obj->move(this_player());
                message_vision(HIW"$N�ӱ����еõ���һ"+obj->query("unit")+obj->name()+"��\n\n"NOR,me); 
        }
                destruct(this_object());
                return 1;
}
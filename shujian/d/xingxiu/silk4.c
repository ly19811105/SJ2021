// /d/xingxiu/silk4.c

inherit ROOM;

void create()
{
        set("short", "˿��֮·");
        set("long", @LONG
�������������˿���̵���ӭ���������һ����ɳ���������岼춻�ԭ֮
�ϡ�һ���ɳ�������󵶸�һ��˺�������������������Ħ�£����������߱�
��
LONG);
        set("outdoors", "yili");

        set("exits", ([
                //"eastup" : __DIR__"silk3",
                "west" : __DIR__"silk5",
                "northwest" : __DIR__"silk5a",
        ]));

        set("objects", ([
                __DIR__"npc/shangren" : 1,
        ]));

        set("coor/x",-260);
  set("coor/y",90);
   set("coor/z",0);

   setup();
}
void init()
{
	object memory;
	string start_room;
	object me=this_player();
	
	memory = me->query_temp("mirror/mirror_memory");
	if (!me->query_temp("smy_job"))
	{
		set("exits/westup", __DIR__"silk3");
	}
	if (memory && me->query_temp("fuben/smy")=="start" && memory->query("user_id/1")==me->query("id"))
	{
		//start_room = me->query_temp("mirror/start_room");
		start_room = me->query_temp("mirror/start_room")+"";
		//��һ��������һ����ɽ��ɽ���վ�������³������˵����Ħ�£��㲻����ԥ����Ȼ�������ݶ��ϣ�
		//tell_object(me,HIG"��һ��������һ����ɽ��ɽ���վ�������³������˵����Ħ�£��㲻����ԥ����Ȼ�������ݶ��ϣ�\n"NOR);
		set("exits/eastup",start_room);
	
	}
	else
		if (me->query_temp("fuben/smy")!="start" || !memory || memory->query("user_id/1") != me->query("id"))
		set("exits/eastup", __DIR__"silk3");
	
}
#include "/d/xingxiu/job2.h";
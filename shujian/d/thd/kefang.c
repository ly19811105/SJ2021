// /u/jpei/thd/kefang.c

inherit ROOM;
#include <ansi.h>
void create()
{
        set("short","�ͷ�");
        set("long",@LONG
�����д�����ס�޵ķ��䡣���ڳ��辫�ţ�������ԣ������Žࡣ
LONG
);
        set("exits",([
                "west" : __DIR__"jicui",
        ]) );
        set("no_clean_up", 0);
        set("sleep_room", 1);
        setup();
}


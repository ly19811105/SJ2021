// /d/xingxiu/silk3.c
//tangfeng@SJ 2004

#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", HIM"��Ħ��"NOR);
        set("long", @LONG
��Ħ����������������Χɽ�ƶ��ͣ���ɽ���ţ�һ����������Ͽ����̶��
Ԩ��Ī�⡣�״��л�����̶�ɳ�����������̶��̶���Ħ�³ɱ��������漣��
�ʴ��پ������������������˿��쾮���Ĺ��̡��������ǳ��ɽ����������
ʯ�š�
LONG);
        set("outdoors", "yili");
        

        set("exits", ([
                "eastdown" : "/d/xingxiu/silk2",
                "westdown" : "/d/xingxiu/silk4",
                "north" : "/d/xingxiu/silk3a",
        ]));


   setup();
}
void init()
{

	tell_object(this_player(),HIG"��һ��������һ����ɽ��ɽ���վ�������³������˵����Ħ�£��㲻����ԥ����Ȼ�������ݶ��ϣ�\n"NOR);
}
//�Ǿ���
int is_mirror() { return 1; }
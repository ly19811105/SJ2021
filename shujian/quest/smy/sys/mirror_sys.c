//edit by rock
//2008.10.16
//���ļ����ᱻ��¡

#include <ansi.h>
#include <localtime.h>
//#include "/quest/smy/sys/list.h"

#define MAX_ROOM_INDEX 200
#define MIRROR_MEMORY  "/quest/smy/sys/memory"
#define MAX_KILLER_INDEX 200
//ȫ�ֱ���
int make_room_index;
int ob_time;
//��������
string* mirror_maps=({
		"/quest/smy/smyfuben",
});
int mirror(object leader);
void mirror_ok(object me);
//��������ѯ��������������
int query_room_amount() { return make_room_index; }
int delete_room_amount() { return make_room_index--; }
//NPC���ã����쾵������ ���˸������Բ�Ҫobject* player����
int mirror(object leader)
{
	object maps,memory,start_room;
	int i,size,j,index;
	mixed time;
	string fileName;

	if(!leader || make_room_index >= MAX_ROOM_INDEX ) return 0;

	//�����ڴ�
	if(!memory = new(MIRROR_MEMORY)) 
	{
		tell_object(leader,HIR"�����ڴ�memory����ʧ�ܣ�\n"NOR);
		return 0;
	}
	//tell_object(leader,HIR"�����ڴ�memory����ɹ���\n"NOR);
	memory->set("leader",leader);
	//�ж�����Ƿ����Ҫ��

		if(!leader || !userp(leader) || !living(leader) )
		{
			destruct(memory);
			tell_object(leader,HIR"�����ڴ�memory����ʧ�ܣ����ݻ��������\n"NOR);
			return 0;//continue;
		}

		memory->set("user_id/1",leader->query("id"));
		memory->set("user/1",leader);
		//tell_object(leader,memory->query("user_id/1")+"\n");
		//tell_object(leader,memory->query("user/1")+"\n");
		leader->set_temp("mirror/mirror_memory",memory);
		tell_object(leader,HIY"��ս��Ħ�¡�����Ϊ�����쾵�����Ժ�......\n"NOR);
		//leader->disable_player("<���뾵����>");
		//leader->set_temp("block_msg/all",1);
	
	
	//��������
	size = sizeof(mirror_maps);
	
	for(j=0;j<size;j++)
	{
		maps = new(mirror_maps[j]);
		if(maps)
		{
			//���е�ͼ��memory
			memory->set(sprintf("maps/%d",j),maps);
			sscanf(mirror_maps[j],"/quest/smy/%s",fileName);
			memory->set(fileName,maps);
			maps->set("memory",memory);
			if(maps->query("short") == HIM"��Ħ��"NOR)
			{
				start_room = maps;
				
			}
			//tell_object(leader,maps->query("short")+"\n");
			index ++;
		}
		//tell_object(find_player("rock"),sprintf("new_mirror: %d\n",j));
	}
	/*if (objectp(start_room))
	{
		tell_object(leader,HIW"start_room is :"+start_room->query("short")+"\n"NOR);
	}*/
	if(index < 1 || !start_room)
	{
		leader->enable_player();
		leader->delete_temp("block_msg");
		tell_object(leader,HIW"Error: ��������ʧ�ܣ�����ϵ��ʦ��\n"NOR);
			
		memory->delete_map();
		destruct(memory);
		time = localtime(time());
		log_file("mirror",sprintf("%d��%d�� %d:%d  ����ռ䴴��ʧ�ܡ�\n",1+time[LT_MON],time[LT_MDAY],time[LT_HOUR],time[LT_MIN]));
		//log_file("mirror", sprintf("%O %O\n", me, environment()));
		return 0;
	}
	else
	{
		make_room_index ++;
		//tell_object(leader,HIW"set leader start_room.\n"NOR);
		leader->set_temp("mirror/start_room",start_room);
		call_out("mirror_ok",2,leader);
			
		memory->set("mirror_time",time()+1320); //��������ʱ�� ��ʱ�趨ʱ22����
		memory->set("open_time",time());        //����ʼʱ��
		//memory->len_exits(); //��ͨ��ͼ(С��)
		memory->heart(1);  //��������
		//call_out("make_killer",60,leader);   //һ���Ӻ�ʼˢ��
	}
}

void mirror_ok(object me)
{
	object start_room,memory;
	int i,size;
	mapping user_id;

	if(!me) return;

	start_room = (object)me->query_temp("mirror/start_room");
	memory = (object)me->query_temp("mirror/mirror_memory");

	me->enable_player();
	me->delete_temp("block_msg");

	//û�п�ʼ����
	if(!start_room)
	{
		tell_object(me,"���������û�ܽ��뾵��\n");
		user_id = (mapping)memory->query("user_id");
		size = sizeof(user_id);

		for(i=0;i<size;i++)
		{
			if(user_id[sprintf("%d",i)] == me->query("id"))
			{
				memory->set(sprintf("user_id/%d",i),0);
				memory->set(sprintf("user/%d",i),0);
				break;
			}
		}
		return;
	}
	else
	{
		//tell_object(me,(string)memory->query("user_id/1")+"\n");
		//tell_object(me,(string)memory->query("user/1")+"\n");
		//me->move(start_room);
		tell_object(me,HIY"��ս��Ħ�¡���Ӣ������׼��,���������Ħ�£�����һƷ����ʿ�������ִ��Ρ�\n"NOR); //���
	}
}



//edit by rock
//2008.10.16
//���񷿼��ڴ�

#include <ansi.h>
inherit ITEM;

#include "/quest/smy/sys/list.h"

#define MIRROR_SYS "/quest/smy/sys/mirror_sys"

void create() { set_name("���񷿼��ڴ�",({ "memory"})); }

//����(С��׼�� ���Ϊ30��)
varargs void heart(int open)
{
	int i,size,index=0,leave_user=0;
	object me,player,*players = ({ }),who;
	mapping userId;
	string str;
	string whoUR,whatName;

	me = this_object();

	userId = me->query("user_id");
	size = sizeof(userId);
	//tell_object(find_player("faint"),HIW"�ҵ��������"+size+"����\n"NOR);
	
	for(i=1;i<size+1;i++)
	{
		str = userId[sprintf("%d",i)];
		
		if(!str || !stringp(str))
		{
			leave_user++;
			continue;
		}
		player = find_player(str);
		if (player && interactive(player))
		{
			if((!environment(player)->is_mirror()) && !open)
			{
				//me->set(sprintf("user_id/%d",i),0); //���񸱱���ָ�����id��Ӧ�ñ�����Ϊ0
				
				CHANNEL_D->do_channel(this_object(), "sys", HIG"��"+me+"����"+HIM"��ҡ�"HIW+player->query("name")+HIM"���Ѿ��뿪������\n"NOR);
			}
		}
	
	}
	
//����뿪����
	
	                            
	//if(leave_user >= size )
	if (player)
	{		
		//if ( player &&(!player->query_temp("smy_job/asked")) && (!environment(player)->is_mirror()))
		if ( interactive(player)  && (!player->query_temp("smy_job/asked")) && (!environment(player)->is_mirror()))
		{
			//tell_object(find_player("faint"),HIG"��"+me+"����" +   HIM"����Ѿ��뿪������30���ʼ���ٸ�����ͼ��\n"NOR);
			CHANNEL_D->do_channel(this_object(), "sys",HIG"��"+me+"����" +   HIM"����Ѿ��뿪������30���ʼ���ٸ�����ͼ��\n"NOR);
			/*
			if(me->delete_map())
			{
				tell_object(find_player("faint"),HIG"��"+me+"����"+HIM"������ͼ�Ѿ��ݻ٣���ʼ���ٸ�������\n"NOR);
				destruct(me);
				return;
			}
			*/
			call_out("dest_fuben",40+random(15));
		}
	}
	else
	{
		CHANNEL_D->do_channel(this_object(), "sys",HIG"��"+me+"����" +   HIM"����Ѿ����ߣ�������ʱ�Զ������У�\n"NOR);
	}
	
	
	userId = me->query("user_id");
	size = sizeof(userId);
	
	
	//�ѵ�������������
	if(me->query("mirror_time") <= time())
	{
		for(i=0;i<size;i++)
		{
			str = userId[sprintf("%d",i)];
			if(!str || !stringp(str)) continue;
			player = find_player(str);
			tell_object(player,HIY"��ս��Ħ�¡���Ħ�¸��������Ѿ��߽⣬��ӭ�ٴ���ս��\n"NOR);
		}
		if(me->delete_map())
		{
			MIRROR_SYS->delete_room_amount();
			destruct(me);
			return;
		}
	}
	//who=me->query("user_id/1")?me->query("user_id/1"):"����";
	if (me->query("user_id/1"))
	{
		whoUR=me->query("user_id/1");
		who=find_player(whoUR);
		if (who)
		{
		whatName=who->query("name");
		}
		else
		{
			whatName="����";
		}
	}
	else
		whoUR="����";
	//tell_object(find_player("faint"),HIG"��"+me+"����"+HIW"��ʣ"+(me->query("mirror_time")-time())+"�룬"+whatName+"\("+whoUR+"\)�ĸ������Զ��ݻ٣�\n"NOR);
	//CHANNEL_D->do_channel(this_object(), "sys",HIG"��"+me+"����"+HIW"��ʣ"+(me->query("mirror_time")-time())+"�룬"+whatName+"\("+whoUR+"\)�ĸ������Զ��ݻ٣�\n"NOR);
	call_out("heart",30);
}
void dest_fuben()
{
	object me=this_object();
		if(me->delete_map())
		{
			//tell_object(find_player("faint"),HIG"��"+me+"����"+HIM"������ͼ�Ѿ��ݻ٣���ʼ���ٸ�������\n"NOR);
			CHANNEL_D->do_channel(this_object(), "sys",HIG"��"+me+"����"+HIM"������ͼ�Ѿ��ݻ٣���ʼ���ٸ�������\n"NOR);
			MIRROR_SYS->delete_room_amount();
			CHANNEL_D->do_channel(this_object(), "sys",HIM"���ø���������"HIG+MIRROR_SYS->query_room_amount()+HIM"��\n"NOR);
			destruct(me);
			
		}
}
//ɾ�������ͼ
int delete_map()
{
	int i,size,j,size2;
	mapping maps;
	object me,map,*objs;

	me = this_object();
	maps = (mapping)me->query("maps");
	size = sizeof(maps);

	for(i=0;i<size;i++)
	{
		if(!map = (object)maps[sprintf("%d",i)] || !clonep(map)) continue;
		if(!objs = all_inventory(map) || !arrayp(objs)) continue;
		
		//�ҳ������ڵ���Ʒ,����ɾ��֮
		size2 = sizeof(objs);
		for(j=0;j<size2;j++)
		{
			if(!objectp(objs[j])) continue;
			if(userp(environment(objs[j]))) continue;

			//��������,�ƶ�����ȫ�ĵط�
			if(userp(objs[j]))
			{
				tell_object(objs[j],HIY"��ս��Ħ�¡������ٶ�̫����������Ħ�¹ؿ���\n"NOR);
				objs[j]->move("/d/xingxiu/silk3");
				//Ϊ��ֹ���������Ħ�¸��������״̬
				objs[j]->delete_temp("fuben/smy");
				objs[j]->delete_temp("smy_job");
				//objs[j]->apply_condition("job_busy",20+random(20));
				objs[j]->apply_condition("smy_job",0);
				continue;
			}
			destruct(objs[j]);
		}
		destruct(map);
	}
	return 1;
}

//��ͨ��ͼ
varargs int len_exits(int rand)
{
	object me,map;
	mapping room_exits,maps,exit;
	string fileName,mapfile,file,*dirs,temp,temp1,name;
	int i,size,j,size2,size3;
	
	me = this_object();
	maps = me->query("maps");
	size = sizeof(maps);

	if(!rand)
	{
		for(i=0;i<size;i++)
		{
			map = maps[sprintf("%d",i)];
	
			if(!clonep(map)) continue;   //�������ʧ��<ע��Σ��,���list����,����п����ߵ�����.����ֻΪ��ֹ����>
	
	//		tell_object(find_player("rock"),sprintf("DEBUG: i = %d\n",i));
			room_exits = map->query("exits");

			dirs = keys(room_exits);
			size2 = sizeof(dirs);
			for(j=0;j<size2;j++)
			{
				file = room_exits[dirs[j]];
				sscanf(file,"/quest/smy/%s",fileName);

				mapfile = sprintf("/%O",me->query(fileName));

				if(strsrch(mapfile,"#") == -1 || !fileName || !stringp(fileName))
				{
					mapfile = sprintf("/%O",map);
				}
				exit = room_exits; exit[dirs[j]] = mapfile[0..<10];


	//			tell_object(find_player("rock"),sprintf("DEBUG: %s == %s mapfile = %s\n",exit[dirs[j]],room_exits[dirs[j]],mapfile));
			}
			map->set("exits",exit);
		}
	}
	else if(rand == 1)
	{
		for(i=0;i<size;i++)
		{
			map = maps[sprintf("%d",i)];
	
			if(!clonep(map)) continue;   //�������ʧ��<ע��Σ��,���list����,����п����ߵ�����.����ֻΪ��ֹ����>

			map->set("only_name",map->query("short"));
			name = sprintf("ȼ�յ�%s",map->query("short"));
			map->set("short",name);
		}
	}
	//�������
	else if(rand == 2 || rand == 3 || rand == 4)
	{
		for(i=0;i<size;i++)
		{
			map = maps[sprintf("%d",i)];
	
			if(!clonep(map)) continue;   //�������ʧ��<ע��Σ��,���list����,����п����ߵ�����.����ֻΪ��ֹ����>

			if(rand == 2)
			{
				name = sprintf("�ջٵ�%s",map->query("only_name"));
				map->set("short",name);
			}
			else if(rand == 3)
			{
				name = "����";
				map->set("short",name);
				map->set("long","һƬ���ڣ��������£������޷��ֱ���ʲô�ط���\n");
			}

			room_exits = map->query("exits");

			dirs = keys(room_exits);
			size2 = sizeof(dirs);

			for(j=0;j<size2;j++)
			{
				size3 = sizeof(mirror_maps);
				file = mirror_maps[random(size3)];
				sscanf(file,"/quest/smy/%s",fileName);

				mapfile = sprintf("/%O",me->query(fileName));

				if(strsrch(mapfile,"#") == -1 || !fileName || !stringp(fileName))
				{
					mapfile = sprintf("/%O",map);
				}
				exit = room_exits;
				//tell_object(find_player("rock"),sprintf("DEBUG: exit = %O  mapfile = %O\n",exit,mapfile));
				exit[dirs[j]] = mapfile[0..<10];

			}
			map->set("exits",exit);
		}
	}
}

void quest_over()
{
	call_out("quest_over_1",60);
}

void quest_over_1()
{
	int size,i;
	mapping userId;
	
	object me = this_object();
	
	userId = me->query("user_id");
	size = sizeof(userId);
	for(i=0;i<size;i++)
	{
		me->set(sprintf("user_id/%d",i),0);
	}
}
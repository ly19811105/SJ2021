int main(object me, string str)
{
        object ob, where, *ob_list;
        int i;

        if (!str)
                return notify_fail("ָ���ʽ����\n"); 
        //ob = find_object(str);
        //if( !ob ) ob = find_living(str);
		ob_list = children(str);
		//if (sizeof(ob_list)<1)	ob_list = objects(str);
        write("\n����"+chinese_number(sizeof(ob_list))+"�����Ƽ�\n");
        if( sizeof(ob_list)>0 ) 
		{
                //str = resolve_path(me->query("cwd"), str);
        
                for(i=0; i<sizeof(ob_list); i++) 
				{
                	
                	write((string)ob_list[i]+"\n");
					catch(destruct(ob_list[i]));
					if(ob_list[i]) 
						write("���޷����������ݻ١�\n");
					else 
						write("���ٳɹ�\n");
                }
                return 1;
        }
        
        return 1;
}  


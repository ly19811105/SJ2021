//edit by rock
//2008.10.20

#include <ansi.h>
inherit NPC;
int do_copy(object ob);
string ask_leave();
string *title1 = ({"���Ů����","�����","�ຣ֮�� ʳ¹���","���콣��","�����Ͼ���","������","���ɨ��Ҷ","ȭ����˫","�˾���","���彣��","������","��������ѹ���� ���컨����Ǭ�� ժ�������޵���","����׷��","�������""�׵罣","������","���Ƕ��","�ﾨ��","ͭȭ����������","���̶�ţ","ǧ����","ǧ����ƣ�����׽�£�������Ӱ","��������","���Ҽ�","���طֽ�","�ɶ�����","��繫��","��������","�������","��Ů","����̫��","½������","÷����","���񽣿�","�������","Ħ�ƽ�","Ħ������","Ħ����","Į�����","�Ϻ�һ��","�������","��������","Ů����","Ů�ϳ�","������","������","ƽ���ް�","�������","��������","����ͯ��","��ɫ���������","������Ϊ","���ϴ���","���ϵ�һ��","���޺�","������Ů","��������","������","������","����ħؤ","����ؤ","�������","��������","��������","��������","�ɴ��","�ɸ���ؤ","��������","��ؤ","�˶���","������ҽ","��","����","�ڰ׵�","��ɽҽ��","�����","��������","��ؤ","������","������ؤ","��������","��������","������","��ɮ","��������","������͵���޿ײ���","������ҽ","Ů����","ƴ������","�߶�����","�ߺ�����","��������","ǧ����ҽ","�����Ի�","ɱ������","ɱ���޳�","ɱ������","������","ʥ������","������","��","��ʹ��","������","��͵","��ҽ�佳","��ҽ����","ʳ��Ůʷ","��ҽ","�����й�","����ʹ��","͵��͵","�������","��������","С��̽��","��ɮ","Ҫ����ؤ","Ҫ������","��˾���","���ʹ��","������","�׹�ѧ��","��������","�����ҽ","��ˮ��","ܽ�ؽ���","��������","��ˮ��","��Ҷ����","��«","����","���Ϸɻ�","���طɻ�","÷������","ǧ��̤��","��������","���ɽ���","�����滨","���Ϸɻ�","����̤��","һ������","һ֦��","һ֦÷","������","�˱���߸","�˱�����","�˲��ϲ�","���Ե�","��������","������","������","�����񵶿�","���ɽ�","�������","�ٲ��ɻ�","��ʤ����","����ѩ��","�������","������ǹ","������ǹ","��������","����","����֮��","���罣","������","������","����","��ȭ","����","��ͷ","�󺣸�","���ϰ�","�󵶸���","�������","���������","������","������ӥ","����׷��","���ƿ���","����׷��","�����","����","����","����","���ɾ�","���ֽ�ά","�����ѻ�","����","�ϳ���","�ϻ���","�ϻ굶","�ϻ꽣","�����","�ɲ�̫��","�ɵ���","�ɻ����죬�������","�ɺ罣","�ɻ�","����콣","�ɽ���","���ǵ�","��ӥ��","�ֹ�׽Ӱ��һ����ɱ","���ɾ�","����˫����","��������","������","����","������","����ǹ","�ֵ�����","����������","����˧","������","��ɷ��","���ν�","������","����","�����Ի���","��Ԫָ","������","����","����ү","���罣","ꪰ�","����","���Ƴ���˫��","����˫��׷���","���","�������","��","���޵�","���޵�������","�����","�����","����","��������ӥצ","������ն������׷��׽��ˮ��Ʈ","��","����ʮ��ǹ","��ǹ","��ǹ̫��","��ǹ����","��������","����","�����Σ","�Ź���","�Ź�������","�Ż�ǹ","������","������","���鸫","����֮�ƣ�����ǧ��","������","����º�","������","��������ɽ","�����й�","��������","��ǹ","��ǹС����","��ȭ","��ȭ�޵�","������","��ͷ","����ǹ","����","���Ʒ���","���ƽ���","���ƽ�","���ƽ𽣶��п�","���ƿ���","�������˷","��ָ����","͵�Դ�����","�䵶","���䣬Ǭ��ɡ������û����","�򻨽�","��ȭ","��֮��","��������","��ʤ��","��ʤ��","����ͨ","�º����","��һ��","��ɷħ��","�⹳��","�廢���ŵ�","�廢��","�廨����","�޵е�","�޿ײ���","��������","��Ӱǹ","��������","��Ӱ��","�嶾����","������","С��","С��ǹ","С��ͨ","�������������","���˽�","���������","���絶","����׷���Ľ�","ѩ��ѩ��Ʈ��","ѩ����","Ѫ��","Ѫ�ֺ�ɷ","����ɡ","һ�������","һ����","һ��������","һ���˷�","һ������","һ���ɻ�","һ����ѩ","һ����˻�","һ�����˷","һ����ų�","һǹ�̾���","һǹ����","һ�Ʒ���","һָ������","һָͨ��","һָ׷��","��������","���꽣","������","ӥצ��","����","����","������","��ǹ","��ǹ����","������","������","��������","ԧ���","ժ����","�ƽ���","������ħ","��ɽ��","��������","��ĸ����","��ĸ�����","��ĸ˫��","��ĸ����","����߻�","��ɰ��","׷�絶","׷�罣","׷�������𽭺�","׷�������������","׷����","׷��ǹ","����˫��","��ħ","��������","��ħ","���ֹ���","�ײ�����","������","������","�����ɾ�","��ɷ","�����ɾ�","�����","���½���","������Ů","��������","������ɲ ���˰��","�����","���½���","�������Ǯ","��ѪħŮ","��ؤ","��Ƥ ������ͷ","���в�Ů","��������","����","���ܸ���","����Ƥ","����������","���Ĺ�ħ","��������","������","���ལ��","��ϲŮ����","��ͷ����","����","��������","����","��ħ","��ɷ","��������","����ӥ��","���ŷ�ħ","��������","����ؤ","����","���ɾ�","��ľ��","������ħ","���º���","����ͷ��","��������","����ʹ��","��Ĺ�","���","��ħ","�������","����","�����˰�","�ۺ�","���ɾ�","��������","���Ǹ���","�������ɾ�","������","������","������","�Ͼ�ɱ��","��©һ��","�Ŀ��","����","��ɱ����","���ɾ�","����","���º�","��Ӱ��","��Ӱ��","����ȥ","����","��ɷ","�����","��¿׷��","��ɷħ��","������","���Ĳ���","�����","����Ħ��","�޵��޻�","�����","�췢��ħ","�������","���潿��","�캢��","���۹�","������","����ħŮ","��������","��������","��ӥ����","��������","����","�����","��������","���ִ���","����ͯ��","������ʩ","��������","����׷��","���׿�","���｣��","��ʵ����","����ɲ","������ɲ","��Ѫ����","���ؿ�ɽ������","�Ե�С��","�һ����","�貨���ӣ�ɢ����Ů","���ʹ��","��ʬ","�����","���ײ���","��ɲ��Ů","��ɲ����","��¶����","�����齣��","����","������","ð�վ��ӣ���Ц���","û��æ","û�õİ���","�����˲�����","������ħ ڤ���л�","ħ��ү","ī������","ľ�ɾ�","�Ϻ�����","�ϼ�����","������","�������Կ�","ŭħ","ŭĿ����","�Ź���","�����","������","ƴ��","ƴ������","ƴ��ռ����","����","���ִ�ʥ","������","��ָ��͵","��ָ����","��ָ��","ǧ����������Ӱ�������ţ����ִ�����","ǧ�����Ƕ���","ǧ�콣��","ǧ�����","ǧ�湫��","ǧ�߽���","ǧ�ֹ���","ǧ��ǧ��","ǧ������","ǧ����ؤ","Ǯ�ز�","��������Ů���","�����","��ħ","���ۺ�ħ","��ħ","���","����ϳ�","ȱĿ��","��ħ","�绨����","��������","������","ɱ�����ɣ������ϳ�","��������","�������","��������","��Ц����","������ʿ","��ֻ��","�������ѰС�һ��һ��ɱҶ��","ɥ����","ɫħ","��������","����ӥ��","ʯ��","ʯ��","ʵ��ľͷ��","�Ӿ�����","˾������","��Ŀ�º����С����","����","�ճԿ�","���˲�����","̫����ħ","���ݿ�","���","���","���","���ħ��","����ʿ","��ħ","������","��ɱ��","����������ɽ","���Ŀ���","����ƮƼ��","����","����ͷ����","��������","����","�����","��������","��������","�����","���ɾ�","������п�","���������","��������","�����º�","��������","����ר��","��������","����","���ɹ�","ͭ��","��������","Ϊ������","��ͯ��","�������","��������","������","�޳���","�޳�����","�޶�ؤ","�޷�����","�޹�����","�޿ײ���","������ħ","��Ŀɷ��","���ʵ�","���鵶","���鹫��","����С��","��ȱ����","������͵","��Ϊ����","������꣬�����ɾ�","��Ӱ��ɲ","�嶾","����","ϲħ","�������","������ɲ","������ħ","С��ͷ","С����","Сɥ��","Сɽ��","Сɥ��","Ц��ص�","Ц��С����","Ц����","Ц������","Ц��׷��","Ц����","Ц����","��˼����","������Ů","����Ů","ѩ������","ѩ���","Ѧ����","Ѫ����","Ѫ��","Ѫ����ɲ","�޻�","����","����","Ҫ����С��","һ�ɳ���","һ������","һĿ��Ȼ","���꽣","��ħ","������","����ʹ��","��������","��������","��ڤ����","������","�տ�����","������","����˫��","���ַֽ�","����С��","���","������Ů","������","���Ȧ","����׷����","������ɽ","�����ǹ","�⻨��","��ղ���","��������","���ﻷ","������","�������˫ǹ","��Ӣ��","���߽�","���ΰ���","���齣","��Ӣ��","éɽ��ָ","÷����","ûӰ��","û���","���׵�","������ҽ","ħ��ħ��ħ�����","�Ϻ�����","ŭ����ն��","��������������","��ѩ˫����","�߲�׷��","����׷����ɷ��","ǧ����ħ","ǧ��׷��������Ӱ����","ǧ�����","ǧ����ħ","ǧ�ֽ���","ǧ������","ǧ������","Ǭ����","Ǭ����","Ǳ����","�ɽ���³��","��罣","��Ƽ��","����˫ǹ","���⵶","��������ɽ","���ֽ�","������ץ","������","��������","���Ƕ������������Σ�һ�ƾ���","��ն����","��������","����콣","����������","������","����׷�罣","��굶","���ҹ�","���ڼ̻�","���޵�","�񵶰���","�񵶴���","����Ӱ","��������","�������","����ӥ��","��Ŀ���","��ȭ��","��ȭС���","��ȭ̩��","��ȭ�޵�","��ȭ�޵д��ڿ�","������Ӱͭȭ����","������","�����缦","�ѻ���","˫���޵�","˫�Ʒ���","̤ѩ�޺�","̫��һ��","���޵���","����һ��","���۽��","��׵��������������ǹ","������˷�","���ݴ���","����һ��","׷����Ӱ","׷��ʹ��","��ɽ����"});

string *t_color=({ HIR , HIG , HIY , HIB , HIM , HIC , HIW});
void create()
{
	string weapon = "null" , menpai ,title,c_title;
	mapping name;
	int i;

    i = random(4);
	
	c_title = t_color[random(6)];
	title =c_title + title1[random(sizeof(title1))];
	
	name = RNAME_D->get_random_name(i);

	set_name(name["name"], name["id"] );
		set("title", title+NOR);
	set("gender", "����");
	set("age", 20 + random(40));
	set("long", "�����ǽ����˳�"+title+NOR+"��"+name["name"]+"��\n");
	set("combat_exp", 7000000);

	set("str", 20+random(5));
	set("int", 20+random(5));
	set("con", 20+random(5));
	set("dex", 20+random(5));
	set("max_qi", 20000);
	set("max_jing", 20000);
	set("max_neili", 7000);
	set("max_neili", 20000);
	set("neili", 7000);
	set("neili", 20000);
	set_temp("apply/armor", 100);
	set("eff_jing", 20000);
	set("eff_jingli", 20000);
	set("jingli", 20000);
	set("max_jingli", 20000);
	set("meitude","peaceful");
	set("no_ansuan",1);
	set("no_bark", 1);
	set("no_quest", 1);
	set("location", 1);

	set_skill("strike", 700);
	set_skill("cuff", 700);
	set_skill("hand", 700);
	set_skill("dodge", 700);
	set_skill("sword", 700);
	set_skill("force", 700);
	set_skill("parry", 700);
	set_skill("blade", 700);
	set_skill("hammer", 700);
	set_skill("stick", 700);
	set_skill("club", 700);
	set_skill("staff", 700);
	set_skill("literate", query("int") * 10);
	set_skill("whip", 700);
	set_skill("dagger", 700);
	set("location",1);
	set("inquiry", ([
		"����" : (: ask_leave :),
		"fight" : (: ask_leave :),
	]));
	
	set("no_get", 1);
	switch( random(30) ) {
		case 0:  // wd1
		set_skill("yinyun-ziqi", 700);
		set_skill("tiyunzong", 700);
		set_skill("taiji-jian", 700);
		set_skill("taiji-quan", 700);
		map_skill("force", "yinyun-ziqi");
		map_skill("dodge", "tiyunzong");
		map_skill("sword", "taiji-jian");
		map_skill("parry", "taiji-quan");
		map_skill("cuff", "taiji-quan");
		prepare_skill("cuff", "taiji-quan");
		set("chat_chance_combat", 30);
		set("chat_msg_combat", ({
			(: exert_function, "taiji" :),
			(: perform_action, "cuff.zhan" :),
			(: perform_action, "cuff.ji" :),
			(: perform_action, "cuff.zhen" :),
		}));
		menpai = "�䵱";
		break;
		case 1:  // wd2
		set_skill("yinyun-ziqi", 700);
		set_skill("tiyunzong", 700);
		set_skill("taiji-jian", 700);
		set_skill("taiji-quan", 700);
		map_skill("force", "yinyun-ziqi");
		map_skill("dodge", "tiyunzong");
		map_skill("sword", "taiji-jian");
		map_skill("parry", "taiji-jian");
		map_skill("cuff", "taiji-quan");
		prepare_skill("cuff", "taiji-quan");
		set("chat_chance_combat", 30);
		set("chat_msg_combat", ({
			(: perform_action, "dodge.zong" :),
			(: perform_action, "sword.chan" :),
			(: perform_action, "sword.sanhuan" :),
		}));
		weapon = "sword";
		menpai = "�䵱";
		break;
		case 2:  // sl1
		set_skill("yijin-jing", 700);
		set_skill("shaolin-shenfa", 700);
		set_skill("riyue-bian", 700);
		set_skill("yizhi-chan", 700);
		map_skill("force", "yijin-jing");
		map_skill("dodge", "shaolin-shenfa");
		map_skill("whip", "riyue-bian");
		map_skill("parry", "riyue-bian");
		map_skill("finger", "yizhi-chan");
		prepare_skill("finger", "yizhi-chan");
		set("chat_chance_combat", 30);
		set("chat_msg_combat", ({
			(: exert_function, "jingang" :),
			(: perform_action, "whip.chanrao" :),
			(: perform_action, "whip.fumoquan" :),
		}));
		weapon = "whip";
		menpai = "����";
		break;
		case 3:  // sl2
		set_skill("yijin-jing", 700);
		set_skill("shaolin-shenfa", 700);
		set_skill("damo-jian", 700);
		set_skill("yizhi-chan", 700);
		map_skill("force", "yijin-jing");
		map_skill("dodge", "shaolin-shenfa");
		map_skill("sword", "damo-jian");
		map_skill("parry", "damo-jian");
		map_skill("finger", "yizhi-chan");
		prepare_skill("finger", "yizhi-chan");
		set("chat_chance_combat", 30);
		set("chat_msg_combat", ({
			(: exert_function, "jingang" :),
			(: perform_action, "sword.sanjue" :),
		}));
		weapon = "sword";
		menpai = "����";
		break;
		case 4:  // sl3
		set_skill("yijin-jing", 700);
		set_skill("shaolin-shenfa", 700);
		set_skill("yizhi-chan", 700);
		map_skill("force", "yijin-jing");
		map_skill("dodge", "shaolin-shenfa");
		map_skill("parry", "yizhi-chan");
		map_skill("finger", "yizhi-chan");
		prepare_skill("finger", "yizhi-chan");
		set("chat_chance_combat", 30);
		set("chat_msg_combat", ({
			(: exert_function, "jingang" :),
			(: perform_action, "finger.wofo" :),
			(: perform_action, "finger.qiankun" :),
		}));
		menpai = "����";
		break;
		case 5:  // hs1
		set_skill("zixia-gong", 700);
		set_skill("huashan-shenfa", 700);
		set_skill("huashan-jianfa", 700);
		set_skill("hunyuan-zhang", 700);
		map_skill("force", "zixia-gong");
		map_skill("dodge", "huashan-shenfa");
		map_skill("sword", "huashan-jianfa");
		map_skill("parry", "huashan-jianfa");
		map_skill("strike", "hunyuan-zhang");
		prepare_skill("strike", "hunyuan-zhang");
		set("chat_chance_combat", 30);
		set("chat_msg_combat", ({
			(: exert_function, "zixia" :),
			(: perform_action, "sword.lianhuan" :),
			(: perform_action, "sword.feijian" :),
		}));
		weapon = "sword";
		menpai = "��ɽ";
		break;
		case 6:  // hs2
		set_skill("zixia-gong", 700);
		set_skill("huashan-shenfa", 700);
		set_skill("fanliangyi-dao", 700);
		set_skill("poyu-quan", 700);
		map_skill("force", "zixia-gong");
		map_skill("dodge", "huashan-shenfa");
		map_skill("blade", "fanliangyi-dao");
		map_skill("parry", "fanliangyi-dao");
		map_skill("cuff", "poyu-quan");
		prepare_skill("cuff", "poyu-quan");
		set("chat_chance_combat", 30);
		set("chat_msg_combat", ({
			(: exert_function, "zixia" :),
			(: perform_action, "blade.sanshenfeng" :),
		}));
		weapon = "blade";
		menpai = "��ɽ";
		break;
		case 7:  // gb1
		set_skill("huntian-qigong", 700);
		set_skill("bangjue", 700);
		set_skill("xiaoyaoyou", 700);
		set_skill("dagou-bang", 700);
		set_skill("xianglong-zhang", 700);
		map_skill("force", "huntian-qigong");
		map_skill("dodge", "xiaoyaoyou");
		map_skill("stick", "dagou-bang");
		map_skill("parry", "dagou-bang");
		map_skill("strike", "xianglong-zhang");
		prepare_skill("strike", "xianglong-zhang");
		set("chat_chance_combat", 30);
		set("chat_msg_combat", ({
			(: exert_function, "huntian" :),
			(: perform_action, "stick.chuo" :),
			(: perform_action, "stick.chan" :),
		}));
		weapon = "stick";
		menpai = "ؤ��";
		break;
		case 8:  // gb2
		set_skill("huntian-qigong", 700);
		set_skill("bangjue", 700);
		set_skill("xiaoyaoyou", 700);
		set_skill("dagou-bang", 700);
		set_skill("xianglong-zhang", 700);
		map_skill("force", "huntian-qigong");
		map_skill("dodge", "xiaoyaoyou");
		map_skill("stick", "dagou-bang");
		map_skill("parry", "xianglong-zhang");
		map_skill("strike", "xianglong-zhang");
		prepare_skill("strike", "xianglong-zhang");
		set("chat_chance_combat", 30);
		set("chat_msg_combat", ({
			(: perform_action, "strike.xiao" :),
			(: perform_action, "strike.paiyun" :),
		}));
		menpai = "ؤ��";
		break;
		case 9:  // thd1
		set_skill("bihai-chaosheng", 700);
		set_skill("qimen-bagua", 700);
		set_skill("suibo-zhuliu", 700);
		set_skill("yuxiao-jian", 700);
		set_skill("tanzhi-shentong", 700);
		set_skill("lanhua-shou", 700);
		set_skill("luoying-zhang", 700);
		set_skill("xuanfeng-tui", 700);
		map_skill("force", "bihai-chaosheng");
		map_skill("dodge", "suibo-zhuliu");
		map_skill("sword", "yuxiao-jian");
		map_skill("parry", "yuxiao-jian");
		map_skill("finger", "tanzhi-shentong");
		prepare_skill("finger", "tanzhi-shentong");
		set("chat_chance_combat", 30);
		set("chat_msg_combat", ({
			(: exert_function, "maze" :),
			(: perform_action, "sword.yuxiao" :),
			(: perform_action, "sword.feiying" :),
			(: perform_action, "sword.qimen" :),
		}));
		set("thd/perform",999);
		weapon = "xiao";
		menpai = "�һ���";
		break;
		case 10: // thd2
		set_skill("bihai-chaosheng", 700);
		set_skill("qimen-bagua", 700);
		set_skill("suibo-zhuliu", 700);
		set_skill("yuxiao-jian", 700);
		set_skill("tanzhi-shentong", 700);
		map_skill("force", "bihai-chaosheng");
		map_skill("dodge", "suibo-zhuliu");
		map_skill("sword", "yuxiao-jian");
		map_skill("parry", "tanzhi-shentong");
		map_skill("finger", "tanzhi-shentong");
		prepare_skill("finger", "tanzhi-shentong");
		set("chat_chance_combat", 30);
		set("chat_msg_combat", ({
			(: exert_function, "maze" :),
			(: perform_action, "finger.huayu" :),
			(: perform_action, "finger.shentong" :),
		}));
		set("thd/perform",999);
		menpai = "�һ���";
		break;
		case 11: // mr1
		set_skill("shenyuan-gong", 700);
		set_skill("douzhuan-xingyi", 700);
		set_skill("yanling-shenfa", 700);
		set_skill("murong-jianfa", 700);
		set_skill("tanzhi-shentong", 700);
		map_skill("force", "shenyuan-gong");
		map_skill("dodge", "yanling-shenfa");
		map_skill("sword", "murong-jianfa");
		map_skill("parry", "douzhuan-xingyi");
		map_skill("finger", "canhe-zhi");
		prepare_skill("finger", "canhe-zhi");
		set("chat_chance_combat", 30);
		set("chat_msg_combat", ({
			(: exert_function, "shenyuan" :),
			(: perform_action, "parry.xingyi" :),
		}));
		weapon = "sword";
		menpai = "����Ľ��";
		break;
		case 12: // gumu1
		set_skill("yunu-xinjing", 700);
		set_skill("yunu-shenfa", 700);
		set_skill("xuantie-jianfa", 700);
		set_skill("anran-zhang", 700);
		map_skill("force", "yunu-xinjing");
		map_skill("dodge", "yunu-shenfa");
		map_skill("sword", "xuantie-jianfa");
		map_skill("parry", "xuantie-jianfa");
		map_skill("strike", "anran-zhang");
		prepare_skill("strike", "anran-zhang");
		set("chat_chance_combat", 30);
		set("chat_msg_combat", ({
			(: perform_action, "sword.wujian" :),
			(: perform_action, "sword.haichao" :),
		}));
		weapon = "sword";
		menpai = "��Ĺ";
		if (random(2)) set("env/��������","����");
		else set("env/��������","��ӿ");
		break;
		case 13: // emei1
		set_skill("linji-zhuang", 700);
		set_skill("anying-fuxiang", 700);
		set_skill("huifeng-jian", 700);
		set_skill("sixiang-zhang", 700);
		map_skill("force", "linji-zhuang");
		map_skill("dodge", "anying-fuxiang");
		map_skill("sword", "huifeng-jian");
		map_skill("parry", "huifeng-jian");
		map_skill("strike", "sixiang-zhang");
		prepare_skill("strike", "sixiang-zhang");
		set("chat_chance_combat", 30);
		set("chat_msg_combat", ({
			(: exert_function, "wuwo" :),
			(: perform_action, "sword.mie" :),
			(: perform_action, "sword.jue" :),
		}));
		weapon = "sword";
		menpai = "����";
		break;
		case 14: // emei2
		set_skill("linji-zhuang", 700);
		set_skill("anying-fuxiang", 700);
		set_skill("yanxing-daofa", 700);
		set_skill("sixiang-zhang", 700);
		map_skill("force", "linji-zhuang");
		map_skill("dodge", "anying-fuxiang");
		map_skill("blade", "yanxing-daofa");
		map_skill("parry", "yanxing-daofa");
		map_skill("strike", "sixiang-zhang");
		prepare_skill("strike", "sixiang-zhang");
		set("chat_chance_combat", 30);
		set("chat_msg_combat", ({
			(: exert_function, "wuwo" :),
			(: perform_action, "blade.huanying" :),
		}));
		weapon = "blade";
		menpai = "����";
		break;
		case 15: // mj1
		set_skill("shenghuo-shengong", 700);
		set_skill("qiankun-danuoyi", 700);
		set_skill("piaoyi-shenfa", 700);
		set_skill("shenghuo-lingfa", 700);
		set_skill("hanbing-mianzhang", 700);
		map_skill("force", "shenghuo-shengong");
		map_skill("dodge", "piaoyi-shenfa");
		map_skill("dagger", "shenghuo-lingfa");
		map_skill("parry", "qiankun-danuoyi");
		map_skill("cuff", "shenghuo-lingfa");
		prepare_skill("cuff", "shenghuo-lingfa");
		set("chat_chance_combat", 30);
		set("chat_msg_combat", ({
			(: exert_function, "yinfeng" :),
			(: perform_action, "dagger.ji" :),
			(: perform_action, "dagger.xinmo" :),
			(: perform_action, "dagger.tisha" :),
		}));
		weapon = "tieling";
		menpai = "����";
		break;
		case 16: // mj2
		set_skill("shenghuo-shengong", 700);
		set_skill("qiankun-danuoyi", 700);
		set_skill("piaoyi-shenfa", 700);
		set_skill("shenghuo-lingfa", 700);
		set_skill("hanbing-mianzhang", 700);
		map_skill("force", "shenghuo-shengong");
		map_skill("dodge", "piaoyi-shenfa");
		map_skill("dagger", "shenghuo-lingfa");
		map_skill("parry", "hanbing-mianzhang");
		map_skill("strike", "hanbing-mianzhang");
		prepare_skill("strike", "hanbing-mianzhang");
		set("chat_chance_combat", 30);
		set("chat_msg_combat", ({
			(: exert_function, "yinfeng" :),
			(: perform_action, "strike.xixue" :),
		}));
		menpai = "����";
		case 17: // dali1
		set_skill("qiantian-yiyang", 700);
		set_skill("tianlong-xiang", 700);
		set_skill("duanjia-jianfa", 700);
		set_skill("qingyan-zhang", 700);
		map_skill("force", "qiantian-yiyang");
		map_skill("dodge", "tianlong-xiang");
		map_skill("sword", "duanjia-jianfa");
		map_skill("parry", "duanjia-jianfa");
		map_skill("strike", "qingyan-zhang");
		prepare_skill("strike", "qingyan-zhang");
		set("chat_chance_combat", 30);
		set("chat_msg_combat", ({
			(: exert_function, "xinjing" :),
			(: perform_action, "sword.fenglei" :),
		}));
		weapon = "sword";
		menpai = "���ϴ���";
		break;
		case 18: // tls
		set_skill("kurong-changong", 700);
		set_skill("tianlong-xiang", 700);
		set_skill("cihang-bian", 700);
		map_skill("force", "kurong-changong");
		map_skill("dodge", "tianlong-xiang");
		map_skill("parry", "kurong-changong");
		map_skill("strike", "kurong-changong");
		prepare_skill("strike","kurong-changong");
		set("chat_chance_combat", 30);
		set("chat_msg_combat", ({
			(: exert_function, "ku" :),
			(: exert_function, "jiuchong" :),
		}));
		menpai = "����������";
		break;
		case 19: // gumu2
		set_skill("yinsuo-jinling", 700);
		set_skill("yunu-jianfa", 700);
		set_skill("yunu-shenfa", 700);
		set_skill("meinu-quanfa", 700);
		set_skill("yunu-xinjing", 700);
		map_skill("force", "yunu-xinjing");
		map_skill("dodge", "yunu-shenfa");
		map_skill("sword", "yunu-jianfa");
		map_skill("whip", "yinsuo-jinling");
		map_skill("parry", "yinsuo-jinling");
		map_skill("cuff", "meinu-quanfa");
		prepare_skill("cuff", "meinu-quanfa");
		set("yueyin", 1);
		set("gmsanwu", 1);
		set("chat_chance_combat", 30);
		set("chat_msg_combat", ({
			(: perform_action, "whip.yueyin" :),
			(: perform_action, "whip.sanwu" :),
		}));
		weapon = "whip";
		menpai = "��Ĺ��";
		break;
		case 20: //gumu3
		set_skill("anran-zhang", 700);
		set_skill("yunu-xinjing", 700);
		set_skill("yunu-shenfa", 700);
		map_skill("force", "yunu-xinjing");
		map_skill("dodge", "yunu-shenfa");
		map_skill("parry", "anran-zhang");
		map_skill("strike", "anran-zhang");
		prepare_skill("strike", "anran-zhang");
		set("chat_chance_combat", 30);
		set("chat_msg_combat", ({
			(: perform_action, "strike.xiaohun" :),
			(: perform_action, "strike.anran" :),
			(: perform_action, "strike.jishi" :),
		}));
		menpai = "��Ĺ��";
		break;
		case 21: // kl1
		set_skill("xuantian-wuji", 700);
		set_skill("taxue-wuhen", 700);
		set_skill("kunlun-zhang", 700);
		map_skill("force", "xuantian-wuji");
		map_skill("dodge", "taxue-wuhen");
		map_skill("parry", "kunlun-zhang");
		map_skill("strike", "kunlun-zhang");
		prepare_skill("strike", "kunlun-zhang");
		set("chat_chance_combat", 30);
		set("chat_msg_combat", ({
			(: perform_action, "strike.diezhang" :),
			(: perform_action, "strike.xuebeng" :),
		}));
		menpai = "������";
		break;
		case 22: // kl2
		set_skill("xuantian-wuji", 700);
		set_skill("taxue-wuhen", 700);
		set_skill("zhentian-quan", 700);
		map_skill("force", "xuantian-wuji");
		map_skill("dodge", "taxue-wuhen");
		map_skill("parry", "zhentian-quan");
		map_skill("cuff", "zhentian-quan");
		prepare_skill("cuff", "zhentian-quan");
		set("chat_chance_combat", 30);
		set("chat_msg_combat", ({
			(: exert_function, "taxue" :),
			(: perform_action, "cuff.kaishan" :),
		}));
		menpai = "������";
		break;
		case 23: // kl3
		set_skill("xuantian-wuji", 700);
		set_skill("taxue-wuhen", 700);
		set_skill("chuanyun-tui", 700);
		map_skill("force", "xuantian-wuji");
		map_skill("dodge", "taxue-wuhen");
		map_skill("parry", "chuanyun-tui");
		map_skill("leg", "chuanyun-tui");
		prepare_skill("leg", "chuanyun-tui");
		set("chat_chance_combat", 30);
		set("chat_msg_combat", ({
			(: exert_function, "taxue" :),
			(: perform_action, "leg.chuanyun" :),
		}));
		menpai = "������";
		break;
		case 24: // kl4
		set_skill("xuantian-wuji", 700);
		set_skill("taxue-wuhen", 700);
		set_skill("liangyi-jian", 700);
		map_skill("force", "xuantian-wuji");
		map_skill("dodge", "taxue-wuhen");
		map_skill("parry", "liangyi-jian");
		map_skill("sword", "liangyi-jian");
		set("chat_chance_combat", 30);
		set("chat_msg_combat", ({
			(: perform_action, "sword.xunlei" :),
			(: perform_action, "sword.hundun" :),
		}));
		menpai = "������";
		weapon = "sword";
		break;
		case 25: // tls3
		set_skill("kurong-changong", 700);
		set_skill("tianlong-xiang", 700);
		set_skill("yiyang-zhi", 700);
		map_skill("force", "kurong-changong");
		map_skill("dodge", "tianlong-xiang");
		map_skill("parry", "kurong-changong");
		map_skill("finger", "yiyang-zhi");
		prepare_skill("finger", "yiyang-zhi");
		set("chat_chance_combat", 30);
		set("chat_msg_combat", ({
			(: perform_action, "finger.sanmai" :),
			(: perform_action, "finger.sandie" :),
		}));
		menpai = "����������";
		break;
		case 26: // tz1
		set_skill("guiyuan-tunafa", 700);
		set_skill("shuishangpiao", 700);
		set_skill("tiezhang-zhangfa", 700);
		map_skill("force", "guiyuan-tuanfa");
		map_skill("dodge", "shuishangpiao");
		map_skill("parry", "tiezhang-zhangfa");
		map_skill("strike", "tiezhang-zhangfa");
		prepare_skill("strike", "tiezhang-zhangfa");
		set("chat_chance_combat", 30);
		set("chat_msg_combat", ({
			(: exert_function, "juli" :),
			(: perform_action, "dodge.piao" :),
			(: perform_action, "strike.heyi" :),
			(: perform_action, "strike.duoming" :),
			(: perform_action, "strike.heisha" :),
		}));
		menpai = "������";
		break;
		case 27: // tz2
		set_skill("guiyuan-tunafa", 700);
		set_skill("shuishangpiao", 700);
		set_skill("tiezhang-zhangfa", 700);
		map_skill("force", "guiyuan-tunafa");
		map_skill("dodge", "shuishangpiao");
		map_skill("parry", "tiezhang-zhangfa");
		map_skill("strike", "tiezhang-zhangfa");
		prepare_skill("strike", "tiezhang-zhangfa");
		set("chat_chance_combat", 30);
		set("chat_msg_combat", ({
			(: exert_function, "juli" :),
			(: perform_action, "dodge.piao" :),
			(: perform_action, "strike.xuanfeng" :),
			(: perform_action, "strike.pushan" :),
			(: perform_action, "strike.honglei" :),
		}));
		menpai = "������";
		break;
		case 28: // sld1
		set_skill("dulong-dafa", 700);
		set_skill("youlong-shenfa", 700);
		set_skill("huagu-mianzhang", 700);
		map_skill("force", "dulong-dafa");
		map_skill("dodge", "youlong-shenfa");
		map_skill("parry", "huagu-mianzhang");
		map_skill("strike", "huagu-mianzhang");
		prepare_skill("strike", "huagu-mianzhang");
		set("chat_chance_combat", 30);
		set("chat_msg_combat", ({
			(: exert_function, "wudi" :),
			(: perform_action, "strike.bujue" :),
		}));
		menpai = "������";
		break;
		case 29: // sld2
		set_skill("dulong-dafa", 700);
		set_skill("youlong-shenfa", 700);
		set_skill("huagu-mianzhang", 700);
		set_skill("tenglong-bifa", 700);
		map_skill("dagger", "tenglong-bifa");
		map_skill("force", "dulong-dafa");
		map_skill("dodge", "youlong-shenfa");
		map_skill("parry", "tenglong-bifa");
		map_skill("strike", "huagu-mianzhang");
		prepare_skill("strike", "huagu-mianzhang");
		set("chat_chance_combat", 30);
		set("chat_msg_combat", ({
			(: exert_function, "wudi" :),
			(: perform_action, "dagger.xiaolian" :),
			(: perform_action, "dagger.guifei" :),
			(: perform_action, "dagger.diqing" :),
		}));
		menpai = "������";
		weapon = "dagger";
		break;
		default: // others      BUG!!!
		set("long","�书���ô���BUG������");
	}
	set("weapon" , weapon);
	set("menpai" , menpai);
	setup();
	if( weapon!="null" ) carry_object(BINGQI_D(weapon))->wield();
	carry_object(ARMOR_D("cloth"))->wear();
	add_money("silver", random(99));


	this_object()->start_call_out( (: call_other, this_object(), "dest", this_object() :), 600);
}
int return_home()
{
	return 0;
}
void dest()
{
	command("emote ����ææ���뿪�ˡ�");
	destruct(this_object());
}
int do_copy(object target,int mode)
{
	mapping skills;
	string *sk;
	object me,ob;
	int lv,exp,i,t;

	me = this_object();
	ob = target;
	if(mode) {
		t = 10;
		//set("long",query("long")+"����ΰ���̫�ã�����������ر�Ӿ��������ģ���˵�������Ǵ��ڸ����أ�\n");
		add_money("gold", random(2));
	}
	else
		t = 12+random(5);

	lv = ob->query("max_pot") -100;
	lv = lv * t/10;
	exp = ob->query("combat_exp") *t/10;
	exp = exp * (100+random(20))/100;
	me->set("no_party_job",1);
	me->set("max_qi", mode?(int)ob->query("max_qi")*t*20/100:(int)ob->query("max_qi")*t/10 );
	me->set("eff_qi", mode?(int)ob->query("max_qi")*t*20/100:(int)ob->query("max_qi")*t/10 );
	me->set("qi", mode?(int)ob->query("max_qi")*t*20/100:(int)ob->query("max_qi")*t/10 );
	me->set("max_jing",(int)ob->query("max_jing"));
	me->set("eff_jing",(int)ob->query("max_jing"));
	me->set("jing",(int)ob->query("max_jing"));
	me->set("max_neili",(int)ob->query("max_neili") );
	me->set("neili",(int)ob->query("neili")*t/10 );
	if( me->query("neili") < me->query("max_neili") )
		me->set("neili",(int)me->query("max_neili") );
	me->set("max_jingli",(int)ob->query("max_jingli"));
	me->set("eff_jingli",(int)ob->query("eff_jingli"));
	me->set("jingli",(int)ob->query("jingli"));
	if( me->query("jingli") < me->query("eff_jingli") )
		me->set("jingli",(int)me->query("eff_jingli") );
	me->set("combat_exp",exp );

	skills = me->query_skills();
	if (mapp(skills)) {
		sk = keys(skills);
		for (i=0;i<sizeof(sk);i++)
			if ( sk[i] != "literate")
			skills[sk[i]] = lv;
	}
	me->set("jiali",(int)me->query_skill("force")/4);
}
string ask_leave()
{
	object me, ob;
	me = this_object();
	ob = this_player();

	if(environment(me)->query("no_fight")) {
		random_move();
	}
	return "����������ְɣ�";
}
#include<stdio.h>
#include<time.h>
#include<stdlib.h>

typedef struct
{
	char name[20];
	char gender[3]; //用字符串而不用字符可以防止玩家误按回车导致读入个回车就走下一条指令了 
	int age;
	int money;
}character;

int numberguess(void);
int dragonfight(void);
void choose(void);
void singer(void);
int finalfight(void);

int main()
{
				//定义变量 
char choice[3];  
char status[3];  
int count; // for numberguess
int dragonthing = 3;//0-death ;1-win ; 2 -escape; 3-never met dragon; 
int internalofdragon=0; 
int markformath = 0;
int seventeen = 0 ;
int sing = 0;	//1 for 两只老虎 ;2 for 小星星 
int getmoney;
int final;
int neighbor=0;
character player1;
				//角色基本信息 
	
printf("\n创建角色:\n\n"); 
printf("请输入姓名：");
scanf("%s",&player1.name);
fflush(stdin);
printf("请输入性别(M:男 F:女): ");
scanf("%s",&player1.gender[0]);
fflush(stdin);
printf("请输入年龄："); 
scanf("%d",&player1.age);
fflush(stdin);

			//主线选择 
printf("你的身份是？ A普通大学生 B普通公司职员 C法师 \n");
scanf("%s",&status[0]); 
printf("\n");	
fflush(stdin);
if(((player1.age>=25)||(player1.age<=15))&&(status[0]=='A')){
	printf("%d岁的大学生....好吧\n",player1.age);
		fflush(stdin);
	scanf("continue");
	fflush(stdin);
}

			//开始 
printf("请确保键盘大写锁定\n   按回车键开始游戏\n      have fun\n");
scanf("start");

									
if (status[0]=='A'){		//学生主线 
	start:
	printf("阳光明媚的一天开始了\n你拿着100块钱上学去了(按回车键继续)\n");	
	player1.money =100;					
	 	
	fflush(stdin);	//这是为了点回车才继续，防止一直走到下个选项一下出太多字很长 
	scanf("continue");
	fflush(stdin);
	
	printf("你的邻居热情地打招呼：早啊%s!\n",player1.name);	//事件 1 邻居问好 
	printf("你选择： A向他问好 B无视他 C给他唱《两只老虎》\n");
	fflush(stdin);
	scanf("%s",&choice[0]);
	fflush(stdin);
	
	if(choice[0]=='A'){
		printf("你向他摆手道“早上好邻居”。问过好后你很高兴。"); 
	}else if (choice[0]=='B'){
		printf("你没有理会他，自顾自走了过去。"); 
		neighbor=1;
		
	}else if (choice[0]=='C'){
		printf("你唱起《两只老虎》，邻居哈哈大笑，还觉得你是个傻逼"); 
		sing = 1;
	}else {
		printf("你愣在原地，邻居喊了你两句你才回过神"); 
	}
	printf("(按回车键继续)");
	fflush(stdin);
	scanf("continue");
	fflush(stdin);
	
	printf("\n\n") ;
						//事件2 高数课 
	printf("高数课上，老师问：“谁能来证明一下拉格朗日中值定理？”\n此时你\n");
	printf("A胸有成竹地举起了手 B根本不懂老师在说什么 C在玩手机\n");
	scanf("%s",&choice[0]);
	fflush(stdin);
	
	if(choice[0]=='A'){			//2.1老师出错	 
		printf("你是全班唯一一个举手的。老师说：“算了，我自己来吧”\n");
		
			fflush(stdin);
			scanf("continue");
			fflush(stdin);
			
		printf("老师在黑板上奋笔疾书之际，\n你火眼金睛般发现老师竟然有一步把小写x写成大写X了！\n");
		fflush(stdin);
		scanf("continue");
		fflush(stdin);	
		printf("你想：\n");
		printf("A 这么个天大的错误我一定要指出来！\n");
		printf("B 唉，好吧，虽然这个问题很严重我还是假装没发现吧\n");
		scanf("%c",&choice);
		fflush(stdin);
		if (choice[0]=='A'){
			printf("你站了起来，浑身正气缭绕，\n你说：“老师，你把大小写弄错了”，语气淡定而神态庄严\n");
			printf("老师定睛一看，叹了口气说道：“我真是老了，竟然犯这么严重的错误。”\n");
				fflush(stdin);
				scanf("continue");
				fflush(stdin);
			printf("你说：\n");
			printf("A人非圣贤孰能无过，老师我们原谅你\nB就是啊，滚蛋吧你\n");
			scanf("%s",&choice[0]);
			fflush(stdin); 
			printf("老师抹了把眼泪默默走出教室\n全班同学都很崇拜你\nBy the way ,第二天高数老师换人了\n");
			}
		else{
			printf("你默默听课，岁月静好"); 
			}
	}else if (choice[0]=='B'){
		printf("全班没有人举手，老师说：“算了，我自己来吧”\n");
		markformath = 1;
	}else {
		printf("你很专心地没听课，并没听到老师说了什么\n"); 
		markformath = 1;
	}	
	fflush(stdin);
	scanf("continue");
	fflush(stdin);
	printf("\n");
					//2 高数课事件完 ,3 猜数字事件
	printf("课间，一个油腻中年男子走向你请你和他玩猜数字，还说你赢了就给你100块钱。\n");
	printf("你选择： A当然要玩  B扔给他100让他离你远点  C无视掉他  D对他唱唱《小星星》\n");		
	scanf("%s",&choice[0]);
	fflush(stdin);
	if(choice[0]=='A'){
		count = numberguess();
		if(count<=3){
			player1.money += 100;
			printf("\n获得100元，现在你有200元。\n"); 
		} else{
			printf("\n不过你用了%d次，不给你钱了\n",count);
		}
	}else if (choice[0]=='B'){
		printf("男子拿着你的钱悻悻地走了，现在你还剩0元了恭喜啊\n");
			fflush(stdin);
			scanf("continue");
			fflush(stdin);	
			printf("\n**************获得成就：身无分文！*********************\n");
		player1.money -= 100;
	}else if (choice[0]=='C'){
		printf("你不理他，自己走了\n");
	}else {
		printf("男子说你唱的很好听给了你一巴掌疼死了\n");
		sing=2; 
	}
	
	fflush(stdin);
	scanf("continue");
	fflush(stdin);
	printf("\n");
					//3 猜数字事件完  4龙事件 
	printf("中午，你在走路，\n你突然发现面前竟然多了条龙！\n");
	printf("你选择  A揍它  B礼貌地让它别挡道 \n");
	fflush(stdin);
	scanf("%s",&choice[0]);
	if (choice[0]=='B'){
		printf("大龙很听话的让开了路\n"); 
	}else if (choice[0]=='A'){
		dragonthing=dragonfight();
		if(dragonthing==0){
			printf("*******你死掉了，但是是战死的，但是人们不会铭记你的*******\n");
			fflush(stdin);
			scanf("continue");
			fflush(stdin);
			goto ending;
		}else if (dragonthing==1){
			printf("\n获得成就********\"dragon-slayer\"********\n");
			printf("龙掉落1000块钱\n");
			player1.money+=1000;
			printf("现在你有%d块钱\n获得材料\"internal of dragon\"\n",player1.money);
			internalofdragon=1;	 
		}
	}
				//4龙事件完 
	fflush(stdin);
	scanf("continue");
	fflush(stdin);
	printf("你往前走了73米后突然意识到---\n")	;
	printf("这他妈的哪来的龙？这不是传说的的生物吗？\n");
	fflush(stdin);
	scanf("continue");
	fflush(stdin);
	if(dragonthing==1){
		printf("可是你身上的战利品提醒你这一切都是真的\n");
	} else if (dragonthing==2){
		printf("可是你刚才与龙打斗留下的伤口还在流血，这不是做梦\n");
	}else if (dragonthing ==3){
		printf("你想，可能是昨天没睡好，出现幻觉了。\n"); 
	}
	
	printf(" 你晃了晃头，决定不再想龙的事\n ");
			fflush(stdin);
			scanf("continue");
			fflush(stdin);
	if(markformath==1){
		printf("这一晃头，你瞥见高数老师，他竟然拖着个大行李箱\n");
		printf("你决定 A视而不见直接走过去  B上前询问他要去旅游吗\n");
		scanf("%s",&choice[0]);
		fflush(stdin);
		if(choice[0]=='A'){
			printf("你淡定从老师面前走过去。\n其实他根本不认识你\n");
				fflush(stdin);
				scanf("continue");
				fflush(stdin);
		}else {
			printf("你上前询问。\n老师叹了口气说：\n");
			printf("妈蛋, 老子刚刚在另一条故事线里被开除了\n");
			fflush(stdin);
			scanf("continue");
			fflush(stdin);	
			printf("****************获得成就：剧情错乱*****************") ;
				fflush(stdin);
			scanf("continue");
			fflush(stdin);
		}
	}
	printf("午饭时间到了\n");
		fflush(stdin);
			scanf("continue");
			fflush(stdin);
	printf("午饭时间结束了\n");
		fflush(stdin);
			scanf("continue");
			fflush(stdin);	
				//邂逅事件 for male
	if(player1.gender[0]=='M'){
		printf("你走出餐厅，外面下雨了\n");
		fflush(stdin);
			scanf("continue");
			fflush(stdin);	
		printf("雨不是很大，地还没有湿\n");
		printf("雨点小心翼翼地吻向花坛刚翻新的泥土\n");
			fflush(stdin);
			scanf("continue");
			fflush(stdin);	
		printf("花坛边上，一个白衣服的姑娘沿小路走着\n");
		printf("当然路上人不少，穿白衣服的也不止她一个\n");
			fflush(stdin);
			scanf("continue");
			fflush(stdin);	
		printf("但是只有她身上像是有淡淡的光环\n她像是把周围都照亮了\n");
		if(dragonthing==1){
			printf("你知道该怎么办\nA上前搭讪  B默默看着她越走越远  C把龙的内脏送给她\n");
		} else{
		printf("你知道该怎么办\tA上前搭讪  B默默看着她越走越远  \n");
		}
			fflush(stdin);
		scanf("%s",&choice[0]);
		fflush(stdin);
		if(choice[0]=='B'){
			printf("她在你视野里渐渐模糊，\n你突然觉得今天可能让你后悔一辈子\n");
			printf("但你仍然没有追上去\n"); 
			fflush(stdin);
			scanf("continue");
			fflush(stdin);	
		} else if (choice[0]=='C'){
			printf("你走过去，把依旧炽热的龙之内脏拿出来说要送给她，\n");
			printf("你感觉像是在捧着自己的那份跳动的情意\n");
			fflush(stdin);
			scanf("continue");
			fflush(stdin);	
			printf("女孩淡淡张口道：好恶心好吓人还带着血呢\n");
			printf("她跑开了，你手中滚烫的热诚里没有她的温度\n") ;
			printf("再也不会有了\n");
			fflush(stdin);
			scanf("continue");
			fflush(stdin);	
		}else if (choice[0]=='A'){
			seventeen = 1;
			printf("你走向女孩：“嘿...呃...虽然我不认识你，但，呃..你想去花坛转转吗？”\n");
			printf("你感觉自己的声音虚得不像自己\n");
			fflush(stdin);
			scanf("continue");
			fflush(stdin);	
			printf("她被你吓了一跳，愣了两秒后笑了笑说好啊\n");
			printf("多年以后，你告诉她今天的濛濛雨中，你看到了最美的画\n");
			fflush(stdin);
			scanf("continue");
			fflush(stdin);
			printf("她说她叫seventeen，你记住了\n");
			printf("你明白，在以后无数个日日夜夜里，你总会默念她的名字，seventeen\n");
			fflush(stdin);
			scanf("continue");
			fflush(stdin);
			
		}
		 
	}						
			//邂逅事件 for female
	else if (player1.gender[0]=='F'){
			printf("你走出餐厅，阳光暖暖的\n");
		fflush(stdin);
			scanf("continue");
			fflush(stdin);	
		printf("你心情很好\n");
			fflush(stdin);
			scanf("continue");
			fflush(stdin);	
		printf("花坛边上，一个白衣服的男生沿小路走着\n");
		printf("他戴着耳机，像是很享受混杂着阳光的音乐\n");
			fflush(stdin);
			scanf("continue");
			fflush(stdin);	
		printf("你感觉他身上有什么东西吸引着你\n也许他和阳光一样干净温暖\n");
		if(dragonthing==1){
			printf("你知道该怎么办\nA上前搭讪  B默默看着他越走越远  C把龙的内脏送给他\n");
		} else{
		printf("你知道该怎么办\tA上前搭讪  B默默看着他越走越远  \n");
		}
			fflush(stdin);
		scanf("%s",&choice[0]);
		fflush(stdin);
		if(choice[0]=='B'){
			printf("他在你视野里渐渐模糊，\n你突然觉得今天可能让你后悔一辈子\n");
			printf("但你仍然没有追上去\n"); 
			fflush(stdin);
			scanf("continue");
			fflush(stdin);	
		} else if (choice[0]=='C'){
			printf("你走过去，把依旧炽热的龙之内脏拿出来说要送给他，\n");
			printf("你感觉像是在捧着自己的那份跳动的情意\n");
			fflush(stdin);
			scanf("continue");
			fflush(stdin);	
			printf("男孩淡淡张口道：卧槽好他妈恶心\n");
			printf("他走开了，你手中滚烫的热诚里没有他的温度\n") ;
			printf("再也不会有了\n");
			fflush(stdin);
			scanf("continue");
			fflush(stdin);	
		}else if (choice[0]=='A'){
			seventeen = 1;
			printf("你走向男生：“嘿...呃...虽然我不认识你，但，呃..你想去花坛转转吗？”\n");
			printf("你感觉自己的声音虚得不像自己\n");
			fflush(stdin);
			scanf("continue");
			fflush(stdin);	
			printf("他被你吓了一跳，愣了两秒后笑了笑说好啊\n");
			printf("多年以后，你告诉他今天的阳光下，你看到了最美的画\n");
			fflush(stdin);
			scanf("continue");
			fflush(stdin);
			printf("他说她叫seventeen，你记住了\n");
			printf("你明白，在以后无数个日日夜夜里，你总会默念他的名字，seventeen\n");
			fflush(stdin);
			scanf("continue");
			fflush(stdin);
			}	
	}	
	printf("\n");
	if(seventeen==1){
	
	printf("与seventeen从花坛出来，你们各回各家\n");
				fflush(stdin);		//money changed
			scanf("continue");
			fflush(stdin);
			}
	printf("在回家路上你有点口渴，于是你转身进路边一家商店想买瓶水\n");
	if(player1.money==0){
		printf("但你想到自己已经没钱了，你很难过\n");
		
	}else {
		printf("你买了水中贵族*Master kang*\n标价5元\n");
		fflush(stdin);
			scanf("continue");
			fflush(stdin);
		printf("老板人就和看上去一样善良，\n他说你想给多少钱就给多少钱吧\n");
			fflush(stdin);
			scanf("continue");
			fflush(stdin);
		 printf("你惊叹于还有这样做生意的\n于是你掏出(元)");
		 int pay = 0;
		 scanf("%d",&pay);
		 if (pay<5){
		 	printf("老板可谓人狠话不多，把你打了一顿并抢走了你20\n");
			 player1.money-=20;
			 printf("现在你还剩%d\n",player1.money) ;
		 }else if (pay>=5){
		 	srand(time(0));
		 	 getmoney =rand()%100+50;
		 	player1.money+=getmoney;
		 	printf("老板觉得你善良，水送你了还给了你%d块钱\n",getmoney);
		 	printf("现在你有%d\n",player1.money);	
		 }
	}
		fflush(stdin);
			scanf("continue");
			fflush(stdin);
				//	about singing come to end 
	if(sing==1){
		printf("出了商店，年轻人走向你\n");
		printf("他说他听到你唱《两只老虎》，很不错，想签约你\n");
			fflush(stdin);
			scanf("continue");
			fflush(stdin);
		printf("“来我们菜鸡唱片公司吧，保你成为唱歌中的菜鸡，走上人生巅峰”他说\n");
		printf("你明白这是个机会，\n于是你") ;
		printf(" A表示很乐意   B拒绝他  \n");
	
		fflush(stdin);
		scanf("%s",&choice[0]);
		fflush(stdin);
		
		if(choice[0]=='A'){
			printf(" \n");
				singer(); 
				goto ending;
		} else if (choice[0]=='B'){
			printf("他灰头土脸的走了\n");	
		}
	}
	else if(sing==2){
		printf("出了商店，年轻人走向你\n");
		printf("他说他听到你唱《小星星》，很不错，想签约你\n");
			fflush(stdin);
			scanf("continue");
			fflush(stdin);
		printf("“来我们菜鸡唱片公司吧，保你成为唱歌中的菜鸡，走上人生巅峰”他说\n");
		printf("你明白这是个机会，\n于是你") ;
		printf(" A表示很乐意   B拒绝他  \n");
	
		fflush(stdin);
		scanf("%s",&choice[0]);
		fflush(stdin);
		
		if(choice[0]=='A'){
			printf(" \n");
				singer(); 
				goto ending;
		} else if (choice[0]=='B'){
			printf("他灰头土脸的走了\n");	
		}
	}
			fflush(stdin);
			scanf("continue");
			fflush(stdin);
				// money thing
	getmoney=rand()%60+150;	
	printf("晚饭前你在外面散步，看到地上有个钱包\n");
	printf("里面一共%d元\n",getmoney);
			printf("你决定 A交给警察叔叔  B自己留着  \n");
	
	fflush(stdin);
	scanf("%s",&choice[0]);
	fflush(stdin);
	
	if(choice[0]=='A'){
		printf("警察叔叔赞扬你是社会主义好青年\n");
	} else if (choice[0]=='B'){
		player1.money+=getmoney;
		printf("现在你有%d块钱\n",player1.money);	
	}											
	
			fflush(stdin);
			scanf("continue");
			fflush(stdin);
	if(seventeen==0){	
		printf("你走着走着，迎面撞上一个穿法师长袍的人\n") ;
		printf("他见到你后，手中突然出现一个火球，面色不善\n");
			fflush(stdin);
			scanf("continue");
			fflush(stdin);
		printf("你暗骂一声，妈的还真会搓火球\n");
		printf("不知为何他明显对你很有敌意\n");
		printf("你选择 A话不多说，揍他   B与他交涉  \n");
		
		fflush(stdin);
		scanf("%s",&choice[0]);
		fflush(stdin);
			//被烧死结局 
		if(choice[0]=='A'){
			printf("在你向他挥起拳头一秒后，你被烧的灰都不剩 \n");
			printf("在这短暂的一秒内，你唯一想到的就是冰块\n") ;
				fflush(stdin);
				scanf("continue");
				fflush(stdin);
					goto ending ;
		} else if (choice[0]=='B')
		
		{
			printf(" 你让他住手，问他为什么要找你麻烦\n");	
				fflush(stdin);
				scanf("continue");
				fflush(stdin);
			printf("你说你抢占了他的生存空间\n你很不理解\n");
			printf("他说:你自己去问作者去吧\n");
				fflush(stdin);
				scanf("continue");
				fflush(stdin);
			printf("然后他抢了你50块钱说要买汽油，就走了\n");
			   player1.money-=50;
			   printf("你还剩%d块钱\n",player1.money);
			   	fflush(stdin);
				scanf("continue");
				fflush(stdin);
		}
	}
	if(seventeen==1){
		
	printf("第二天，seventeen约你去看电影\n");
	printf("你们的欢笑声从电影院流转到装饰很精致的小餐厅\n");
			fflush(stdin);
			scanf("continue");
			fflush(stdin);	
	printf("你们躲在公交车后座接吻\n");
	printf("接下来的几天你都和seveteen呆在一起\n");
			fflush(stdin);
			scanf("continue");
			fflush(stdin);
	printf("你们漫无目的的逛街，只为了牵着手\n");
	printf("除了彼此融化在一起，你别无所求\n");
			fflush(stdin);
			scanf("continue");
			fflush(stdin);
			
	printf("在你享受你的小甜蜜之际，\n网上一条新闻吸引了你的注意\n");
	fflush(stdin);
			scanf("continue");
			fflush(stdin);
	printf("网上有人要去猎杀龙，寻求组队\n");
	fflush(stdin);
			scanf("continue");
			fflush(stdin);
	printf("难道真的有龙？\n前两天你遇到的龙又是怎么回事？\n");
	fflush(stdin);
			scanf("continue");
			fflush(stdin);
		printf("你决定 A享受现在的生活   B去探寻龙的真相  \n");
	
	fflush(stdin);
	scanf("%s",&choice[0]);
	fflush(stdin);
	
	if(choice[0]=='A'){			//happy ending
	
		printf("你把新闻抛到脑后，\n继续你简单而幸福的生活 \n");
			fflush(stdin);
			scanf("continue");
			fflush(stdin);
		printf("大学毕业后，\n你找了份还算体面的工作\n");
		printf("你与seventeen组成了令人羡慕的家庭，\n你们有一儿一女，他俩都很可爱\n");
			fflush(stdin);
			scanf("continue");
			fflush(stdin);
		printf("很多年后，你对seventeen说，\n你们第一次相遇那天,你们就是最美的画\n");
		goto ending;
		}else {
		
		printf("你选择了这条不知通向哪里的路\n");
		printf("那天下午，你与家人，与seventeen告别，踏上了这段旅程\n");
		if(neighbor==1){
			getmoney = rand()%30+30;
			player1.money-=getmoney;
			printf("由于前几天早晨你无视了邻居，他怀恨在心，见到你时抢走了你%d块钱\n",getmoney);
			printf("你还剩%d\n",player1.money);
			 
		}
			fflush(stdin);
			scanf("continue");
			fflush(stdin);
		
		}
	} 
	else if (seventeen == 0){
	
		
		printf("在你无所事事之际，\n网上一条新闻吸引了你的注意\n");
		fflush(stdin);
				scanf("continue");
				fflush(stdin);
		printf("网上有人要去猎杀龙，寻求组队\n");
		fflush(stdin);
				scanf("continue");
				fflush(stdin);
		printf("难道真的有龙？\n前两天你遇到的龙又是怎么回事？\n");
		fflush(stdin);
				scanf("continue");
				fflush(stdin);
			printf("你决定 A继续现在的生活   B去探寻龙的真相  \n");
		
					fflush(stdin);
			scanf("%s",&choice[0]);
			fflush(stdin);
			
			if(choice[0]=='A'){
				printf("大学毕业后，你找了份普通的工作\n");
				printf("通过相亲促成不咸不淡的婚姻\n");
					 fflush(stdin);
					scanf("continue");
					fflush(stdin);
				printf("生活平淡如水，不说痛苦，也很少快乐\n");
						goto ending ; 
			} else{
						printf("你选择了这条不知通向哪里的路\n");
				printf("那天下午，你与家人朋友告别，踏上了这段旅程\n");
				if(neighbor==1){
				getmoney = rand()%30+30;
				player1.money-=getmoney;
				printf("由于前几天早晨你无视了邻居，他怀恨在心，见到你时抢走了你%d块钱\n",getmoney);
				printf("你还剩%d\n",player1.money);
				}
					fflush(stdin);
					scanf("continue");
					fflush(stdin);
			}
		}
				//dragon、 plateau
		printf("猎龙队伍的队长告诉你你们要去的地方叫dragon plateau\n");
		printf("你根本没听说过这地方\n");
					fflush(stdin);
					scanf("continue");
					fflush(stdin);
		printf("队长说他也没听说的，像是一夜之间突然出现的地方\n");
		printf("这事让人越发不明白\n");
					fflush(stdin);
					scanf("continue");
					fflush(stdin);
		if(dragonthing==1){			//internal	thing
			printf("当队友们发现你竟然有龙内脏，都很震惊\n");
			printf("你也很惊讶，他们竟然都没见过龙\n") ;
				fflush(stdin);
					scanf("continue");
					fflush(stdin);
			printf("他们只是不知从哪听说听说龙的事情，就要去捕猎\n");
			printf("你觉得他们不靠谱\n");
				fflush(stdin);
					scanf("continue");
					fflush(stdin);
			printf("队长说他想用他的Feather Of Sparrow 换你的Internal Of Dragon\n");
				
					printf("你对他说 A滚你妈的    B不换，可以1000卖给你 \n");
	
					fflush(stdin);
					scanf("%s",&choice[0]);
					fflush(stdin);
					
					if(choice[0]=='A'){
					
						printf("你和队长打了一架，然后你们决定用猜数字游戏解决问题\n");
								fflush(stdin);
								scanf("continue");
								fflush(stdin);
						if(numberguess()<=3){
						printf("你赢了，不仅守住了龙内脏，还赢得了麻雀羽毛\n");
						}else {
							printf("你用了超过三次才猜到\n你不仅输掉了龙内脏，还输掉了尊严\n");
						}
					} else if (choice[0]=='B'){
						player1.money+=1000;
						printf("队长爽快答应了，你现在有%d块钱\n",player1.money);	
					}
				}	
							fflush(stdin);
								scanf("continue");
								fflush(stdin);
		printf("经过几天的行程，你们终于到达了目的地\n");
		printf("四周都是龙，看到这么多龙大家都目瞪口呆\n");
						fflush(stdin);
						scanf("continue");
						fflush(stdin);
		printf("你不知为何，总感觉这些龙像是有人在驯养\n");
						fflush(stdin);
						scanf("continue");
						fflush(stdin);
		printf("前面有家武器商店，也许你可以买点什么\n");
					fflush(stdin);
						scanf("continue");
						fflush(stdin);
		printf("--------------------------------------------------------------------\n");
		printf("大血瓶(回复200点生命)50000元        小血瓶(增加5点当前生命)30000元\n");
		printf("             大宝剑(增加30点攻击力)100000元\n") ;
		printf("             厚铠甲(增加20点防御力)100000元\n");
		printf("---------------------------------------------------------------------\n");
						fflush(stdin);
						scanf("continue");
						fflush(stdin);
		printf("你现在有%d块钱\n",player1.money);
		printf("你觉得你能买得起什么？\nA Nothing B Nothing\n\n");
						fflush(stdin);
				scanf("%s",&choice[0]);
				fflush(stdin);
				
			printf("是的，你什么都买不起\n");
					
		printf("再往前走，你看到了.....\n");
						fflush(stdin);
						scanf("continue");
						fflush(stdin);
		printf("高数老师？？！！\n");
						fflush(stdin);
						scanf("continue");
						fflush(stdin);
		printf("高数老师说：没想到被你们发现了\n");
		printf("这些龙是我养来喷火好供我烧烤的\n");
						fflush(stdin);
						scanf("continue");
						fflush(stdin);
		printf("虽然不知道数学老师怎么找到龙的\n");
		printf("但，无论如何。天哪，烧烤，数学老师竟然这么残忍\n");
		printf("你必须拯救这些精灵\n");
							fflush(stdin);
						scanf("continue");
						fflush(stdin);
		printf("Reincarnation! 老师喊道\n");
				fflush(stdin);
						scanf("continue");
						fflush(stdin);
		printf("一道红光袭来，很快，你知道这很危险\n");
		printf("于是你选择 A被它击中   B不被它击中\n");
					fflush(stdin);
					scanf("%s",&choice[0]);
					fflush(stdin);
					
					if(choice[0]=='A'){
					
						printf(" 你被击中了\n");
								fflush(stdin);
						scanf("continue");
						fflush(stdin);
						goto start;
					} else if (choice[0]=='B'){
						printf(" 你没被击中，好危险\n");
						printf("有的队友被击中了，一下就不见了\n")	;
								fflush(stdin);
								scanf("continue");
								fflush(stdin);
					}
		printf("紧接着，数学老师扑了过来！\n") ;
		printf("你明白，最后的战役打响了\n");
					fflush(stdin);
					scanf("continue");
					fflush(stdin);
			    int final =finalfight();
		if(final==0){
			printf("虽然你死了，但倒下的一刻，你看到你的队友前赴后继迎战\n");
			printf("你明白，你们赢了，你们阻止了老师利用龙来烧烤的可怕计划\n");
				fflush(stdin);
					scanf("continue");
					fflush(stdin);
			printf("一切都是值得的"); 
			goto ending;	
		} else{
			printf("看着数学老师倒下，\n");
			printf("你明白你们胜利了，老师再也不能利用龙来烧烤\n");
				fflush(stdin);
					scanf("continue");
					fflush(stdin);
			
			printf("胜利的欢呼声传开\n") ;
			printf("你热泪盈眶\n");
				fflush(stdin);
					scanf("continue");
					fflush(stdin);
					goto ending; 
			
		} 
			
		
			// this is the end												
} 							
else if (status[0]=='B'){		//职员主线    不写了 
		printf("作者好累啊，不想写职员的故事线了，你去玩学生线吧。\n");
		printf("A好的     B不行，我今天一定要玩这条线\n")	;
		fflush(stdin);
		scanf("%s",&choice[0]);
		fflush(stdin);
		if(choice[0]=='A'){
			printf("\n\n");
			goto start;
		} else{
			printf("行吧，既然你执意的话,(按回车键继续)\n") ;
				fflush(stdin);
				scanf("continue");
				fflush(stdin);
			printf("你是一名普通公司职员,\n有一天你坐时光机回到了学生时代\n");
			printf("(按回车键继续)\n\n"); 
			fflush(stdin);
			scanf("continue");
			fflush(stdin);
			goto start;
		}
	}												
else if (status[0]=='C'){		//法师主线   也不写了妈蛋 
		printf("作者好累啊，不想写法师的故事线了，你去玩学生线吧。\n");
	printf("A好的     B不行，我今天一定要玩这条线\n")	;
			fflush(stdin);
			scanf("%s",&choice[0]);
			fflush(stdin);
	if(choice[0]=='A'){
		choose(); 
		goto start;
	} else{
		printf("行吧，既然你执意的话,");
		printf("(按回车键继续)\n"); 
			fflush(stdin);
			scanf("continue");
			fflush(stdin);
		printf("你是一个厉害的法师\n有一天你被人剥夺了法力然后扔进时光机回到了学生时代\n");
			fflush(stdin);
			scanf("continue");
			fflush(stdin);	
		goto start;
	}

}					
else {			//主线没选 
	printf("\n关了吧没意思"); 
}
ending:
printf("\n\n");
printf("END\n(按回车键结束)");
fflush(stdin);
scanf("end");
return 0 ;


}
////////////main 

///////////other functions
int numberguess()
{
	srand(time(0));
	int number = rand()%10+1;
	int count = 0 ;
	int a = 0;
	printf("我想好了一个1-10之间的数，三次及以内猜对就算你赢\n");
	
		printf("来猜吧\n");
	do{	scanf("%d",&a);
		count++;
		if(a>number){
			printf("你猜的大了\n"); 
		} else if (a<number){
			printf("你猜的小了\n"); 
		}
	} while(a!=number);
	printf("你猜对了\n");
	return count; 
}

int dragonfight(void){
	int boc = 10;    // blood of character
	int bod = 10;    //blood of dragon
	int turn = 0;
	char moc[3] ; 	//move of character
	int mod =0;     // move of dragon
	int end = 1;   //1-win ; 0-death ; 2-escape
	srand(time(0));
	printf("\n\n---------龙之战-----------\n\n");
	printf("\n你和龙都有10滴血，掉光就死了\n");
	printf("龙会干的事有 打你(让你-1血)、使劲打你(让你-3血)和愤怒咆哮(没什么用)\n\n");
	
	do {	//每回合内容 
	turn++; 
	printf("第%d回合\n",turn);
			//玩家动作 
	printf("你选择： A拿匕首戳龙(使龙-2血)   B防御(本回合不受伤)   C逃跑(离开战场)\n");
	fflush(stdin);
	scanf("%s",&moc[0]);
	if(moc[0]=='C'){		//只要逃跑就不用进行下面的了 
		end = 2;		
		printf("你逃掉了，心有余悸\n"); 
		break;								
	}
				//龙动作 
	mod = rand()%3;
	printf("\n");
	if (mod ==0 ){								
		printf("龙决定打你一下(-1)\n"); 
	}else if (mod == 1 ){
		printf("龙决定使劲打你一下(-3)\n");
	}else {
		printf("龙愤怒的咆哮了一声\n"); 
	} 
			//结果计算 
	if (moc[0]=='A'){	//玩家选A龙-2，玩家受龙伤害；玩家选B一定什么都没发生；玩家选C上面已经break了； 
		bod-=2;
		if(mod == 0){
			boc-=1;
		}else if (mod==1){
			boc -= 3;
		}
	} 
			//输出本回合结果 
	printf("经过这回合,你还剩%d滴血，龙还剩%d滴血\n\n",boc,bod); 
			fflush(stdin);
			scanf("continue");
			fflush(stdin);
 }while((boc>0)&&(bod>0)); 
 	if(boc<=0){
 		printf("你死了。。\n");
		end = 0; 
	 }else if(bod<=0){
	 	printf("你赢了！\n"); 	
	 }
		fflush(stdin);
		scanf("continue");
		fflush(stdin);
	 return end;
}

void choose(void)
{
	/************ mould of choosing******************
	 
	printf(" A   B  \n");
	
	fflush(stdin);
	scanf("%s",&choice[0]);
	fflush(stdin);
	
	if(choice[0]=='A'){
	
		printf(" \n");
	} else if (choice[0]=='B'){
		printf(" \n");	
	}
	
	**************************************************/
	printf("\n");
}

void singer(void){
	printf("你接受了他的提议\n你努力唱歌，迅速走红\n");
	printf("收获了很多钱，名声，粉丝，追捧，还有非议与谩骂\n");
	fflush(stdin);
		scanf("continue");
		fflush(stdin);
		printf("\n");
	printf("有时，你也在怀念自己唱《两只老虎》或者《小星星》时单纯的简单的快乐\n");
} 



int finalfight(void)
{
	int boc =  12;         // blood of character
	int bom = 20;        //blood of mathteacher
	int turn = 0;
	char moc[3] ; 			//move of character
	int mom =0;       // move of mathteacher
	int end = 1;   //1-win ; 0-death 
	srand(time(0));
	printf("\n\n--------------老师之战----------------\n\n");
	printf("\n你只有12血，老师有20血\n");
	printf("老师会干的事有 打你(让你-1血)、使劲打你(让你-2血)和愤怒地念公式(没什么用)\n\n");
	
	do {		//每回合内容 
	turn++; 
	printf("第%d回合\n",turn);
			//玩家动作 
	printf("你选择： A拿匕首戳老师(使龙-2血)   B防御(本回合不受伤) \n");
	fflush(stdin);
	scanf("%s",&moc[0]);
			//math move
	mom = rand()%3;
	printf("\n");
	if (mom ==0 ){								
		printf("老师决定打你一下(-1)\n"); 
	}else if (mom == 1 ){
		printf("老师决定使劲打你一下(-2)\n");
	}else {
		printf("老师愤怒的念了个公式\n"); 
	} 
			//结果计算 
	if (moc[0]=='A'){	//玩家选A老师-2，玩家受伤害；玩家选B一定什么都没发生；
		bom-=2;
		if(mom == 0){
			boc-=1;
		}else if (mom==1){
			boc -= 2;
		}
	} 
			//输出本回合结果 
	printf("经过这回合,你还剩%d滴血，老师还剩%d滴血\n\n",boc,bom); 
			fflush(stdin);
			scanf("continue");
			fflush(stdin);
 }while((boc>0)&&(bom>0)); 
 	if(boc<=0){
 		printf("你死了\n");
		end = 0; 
	 }else if(bom<=0){
	 	printf("你赢了！\n"); 	
	 }
		fflush(stdin);
		scanf("continue");
		fflush(stdin);
	 return end;
}

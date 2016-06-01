#include <windows.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include "SeqList.h"
#include "file.h"
# define MaxSize 200

int PASS;														  //定义全局变量          
SeqList queueList;
//ListInitiate(&queueList);

int num1=0;														  //订票客户人数
int num2=0;														  //排队客户人数   

void menu();													  //菜单函数原型声明
void scline();													  //查询航线信息原型声明
void order();													  //订票函数原型声明
void tuipiao();													  //退票函数原型声明
void sccli();													  //查询订票客户名单原型声明
void scque();													  //查询排队客户名单原型声明
void back();													  //退出函数原型声明
void passde();												      //登录密码函数原型声明

createFile(struct client cli[]);								  //建立初始的数据文件
createFilewait( struct queuecli wait[ ]);						  //建立初始的数据文件


void menu()														  //菜单函数
{
    char c;
    printf("\n\n                              航空订票系统菜单          \n");
	printf("\n  ☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆\n");
	printf("\n     ◇ 1 查询航线\n");
    printf("\n     ◇ 2 查询订票客户名单\n");
	printf("\n     ◇ 3 查询等候替补客户名单\n");
	printf("\n     ◇ 4 订票\n");
	printf("\n     ◇ 5 退票\n");
	printf("\n     ◇ 6 退出\n");
    printf("\n  ☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆\n");
	printf("\n\n请选择功能选项（1-6）:[  ]\b\b\b ");
		
	switch(c=getch())
	{
	case 49: scline();break;										//输入1执行case49
    case 50: sccli();break;											//输入2执行case50
    case 51: scque();break;											//输入3执行case51
	case 52: order();break;											//输入4执行case52
	case 53: tuipiao();break;										//输入5执行case53
	case 54: exit(0);break;											//输入6执行case54
	default:printf("\n\n*****输入错误！*****\n");system("cls");back(); //不在上述情况中时执行default语句
	}	
}

void scline()														//查询航线信息
{   int i;															//定义变量i代表航班号
	int city;                  
	printf("\n\n                         航空订票系统->航线查询         \n");
	printf("\n  **********************************************************************\n");

shuru:	printf("\n请选择终点站:[  ]\b\b\b\n");
	readtxt1();														//调用读出文件函数
    scanf("%d",&city);                                              //输入城市编号
	if(city>0&&city<21)												//控制城市为文件中的20个城市
	{   
		printf("\n查询结果：\n");
		printf("\n终点站：\n");
	    switch(city)												//switch语句判断输入的城市编号

		{
        case 1: printf("北京\n\n");break;
        case 2: printf("上海\n\n");break;
        case 3: printf("南京\n\n");break;
		case 4: printf("长沙\n\n");break;
        case 5: printf("拉萨\n\n");break;
        case 6: printf("广州\n\n");break;
		case 7: printf("深圳\n\n");break;
        case 8: printf("武汉\n\n");break;
        case 9: printf("苏州\n\n");break;
		case 10: printf("成都\n\n");break;
        case 11: printf("重庆\n\n");break;
        case 12: printf("厦门\n\n");break;
		case 13: printf("合肥\n\n");break;
        case 14: printf("南昌\n\n");break;
        case 15: printf("天津\n\n");break;
		case 16: printf("西安\n\n");break;
        case 17: printf("兰州\n\n");break;
        case 18: printf("昆明\n\n");break;
        case 19: printf("大理\n\n");break;
        case 20: printf("香港\n\n");break;
		}
        printf("航班号   飞机号     飞机周日	起飞时间   到达时间   余票量\n");
		for(i=0;i<26;i++)
		{
			if(fliinfo[i].city==city)								//判断航班号是否超出范围
				printf("\n  %d	  %s %13s	%s      %s       %d\n",fliinfo[i].flinum,fliinfo[i].planenum,fliinfo[i].week,fliinfo[i].starttime,fliinfo[i].endtime,fliinfo[i].overplus);
		}


	}
	else
	{
        printf("\n*****输入错误！请重新选择！*****\n");				//显示输入错误
	    goto shuru;
    }
    back();															//调用退出函数
	
}
	
void order()														//订票函数
{   QueuecliType s;                         
	int m,n,level,op,levelmax,p,i;
    printf("\n\n                            航空订票系统->订票          \n");
	printf("\n  **********************************************************************\n");

shuru:	printf("请输入航班号（1-26）:[  ]\b\b\b");
	scanf("%d",&m);													//输入订票航班号
	if(m>0&&m<27)													//判断航班号是否超出范围
	{
	printf("\n请输入您要订票的数量:[  ]\b\b\b");
	scanf("%d",&n);													//输入订票数量
	printf("\n请输入您订票的舱位等级（1-3）:[  ]\b\b\b");
	scanf("%d",&level);												//输入舱位等级
	switch(level)
	{
	case 1:{levelmax=fliinfo[m-1].levelone;op=fliinfo[m-1].opone;}break;//一等舱情况
    case 2:{levelmax=fliinfo[m-1].leveltwo;op=fliinfo[m-1].optwo;}break;//二等舱情况
    case 3:{levelmax=fliinfo[m-1].levelthree;op=fliinfo[m-1].opthree;}break;//三等舱情况
	}
     
	if(n<=op)
	{   cli[num1].flinum=m;											//登记订票客户信息                                
	    cli[num1].tickets=n;										//登记需求票量
	    cli[num1].level=level;										//登记需求舱位等级
		printf("\n请输入您的姓名： ");
		scanf("%s",&cli[num1].name);								//输入姓名
		printf("\n请输入您的身份证号码： ");
		scanf("%s",&cli[num1].id);									//输入身份证号
	    num1=num1+1;
		saveFileCli(cli,1);											//保存在文件中
		printf("\n\n订票成功！\n\n");
		printf("您的预订票舱位等级：%d\n",level);
		printf("\n您的座位号： ");
		for(i=1;i<=n;i++)
			printf("%d   ",(levelmax-op)+i);						//输出座位号
		switch(level)
		{
		case  1: fliinfo[m-1].opone=fliinfo[m-1].opone-n;break;
        case  2: fliinfo[m-1].optwo=fliinfo[m-1].optwo-n;break;
        case  3: fliinfo[m-1].opthree=fliinfo[m-1].opthree-n;break;
		}
		fliinfo[m-1].overplus=fliinfo[m-1].opone+fliinfo[m-1].optwo+fliinfo[m-1].opthree;

	}
	else
	{
		printf("\n*****对不起！余票量少于您的订票额！*****\n\n");
		printf("是否登记排队候补（1 是  2 否 ）:[  ]\b\b\b");
		scanf("%d",&p);												 //输入1或2

		if(p==1)
		{
			s.flinum=m;												 //登记排队客户信息
            s.demand=n;											 	 //登记需求票量
			s.level=level;											 //登记需求舱位等级
            printf("\n请输入您的姓名： ");
		    scanf("%s",&s.name);
		    printf("\n请输入您的身份证号码： ");
		    scanf("%s",&s.id);
			ListInsert(&queueList,num2,s);							 //在顺序表queueList中插入一条记录
			printf("\n请再次确认信息！请输入--\n");
			readwait(wait,1);
			saveFileWait(wait,1);									 //将结构体数组的内容写入文件
		    printf("\n\n★★★★★排队登记成功！★★★★★\n\n");
			num2++;          
		}
		
	}
	back();															 //调用退出函数
	
	}
	else
	{
        printf("\n*****输入错误！请重新选择！*****\n");
	    goto shuru;
	}  
}


void tuipiao()													     //退票函数
{   
	char a[20],b[20];
    int c,i,j,p,opl;
	int t;
	int flag=0;													    //查看是否有退票人记录的标志
	int flag2=0;												    //查看是否有等候替补客户预定已退票的标志
	QueuecliType k;
	printf("\n                            航空订票系统->退票          \n");
	printf("\n  **********************************************************************\n");

	printf("\n请输入您的姓名： ");
	scanf("%s",&a);												   //输入客户姓名
	printf("\n\n请输入您的身份证号码： ");
	scanf("%s",&b);												   //输入客户身份证号
    printf("\n\n请输入您要退票的航班号（1-8）:[  ]\b\b\b");
	scanf("%d",&c);												   //输入航班号
    printf("\n\n您的订票信息：\n");
	printf("\n航班号	订票量	舱位等级\n");
    for(t=0;t<num1;t++)
	if(c==cli[t].flinum&&strcmp(b,cli[t].id)==0)
	{printf("%d	%d	%d\n",c,cli[t].tickets,cli[t].level);		   //输出客户之前的订票信息
	 flag=1;
	}
	if(flag==0)
	{
		printf("\n\n没有您的订票记录！\n"); 
	        back();												   //调用退出函数                       
	} 
	 else printf("\n\n您确定要退票？（1是 2否）:[  ]\b\b\b");
          scanf("%d",&p);										   //输入1或2
	if(p==1)
	{
	
   	for(i=0;i<num1;i++)
	{
		if(c==cli[i].flinum&&strcmp(b,cli[i].id)==0)
		{
			switch(cli[i].level)								   //根据之前订的票的舱位等级删除订票记录
			{
			case 1: {fliinfo[c-1].opone=fliinfo[c-1].opone+cli[i].tickets;  //退一等舱的票
				     fliinfo[c-1].overplus=fliinfo[c-1].overplus+cli[i].tickets;
					 opl=fliinfo[c-1].opone;
					}break;
			case 2: {fliinfo[c-1].optwo=fliinfo[c-1].optwo+cli[i].tickets; //退二等舱的票
				     fliinfo[c-1].overplus=fliinfo[c-1].overplus+cli[i].tickets;
					 opl=fliinfo[c-1].optwo;
					}break;
			case 3: {fliinfo[c-1].opthree=fliinfo[c-1].opthree+cli[i].tickets;//退三等舱的票
				     fliinfo[c-1].overplus=fliinfo[c-1].overplus+cli[i].tickets;
					 opl=fliinfo[c-1].opthree;
					}break;
			}
			cli[i].flinum=-1;									  //退票客户航班号置-1，表示已删除  
		}

  loop:			for(j=0;j<num2;j++)
			{
				if(c==queueList.list[j].flinum&&opl>=queueList.list[j].demand&&cli[i].level==queueList.list[j].level)
				{
				    cli[num1].flinum=queueList.list[j].flinum;    //将退的票给排队客户
                    strcpy(cli[num1].id,queueList.list[j].id);
                    cli[num1].level=queueList.list[j].level;
                    strcpy(cli[num1].name,queueList.list[j].name);
                    cli[num1].tickets=queueList.list[j].demand;
					num1++;
                    ListDelete(&queueList,j,&k);				  //在顺序表queueList中删除一条记录
					 num2--;
					 flag2=1;									  //退的票被排队客户预定标志位置1
					 
					 goto loop;

				}
			}


	}
	if(flag2==0)
	{
		printf("\n\n★★★★★退票成功！★★★★★\n\n");
		printf("\n★★★★★没有等候替补客户预定！★★★★★\n\n");
		back();													 //调用退出函数
	}
	else 
	{
		printf("\n\n★★★★★退票成功！★★★★★\n\n");
		printf("\n★★★★★您的退票已被等候替补客户预定！★★★★★\n\n");
        back();													 //调用退出函数

	}

	}
	else  back();												 //调用退出函数
 
}


void sccli()                                                     //查询订票客户名单
{      int p,i,j; 
       int flag=0;												 //查看是否有订票人记录的标志                                             
	   printf("\n\n\n                     航空订票系统->查询订票客户名单          \n");
	   printf("\n  **********************************************************************\n");
	   printf("\n查询本次操作订票客户请输入1，查询以前的订票客户名单请输入2\n");
	   scanf("%d",&j);											 //输入1或2

		if(j==1)
		{
            printf("\n请输入要查询的航班号（1-26）:[  ]\b\b\b");
        scanf("%d",&p);											 //输入航班号
		if(p>0&&p<27)
		{
	    printf("\n\n航班号：%d\n\n",p);
	    printf("订票客户名单：\n");
		printf("\n姓名		订票量		舱位等级\n");
		for(i=0;i<num1;i++)
			if(p==cli[i].flinum)                                 //判断是否已定过航班号
			{
				printf("%s		%d		%d\n",cli[i].name,cli[i].tickets,cli[i].level);
				flag=1;
			}
			if(flag==0)
				printf("\n*****无记录！*****\n");
		}
		else printf("\n\n*****输入航班号错误！*****\n\n");
		back();													 //调用退出函数
		}
		else readtxt2();										 //调用读出文件函数		
		back();													 //调用退出函数
	
}



	

void scque()													//查询排队客户名单
{
		int p,i,j;
		int flag=0;												//查看是否有排队人记录的标志
		printf("\n\n\n                      航空订票系统->查询排队客户名单          \n");
  	    printf("\n  **********************************************************************\n");
		printf("\n查询本次操作排队客户请输入1,查询以前的排队客户名单请输入2\n");
		  scanf("%d",&j);										//输入1或2
		printf("\n\n请输入要查询的航班号（1-26）:[  ]\b\b\b");
        scanf("%d",&p);											//输入航班号
		if(j==1)
		{
		if(p>0&&p<27)											//判断航班号输入是否正确
		{
	    printf("\n\n航班号：%d\n\n",p);
	    printf("等候替补客户名单：\n");
		printf("\n姓名		需求量		舱位等级\n");
		for(i=0;i<num2;i++)
		
			if(p==queueList.list[i].flinum)						 //判断是否有排队记录
			{
				printf("%s		%d		%d\n",queueList.list[i].name,queueList.list[i].demand,queueList.list[i].level);//输出排队客户信息
				flag=1;
			}
			if(flag==0)
				printf("\n*****无记录！*****\n");
		} 
		else printf("\n\n*****输入航班号错误！*****\n\n");
		back();													 //调用退出函数
		}
		else readtxt3();										 //调用读出文件函数
		back();													 //调用退出函数

} 


void back()
{
	printf("\n\n《《《《《《任意键返回菜单页！》》》》》》\n");
    getch();													 //输入字符
	system("cls");												 //清屏
	menu();														 //菜单函数调用
}
void passde()													 //登录密码函数
{
	int ture;													 //定义密码变量
	printf("请输入密码！\n");
	scanf("%d",&PASS);											 //输入密码
	ture=123456;												 //设定登录密码为123456
	if(PASS==ture)												 //判断密码是否正确
	{
		printf("登入成功！\n");									 //输出登入成功
	}
	else
	{
		printf("密码错误！\n");								   	 //输出密码错误
		exit(0); 
	}
}


void main()
{
	system("Color f0");											 //将运行界面底色改为白色
	printf("\n                            欢迎进入航空订票系统！ \n");
	passde();													 //登录密码函数调用
    menu();														 //菜单函数调用
}

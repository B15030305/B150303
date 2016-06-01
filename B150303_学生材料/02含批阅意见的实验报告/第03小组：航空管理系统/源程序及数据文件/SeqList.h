//#include<stdio.h>
//#include<stdlib.h>
typedef struct queuecli         //等候替补客户信息
{
	int flinum;                 //航班号
    char name[20];            //客户姓名
    char id[20];              //客户ID
	int  demand;               //需求数量
	int  level;                //舱位等级
}QueuecliType;


struct queuecli wait[100];

typedef struct
{
	struct queuecli list[200];
	int size;
}SeqList;


struct fliinfo          //航班信息
{
	int city;					//目的地
	int flinum;					//航班号
    char planenum[10];         //飞机型号
    char week[10];               //星期几飞行
    int  maxnum;               //成员定额
    int  overplus;             //余票量
    int  levelone;             //一等舱座位数量
    int  opone;                //一等舱余票量
    int  leveltwo;             //二等舱座位数量
    int  optwo;                //二等舱余票量
    int  levelthree;           //三等舱座位数量
    int  opthree;              //三等舱余票量
   char  starttime[7];			//起飞时间
   char  endtime[7];			//到达时间

}fliinfo[26]={
{1,1,"737","MONDAY",120,120,10,10,20,20,90,90,"09:50","12:15"},
{1,2,"K320","WEDNESDAY",120,120,10,10,20,20,90,90,"15:00","17:30"},
{1,3,"737","FRIDAY",120,120,10,10,20,20,90,90,"13:25","15:55"},
{2,4,"757","TUESDAY",120,120,10,10,20,20,90,90,"10:15","11:45"},
{4,5,"737","SATURDAY",120,120,10,10,20,20,90,90,"14:45","16:00"},
{2,6,"K320","THURSDAY",120,120,10,10,20,20,90,90,"20:10","21:30"},
{3,7,"737","WEDNESDAY",120,120,10,10,20,20,90,90,"11:30","12:30"},
{3,8,"737","SUNDAY",120,120,10,10,20,20,90,90,"17:25","18:30"},
{4,9,"737","MONDAY",120,120,10,10,20,20,90,90,"10:50","12:15"},
{5,10,"K320","WEDNESDAY",120,120,10,10,20,20,90,90,"14:00","17:30"},
{6,11,"737","FRIDAY",120,120,10,10,20,20,90,90,"13:45","15:55"},
{7,12,"757","TUESDAY",120,120,10,10,20,20,90,90,"10:40","11:45"},
{8,13,"737","SATURDAY",120,120,10,10,20,20,90,90,"13:45","16:00"},
{9,14,"K320","THURSDAY",120,120,10,10,20,20,90,90,"20:00","21:30"},
{10,15,"737","WEDNESDAY",120,120,10,10,20,20,90,90,"11:30","12:50"},
{11,16,"737","FRIDAY",120,120,10,10,20,20,90,90,"13:25","15:20"},
{12,17,"757","TUESDAY",120,120,10,10,20,20,90,90,"9:15","11:45"},
{12,18,"737","SATURDAY",120,120,10,10,20,20,90,90,"13:45","16:00"},
{13,19,"K320","THURSDAY",120,120,10,10,20,20,90,90,"20:10","23:30"},
{14,20,"737","WEDNESDAY",120,120,10,10,20,20,90,90,"12:30","17:30"},
{15,21,"737","FRIDAY",120,120,10,10,20,20,90,90,"13:10","16:55"},
{16,22,"757","TUESDAY",120,120,10,10,20,20,90,90,"12:15","14:45"},
{17,23,"737","SATURDAY",120,120,10,10,20,20,90,90,"16:45","17:55"},
{18,24,"K320","THURSDAY",120,120,10,10,20,20,90,90,"22:10","24:00"},
{19,25,"737","WEDNESDAY",120,120,10,10,20,20,90,90,"11:30","12:30"},
{20,26,"737","WEDNESDAY",120,120,10,10,20,20,90,90,"14:30","16:30"},
};

typedef struct client              //订票客户信息
{
	int  flinum;            //航班号
    char name[20];         //客户姓名
	char  id[20];          //客户ID
    int  tickets;         //订票数量
    int  level;            //舱位等级
}client;
struct client  cli[200];

int readcli(struct client cli[],int n)          /*读入订票*/
{
	int i;
	for (i=0;i<n;i++)
	{
		printf("Input one client\'s information\n");
		printf("flinum:  ");
	    scanf("%ld", &cli[i].flinum);
		printf("name: ");
		scanf("%s",&cli[i].name);	
		printf("id:  ");
		scanf("%s",&cli[i].id);
		printf("tickets: ");
		scanf("%d",&cli[i].tickets);	
		printf("level:  ");
		scanf("%d",&cli[i].level);
		break;
	}
	   	return i;                         /*返回实际读入的记录条数*/
}

int readwait(struct queuecli wait[],int n)          /*读入待订票*/
{
	int i;
	for (i=0;i<n;i++)
	{
		printf("Input one client\'s information\n");
		printf("flinum:  ");
	    scanf("%ld", &wait[i].flinum);
		printf("name: ");
		scanf("%s",&wait[i].name);	
		printf("id:  ");
		scanf("%s",&wait[i].id);
		printf("tickets: ");
		scanf("%d",&wait[i].demand);	
		printf("level:  ");
		scanf("%d",&wait[i].level);
		break;
	}
	return i;                         /*返回实际读入的记录条数*/
}


void ListInitiate(SeqList *L)
{
	L->size=0;
}

int ListLength(SeqList L)
{
	return L.size;
}

int ListInsert(SeqList *L,int i,struct queuecli x)
{
	int j;
	if(L->size>=200)
	{
		printf("顺序表已满无法插入！\n");
		return 0;
	}
	else if(i<0||i>L->size)
	{
		printf("参数i不合法！\n");
		return 0;
	}
	else
	{
		for(j=L->size;j>i;j--)L->list[j]=L->list[j-1];
        L->list[i]=x;
        L->size++;
		return 1;
	}
}


int ListDelete(SeqList *L,int i,struct queuecli *x)
{
	int j;
	if(L->size<=0)
	{
		printf("顺序表已无数据可删！\n");
		return 0;

	}
	else if(i<0||i>L->size-1)
	{
		printf("参数i不合法！\n");
		return 0;
	}
	else 
	{
		*x=L->list[i];
		for(j=i+1;j<=L->size-1;j++)L->list[j-1]=L->list[j];
        L->size--;
		return 1;
	}
}






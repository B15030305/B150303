#include <stdio.h>
#include <stdlib.h>
int  createFile(struct client cli[])              /*建立初始的数据文件*/
{
	FILE *fp;
	int n;
   	if((fp=fopen("d:\\client.txt", "w")) == NULL) /*指定好文件名，以写入方式打开*/
	{
	    printf("can not open file !\n");         /*若打开失败，输出提示信息*/
	    exit(0);                           /*然后退出*/
    }
	printf("input clients\' information:\n");
	n=readcli(cli,26);                /*调用SeqList.h中的函数读数据*/
	fwrite(cli,sizeof(cli),1000,fp);                  /*将刚才读入的所有记录一次性写入文件*/
 	fclose(fp);                             /*关闭文件*/
	return n;
}

int  createFilewait(struct queuecli DataType[ ])              /*建立初始的数据文件*/
{
	FILE *fp;
	int n;
   	if((fp=fopen("d:\\DataType.txt", "w")) == NULL) /*指定好文件名，以写入方式打开*/
	{
	    printf("can not open file !\n");         /*若打开失败，输出提示信息*/
	    exit(0);                           /*然后退出*/
    	}
	printf("input waitpassengers\' information:\n");
	n=readwait(wait,100);                /*调用SeqList.h中的函数读数据*/
	fwrite(wait,sizeof(struct queuecli),100,fp);                  /*将刚才读入的所有记录一次性写入文件*/
 	fclose(fp);                             /*关闭文件*/
	return n;
}

void saveFileCli( struct client cli[],int n)                  /*将结构体数组的内容写入文件*/
{   			
  	FILE *fp;	
   	if((fp=fopen("d:\\client.txt", "a+")) == NULL) /*以写的方式打开指定文件*/
	{
		printf("can not open file !\n");           /*如果打开失败，输出提示信息*/
		exit(0);                            /*然后退出*/
	}
	fwrite(cli,sizeof(struct client),n,fp);        
	fclose(fp);                              /*关闭文件*/
}

void changeFile(struct client cli[],int n)                  /*将结构体数组的内容写入文件*/
{   			
  	FILE *fp;	
   	if((fp=fopen("d:\\client.txt", "a+")) == NULL) /*以读写的方式打开指定文件*/
	{
		printf("can not open file !\n");           /*如果打开失败，输出提示信息*/
		exit(0);                            /*然后退出*/
	}
	fwrite(cli,sizeof(struct client),n,fp);        
	fclose(fp);                              /*关闭文件*/
}


void saveFileWait(struct queuecli wait[],int n)                  /*将结构体数组的内容写入文件*/
{   			
  	FILE *fp;	
   	if((fp=fopen("d:\\DataType.txt", "a+")) == NULL) /*以写的方式打开指定文件*/
	{
		printf("can not open file !\n");           /*如果打开失败，输出提示信息*/
		exit(0);                            /*然后退出*/
	}	
	fwrite(wait,sizeof(struct queuecli),n,fp);        
	fclose(fp);                              /*关闭文件*/
}

void readtxt1()//读出C:\\city.txt中的内容
{
	FILE *fp;
	char ch;
	fp=fopen("C:\\city.txt","r");//打开文件
	if(fp==0)
	{
		printf("file error\n");//文件打开错误
		exit(1);
	}
	while ((ch=fgetc(fp))!=EOF)//判断是否读完
	{
		putchar(ch); //读出字符
	}
	putchar('\n');
	fclose(fp);//关闭文件
}

void readtxt2()//读出
{
	FILE *fp;
	char ch;
	fp=fopen("d:\\client.txt","r+");//读出乘客信息
	if(fp==0)
	{
		printf("file error\n");//文件打开错误
		exit(1);
	}
	while ((ch=fgetc(fp))!=EOF)//判断是否读完
	{
		putchar(ch);
	}
	putchar('\n');
	fclose(fp);//关闭文件
}

void readtxt3()//读出
{
	FILE *fp;
	char ch;
	fp=fopen("d:\\DataType.txt","r+");//候补
	if(fp==0)
	{
		printf("file error\n");//文件打开错误
		exit(1);
	}
	while ((ch=fgetc(fp))!=EOF)//判断是否读完
	{
		putchar(ch);
	}
	putchar('\n');
	fclose(fp);//关闭文件
}
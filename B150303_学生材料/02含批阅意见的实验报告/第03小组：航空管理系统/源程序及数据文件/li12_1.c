#include <windows.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include "SeqList.h"
#include "file.h"
# define MaxSize 200

int PASS;														  //����ȫ�ֱ���          
SeqList queueList;
//ListInitiate(&queueList);

int num1=0;														  //��Ʊ�ͻ�����
int num2=0;														  //�Ŷӿͻ�����   

void menu();													  //�˵�����ԭ������
void scline();													  //��ѯ������Ϣԭ������
void order();													  //��Ʊ����ԭ������
void tuipiao();													  //��Ʊ����ԭ������
void sccli();													  //��ѯ��Ʊ�ͻ�����ԭ������
void scque();													  //��ѯ�Ŷӿͻ�����ԭ������
void back();													  //�˳�����ԭ������
void passde();												      //��¼���뺯��ԭ������

createFile(struct client cli[]);								  //������ʼ�������ļ�
createFilewait( struct queuecli wait[ ]);						  //������ʼ�������ļ�


void menu()														  //�˵�����
{
    char c;
    printf("\n\n                              ���ն�Ʊϵͳ�˵�          \n");
	printf("\n  ������������������������������������\n");
	printf("\n     �� 1 ��ѯ����\n");
    printf("\n     �� 2 ��ѯ��Ʊ�ͻ�����\n");
	printf("\n     �� 3 ��ѯ�Ⱥ��油�ͻ�����\n");
	printf("\n     �� 4 ��Ʊ\n");
	printf("\n     �� 5 ��Ʊ\n");
	printf("\n     �� 6 �˳�\n");
    printf("\n  ������������������������������������\n");
	printf("\n\n��ѡ����ѡ�1-6��:[  ]\b\b\b ");
		
	switch(c=getch())
	{
	case 49: scline();break;										//����1ִ��case49
    case 50: sccli();break;											//����2ִ��case50
    case 51: scque();break;											//����3ִ��case51
	case 52: order();break;											//����4ִ��case52
	case 53: tuipiao();break;										//����5ִ��case53
	case 54: exit(0);break;											//����6ִ��case54
	default:printf("\n\n*****�������*****\n");system("cls");back(); //�������������ʱִ��default���
	}	
}

void scline()														//��ѯ������Ϣ
{   int i;															//�������i�������
	int city;                  
	printf("\n\n                         ���ն�Ʊϵͳ->���߲�ѯ         \n");
	printf("\n  **********************************************************************\n");

shuru:	printf("\n��ѡ���յ�վ:[  ]\b\b\b\n");
	readtxt1();														//���ö����ļ�����
    scanf("%d",&city);                                              //������б��
	if(city>0&&city<21)												//���Ƴ���Ϊ�ļ��е�20������
	{   
		printf("\n��ѯ�����\n");
		printf("\n�յ�վ��\n");
	    switch(city)												//switch����ж�����ĳ��б��

		{
        case 1: printf("����\n\n");break;
        case 2: printf("�Ϻ�\n\n");break;
        case 3: printf("�Ͼ�\n\n");break;
		case 4: printf("��ɳ\n\n");break;
        case 5: printf("����\n\n");break;
        case 6: printf("����\n\n");break;
		case 7: printf("����\n\n");break;
        case 8: printf("�人\n\n");break;
        case 9: printf("����\n\n");break;
		case 10: printf("�ɶ�\n\n");break;
        case 11: printf("����\n\n");break;
        case 12: printf("����\n\n");break;
		case 13: printf("�Ϸ�\n\n");break;
        case 14: printf("�ϲ�\n\n");break;
        case 15: printf("���\n\n");break;
		case 16: printf("����\n\n");break;
        case 17: printf("����\n\n");break;
        case 18: printf("����\n\n");break;
        case 19: printf("����\n\n");break;
        case 20: printf("���\n\n");break;
		}
        printf("�����   �ɻ���     �ɻ�����	���ʱ��   ����ʱ��   ��Ʊ��\n");
		for(i=0;i<26;i++)
		{
			if(fliinfo[i].city==city)								//�жϺ�����Ƿ񳬳���Χ
				printf("\n  %d	  %s %13s	%s      %s       %d\n",fliinfo[i].flinum,fliinfo[i].planenum,fliinfo[i].week,fliinfo[i].starttime,fliinfo[i].endtime,fliinfo[i].overplus);
		}


	}
	else
	{
        printf("\n*****�������������ѡ��*****\n");				//��ʾ�������
	    goto shuru;
    }
    back();															//�����˳�����
	
}
	
void order()														//��Ʊ����
{   QueuecliType s;                         
	int m,n,level,op,levelmax,p,i;
    printf("\n\n                            ���ն�Ʊϵͳ->��Ʊ          \n");
	printf("\n  **********************************************************************\n");

shuru:	printf("�����뺽��ţ�1-26��:[  ]\b\b\b");
	scanf("%d",&m);													//���붩Ʊ�����
	if(m>0&&m<27)													//�жϺ�����Ƿ񳬳���Χ
	{
	printf("\n��������Ҫ��Ʊ������:[  ]\b\b\b");
	scanf("%d",&n);													//���붩Ʊ����
	printf("\n����������Ʊ�Ĳ�λ�ȼ���1-3��:[  ]\b\b\b");
	scanf("%d",&level);												//�����λ�ȼ�
	switch(level)
	{
	case 1:{levelmax=fliinfo[m-1].levelone;op=fliinfo[m-1].opone;}break;//һ�Ȳ����
    case 2:{levelmax=fliinfo[m-1].leveltwo;op=fliinfo[m-1].optwo;}break;//���Ȳ����
    case 3:{levelmax=fliinfo[m-1].levelthree;op=fliinfo[m-1].opthree;}break;//���Ȳ����
	}
     
	if(n<=op)
	{   cli[num1].flinum=m;											//�ǼǶ�Ʊ�ͻ���Ϣ                                
	    cli[num1].tickets=n;										//�Ǽ�����Ʊ��
	    cli[num1].level=level;										//�Ǽ������λ�ȼ�
		printf("\n���������������� ");
		scanf("%s",&cli[num1].name);								//��������
		printf("\n�������������֤���룺 ");
		scanf("%s",&cli[num1].id);									//�������֤��
	    num1=num1+1;
		saveFileCli(cli,1);											//�������ļ���
		printf("\n\n��Ʊ�ɹ���\n\n");
		printf("����Ԥ��Ʊ��λ�ȼ���%d\n",level);
		printf("\n������λ�ţ� ");
		for(i=1;i<=n;i++)
			printf("%d   ",(levelmax-op)+i);						//�����λ��
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
		printf("\n*****�Բ�����Ʊ���������Ķ�Ʊ�*****\n\n");
		printf("�Ƿ�Ǽ��ŶӺ򲹣�1 ��  2 �� ��:[  ]\b\b\b");
		scanf("%d",&p);												 //����1��2

		if(p==1)
		{
			s.flinum=m;												 //�Ǽ��Ŷӿͻ���Ϣ
            s.demand=n;											 	 //�Ǽ�����Ʊ��
			s.level=level;											 //�Ǽ������λ�ȼ�
            printf("\n���������������� ");
		    scanf("%s",&s.name);
		    printf("\n�������������֤���룺 ");
		    scanf("%s",&s.id);
			ListInsert(&queueList,num2,s);							 //��˳���queueList�в���һ����¼
			printf("\n���ٴ�ȷ����Ϣ��������--\n");
			readwait(wait,1);
			saveFileWait(wait,1);									 //���ṹ�����������д���ļ�
		    printf("\n\n�������ŶӵǼǳɹ���������\n\n");
			num2++;          
		}
		
	}
	back();															 //�����˳�����
	
	}
	else
	{
        printf("\n*****�������������ѡ��*****\n");
	    goto shuru;
	}  
}


void tuipiao()													     //��Ʊ����
{   
	char a[20],b[20];
    int c,i,j,p,opl;
	int t;
	int flag=0;													    //�鿴�Ƿ�����Ʊ�˼�¼�ı�־
	int flag2=0;												    //�鿴�Ƿ��еȺ��油�ͻ�Ԥ������Ʊ�ı�־
	QueuecliType k;
	printf("\n                            ���ն�Ʊϵͳ->��Ʊ          \n");
	printf("\n  **********************************************************************\n");

	printf("\n���������������� ");
	scanf("%s",&a);												   //����ͻ�����
	printf("\n\n�������������֤���룺 ");
	scanf("%s",&b);												   //����ͻ����֤��
    printf("\n\n��������Ҫ��Ʊ�ĺ���ţ�1-8��:[  ]\b\b\b");
	scanf("%d",&c);												   //���뺽���
    printf("\n\n���Ķ�Ʊ��Ϣ��\n");
	printf("\n�����	��Ʊ��	��λ�ȼ�\n");
    for(t=0;t<num1;t++)
	if(c==cli[t].flinum&&strcmp(b,cli[t].id)==0)
	{printf("%d	%d	%d\n",c,cli[t].tickets,cli[t].level);		   //����ͻ�֮ǰ�Ķ�Ʊ��Ϣ
	 flag=1;
	}
	if(flag==0)
	{
		printf("\n\nû�����Ķ�Ʊ��¼��\n"); 
	        back();												   //�����˳�����                       
	} 
	 else printf("\n\n��ȷ��Ҫ��Ʊ����1�� 2��:[  ]\b\b\b");
          scanf("%d",&p);										   //����1��2
	if(p==1)
	{
	
   	for(i=0;i<num1;i++)
	{
		if(c==cli[i].flinum&&strcmp(b,cli[i].id)==0)
		{
			switch(cli[i].level)								   //����֮ǰ����Ʊ�Ĳ�λ�ȼ�ɾ����Ʊ��¼
			{
			case 1: {fliinfo[c-1].opone=fliinfo[c-1].opone+cli[i].tickets;  //��һ�Ȳյ�Ʊ
				     fliinfo[c-1].overplus=fliinfo[c-1].overplus+cli[i].tickets;
					 opl=fliinfo[c-1].opone;
					}break;
			case 2: {fliinfo[c-1].optwo=fliinfo[c-1].optwo+cli[i].tickets; //�˶��Ȳյ�Ʊ
				     fliinfo[c-1].overplus=fliinfo[c-1].overplus+cli[i].tickets;
					 opl=fliinfo[c-1].optwo;
					}break;
			case 3: {fliinfo[c-1].opthree=fliinfo[c-1].opthree+cli[i].tickets;//�����Ȳյ�Ʊ
				     fliinfo[c-1].overplus=fliinfo[c-1].overplus+cli[i].tickets;
					 opl=fliinfo[c-1].opthree;
					}break;
			}
			cli[i].flinum=-1;									  //��Ʊ�ͻ��������-1����ʾ��ɾ��  
		}

  loop:			for(j=0;j<num2;j++)
			{
				if(c==queueList.list[j].flinum&&opl>=queueList.list[j].demand&&cli[i].level==queueList.list[j].level)
				{
				    cli[num1].flinum=queueList.list[j].flinum;    //���˵�Ʊ���Ŷӿͻ�
                    strcpy(cli[num1].id,queueList.list[j].id);
                    cli[num1].level=queueList.list[j].level;
                    strcpy(cli[num1].name,queueList.list[j].name);
                    cli[num1].tickets=queueList.list[j].demand;
					num1++;
                    ListDelete(&queueList,j,&k);				  //��˳���queueList��ɾ��һ����¼
					 num2--;
					 flag2=1;									  //�˵�Ʊ���Ŷӿͻ�Ԥ����־λ��1
					 
					 goto loop;

				}
			}


	}
	if(flag2==0)
	{
		printf("\n\n��������Ʊ�ɹ���������\n\n");
		printf("\n������û�еȺ��油�ͻ�Ԥ����������\n\n");
		back();													 //�����˳�����
	}
	else 
	{
		printf("\n\n��������Ʊ�ɹ���������\n\n");
		printf("\n������������Ʊ�ѱ��Ⱥ��油�ͻ�Ԥ����������\n\n");
        back();													 //�����˳�����

	}

	}
	else  back();												 //�����˳�����
 
}


void sccli()                                                     //��ѯ��Ʊ�ͻ�����
{      int p,i,j; 
       int flag=0;												 //�鿴�Ƿ��ж�Ʊ�˼�¼�ı�־                                             
	   printf("\n\n\n                     ���ն�Ʊϵͳ->��ѯ��Ʊ�ͻ�����          \n");
	   printf("\n  **********************************************************************\n");
	   printf("\n��ѯ���β�����Ʊ�ͻ�������1����ѯ��ǰ�Ķ�Ʊ�ͻ�����������2\n");
	   scanf("%d",&j);											 //����1��2

		if(j==1)
		{
            printf("\n������Ҫ��ѯ�ĺ���ţ�1-26��:[  ]\b\b\b");
        scanf("%d",&p);											 //���뺽���
		if(p>0&&p<27)
		{
	    printf("\n\n����ţ�%d\n\n",p);
	    printf("��Ʊ�ͻ�������\n");
		printf("\n����		��Ʊ��		��λ�ȼ�\n");
		for(i=0;i<num1;i++)
			if(p==cli[i].flinum)                                 //�ж��Ƿ��Ѷ��������
			{
				printf("%s		%d		%d\n",cli[i].name,cli[i].tickets,cli[i].level);
				flag=1;
			}
			if(flag==0)
				printf("\n*****�޼�¼��*****\n");
		}
		else printf("\n\n*****���뺽��Ŵ���*****\n\n");
		back();													 //�����˳�����
		}
		else readtxt2();										 //���ö����ļ�����		
		back();													 //�����˳�����
	
}



	

void scque()													//��ѯ�Ŷӿͻ�����
{
		int p,i,j;
		int flag=0;												//�鿴�Ƿ����Ŷ��˼�¼�ı�־
		printf("\n\n\n                      ���ն�Ʊϵͳ->��ѯ�Ŷӿͻ�����          \n");
  	    printf("\n  **********************************************************************\n");
		printf("\n��ѯ���β����Ŷӿͻ�������1,��ѯ��ǰ���Ŷӿͻ�����������2\n");
		  scanf("%d",&j);										//����1��2
		printf("\n\n������Ҫ��ѯ�ĺ���ţ�1-26��:[  ]\b\b\b");
        scanf("%d",&p);											//���뺽���
		if(j==1)
		{
		if(p>0&&p<27)											//�жϺ���������Ƿ���ȷ
		{
	    printf("\n\n����ţ�%d\n\n",p);
	    printf("�Ⱥ��油�ͻ�������\n");
		printf("\n����		������		��λ�ȼ�\n");
		for(i=0;i<num2;i++)
		
			if(p==queueList.list[i].flinum)						 //�ж��Ƿ����ŶӼ�¼
			{
				printf("%s		%d		%d\n",queueList.list[i].name,queueList.list[i].demand,queueList.list[i].level);//����Ŷӿͻ���Ϣ
				flag=1;
			}
			if(flag==0)
				printf("\n*****�޼�¼��*****\n");
		} 
		else printf("\n\n*****���뺽��Ŵ���*****\n\n");
		back();													 //�����˳�����
		}
		else readtxt3();										 //���ö����ļ�����
		back();													 //�����˳�����

} 


void back()
{
	printf("\n\n��������������������ز˵�ҳ��������������\n");
    getch();													 //�����ַ�
	system("cls");												 //����
	menu();														 //�˵���������
}
void passde()													 //��¼���뺯��
{
	int ture;													 //�����������
	printf("���������룡\n");
	scanf("%d",&PASS);											 //��������
	ture=123456;												 //�趨��¼����Ϊ123456
	if(PASS==ture)												 //�ж������Ƿ���ȷ
	{
		printf("����ɹ���\n");									 //�������ɹ�
	}
	else
	{
		printf("�������\n");								   	 //����������
		exit(0); 
	}
}


void main()
{
	system("Color f0");											 //�����н����ɫ��Ϊ��ɫ
	printf("\n                            ��ӭ���뺽�ն�Ʊϵͳ�� \n");
	passde();													 //��¼���뺯������
    menu();														 //�˵���������
}

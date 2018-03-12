// ConsoleApplication2.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "stdio.h"
#include "stdlib.h"
#include"string.h"
/*数据结构部分*/

struct grade
{
	char name[20];
	int no;
	float s1;
	float s2;
	float s3;
	struct grade *next;
};
typedef struct grade* link;
/*通用指针部分*/
link head=NULL;
link prev=NULL;
link after=NULL;
link action = NULL;
link dataspace = (link)malloc(sizeof(grade));
/*函数部分*/
void creatl();
void addi(link head);
void avaofp(link head);
void avaofs(link head);
void outp(link head);
void freea(link head);

int main()
{
	printf_s("----------------------------------------------\nwelcome to the sys!\n----------------------------------------------\n");
	system("pause");
	system("cls");
	sta:
	printf_s("1.create\n2.add\n3. ava of person\n4.ava of sub\n5.output by the order\n6.exit\n");
	int swi;
	scanf_s("%d", &swi); system("cls");
	switch (swi)
	{
	case 1: {creatl();  goto sta;  }
	case 2: {addi(head);  goto sta;  }
	case 3: { avaofp(head); goto sta; }
	case 4: {avaofs(head);  goto sta;  }
	case 5: {outp(head);  goto sta;  }
	case 6: {freea(head); break; }
	default: {printf_s("eorror!"); goto sta; }
	}
    return 0;
}

/*函数定义部分*/
void creatl()
{
	printf_s("get ready to input the data");
	getchar();
	system("cls");
	int co = 1;
	int cho = 1;

	dataspace->next = NULL;
	while(cho)
	{printf_s("put in the student %d 's name:\n ", co);
	gets_s(dataspace->name);
	system("cls");
	printf_s("put in the stident %d 's no:\n ", co);
	scanf_s("%d", &dataspace->no);
	system("cls");
	printf("put in the stident %d 's sub1 sco:\n", co);
	scanf_s("%f", &dataspace->s1);
	system("cls");
	printf("put in the stident %d 's sub2 sco:\n", co);
	scanf_s("%f", &dataspace->s2);
	system("cls");
	printf("put in the stident %d 's sub3 sco:\n", co);
	scanf_s("%f", &dataspace->s3);
	system("cls");
	if (head==NULL)
	{
		head=(link)malloc(sizeof(grade));
		prev = head;
		after = head;
		*head = *dataspace;
	}
	else
	{
		after=(link)malloc(sizeof(struct grade));
		prev->next = after;
		*after = *dataspace;
		prev = after;
	}
	printf_s("录入终了。继续？0.N\n1.Y\n");
		scanf_s("%d", &cho);
	system("cls");
	co++;
}
	printf_s("过程终了。\n");
	system("pause");
	system("cls");
	
}


void addi(link head)
{
	printf_s("get ready to input the data");
	system("pause");
	system("cls");
	int chi = 1;
	int ni = 0;
	while(!ni)
	{
		printf_s("put in the student %d 's name:\n ", chi);
		gets_s(dataspace->name);
		system("cls");
		printf_s("put in the stident %d 's no:\n ", chi);
		scanf_s("%d", &dataspace->no);
		system("cls");
		printf("put in the stident %d 's sub1 sco:\n", chi);
		scanf_s("%f", &dataspace->s1);
		system("cls");
		printf("put in the stident %d 's sub2 sco:\n", chi);
		scanf_s("%f", &dataspace->s2);
		system("cls");
		printf("put in the stident %d 's sub3 sco:\n", chi);
		scanf_s("%f", &dataspace->s3);
		system("cls");
		after =(link) malloc(sizeof(struct grade));
		*after = *dataspace;
		prev->next = after;
		prev = after;
		printf_s("录入终了。继续？0.N\n1.Y\n");
		scanf_s("%d", &ni);
		system("cls");
		chi++;
	}
	printf_s("过程终了。\n");
	system("pause");
	system("cls");
}
void avaofp(link head)
{
	action = head;
	float avap=0;
	int coun = 1;
	while(action)
	{
		avap = action->s1 + action->s2 + action->s3;
		printf_s("the %d student's ava is %f", coun, avap / 3);
		action = action->next;
	}
	printf_s("过程终了。\n");
	system("pause");
	system("cls");
}
void avaofs(link head)
{
	action = head;
	float avas1 = 0;
	float avas2 = 0;
	float avas3 = 0;
	int coun = 1;
	while(action)
	{
		avas1 += action->s1;
		avas2 += action->s2;
		avas3 += action->s3;
		action = action->next;
		coun++;
	}
	printf_s("the ava of s1=%f\nthe ava of s2=%f\nthe ava of s3=%f\n", avas1 / coun, avas2 / coun, avas3 / coun);
	printf_s("过程终了。\n");
	system("pause");
	system("cls");

}
void outp(link head)
{
	action = head;
	while (action)
	{
		printf("%s\n", action->name);
		printf("%d\n", action->no);
		printf_s("%f\n", action->s1);
		printf_s("%f\n", action->s2);
		printf_s("%f\n", action->s2);
		action = action->next;
	}
	system("pause");	system("cls");
	printf_s("过程终了。\n");
	system("pause");
	system("cls");
}
void freea(link head)
{
	action = head;
	prev = NULL;
	after = NULL;

	while(action)
	{
		head = head->next;
		free(action);
		action = head;
	}action = NULL;
	head = NULL;
	printf_s("过程终了。\n");
	system("pause");
	system("cls");
}
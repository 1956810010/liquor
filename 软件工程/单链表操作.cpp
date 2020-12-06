#include "stdio.h"
#include "stdlib.h"

typedef char datatype;
typedef struct node
{
	datatype data;
	struct node *next;
}linklist;

linklist *creatlist()
{
	char ch;
	linklist *head, *s, *r;
	head = (linklist*)malloc(sizeof(linklist));
	r = head;
	printf("请输入字符产生链表,以#结束\n");
	ch = getchar();
	while (ch != '#')
	{
		s = (linklist*)malloc(sizeof(linklist));
		s->data = ch;
		r->next = s;
		r = s;
		ch = getchar();
	}
	r->next = NULL;
	return head;
}
void delet(linklist *head,int m)
{
	linklist *p,*s;
	p = head;
	s = head->next;
	for (int i = 0; i < m-1; i++)
	{
		p = p->next;
		s = s->next;
	}
	p->next = s->next;
	free(s);
}
void insert(linklist *head,int m,char ch)
{
	linklist *p, *s;
	p = head;
	for (int i = 0; i < m - 1; i++)
	{
		p = p->next;
	}
	s = (linklist*)malloc(sizeof(linklist));
	s->data = ch;
	s->next = p->next;
	p->next = s;
}


char getlist(linklist *head, int i)
{
	int j = 0;
	linklist *p;
	p = head;
	while ((p->next != NULL) && (j < i))
	{
		p = p->next;
		j++;
	}
	if (i == j)
		return p->data;
	else
		return -1;
}

int  main()
{
	linklist *head, *r;
	int num;
	char n;
	head = creatlist();
	printf("总链表:");
	r = head->next;
	while (r)
	{
		printf("%c", r->data);
		r = r->next;
	}
	printf("\n");
	printf("请输入要查询的序号(输入-1停止查找):\n");
	scanf_s("%d", &num);
	n = getlist(head, num);
	while (num != -1)
	{
		if (n == -1)
			printf("没有查到\n");
		else
			printf("查找的结果为:%c\n", n);
		printf("请输入要查询的序号:");
		scanf_s("%d", &num);
		n = getlist(head, num);
	}
	if (num == -1)
		printf("查找结束\n");
	printf("请输入要插入的序号及数据(输入0位置停止):\n");
	scanf_s("%d %c",&num,&n);
	while(num!=0)
	{ 
		insert(head, num, n);
		printf("插入成功\n");
		printf("请输入要插入的序号及数据:\n");
		scanf_s("%d %c", &num,&n);
	}
	printf("插入结束\n");
	r = head->next;
	while (r)
	{
		printf("%c", r->data);
		r = r->next;
	}
	printf("\n");
	printf("请输入要删除的序号(输入0位置停止):\n");
	scanf_s("%d", &num);
	while (num!=0)
	{
		delet(head, num);
		printf("删除成功\n");
		printf("请输入要删除的序号:\n");
		scanf_s("%d", &num);
	}
	printf("删除结束\n");
	r = head->next;
	while (r)
	{
		printf("%c", r->data);
		r = r->next;
	}
}
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
	printf("请输入要查询的序号:");
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
	if (num == -1) printf("查找结束\n");
}
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
	printf("�������ַ���������,��#����\n");
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
	printf("������:");
	r = head->next;
	while (r)
	{
		printf("%c", r->data);
		r = r->next;
	}
	printf("\n");
	printf("������Ҫ��ѯ�����(����-1ֹͣ����):\n");
	scanf_s("%d", &num);
	n = getlist(head, num);
	while (num != -1)
	{
		if (n == -1)
			printf("û�в鵽\n");
		else
			printf("���ҵĽ��Ϊ:%c\n", n);
		printf("������Ҫ��ѯ�����:");
		scanf_s("%d", &num);
		n = getlist(head, num);
	}
	if (num == -1)
		printf("���ҽ���\n");
	printf("������Ҫ�������ż�����(����0λ��ֹͣ):\n");
	scanf_s("%d %c",&num,&n);
	while(num!=0)
	{ 
		insert(head, num, n);
		printf("����ɹ�\n");
		printf("������Ҫ�������ż�����:\n");
		scanf_s("%d %c", &num,&n);
	}
	printf("�������\n");
	r = head->next;
	while (r)
	{
		printf("%c", r->data);
		r = r->next;
	}
	printf("\n");
	printf("������Ҫɾ�������(����0λ��ֹͣ):\n");
	scanf_s("%d", &num);
	while (num!=0)
	{
		delet(head, num);
		printf("ɾ���ɹ�\n");
		printf("������Ҫɾ�������:\n");
		scanf_s("%d", &num);
	}
	printf("ɾ������\n");
	r = head->next;
	while (r)
	{
		printf("%c", r->data);
		r = r->next;
	}
}
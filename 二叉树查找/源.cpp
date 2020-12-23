#include"stdio.h"
#include"stdlib.h"
typedef struct bitnode
{
	int key;
	struct bitnode* lchild;
	struct bitnode* rchild;
}bnode;
void ins_bitree(bnode* p, int k)
{
	bnode* q;
	if (p->key > k && p->lchild)
		ins_bitree(p->lchild, k);
	else 
		if (p->key <= k && p->rchild)
			ins_bitree(p->rchild, k);
	else
	{
		q = (bnode*)malloc(sizeof(bnode));
		q->key = k;
		q->lchild = NULL;
		q->rchild = NULL;
		if (p->key > k)
			p->lchild = q;
		else
			p->rchild = q;
	}
}
void bit_search(bnode* p, int k)
{
	if (p->key > k && p->lchild)
		bit_search(p->lchild, k);
	else
		if (p->key < k && p->rchild)
			bit_search(p->rchild, k);
		else
			if (p->key == k)
			{
				printf("���ҳɹ���\n");
			}
			else
				printf("����ʧ�ܣ�\n");
}
void inorder(bnode* p)
{
	if (p)
	{
		inorder(p->lchild);
		printf("%4d", p->key);
		inorder(p->rchild);
	}
}
int main()
{
	int k;
	bnode* p;
	p = NULL;
	printf("���������������ֵ������0������\n");
	scanf_s("%d",&k);
	p = (bnode*)malloc(sizeof(bnode));
	p->key = k;
	p->lchild = NULL;
	p->rchild = NULL;
	scanf_s("%d",&k);
	while (k > 0)
	{
		ins_bitree(p,k);
		scanf_s("%d",&k);
	}
	printf("\n");
	printf("����������Ľ����");
	inorder(p);
	printf("\n��������ҵ�ֵ:\n");
	scanf_s("%d",&k);
	bit_search(p, k);
}
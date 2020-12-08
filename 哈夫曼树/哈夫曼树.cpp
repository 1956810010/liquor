#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define n 6
#define m 2*n-1
#define Maxval 1
typedef char datatype;
typedef struct
{
	float weight;
	datatype data;
	int lchild, rchild, parent;
}hufmtree;
hufmtree tree[m];
typedef struct
{
	char bits[n];
	int start;
	datatype data;
}codetype;
codetype code[n];
void HUFFMAN(hufmtree tree[])
{
	int i, j, p1, p2;
	char ch;
	float small1, small2, f;
	for (i = 0; i < m; i++)
	{
		tree[i].parent = 0;
		tree[i].lchild = 0;
		tree[i].rchild = 0;
		tree[i].weight = 0.0;
		tree[i].data = '0';
	}
	for (i = 0; i < n; i++)
	{
		scanf_s("%f", &f);
		tree[i].weight = f;
		scanf_s(" %c", &ch);
		tree[i].data = ch;
	}
	for (i = n; i < m; i++)
	{
		p1 = p2 = 0;
		small1 = small2 = Maxval;
		for (j = 0; j <= i - 1; j++)
			if (tree[j].parent == 0)
				if (tree[j].weight < small1)
				{
					small2 = small1;
					small1 = tree[j].weight;
					p2 = p1;
					p1 = j;
				}
				else if (tree[j].weight < small2)
				{
					small2 = tree[j].weight;
					p2 = j;
				}
		tree[p1].parent = i;
		tree[p2].parent = i;
		tree[i].lchild = p1;
		tree[i].rchild = p2;
		tree[i].weight = tree[p1].weight + tree[p2].weight;
	}
}
void HUFFMANCODE(codetype code[], hufmtree tree[])
{
	int i, c, p;
	codetype cd;
	for (i = 0; i < n; i++)
	{
		cd.start = n;
		c = i;
		p = tree[c].parent;
		cd.data = tree[c].data;
		while (p != 0)
		{
			cd.start--;
			if (tree[p].lchild == c)
				cd.bits[cd.start] = '0';
			else
				cd.bits[cd.start] = '1';
			c = p;
			p = tree[c].parent;
		}
		code[i] = cd;
		printf("%c:", cd.data);
		for (int k = cd.start; k < n; k++)
			printf("%c", cd.bits[k]);
		printf("\n");
	}
}
void HUFFMANDECODE(codetype code[], hufmtree tree[])
{
	int i, b;
	int endflag = 2;
	i = m - 1;
	scanf_s("%1d", &b);
	while (b != endflag)
	{
		if (b == 0)
			i = tree[i].lchild;
		else
			i = tree[i].rchild;
		if (tree[i].lchild == 0)
		{
			putchar(code[i].data);
			i = m - 1;
		}
		scanf_s("%1d", &b);
	}
	if ((tree[i].lchild != 0) && (i != m - 1))
		printf("\nERROR\n");
}
void DLR(hufmtree *T)
{
	if(T->data!='0')
	printf("%c", T->data);
	if (T->lchild==NULL&&T->rchild==NULL) return;
	DLR(&tree[T->lchild]);
	DLR(&tree[T->rchild]);
}
int GEN(hufmtree tree[])
{
	int c, p;
	c = 0;
	p = tree[c].parent;
	while (p != 0)
	{
		c = p;
		p = tree[c].parent;
	}
	return c;
}
int main()
{
	int b;
	printf("�������Ȩֵ�ͽ����ĸ���ÿո����������0.4 a��\n");
	HUFFMAN(tree);
	printf("\n������\n");
	HUFFMANCODE(code, tree);
	b = GEN(tree);
	DLR(&tree[b]);
	printf("\n��ʼ���룬����������\n");
	HUFFMANDECODE(code, tree);
	printf("\n");
}

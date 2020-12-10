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
		scanf_s("%f %c",&f,&ch);
		tree[i].weight = f;
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
	
	if (T->lchild==NULL&&T->rchild==NULL) { printf("%c ", T->data); return; }
	else printf(" %.2f ", T->weight);
	DLR(&tree[T->lchild]);
	DLR(&tree[T->rchild]);
}
void LDR(hufmtree *T)
{
	if (T->lchild == NULL && T->rchild == NULL) { printf("%c ", T->data); return; }
	LDR(&tree[T->lchild]);
	printf(" %.2f ", T->weight);
	LDR(&tree[T->rchild]);
}
void LRD(hufmtree *T)
{
	if (T->lchild == NULL && T->rchild == NULL) { printf("%c ", T->data); return; }
	LRD(&tree[T->lchild]);
	LRD(&tree[T->rchild]);
	printf(" %.2f ", T->weight);
}

int main()
{
	printf("输入结点的权值和结点字母，用空格隔开：（如0.4 a）\n");
	HUFFMAN(tree);
	printf("\n编码结果\n");
	HUFFMANCODE(code, tree);
	printf("\n先序遍历：");
	DLR(&tree[10]);
	printf("\n中序遍历：");
	LDR(&tree[10]);
	printf("\n后序遍历：");
	LRD(&tree[10]);
	printf("\n\n开始译码，请输入密码\n");
	HUFFMANDECODE(code, tree);
	printf("\n");
}

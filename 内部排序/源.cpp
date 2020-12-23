#include"stdio.h"
#include"time.h"
#define size 11
typedef char datatype;
typedef struct
{
	int key;
	datatype others;
}rectype;

void INSERTSORT(rectype R[])
{
	int i,j;
	rectype temp;
	for ( i = 2; i < size; i++)
	{
		R[0] = R[i];
		j = i - 1;
		while (R[0].key<R[j].key)
		{
			R[j + 1] = R[j]; j--;
		}
		R[j + 1] = R[0];
	}
}
void SHELLSORT(rectype R[], int n)
{
	int i, j, h;
	rectype temp;
	h = n / 2;
	while (h>0)
	{
		for (j = h;j <= n - 1; j++)
		{
			temp = R[j];
			i = j - h;
			while ((i>=0)&&temp.key<R[i].key)
			{
				R[i + h] = R[i];
				i = i - h;
			}
			R[i + h] = temp;
		}
		h = h / 2;
	}
}
int PARTITION(rectype R[], int l, int h)
{
	int i, j;
	rectype temp;
	i = l; j = h; temp = R[i];
	do
	{
		while ((R[j].key>=temp.key)&&(i<j))
			j--;
		if (i < j) R[i++] = R[j];
		while ((R[i].key <= temp.key) && (i < j))
			i++;
		if (i < j) R[j--] = R[i];
	} while (i!=j);
	R[i] = temp;
	return i;
}
void QUICKSORT(rectype R[], int s1, int t1)
{
	int i;
	if(s1<t1)
	{
		i = PARTITION(R, s1, t1);
		QUICKSORT(R, s1, i - 1);
		QUICKSORT(R, i + 1, t1);	
	}
}
int main()
{
	rectype R[size];
	int i;
	printf("请输入使用插入算法排序的十个数据\n");
	for (i = 1; i < size; i++)
		scanf_s("%d",&R[i].key);
	printf("\n插入排序之前\n");
	for (i = 1; i < size; i++)
			printf("%d\t", R[i].key);
	INSERTSORT(R);
	printf("\n插入排序之后\n");
	for (i = 1; i < size; i++)
		printf("%d\t",R[i].key);
	printf("\n\n");
	printf("请输入使用希尔算法排序的十个数据\n");
	for (i = 0; i < size-1; i++)
		scanf_s("%d", &R[i].key);
	printf("\n希尔排序之前\n");
	for (i = 0; i < size-1; i++)
		printf("%d\t", R[i].key);
	SHELLSORT(R,10);
	printf("\n希尔排序之后\n");
	for (i = 0; i < size-1; i++)
		printf("%d\t", R[i].key);
	printf("\n\n");
	printf("请输入使用快速算法排序的十个数据\n");
	for (i = 1; i < size; i++)
		scanf_s("%d", &R[i].key);
	printf("\n快速排序之前\n");
	for (i = 1; i < size; i++)
		printf("%d\t", R[i].key);
	QUICKSORT(R,1,10);
	printf("\n快速排序之后\n");
	for (i = 1; i < size; i++)
		printf("%d\t", R[i].key);
}


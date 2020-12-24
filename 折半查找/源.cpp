#include"stdio.h"
#define MAX 100
typedef struct
{
	int elem[MAX + 1];
	int length;
}Stable;
void create_seq(Stable *list)
{
	int i;
	printf("请输入顺序表的内容：\n");
	for (i = 1; i <= list->length; i++)
	{
		printf("第%d个元素：", i);
		scanf_s("%d", &list->elem[i]);
	}
}
int sort_seq(Stable *list)
{
	int i, j, flag;
	for ( i = 1; i < list->length; i++)
	{
		flag = 0;
		for ( j = 0; j < list->length-i+1; j++)
	
			if (list->elem[j] > list->elem[j + 1])
			{
				list->elem[0] = list->elem[j + 1];
				list->elem[j + 1] = list->elem[j];
				list->elem[j] = list->elem[0];
				flag = 1;
			}
		if (flag == 0) return 1;
	}
}

int bin_seach(Stable *list, int k,int low,int high)
{
	int mid;
	if (low>high)
	{
		printf("没有找到想要查找的值\n");
		return (0);
	}
	mid = (low + high) / 2;
	if (list->elem[mid]==k)
	{
		printf("查找成功\n");
		printf("第%d个元素是：%d\n",mid,k);
		return (mid);
	}
	else
	{
		if (list->elem[mid] < k)
			return(bin_seach(list, k, mid + 1, high));

		else
			return(bin_seach(list, k, low, mid - 1));
	}
}
int main()
{
	Stable *list,table;
	int i,key;
	list = &table;
	printf("请输入线性表的长度：");
	scanf_s("%d", &list->length);
	create_seq(list);
	sort_seq(list);
	printf("排序后的数据：\n");
	for (i = 1; i <= list->length; i++)
		printf("第%d元素是：%d\n", i, list->elem[i]);
	printf("\n输入查找的值：");
	scanf_s("%d", &key);
	while (key != -1)
	{
		bin_seach(list, key, 1, list->length);
		printf("\n输入查找的值：");
		scanf_s("%d", &key);
	}
}

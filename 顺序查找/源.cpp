#include"stdio.h"
#define MAX 100
typedef int keytype;
typedef struct
{
	keytype key;
}elemtype;
typedef struct
{
	elemtype elem[MAX + 1];
	int length;
}SStable;
void create_seq(SStable* list)
{
	int i;
	printf("请输入顺序表的内容：\n");
	for (i = 0; i < list->length; i++)
	{
		printf("list.elem[%d].key=", i + 1);
		scanf_s("%d", &list->elem[i].key);
	}
}
int seq_seach(SStable* list, keytype k)
{
	int i = 0, flag = 0;
	while (i < list->length)
	{
		if (list->elem[i].key == k)
		{
			flag = 1;
			printf("list.elem[%d].key=%d\n", i + 1, k);
		}
		i++;
	}
	if (flag == 0)
		printf("没有找到数据%d\n", k);
	return flag;
}
int main()
{
	SStable* list, table;
	keytype key;
	int i;
	list = &table;
	printf(" 请输入顺序表的长度：");
	scanf_s("%d",&list->length);
	create_seq(list);
	printf("创建的顺序表内容：\n");
	for (i = 0; i < list->length; i++)
		printf("list.elem[%d].key=%d\n", i + 1,list->elem[i].key);
	printf("输入查找关键字：");
	scanf_s("%d",&key);
	seq_seach(list, key);
}

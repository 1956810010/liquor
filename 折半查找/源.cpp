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
	printf("������˳�������ݣ�\n");
	for (i = 1; i <= list->length; i++)
	{
		printf("��%d��Ԫ�أ�", i);
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
		printf("û���ҵ���Ҫ���ҵ�ֵ\n");
		return (0);
	}
	mid = (low + high) / 2;
	if (list->elem[mid]==k)
	{
		printf("���ҳɹ�\n");
		printf("��%d��Ԫ���ǣ�%d\n",mid,k);
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
	printf("���������Ա�ĳ��ȣ�");
	scanf_s("%d", &list->length);
	create_seq(list);
	sort_seq(list);
	printf("���������ݣ�\n");
	for (i = 1; i <= list->length; i++)
		printf("��%dԪ���ǣ�%d\n", i, list->elem[i]);
	printf("\n������ҵ�ֵ��");
	scanf_s("%d", &key);
	while (key != -1)
	{
		bin_seach(list, key, 1, list->length);
		printf("\n������ҵ�ֵ��");
		scanf_s("%d", &key);
	}
}

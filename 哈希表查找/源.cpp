#include"stdio.h"
#define MAX 11
void ins_hash(int hash[], int key)
{
	int k, k2, k1;
	k = key % MAX;
	if (hash[k] == 0)
	{
		hash[k] = key;
		return;
	}
	else
	{
		k1 = k + 1;
		while (k1 < MAX && hash[k1] != 0)
			k1++;
		if (k1<MAX)
		{
			hash[k1] = key;
			return;
		}
		k2 = 0;
		while (k2<MAX&&hash[k2]!=0)	
			k2++;
		if (k2<k)
		{
			hash[k2] = key;
			return;
		}
	}
}
void out_hash(int hash[])
{
	int i;
	for ( i = 0; i < MAX; i++)
	{
		if (hash[i])
			printf("hash[%d]=%d\n", i, hash[i]);
	}
}
void hash_search(int hash[], int key)
{
	int k1, k, k2, flag = 0;
	k = key % MAX;;
	if (hash[k]==key)
	{
		printf("hash[%d]=%d\n",k,key);
		flag = 1;
	}
	else
	{
		k1 = k + 1;
		while (k1 < MAX && hash[k1] != key)
			k1++;
		if (k1 < MAX)
		{
			printf("hash[%d]=%d\n", k1, key);
			flag = 1;
		}
		k2 = 0;
		if (!flag)
		{
			while (k2 < MAX && hash[k2] != key)
				k2++;
			if (k2 < k)
			{
				printf("hash[%d]=%d\n", k2, key);
				flag = 1;
			}
		}
		if (flag)
		{
			printf("查找成功\n");
			return;
		}
		else
		{
			printf("查找失败\n");
			return;
		}
	}
}
int main()
{
	int i, key, k, sum = 0;
	int hash[MAX];
	for (i = 0; i < MAX; i++)
		hash[i] = 0;
	printf("请输入数据，以0结束:\n");
	scanf_s("%d", &key);
	sum++;
	while (key&&sum<MAX)
	{
		ins_hash(hash, key);
		scanf_s("%d", &key);
		sum++;
	}
	printf("\n");
	out_hash(hash);
	printf("\n");
	printf("请输入查找的值:");
	scanf_s("%d", &k);
	hash_search(hash, k);
	printf("\n");
}
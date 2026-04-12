#include <stdio.h>
#include <string.h>
#define MAX_N 10000
#define MAX_LEN 11
char strs[MAX_N][MAX_LEN];
void qsort(int left, int right)
{
	if (left >= right)
		return;
	int i = left, j = right;
	char pivot[MAX_LEN];
	strcpy(pivot, strs[(left + right) / 2]);
	char temp[MAX_LEN];
	while (i <= j)
	{
		while (strcmp(strs[i], pivot) > 0)
			i++;
		while (strcmp(strs[j], pivot) < 0)
			j--;

		if (i <= j)
		{
			strcpy(temp, strs[i]);
			strcpy(strs[i], strs[j]);
			strcpy(strs[j], temp);
			i++;
			j--;
		}
	}

	qsort(left, j);
	qsort(i, right);
}

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%s", strs[i]);
	}
	qsort(0, n - 1);
	for (int i = 0; i < n; i++)
	{
		printf("%s\n", strs[i]);
	}

	return 0;
}
#include <stdio.h>
#include <math.h>

int main()
{
	int n;
	scanf("%d", &n);

	int start, end;
	scanf("%d %d", &start, &end);

	int cnt[201] = {0};

	for (int i = 0; i < n; i++)
	{
		int x = (int)(100 * (sin(i + n) + 1));
		cnt[x]++;
	}
	int idx = 0;
	int cou = 0;

	for (int i = 0; i <= 200; i++)
	{
		if (cnt[i] == 0)
			continue;
		int nextidx = idx + cnt[i];
		if (nextidx > start && idx < end)
		{
			int from = (idx > start) ? idx : start;
			int to = (nextidx < end) ? nextidx : end;

			for (int j = from; j < to; j++)
			{
				printf("%d\n", i);
				cou++;
			}
		}

		idx = nextidx;
		if (cou >= end - start)
			break;
	}

	return 0;
}
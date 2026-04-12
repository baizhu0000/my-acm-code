#include <bits/stdc++.h>
using namespace std;
int main()
{
	string s;
	cin >> s;
	stack<int> num;
	int n = 0;
	char c = '+';
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] <= '9' && s[i] >= '0')
		{
			n = n * 10 + (int)(s[i] - '0');
			n %= 10000;
		}
		else
		{
			if (c == '+')
			{
				num.push(n);
			}
			else if (c == '*')
			{
				int t = num.top();
				num.pop();
				num.push((t * n) % 10000);
			}
			n = 0;
			if (i < s.size())
			{
				c = s[i];
			}
		}
	}
	if (c == '+')
	{
		num.push(n);
	}
	else if (c == '*')
	{
		int t = num.top();
		num.pop();
		num.push((t * n) % 10000);
	}
	long long ans = 0;
	while (!num.empty())
	{
		ans = ((ans + num.top()) % 10000);
		num.pop();
	}
	cout << ans << endl;
	return 0;
}

#include <bits/stdc++.h>
using namespace std;
int main()
{
	string s;
	cin >> s;
	int pd = 0;
	string ans;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == '(')
		{
			pd++;
			ans += '(';
		}
		else if (s[i] == ')')
		{
			if (pd > 0)
			{
				pd--;
				ans += ')';
			}
			else
			{
				ans = '(' + ans + ')';
			}
		}
	}
	while (pd--)
	{
		ans += ')';
	}
	cout << ans;
	return 0;
}
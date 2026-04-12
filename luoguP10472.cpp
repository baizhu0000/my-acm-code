#include <bits/stdc++.h>
using namespace std;
bool pd(char l, char r)
{
	if ((l == '(' && r == ')') || (l == '{' && r == '}') || (l == '[' && r == ']'))
	{
		return true;
	}
	else
	{
		return false;
	}
}
int main()
{
	string s;
	cin >> s;
	int ans = 0;
	stack<int> st;
	vector<int> dp(s.size(), 0);
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == '(' || s[i] == '{' || s[i] == '[')
		{
			st.push(i);
		}
		else
		{
			if (!st.empty() && pd(s[st.top()], s[i]))
			{
				int l = st.top();
				st.pop();
				int len = i - l + 1;
				if (l > 0)
				{
					len += dp[l - 1];
				}
				dp[i] = len;
				ans = max(ans, dp[i]);
			}
			else
			{
				while (!st.empty())
				{
					st.pop();
				}
				dp[i] = 0;
			}
		}
	}
	cout << ans << endl;
	return 0;
}

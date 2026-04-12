#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin >> n;
	stack<int> st;
	stack<int> ma;
	vector<int> ans;

	while (n--)
	{
		int op;
		cin >> op;

		if (op == 0)
		{
			int x;
			cin >> x;
			st.push(x);
			if (ma.empty())
			{
				ma.push(x);
			}
			else
			{
				ma.push(max(ma.top(), x));
			}
		}
		else if (op == 1)
		{
			if (!st.empty())
			{
				st.pop();
				ma.pop();
			}
		}
		else if (op == 2)
		{
			if (st.empty())
			{
				ans.push_back(0);
			}
			else
			{
				ans.push_back(ma.top());
			}
		}
	}

	for (int i = 0; i < ans.size(); i++)
	{
		cout << ans[i] << '\n';
	}

	return 0;
}
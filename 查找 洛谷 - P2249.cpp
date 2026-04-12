#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;
	vector<int> a(n);
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	vector<int> ans;
	for (int i = 0; i < m; i++)
	{
		int q;
		cin >> q;
		auto it = lower_bound(a.begin(), a.end(), q);
		if (it == a.end() || *it != q)
		{
			ans.push_back(-1);
		}
		else
		{
			int pos = it - a.begin();
			ans.push_back(pos + 1);
		}
	}
	for (int i = 0; i < ans.size(); i++)
	{
		cout << ans[i] << " ";
	}
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin >> n;

	vector<int> a(n);
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
	cout << "\n";
	sort(a.begin(), a.end(), greater<int>());
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
	sort(a.begin(), a.end());
	a.erase(unique(a.begin(), a.end()), a.end());
	for (auto i : a)
	{
		cout << i << " ";
	}
	cout << endl;
	return 0;
}
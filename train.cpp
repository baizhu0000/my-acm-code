#include <bits/stdc++.h>
using namespace std;
<<<<<<< HEAD
int main(){
    int m;
    cin>>m;
    int l=1,r=0,sum=0;
    while(l<=m/2){
        if(sum==m){
            cout<<l<<" "<<r<<endl;
            sum-=l;;
            l++;
        }else if(sum<m){
            r++;
            sum+=r;
        }else{
            sum-=l;
            l++;
        }
    }
    return 0;
=======
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
>>>>>>> 5c1e01074414ecbf7fc6c3273c687a69729a1c50
}
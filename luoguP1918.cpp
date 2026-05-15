#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n; 
	map<int,int> mp; 
	for(int i=1;i<=n;i++){
		int t;
		cin>>t;
		mp[t]=i; 
	}
	int q;
	cin>>q;
	while(q--){
		int m;
		cin>>m;
		if(mp.find(m)!=mp.end()){
			cout<<mp[m]<<endl;
		}else{
			cout<<0<<endl;
		}
	}
	
	return 0;
 } 

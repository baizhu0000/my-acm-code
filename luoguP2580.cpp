#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	map<string,int>mp;
	cin>>n;
	while(n--){
		string name;
		cin>>name;
		mp[name]++;
	}
	int m;
	cin>>m;
	while(m--){
		string t;
		cin>>t;
		if(mp.find(t)!=mp.end()){
			if(mp[t]==1){
				cout<<"OK"<<endl;
				mp[t]--;
			}else if(mp[t]==0){
				cout<<"REPEAT"<<endl;
			}
		}else{
			cout<<"WRONG"<<endl;
		}
	}
	return 0;
 } 

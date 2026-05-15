#include <bits/stdc++.h>
using namespace std;
int main()
{
	int q;
	cin>>q;
	map<string,int>mp;
	while(q--){
		int op;
		cin>>op;
		if(op==1){
			string n;
			int s;
			cin>>n>>s;
			mp[n]=s;
			cout<<"OK"<<endl; 
		}else if(op==2){
			string n;
			cin>>n;
			if(mp.find(n)!=mp.end()){
				cout<<mp[n]<<endl;
			}else{
				cout<<"Not found"<<endl;
			}
		}else if(op==3){
			string n;
			cin>>n;
			if(mp.find(n)!=mp.end()){
				mp.erase(n);
				cout<<"Deleted successfully"<<endl; 
			}else{
				cout<<"Not found"<<endl;
			}
		}else if(op==4){
			cout<<mp.size()<<endl;
		}
	} 
	
	return 0;
}

#include <bits/stdc++.h>
using namespace std;
int main()
{
	int m;
	cin>>m;
	set<int> ds;
	while(m--){
		int op,l;
		cin>>op>>l;
		if(op==1){
			if(ds.find(l)!=ds.end()){
				cout<<"Already Exist"<<endl;
			}else{
				ds.insert(l);
			}
		}else if(op==2){
			if(ds.empty()){
				cout<<"Empty"<<endl;
				continue;
			}
			if(ds.find(l)!=ds.end()){
				cout<<l<<endl;
				ds.erase(l);
				continue;
			}
			auto it=ds.lower_bound(l);
			if(it==ds.end()){
				it--;
				cout<<*it<<endl;
				ds.erase(it);
				continue;
			}
			if(it!=ds.begin()){
				auto itt=it;
				itt--;
				if(l-(*itt)<=(*it)-l){
					cout<<*itt<<endl;
					ds.erase(itt);
				}else{
					cout<<*it<<endl;
					ds.erase(it);
				}
			}else{
				cout<<*it<<endl;
				ds.erase(it);
			}
		}
	}
	
	return 0;
 } 

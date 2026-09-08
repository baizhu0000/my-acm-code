#include <iostream>
#include <string>
using namespace std;
class Vedio{
private:
    int type,price,ing;
    string name;
public:
    Vedio(int t,string n,int p,int i):type(t),name(n),price(p),ing(i){}
    void print(){
        if(type==1){
            cout<<"黑胶片";
        }else if(type==2){
            cout<<"CD";
        }else if(type==3){
            cout<<"VCD";
        }else if(type==4){
            cout<<"DVD";
        }
        cout<<"["<<name<<"]";
        if(ing==0){
            cout<<"未出租";
        }else if(ing==1){
            cout<<"已出租";
        }
        cout<<endl;
    }
    void countfee(int m){
        if(ing==0){
            cout<<"未产生租金"<<endl;
        }else if(ing==1){
            int ans=m*price;
            cout<<"当前租金为"<<ans<<endl;
        }
    }
};
int main()
{
    int n;
    cin>>n;
    while(n--){
        int t,p,i;
        string na;
        cin>>t>>na>>p>>i;
        Vedio a(t,na,p,i);
        int m;
        cin>>m;
        a.print();
        if(m==0){
            continue;
        }else{
            a.countfee(m);
        }
    }
    return 0;
}
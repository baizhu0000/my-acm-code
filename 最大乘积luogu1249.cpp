#include <iostream>
using namespace std;
int a[200],b[10000]={1};
void chen(int b[],int &len,int x){
    int c=0;
    for(int i=0;i<len;i++){
        int p=b[i]*x+c;
        b[i]=p%10;
        c=p/10;
    }
    while(c>0){
        b[len]=c%10;
        c/=10;
        len++;
    }
}
int main()
{
    int n;
    cin>>n;
    int sum=0;
    int yu,len=0,lenb=1;
    if(n==3||n==4){
        cout<<n<<endl<<n;
        return 0;
    }
    for(int i=2;sum<n;i++,len++){
        sum+=i;
        a[len]=i;
        yu=n-sum;
        if(yu<i+1){
            break;
        }
    }
    while(yu>0){
        for(int i=len;i>=0;i--){
            a[i]++;
            yu--;
            if(yu==0){
                break;
            }
        }
    }
    for(int i=0;i<=len;i++){
        chen(b,lenb,a[i]);
        cout<<a[i]<<" ";
    }
    cout<<endl;
    for(int i=lenb;i>=0;i--){
        if(i==lenb&&b[i]==0){
            continue;
        }
        cout<<b[i];
    }
    return 0;
}
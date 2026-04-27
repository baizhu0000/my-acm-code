#include <bits/stdc++.h>
using namespace std;
string target="123804765",s;
int dx[4]={0,-1,0,1};
int dy[4]={-1,0,1,0};
int bfs(string s){
    if(s==target){
        return 0;
    }
    queue<string>q;
    q.push(s);
    unordered_map<string,int>d;
    d[s]=0;
    while(!q.empty()){
        string change=q.front();
        q.pop();
        int zero=change.find("0");
        int x=zero/3;
        int y=zero%3;
        for(int i=0;i<4;i++){
            int tx=x+dx[i],ty=y+dy[i];
            if(tx>=0&&tx<3&&ty>=0&&ty<3){
                int ne=tx*3+ty;
                string temp=change;
                swap(temp[zero],temp[ne]);
                if(!d.count(temp)){
                    d[temp]=d[change]+1;
                    if(temp==target){
                        return d[temp];
                    }
                    q.push(temp);
                }
            }
        }
    }

}
int main()
{
    cin>>s;
    cout<<bfs(s);
    return 0;
}
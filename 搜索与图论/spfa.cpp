#include<cstring>
#include<queue>
#include<iostream>
using namespace std;
int n,m,idx=1;
const int N=2e5+10;
int h[N],e[N],ne[N],w[N],dis[N],st[N];
void add(int a,int b,int c){
    e[idx]=b;
    w[idx]=c;
    ne[idx]=h[a];
    h[a]=idx++;
}
void spfa(){
    for(int i=0;i<=n;i++){
        dis[i]=0x3f3f3f3f;
    }
    queue<int> q;
    q.push(1);
    dis[1]=0;
    while(q.size()){
        int t=q.front();q.pop();
        st[t]=0;
        for(int i=h[t];i;i=ne[i]){
            int j=e[i];
            if(dis[j]>dis[t]+w[i]){
                dis[j]=dis[t]+w[i];
                if(!st[j]){
                    st[j]=1;
                    q.push(j);
                }
            }
        }
    }
}
int main(){
    cin>>n>>m;
    while(m--){
        int a,b,c;
        cin>>a>>b>>c;
        add(a,b,c);
    }
    spfa();
    if(dis[n]==0x3f3f3f3f){
        cout<<-1<<endl;
    }else cout<<dis[n]<<endl;
}

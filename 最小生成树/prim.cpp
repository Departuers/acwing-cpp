#include<cstring>
#include<iostream>
using namespace std;
int n,m,inf=0x3f3f3f3f;
int g[510][510],dis[510],st[510];
int prim(){
    memset(dis,63,sizeof dis);
    int res=0;
    for(int i=0;i<n;i++){
        int t=-1;
        for(int j=1;j<=n;j++)
        if(!st[j]&&(t==-1||dis[t]>dis[j]))t=j;
        if(i&&dis[t]==inf)return inf;
        if(i)res+=dis[t];//如果不初始化dis就要写if(i)
        st[t]=1;
        for(int j=1;j<=n;j++){
            dis[j]=min(dis[j],g[t][j]);
        }
    }
    return res;
}
int main(){
    
    cin>>n>>m;
    memset(g,63,sizeof g);
    int a,b,c;
    while(m--){
        cin>>a>>b>>c;
        g[a][b]=g[b][a]=min(g[a][b],c);
    }
    int t=prim();
    if(t==inf)cout<<"impossible"<<endl;
    else cout<<t<<endl;
}
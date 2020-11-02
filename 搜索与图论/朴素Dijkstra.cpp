#include<iostream>
#include<cstring>
using namespace std;
int n,m;
int g[510][510],dis[510],st[510];
void dij(){
    dis[1]=0;
    for(int i=0;i<n;i++){
        int t=-1;
        for(int j=1;j<=n;j++){
            if(!st[j]&&(t==-1||dis[t]>dis[j]))t=j;
        }
        st[t]=1;
        for(int j=1;j<=n;j++){
            dis[j]=min(dis[j],dis[t]+g[t][j]);
        }
    }
}
int main(){
    cin>>n>>m;
    memset(dis,63,sizeof dis);
    memset(g,63,sizeof g);
    for(int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        g[a][b]=min(g[a][b],c);
    }
    dij();
    if(dis[n]==0x3f3f3f3f)cout<<"-1"<<endl;
    else cout<<dis[n]<<endl;
    return 0;
}
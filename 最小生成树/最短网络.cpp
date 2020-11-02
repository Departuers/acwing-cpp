#include<cstring>
#include<iostream>
using namespace std;
int n,inf=0x3f3f3f3f;
int g[110][111],dis[111],st[110];
int prim(){
    int res=0;
    memset(dis,63,sizeof dis);
    dis[1]=0;
    for(int i=0;i<n;i++){
        int t=-1;
        for(int j=1;j<=n;j++){
            if(!st[j]&&(t==-1||dis[t]>dis[j]))t=j;
        }
        if(i&&dis[t]==inf)return inf;
        res+=dis[t];
        st[t]=1;
        for(int j=1;j<=n;j++){
            dis[j]=min(dis[j],g[t][j]);
        }
    }
    return res;
    
}
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>g[i][j];
        }
    }
    cout<<prim()<<endl;
    return 0;
}
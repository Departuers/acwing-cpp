#include<iostream>
#include<cstring>

using namespace std;
int n,g[510][510],st[510],dis[510];
int prim(){
    memset(dis,63,sizeof dis);
    dis[0]=0;
    int res=0;
    for(int i=0;i<=n;i++){
        int t=-1;
        for(int j=0;j<=n;j++)
            if(!st[j]&&(t==-1||dis[t]>dis[j]))t=j;
        res+=dis[t];
        st[t]=1;
        for(int j=0;j<=n;j++){
            dis[j]=min(dis[j],g[t][j]);
        }
    }
    return res;
}
int main(){
    cin>>n;
    for(int i=1;i<=n;i++)cin>>g[0][i],g[i][0]=g[0][i];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++){
            cin>>g[i][j];
        }
    cout<<prim()<<endl;
    return 0;
}
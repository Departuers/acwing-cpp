#include<iostream>
using namespace std;
int n,m,T,S;
double g[5100][2130];
double dis[5100];
bool st[3410];
void dij(){
    dis[S]=1;
    for(int i=1;i<=n;i++){
        int t=-1;
        for(int j=1;j<=n;j++){
            if(!st[j]&&(t==-1||dis[t]<dis[j]))t=j;
        }
        st[t]=1;
        for(int j=1;j<=n;j++){
            dis[j]=max(dis[j],dis[t]*g[t][j]);
        }
    }
}
int main(){
    cin>>n>>m;
    while(m--){
        int a,b,c;
        cin>>a>>b>>c;
        double z=(100.0-c)/100;
        g[a][b]=g[b][a]=max(g[a][b],z);
    }
    cin>>S>>T;
    dij();
    printf("%.8f",100/dis[T]);
    return 0;
}
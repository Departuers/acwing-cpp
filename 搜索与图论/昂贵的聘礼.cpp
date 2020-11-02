#include<iostream>
#include<cstring>
using namespace std;

const int N=110;
int n,m;
int w[N][N],level[N],st[N],dis[N];
int dij(int down,int up){
    memset(dis,63,sizeof dis);
    memset(st,0,sizeof st);
    dis[0]=0;
    for(int i=0;i<n;i++){
        int t=-1;
        for(int j=0;j<=n;j++){
            if(!st[j]&&(t==-1||dis[t]>dis[j]))t=j;
        }
        st[t]=1;
        for(int j=1;j<=n;j++){
            if(level[j]>=down&&level[j]<=up){
                dis[j]=min(dis[j],dis[t]+w[t][j]);
            }
        }
    }
    return dis[1];
}
int main(){
    cin>>m>>n;
    memset(w,63,sizeof w);
    for(int i=0;i<=n;i++)w[i][i]=0;
    for(int i=1;i<=n;i++){
        int price,cnt;
        cin>>price>>level[i]>>cnt;
        w[0][i]=price;
        while(cnt--){
            int id,cost;
            cin>>id>>cost;
            w[id][i]=min(w[id][i],cost);
        }
    }
    int res=1e9;
    for(int i=level[1]-m;i<=level[1];i++){
        res=min(res,dij(i,i+m));
    }
    cout<<res<<endl;
    return 0;
}
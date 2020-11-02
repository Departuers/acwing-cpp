#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
int n,m,p,idx=1,inf=0x3f3f3f3f;
const int N=5000,M=20010;
int h[N],e[M],ne[M],w[M],dis[M],st[N],g[N];
void add(int a,int b,int c){
    e[idx]=b;
    w[idx]=c;
    ne[idx]=h[a];
    h[a]=idx++;
}
int spfa(int s){
    memset(dis,63,sizeof dis);
    memset(st,0,sizeof st);
    dis[s]=0;
    queue<int> q;
    q.push(s);
    while(q.size()){
        int v=q.front();q.pop();
        st[v]=0;
        for(int i=h[v];i;i=ne[i]){
            int j=e[i];
            if(dis[j]>dis[v]+w[i]){
                dis[j]=dis[v]+w[i];
                if(!st[j]){
                    st[j]=1;
                    q.push(j);
                }
            }
        }
    }
    int res=0;
    for(int i=0;i<n;i++){
        int j=g[i];
        if(dis[j]==inf)return inf;
        res+=dis[j];
    }
    return res;
}

int main(){
    cin>>n>>p>>m;
    for(int i=0;i<n;i++){
        cin>>g[i];
    }
    for(int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        add(a,b,c);
        add(b,a,c);
    }
    int ans=1e9;
    for(int i=1;i<=p;i++){
        ans=min(ans,spfa(i));
    }
    cout<<ans<<endl;
    return 0;
}
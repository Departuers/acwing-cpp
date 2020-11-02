#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int inf=0x3f3f3f3f,N=100100,M=200100;
int p[N];
int n,m;
struct edge{
    int a,b,w;
    bool operator< (const edge &W)const {
        return w<W.w;
    }
}e[M];
int find(int x){
    if(x!=p[x])p[x]=find(p[x]);
    return p[x];
}
int kru(){
    sort(e,e+m);
    for(int i=1;i<=n;i++)p[i]=i;
    int res=0,cnt=0;
    for(int i=0;i<m;i++){
        int a=e[i].a,b=e[i].b,w=e[i].w;
        a=find(a),b=find(b);
        if(a!=b){
            p[a]=b;
            res+=w;
            cnt++;
        }
    }
    if(cnt<n-1)return inf;
    return res;
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++){
        int a,b,w;
        scanf("%d%d%d",&a,&b,&w);
        e[i]={a,b,w};
    }
    int k=kru();
    if(k==inf)puts("impossible");
    else cout<<k<<endl;
    return 0;
}
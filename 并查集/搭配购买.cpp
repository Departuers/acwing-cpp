//把一个连通块看成一个物品再用01背包来做,同时维护体积和价值,维护到根节点,
#include<iostream>
using namespace std;
const int N=10010;
int n,m,q,f[N],p[N],v[N],w[N];
int find(int x){
    if(p[x]!=x)p[x]=find(p[x]);
    return p[x];
}
int main(){
    for(int i=1;i<N;i++)p[i]=i;
    cin>>n>>m>>q;
    for(int i=1;i<=n;i++)cin>>v[i]>>w[i];
    while(m--){
        int a,b;
        cin>>a>>b;
        a=find(a),b=find(b);
        if(a!=b){
            v[b]+=v[a];
            w[b]+=w[a];
            p[a]=b;
        }
    }
    for(int i=1;i<=n;i++){
        if(p[i]==i){
            for(int j=q;j>=v[i];j--){
                f[j]=max(f[j],f[j-v[i]]+w[i]);
            }
        }
    }
    cout<<f[q]<<endl;
    return 0;
}
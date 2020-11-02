#include<iostream>
#include<bitset>
using namespace std;
const int N=30010;
bitset<N> f[N];
int h[N],e[N],ne[N],q[N],d[N],n,m,idx=1;
void topo(){
    int hh=0,tt=-1;
    for(int i=1;i<=n;i++){
        if(!d[i])q[++tt]=i;
    }
    while(hh<=tt){
        int t=q[hh++];
        for(int i=h[t];i;i=ne[i]){
            int j=e[i];
            if(!--d[j]){
                q[++tt]=j;
            }
        }
    }
}
void add(int a,int b){
    e[idx]=b;ne[idx]=h[a],h[a]=idx++;
}
int main(){
    cin>>n>>m;
    int a,b;
    while(m--){
        cin>>a>>b;
        add(a,b);
        d[b]++;
    }
    topo();
    for(int i=n-1;i>=0;i--){
        int j=q[i];
        f[j][j]=1;
        for(int k=h[j];k;k=ne[k]){
            f[j]|=f[e[k]];
        }
    }
    for(int i=1;i<=n;i++)cout<<f[i].count()<<endl;
    return 0;
}
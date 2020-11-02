#include<iostream>

using namespace std;
const int N=11001,M=20010;
int n,m;
int h[N],e[M],q[M],ne[M],din[N],dis[N],idx=1;
void add(int a,int b){
    e[idx]=b,ne[idx]=h[a];h[a]=idx++;
}
bool topo(){
    int hh=0,tt=-1;
    for(int i=1;i<=n;i++){
        if(!din[i]){
            q[++tt]=i;
        }
    }
    while(hh<=tt){
        int t=q[hh++];
        for(int i=h[t];i;i=ne[i]){
            int j=e[i];
            din[j]--;
            if(!din[j]){
                q[++tt]=j;
            }
        }
    }
    return tt==n-1;
}
int main(){
    cin>>n>>m;
    int a,b;
    while(m--){
        cin>>a>>b;
        add(b,a);
        din[a]++;
    }
    if(topo()){
        for(int i=1;i<=n;i++){
            dis[i]=100;
        }
        for(int i=0;i<n;i++){
            int j=q[i];
            for(int k=h[j];k;k=ne[k]){
                dis[e[k]]=max(dis[ e[k]],dis[j]+1);
            }
        }
        int res=0;
        for(int i=1;i<=n;i++){
            res+=dis[i];
        }
        cout<<res<<endl;
    }else puts("Poor Xed");
    return 0;
}
#include<iostream>
using namespace std;
const int N=110,M=N*N;
int q[M],h[N],e[M],ne[M],idx=1,n,m,in[N];
void add(int a,int b){
    e[idx]=b;
    ne[idx]=h[a];
    h[a]=idx++;
}
void topo(){
    int hh=0,tt=-1;
    for(int i=1;i<=n;i++){
        if(!in[i])q[++tt]=i;
    }
    while(hh<=tt){
        int t=q[hh++];
        for(int i=h[t];i;i=ne[i]){
            int j=e[i];
            in[j]--;
            if(!in[j])q[++tt]=j;
        }
    }
    for(int i=0;i<n;i++){
        cout<<q[i]<<" ";
    }
}
int main(){
    cin>>n;
    int s;
    for(int i=1;i<=n;i++){
        while(cin>>s,s){
            add(i,s);
            in[s]++;
        }
    }
    topo();
    return 0;
}
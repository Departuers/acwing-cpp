#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int p[6010],sizee[6100];
int n,m,t;
struct edge{
    int a,b,w;
    bool operator< (const edge &W)const {
        return w<W.w;
    }
}e[6120];
int find(int x){
    if(p[x]!=x)p[x]=find(p[x]);
    return p[x];
}
int main(){
    cin>>t;
    while(t--){
        
        int a,b,w;
        cin>>n;
        for(int i=0;i<n-1;i++){
            cin>>a>>b>>w;
            e[i]={a,b,w};
        }
        sort(e,e+n-1);
        for(int i=0;i<=n;i++){
            sizee[i]=1;
            p[i]=i;
        }
        int res=0;
        for(int i=0;i<n-1;i++){
             a=find(e[i].a),b=find(e[i].b);
             if(a!=b){
                 res+=(sizee[a]*sizee[b]-1)*(e[i].w+1);
                 sizee[b]+=sizee[a];
                 p[a]=b;
             }
        }
        cout<<res<<endl;
    }
    return 0;
}
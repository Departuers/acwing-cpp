#include<iostream>
#include<algorithm>

using namespace std;
int p[2010];
struct edge{
    int a,b,w;
    bool operator<(const edge &W)const {
        return w<W.w;
    }
}e[20010];
int find(int x){
    if(p[x]!=x)p[x]=find(p[x]);
    return p[x];
}
int main(){
for(int i=1;i<2010;i++)p[i]=i;
    int n,m;
    cin>>n>>m;
    int t,a,b,w,res=0;
    for(int i=0;i<m;i++){
        cin>>t>>a>>b>>w;
        if(t==1){
            res+=w;
            a=find(a),b=find(b);
            if(a!=b)p[a]=b;
        }else{
            e[i]={a,b,w};
        }
    }
    sort(e,e+m);
    for(int i=0;i<m;i++){
        a=find(e[i].a),b=find(e[i].b);
        if(a!=b){
            p[a]=b;
            res+=e[i].w;
        }
    }
    cout<<res<<endl;
    return 0;
}
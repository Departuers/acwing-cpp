#include<iostream>
#include<algorithm>
using namespace std;
int p[1010];
struct edge{
    int a,b,w;
    bool operator< (const edge &W)const {
        return w<W.w;
    }
}e[1010];
int find(int x){
    if(p[x]!=x)p[x]=find(p[x]);
    return p[x];
}

int main(){
    int n,m;
    cin>>n>>m;
    int b,a,w;
    for(int i=0;i<m;i++){
        p[i]=i;
        cin>>a>>b>>w;
        e[i]={a,b,w};
    }
    sort(e,e+m);
    int res=0;
    for(int i=0;i<m;i++){
        a=find(e[i].a),b=find(e[i].b);
        if(a!=b)p[a]=b;
        else res+=e[i].w;
    }
    cout<<res<<endl;
    return 0;
}
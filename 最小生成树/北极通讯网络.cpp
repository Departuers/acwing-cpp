#include<cmath>
#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,k,cnt=0;
struct edge{
    int a,b;
    double w;
    bool operator< (const edge &W) const {
        return w<W.w;
    }
}e[510*510];
int x[510],y[510],p[510];
int find(int x){
    if(p[x]!=x)p[x]=find(p[x]);
    return p[x];
}

double get(int x1,int y1,int x2,int y2){
    int dx=x2-x1,dy=y2-y1;
    return sqrt(dx*dx+dy*dy);
}
int main(){
    int a=1LL;
    cin>>n>>k;
    for(int i=0;i<n;i++){
        p[i]=i;
        cin>>x[i]>>y[i];
        for(int j=0;j<i;j++){
            double dis=get(x[i],y[i],x[j],y[j]);
            e[cnt++]={i,j,dis};
        }
    }
    sort(e,e+cnt);
    int num=n;
    double res=0;
    for(int i=0;i<cnt;i++){
        if(num<=k)break;
        int a=find(e[i].a),b=find(e[i].b);
        if(a!=b){
            num--;
            res=e[i].w;
            p[a]=b;
        }
    }
    printf("%.2f",res);
    return 0;
}
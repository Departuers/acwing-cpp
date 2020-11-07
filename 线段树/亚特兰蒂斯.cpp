#include <iostream>
#include <cstdio>
#include <algorithm>
#include<vector>
using namespace std;
const int inf = 0x3f3f3f3f,N=10010;
int n,m;
vector<double> ys;
struct se{
    int x,y1,y2,k;
    bool operator< (const se &t)const {
        return x<t.x;
    }
}seg[N<<1];
struct node{
    int l,r,cnt,len;
}tr[N<<2];

void build(int k,int l,int r){
    tr[k]={l,r,0,0};
    if(l==r)return ;
    int mid=l+r>>1;
    build(k<<1,l,mid),build(k<<1|1,mid+1,r);
}

void push(int k){
    if(tr[k].cnt)tr[k].len=tr[k].r-tr[k].l+1;
    else if(tr[k].l==tr[k].r)tr[k].len=0;
    else tr[k].len=tr[k<<1].len+tr[k<<1|1].len;
}
void up(int k,int l,int r,int u){
    if(tr[k].l>=l&&tr[k].r<=r){
        tr[k].cnt+=u;
    }else {
        int mid=tr[k].l+tr[k].r>>1;
        if(l<=mid)up(k<<1,l,r,u);
        if(r>mid)up(k<<1|1,l,r,u);
    }
    push(k);
}
int main(){
    scanf("%d",&n);
    m=0;
    int x1,x2,y1,y2;
    for(int i=0;i<n;i++){
        scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
        seg[m++]={x1,y1,y2,1};
        seg[m++]={x2,y1,y2,-1};
    }
    sort(seg,seg+m);
    build(1,0,10000);
    int res=0;
    for(int i=0;i<m;i++){
        if(i)res+=tr[1].len*(seg[i].x-seg[i-1].x);
        up(1,seg[i].y1,seg[i].y2-1,seg[i].k);
    }
    cout<<res<<endl;
    return 0;
}
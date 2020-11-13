#include <cstdio>
#include<algorithm>
using namespace std;
const int N = 10100;
int m,n;
struct t
{
    int l, r, cnt, len;
} tr[N << 2];
struct segm
{
    int x, y1, y2, k;
    bool operator<(const segm &T) const
    {
        return x < T.x;
    }
} seg[N*2];
void build(int k,int l,int r){
    tr[k]={l,r};
    if(l!=r){
        int mid=l+r>>1;
        build(k<<1,l,mid),build(k<<1|1,mid+1,r);
    }
}
void push(int k){
    if(tr[k].cnt>0)tr[k].len=tr[k].r-tr[k].l+1;
    else if(tr[k].l==tr[k].r)tr[k].len=0;
    else tr[k].len=tr[k<<1].len+tr[k<<1|1].len;
}
void up(int k,int l,int r,int v){
    if(tr[k].l>=l&&tr[k].r<=r){
        tr[k].cnt+=v;
    }else{
        int mid=tr[k].l+tr[k].r>>1;
        if(l<=mid)up(k<<1,l,r,v);
        if(r>mid)up(k<<1|1,l,r,v);
    }
    push(k);
}
int main(int argc, char const *argv[])
{
    scanf("%d",&n);
    int x1,x2,y1,y2;
    for(int i=0;i<n;i++){
        scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
        seg[m++]={x1,y1,y2,1};
        seg[m++]={x2,y1,y2,-1};
    }
    sort(seg,seg+m);
    build(1,0,10001);
    int res=0;
    for(int i=0;i<m;i++){
        if(i)res+=tr[1].len*(seg[i].x-seg[i-1].x);
        up(1,seg[i].y1,seg[i].y2-1,seg[i].k);
    }
    printf("%d",res);
    return 0;
}

#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
const int inf = 0x3f3f3f3f,N=100010;
int n, m;
struct tree
{
    int l,r,cnt,len;
}tr[N];
void pushup(int k){
    if(tr[k].cnt>0)tr[k].len=tr[k].r-tr[k].l+1;
    else if(tr[k].l==tr[k].r)tr[k].len=0;//cnt=0 判断是不是叶子节点
    else
        tr[k].len=tr[k<<1].len+tr[k<<1|1].len;
}
void build(int k,int l,int r){
    tr[k]={l,r};
    if(l==r)return;
    int mid=l+r>>1;
    build(k<<1,l,mid),build(k<<1|1,mid+1,r);
}
void up(int k,int l,int r,int u){
    if (tr[k].l>=l&&tr[k].r<=r)
    {
        tr[]
    }
    
}

int main(int argc, char const *argv[])
{
    return 0;
}
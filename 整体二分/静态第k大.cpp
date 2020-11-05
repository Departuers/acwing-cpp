#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
const int inf = 0x3f3f3f3f,N=100100,M=N/2;
int n, m,idx;
struct node
{
    int op;
    int x,y,z;
    int k;
};
typedef long long ll;
node q[N],lq[N],rq[N];
int tr[N],ans[M];
void add(int x,int v){
    for(;x<=n;i++)tr[x]+=v;
}
ll ask(int x){
    ll r=0;
    for(;x;x-=(x&-x))r+=tr[x];
    return r;
}
void solve(int vl,int vr,int ql,int qr){
    
}
int main(int argc, char const *argv[])
{
    return 0;
}
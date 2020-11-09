#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>
#include <vector>
#include <cstring>
#include <unordered_map>
#include <deque>
#define x first
#define y second
using namespace std;
const int inf = 0x3f3f3f3f,N=10100;
int n, m, ans;
int a[N],up[N],down[N];
void dfs(int u,int su,int sd){
    if(su+sd>=ans)return;
    if(u==n){
        ans=su+sd;
        return;
    }

    //把当前数当到上升子序列里面去
    int j=0;
    while (j<su&&a[u]<=up[j])j++;
    int t=up[j];
    up[j]=a[u];
    if(j<su)dfs(u+1,su,sd);
    else dfs(u+1,su+1,sd);
    up[j]=t;

    //把当前数当到下降子序列里面去
    j=0;
    while (j<=sd&&a[u]>=down[j])j++;
    int t=down[j];
    down[j]=a[u];
    if(j<sd)dfs(u+1,su,sd);
    else dfs(u+1,su,sd+1);
    down[j]=t;
}
int main(int argc, char const *argv[])
{
    while (cin >> n, n)
    {
        for (int i = 0; i < n; i++)
            cin >> a[i];
        ans=n;
        dfs(0,0,0);
        cout<<ans<<endl;
    }
    return 0;
}
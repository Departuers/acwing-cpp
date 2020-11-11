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
const int inf = 0x3f3f3f3f;
int n, m;
typedef pair<int, int> PII;
/**
 * f[i,1]表示选择以i为根的子树,选择了i顶点的最大快乐指数
 * f[i,0]表示选择以i为根的子树,不选择了i顶点的最大快乐指数
 * 一条边最多只能选一个点
 * f[u,1]=f[j,0]+...+happy[u]选择u不选择u的子节点,且加上u的快乐值
 * f[u,0]=max(f[j,0],f[j,1])不选当前节点,则子节点可选可不选
 * */
const int N=6010;
int happy[N];
int h[N],e[N],ne[N],idx=1,f[N][2],hasfa[N];
void dfs(int u){
    f[u][1]=happy[u];
    for(int i=h[u];i;i=ne[i]){
        int j=e[i];
        dfs(j);
        f[u][1]+=f[j][0];
        f[u][0]+=max(f[j][1],f[j][0]);
    }
}
void add(int a,int b){
    e[idx]=b,ne[idx]=h[a],h[a]=idx++;
}

int main(int argc, char const *argv[])
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)cin>>happy[i];
    for(int i=0;i<n-1;i++){
        int a,b;
        cin>>a>>b;
        add(b,a);
        hasfa[a]=1;
    }
    int root=1;
    while (hasfa[root])root++;
    dfs(root);
    cout<<max(f[root][1],f[root][0]);
    return 0;
}
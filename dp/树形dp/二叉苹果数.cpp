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
const int inf = 0x3f3f3f3f,N=110;
int n, m;
typedef pair<int, int> PII;
/* 其实是有依赖的背包问题,
 * f(i,j)以i为根的子树中选择j条边的最大价值
 * 比如i点可以选j条边
 *        i
 *     w/   \
 *    s1     s2
 * 物品组1    物品组2
 * 选择一个物品组,就必须保留这条边,
 * 在第一个物品组选择0条边 对应f(s1,0) 价值还要加上必选的那条边,w
 * 第一个个物品组选择1条边,对应f(s1,1) 如上
 * 显然按照选多少条边来划分枚举
 * 再利用分组背包的思想解决
 * 把选0个物品,选1个物品,选2个物品...选m个物品,都看作体积是1的物品
 */
int f[N][N],h[N],e[N<<1],w[N<<1],ne[N<<1],idx=1;
void add(int a,int b,int c){
    e[idx]=b,w[idx]=c,ne[idx]=h[a],h[a]=idx++;
}
void dfs(int u,int fa){
    for(int i=h[u];i;i=ne[i]){
        int son=e[i];
        if(son==fa)continue;
        dfs(son,u);
        for(int j=m;j>=0;j--){//枚举体积
            for(int k=0;k<j;k++){//每条边的体积都是1,枚举决策k条边
                f[u][j]=max(f[u][j],f[u][j-k-1]+f[son][k]+w[i]);
            }
        }
    }
}
int main(int argc, char const *argv[])
{
    cin>>n>>m;
    int a,b,c;
    for(int i=0;i<n-1;i++)
    {
        cin>>a>>b>>c;
        add(a,b,c);
        add(b,a,c);
    }
    dfs(1,-1);
    cout<<f[1][m]<<endl;
    return 0;
}
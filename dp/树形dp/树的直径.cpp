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
 * 给定一棵树，树中包含 n个结点（编号1~n）和 n−1 条无向边，每条边都有一个权值。
现在请你找到树中的一条最长路径。
换句话说，要找到一条路径，使得使得路径两端的点的距离最远。
注意：路径中可以只包含一个点。
输入格式
第一行包含整数 n。
接下来 n−1行，每行包含三个整数 ai,bi,ci，表示点 ai和 bi 之间存在一条权值为 ci 的边。
输出格式
输出一个整数，表示树的最长路径的长度。
数据范围
1≤n≤10000
1≤ai,bi≤n,
−10^5≤ci≤10^5
输入样例：
6
5 1 6
1 4 5
6 3 9
2 6 8
6 1 7
输出样例：
22
注意：由于本题的树是无向的，所以在做DFS是遇见遍历到某节点的根节点时需要跳过。
对于没有边权的树,它的直径就是最多经过的边数
经典做法:
1.任取两个点作为起点,找到距离该点的最短点u
2.从u找到距离u最远的点v (BFS)
那么u和v之间的路径就是一条直径

用树形dp
枚举所有的路径,在所有路径找边权最大值,
由于是无向树,所以,所有的点都有可能是根节点
先随便选一个点作为根节点,变成一颗树
以每个点来分类,每条路径归结到一个点上
把所有的路径分到点上
每个点上代表所有路径上最高的点是那个点的所有最长路径,
每条直径都有一条唯一的最高点
求每个点挂的所有路径长度的最大值
对于每个子节点,求出往下走的最大长度和次大长度,加上子节点到根节点这条边,可以是一条路径
就是所有穿过该点的路径的最大长度
所有挂在这个点的路径分成往下走 
 * */
const int N = 10010, M = N * 2;
int e[M], h[N], ne[M], w[M], idx = 1, ans;
void add(int a, int b, int c)
{
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}
int dfs(int u, int fa)
{
    int d1 = 0, d2 = 0; //d1代表当前这个点往下走的最大长度,d2是次大长度
    //初始化为0,如果往下走的边权为负数,就不要这条边
    for (int i = h[u]; i; i = ne[i])
    {
        int j = e[i];
        if (j == fa)
            continue;
        int d = dfs(j, u) + w[i];
        if (d >= d1)
            d2 = d1, d1 = d;
        else if (d > d2)
            d2 = d;
    }
    ans = max(ans, d1 + d2);
    return d1;
}
int main(int argc, char const *argv[])
{
    cin >> n;
    int a, b, c;
    for (int i = 0; i < n - 1; i++)
    {
        cin >> a >> b >> c;
        add(a, b, c), add(b, a, c);
    }
    dfs(1, -1);
    cout << ans << endl;
    return 0;
}
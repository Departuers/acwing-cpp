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
typedef long long ll;
ll f[3010], v[3100];
/**
 * 给你一个n种面值的货币系统，求组成面值为m的货币有多少种方案。
 * 完全背包
 * f[i,j]表示从前i种物品选,体积恰好是j的所有方案
 * 属性方案数count
 * 考虑第i种物品选k个
 * f[i,j]=f[i-1,j]+ f[i-1,j-v[i]]+w[i]+f[i-1,j-2v[i]]+2w[i] +...+f[i-1,j-kv[i]]+kw[i])  (j>=k[i])
 * f[i,j-v]=        f[i-1,j-v[i]]+w[i]+f[i-1,j-2v[i]]+2w[i] +...+f[i-1,j-kv[i]]+kw[i])  (j>=k[i])
 * 从而f[i][j] = f[i][j-v[i]] + f[i-1][j]
 * */
int main(int argc, char const *argv[])
{
    cin >> n >> m;
    f[0] = 1;
    for (int i = 1; i <= n; i++)
        cin >> v[i];
    for (int i = 1; i <= n; i++)
    {
        for (int j = v[i]; j <= m; j++)
        {
            f[j] += f[j - v[i]];
        }
    }
    cout << f[m] << endl;
    return 0;
}
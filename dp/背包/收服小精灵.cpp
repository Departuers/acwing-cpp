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
const int inf = 0x3f3f3f3f, N = 1010, M = 510, K = 104;
int n, m, f[N][M], k, v[K], w[K];
/**
 * f[i,j,k]表示前i个精灵中使用不超过j个精灵球
 * 和不超过k的体力最大能收服的数量
 * 最后一维枚举体力,体力不能用完
 * 考虑选不选第i个物品
 * f[i,j,k]=max(f[i-1][j-v1[i]][k-v2[i]]+1,f[i-1,j,k])
 * 
 * */
int main(int argc, char const *argv[])
{
    cin >> n >> m >> k;
    for (int i = 1; i <= k; i++)
        cin >> v[i] >> w[i];
    for (int i = 1; i <= k; i++)
    {
        for (int v1 = n; v1 >= v[i]; v1--)
        {
            for (int v2 = m - 1; v2 >= w[i]; v2--)
            {
                f[v1][v2] = max(f[v1][v2], f[v1 - v[i]][v2 - w[i]] + 1);
            }
        }
    }
    cout << f[n][m - 1] << " ";
    int i = m - 1;
    while (i > 0 && f[n][i - 1] == f[n][m - 1])
        i--;
    cout << m - i << endl;
    return 0;
}
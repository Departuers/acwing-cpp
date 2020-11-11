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
const int inf = 0x3f3f3f3f, N = 20;
int n, m, f[N][N], w[N][N], path[N];
/**
 * 故状态表示f[i][j]表示在前i家公司中选择分配不超过j台设备的最大盈利。
 * 状态转移方程为f[i][j] = max(f[i-1][j-k]+w[i][k])，其中j >= k。
 * 
 * */
int main(int argc, char const *argv[])
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> w[i][j];
        }
    }
    for (int i = 1; i <= n; i++) //枚举物品
    {
        for (int j = 1; j <= m; j++) //枚举体积
        {
            for (int k = 0; k <= j; k++) //枚举每一组选择物品数量
            {
                f[i][j] = max(f[i][j], f[i - 1][j - k] + w[i][k]);
            }//每个物品体积都为1
        }
    }

    cout << f[n][m] << endl;
    for (int i = n; i >= 1; i--)
    {
        for (int k = 0; k <= m; k++)
        {
            if (f[i][m] == f[i - 1][m - k] + w[i][k])
            {
                //这个时候f[i,m]是答案,往前推
                path[i] = k;//代表第i家公司分配了多少
                m -= k;
                break;
            }
        }
    }
    for (int i = 1; i <=n; i++)
    {
        printf("%d %d\n",i,path[i]);
    }
    
    return 0;
}
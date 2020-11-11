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
int n, m, k, f[2010][2020], v1[1010], v2[1010], w[1010];
/**
 * 而本题相反，需要求出满足氧气和氮气体积需要的前提下所带气缸的最小重量，
 * 抽象一下就是花费1和花费2不小于某数的最小价值。
 * f[i,j,k]表示从前i个物品中选出若干个气缸使得氧气不小于j,氮气不小于k的最小值
 * 而二维体积背包是这样f[i,j,k]=min(f[i-1,j,k],f[i-1][j-v1][k-v2]+w)
 * 边界条件,初始化大不相同
 * f[0,j,k]=inf 不可达,从含义出发
 * 对于负数情况f[0,-1,-1]也是合法的,j>=v1,k>=v2没有必要
 * 比如f[0][-1][-1]，尽管一个物品都不选，显然体积是大于负数的
 * 
 * f[0,j,k]对于j k都小于0视为f[0,0,0]
 * 最终为f[i,j,k]=min(f[i-1,j,k],f[i-1,max(0,j-v1),max(0,k-v2)])
 * 由于用到上一层左边的状态,所以要倒着枚举
 * 
 * */
int main(int argc, char const *argv[])
{
    cin >> m >> k >> n;
    memset(f, 63, sizeof f);

    f[0][0] = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> v1[i] >> v2[i] >> w[i];
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = m; j >= 0; j--)
        {
            for (int k1 = k; k1 >= 0; k1--)
            {
                int t1 = max(j - v1[i], 0), t2 = max(k1 - v2[i], 0);
                f[j][k1] = min(f[j][k1], f[t1][t2] + w[i]);
            }
        }
    }
    cout << f[m][k] << endl;
    return 0;
}
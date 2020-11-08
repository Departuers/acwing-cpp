#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
const int inf = 0x3f3f3f3f;
int n, m;
int a[110][110];
int f[110][110][110];
/**
 * 跟方格取数不同的是,这一次每个位置只能经过一次,
 * 方格取数是从左上角走到右下角走两次，走过的数只能被取一次，
 * 而本题是一个人从左上角往右下角走，另一个从右下角向左上角走，
 * 一个人只能传一次纸条。
 * 所以我们可以不计算走到同一个格子的状态，即i1 == i2时直接跳过即可，
 * 不存在同一个人传递两次纸条的情况，
 * 需要注意的是，终点（m，n）是我们状态转移的终点，其好心程度为0，
 * 所以需要转移到终点这种状态。
 * 状态转移方程为
 * f[k][i1][i2] = max(f[k-1][i1-1][i2-1],f[k-1][i1][i2],f[k-1][i1-1][i2],f[k-1][i1][i2-1]) + w[i1][j1] + w[i2][j2]
 * */
int main(int argc, char const *argv[])
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> a[i][j];
    for (int k = 2; k <= n + m; k++)
    {
        for (int i1 = 1; i1 <= n; i1++)
            for (int i2 = 1; i2 <= n; i2++)
            {
                if (i1 != i2 || k == m + n)
                {
                    int j1 = k - i1, j2 = k - i2;
                    if (j1 > 0 && j1 <= m && j2 > 0 && j2 <= m)
                    {
                        int t = a[i1][j1] + a[i2][j2];
                        f[k][i1][i2] = max(max(f[k - 1][i1 - 1][i2 - 1], f[k - 1][i1][i2]), max(f[k - 1][i1 - 1][i2], f[k - 1][i1][i2 - 1])) + t;
                    }
                }
            }
    }
    cout << f[n + m][n][n] << endl;
    return 0;
}
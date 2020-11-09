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
const int inf = 0x3f3f3f3f, N = 31000;
int n, m;
/**
 * https://blog.csdn.net/qq_30277239/article/details/104064303
 * f[i,j]表示由第一个序列前i个字母,和第二个序列的前j个字母构成的
 * 且以b[j]结尾的公共上升子序列
 * 划分依据,包不包含a[i]
 * 不包含a[i] 最大值为f[i-1,j]
 * 包含a[i],
 * ________a[i]
 * ________a[i]
 * ...
 * a[i]=b[j]
 * 继续划分:根据倒数第二个数,包含a[i]的最长上升子序列
 * 空,b[1],b[2],b][3]...b[k]
 * 枚举序列倒数第2个数是什么
 * f[i,k]+1
 * */
int a[N], b[N], f[N][N];
int main(int argc, char const *argv[])
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        cin >> b[i];
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            f[i][j] = f[i - 1][j];
            if (a[i] == b[j])
            {
                f[i][j] = max(f[i][j], 1);
                for (int k = 1; k < j; k++)
                {
                    if (b[j] > b[k]) //这里a[i]==b[j]实际上和j没有关系是一个前缀最大值
                        f[i][j] = max(f[i][k] + 1, f[i][j]);
                }
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        int maxv = 1; //用一个遍历记录前缀最大值
        for (int j = 1; j <= n; j++)
        {
            f[i][j] = f[i - 1][j];
            if (a[i] == b[j])
                f[i][j] = max(f[i][j], maxv);
            if (a[i] > b[j])
                maxv = max(maxv, f[i][j] + 1);
        }
    }

    int res = 0;
    for (int i = 1; i <= n; i++)
    {
        res = max(f[n][i], res);
    }
    cout << res << endl;
    return 0;
}
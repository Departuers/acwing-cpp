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
const int inf = 0x3f3f3f3f, N = 10100;
int n, m;
/**
 * https://blog.csdn.net/qq_30277239/article/details/104098822
 * 给定N个正整数A1,A2,…,AN，从中选出若干个数，使它们的和为M，求有多少种选择方案。
 * f[i,j]表示前i个物品中选,且体积恰好是j的方案数
 * 注意是恰好!!!
 * 属性count
 * f[i,j]
 * 划分依据,包不包含物品i
 * f[i,j]=f[i-1,j]+f[i-1,j-v[i]]
 * 01背包,
 * */
int v[N], w[N], f[N];
int main(int argc, char const *argv[])
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> v[i];
    f[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = m; j >= v[i]; j--)//代表01背包倒序枚举
        {
            f[j] += f[j - v[i]];
        }
    }
    cout << f[m] << endl;
    return 0;
}
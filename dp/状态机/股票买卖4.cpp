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
const int inf = 0x3f3f3f3f, N = 100100, M = 105;
int n, m, f[N][M][2];
typedef pair<int, int> PII;
/**
 * 给定一个长度为 N 的数组，数组中的第 i 个数字表示一个给定股票在第 i天的价格。
设计一个算法来计算你所能获取的最大利润，你最多可以完成 k笔交易。
注意：你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。一次买入卖出合为一笔交易。
输入格式
第一行包含整数 N和 k，表示数组的长度以及你可以完成的最大交易数量。
第二行包含 N个不超过 10000的正整数，表示完整的数组。
输出格式
输出一个整数，表示最大利润。
数据范围
1≤N≤10^5,
1≤k≤100
输入样例1：
3 2
2 4 1
f[i,j,0]表示第i天进行了j次交易并且未持仓
f[i,j,1]表示第i天进行了j次交易并持仓
考虑转移
f[i,j,0]可以是前一天也未持仓,也可以是昨天卖了
f[i,j,0]=max(f[i-1,j,0],f[i-1,j,1]+a[i]) 我们规定卖出不消耗次数,买入消耗次数
f[i,j,1]可以是前一天买了今天没卖,也可以是昨天没买,今天买上
f[i,j,1]=max(f[i-1,j,1],f[i-1,j-1,0]-a[i] )
考虑初始化
f[0,i,j]考虑当i,j皆不为0,显然非法,求最大值,初始化为-INF
 * */

int main(int argc, char const *argv[])
{
    cin >> n >> m;
    memset(f, -63, sizeof f);
    f[0][0][0] = 0;
    int price = 0;
    for (int i = 1; i <= n; i++) //枚举天数
    {
        cin >> price;
        f[i][0][0] = 0;
        for (int j = 1; j <= m; j++) //枚举交易次数
        {
            f[i][j][0] = max(f[i - 1][j][0], f[i - 1][j][1] + price);
            f[i][j][1] = max(f[i - 1][j][1], f[i - 1][j - 1][0] - price);
        }
    }
    int r = 0;
    for (int i = 0; i < M; i++)
    {
        r = max(f[n][i][0], r);
    }
    cout << r << endl;
    return 0;
}
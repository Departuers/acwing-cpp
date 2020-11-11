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
const int inf = 0x3f3f3f3f, N = 100010;
int n, m, f[N][3], price;
typedef pair<int, int> PII;
/**
 * f[i,0] 表示第i天未持仓
 * 前一天也没持仓,或者前一天持仓今天卖了
 * f[i][0] = max(f[i - 1][0], f[i - 1][1] + price);
 * f[i,1] 表示第i天持仓
 * 前一天没持仓2天前买的,前一天也持仓
 * f[i][1] = max(f[i - 2][0] - price, f[i - 1][1]);
 * 
 * 根据状态定义,从实际含义出发
 * 
 * */
int main(int argc, char const *argv[])
{
    cin >> n >> price;
    f[1][1] = -price; //第一天买了
    f[1][0] = 0;      //第一天啥都没干
    for (int i = 2; i <= n; i++)
    {
        cin >> price;
        f[i][0] = max(f[i - 1][0], f[i - 1][1] + price);
        f[i][1] = max(f[i - 2][0] - price, f[i - 1][1]);
    }
    cout << f[n][0] << endl;
    return 0;
}
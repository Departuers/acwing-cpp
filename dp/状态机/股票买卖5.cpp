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
int n, m, f[N][3];
typedef pair<int, int> PII;
/**
 * f[i,0] 表示第i天持仓
 * 可以是前一天买了,今天没卖,也可以是前一天没买,今天买的
 * f[i,0]=max(f[i-1][0],f[i-1][2]+price)
 * 
 * f[i,1] 表示刚卖出去的第1天
 * 前一天是卖出去的第2+天
 * f[i,1]=f[i-1][2]-price;
 * 
 * f[i,2] 表示刚卖出去的第2天以后
 * 根据状态定义,从实际含义出发
 * 前一天,是卖出去的第一天,或者前一天是卖出去的第2+天
 * f[i,2]=max(f[i-1,2],f[i-1][1])
 * 
 * 考虑初始化
 * 第0天不能是刚卖出去的第1天,也不能持仓,
 * 则f[0][0] = f[0][1] = -1e9;
 * 
 * */
int main(int argc, char const *argv[])
{
    cin >> n;
    int price;
    f[0][0] = f[0][1] = -1e9;
    for (int i = 1; i <= n; i++)
    {
        cin >> price;
        f[i][0] = max(f[i - 1][0], f[i - 1][2] - price);
        f[i][1] = f[i - 1][0] + price;
        f[i][2] = max(f[i - 1][1], f[i - 1][2]);
    }
    cout << max(f[n][1], f[n][2]) << endl;
    return 0;
}
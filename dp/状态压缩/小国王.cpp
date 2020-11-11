#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
/**
 * https://blog.csdn.net/qq_30277239/article/details/104202667
 * 在 n×n 的棋盘上放 k 个国王，国王可攻击相邻的 8个格子，求使它们无法互相攻击的方案总数。
输入格式
共一行，包含两个整数 n和 k。
输出格式
共一行，表示方案总数，若不能够放置则输出0。
数据范围
1≤n≤10,
0≤k≤n^2
输入样例：
3 2
输出样例：
16
由于只有10行最多,可以二进制枚举每一行的状态
f[i,j,k]表示只考虑前i行,且放置了j个国王,且当前行状态为k的所有方案数
划分依据,枚举倒数第二行,也就是第i-1行,由于当前状态是k,考虑是由哪一个状态转移过来的,
也就是枚举不与k冲突的状态
f[i,j,k]=f[i,j,k]+f[i-1,j-cnt[i],k`] 其中k`是不与k冲突的状态

在统一行中考虑到不能有2个相邻的可以用st&(st>>1)为0
说明不存在相邻两列为1

考虑国王可以攻击到上面的格子,上下不存在相邻国王,可以用s&t为0判断
上下对角线不存在相邻格子可以用,s|t判断是否存在相邻的两个1
 * */
const int N = 12, M = 104, K = 1 << 10;
typedef long long ll;
vector<int> state;
int n, m, f[N][M][K];
vector<int> head[M], cnt;
//判断是否存在相邻的两个1
bool check(int st)
{
    return (st & (st >> 1)) == 0;
}
//统计t的二进制表示有多少个1
int count(int t)
{
    int r = 0;
    while (t)
    {
        t -= (t & -t);
        r++;
    }
    return r;
}
int main(int argc, char const *argv[])
{
    cin >> n >> m;
    for (int i = 0; i < 1 << n; i++)
    {
        if (check(i))
            state.push_back(i), cnt.push_back(count(i));
    }
    for (int i = 0; i < state.size(); i++)
    {
        for (int j = 0; j < state.size(); j++)
        {
            int a = state[i], b = state[j];
            if ((a & b) == 0 && check(a | b))
                head[a].push_back(b);
        }
    }
    f[0][0][0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            for (int k = 0; k < state.size(); k++)
            {
                int t = state[k];
                for (auto u : head[t])
                {
                    if (j >= cnt[k])
                        f[i][j][t] += f[i - 1][j - cnt[k]][u];
                }
            }
        }
    }
    ll r = 0;
    for (int i = 0; i < state.size(); i++)
    {
        r += f[n][m][state[i]];
    }
    cout << r << endl;
    return 0;
}

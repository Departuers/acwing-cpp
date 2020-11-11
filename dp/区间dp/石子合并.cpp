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
int n, m;
typedef pair<int, int> PII;
/**
 * f[i,j]表示表示所有从i~j这一段合并的方案
 * 属性:min
 * f[i,j]状态划分根据最后一个不同点划分成若干个子集
 * 划分依据,考虑分界点
 * (i___)k(____j) 
 * 先合并i~k,在合并k~j这一段,最后合并i~j这一段
 * 枚举分界点k
 * f[l,k]+f[k+1,r]+S[l,r]其中S是区间和
 * */
int s[410], f[410][410];
int main(int argc, char const *argv[])
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> s[i];
        s[i] += s[i - 1];
    }
    for (int len = 2; len <= n; len++)//区间长度
    {
        for (int l = 1; l + len - 1 <= n; l++)//左端点
        {
            int r = l + len - 1;//右端点
            f[l][r] = 1e9;
            for (int k = l; k < r; k++)
            {
                f[l][r] = min(f[l][r], f[l][k] + f[k + 1][r] + s[r] - s[l - 1]);
            }
        }
    }
    cout << f[1][n] << endl;
    return 0;
}
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
int f[32010];
PII zhu[70];
vector<PII> fu[70];
/**
 * 分组背包加上每一组二进制枚举附件的选择
 * */
int main(int argc, char const *argv[])
{
    cin >> m >> n;
    int v, p, q;
    for (int i = 1; i <= n; i++)
    {
        cin >> v >> p >> q;
        if (q)
            fu[q].push_back({v, p * v});
        else
            zhu[i] = {v, p * v};
    }
    for (int i = 1; i <= n; i++) //枚举物品
    {
        if (!zhu[i].x)
            continue;                //不是主件
        for (int j = m; j >= 0; j--) //枚举体积
        {

            //二进制枚举附件选择
            for (int k = 0; k < 1 << fu[i].size(); k++)
            {
                int v = zhu[i].x, w = zhu[i].y; //先把主件选上
                for (int u = 0; u < fu[i].size(); u++)
                {
                    if (k >> u & 1)
                    {
                        v += fu[i][u].x;
                        w += fu[i][u].y;
                    }
                }
                if (j >= v)
                    f[j] = max(f[j], f[j - v] + w);
            }
            
        }
    }
    cout << f[m] << endl;
    return 0;
}
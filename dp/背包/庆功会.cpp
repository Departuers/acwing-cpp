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
int n, m, v[510], w[510], f[1010], s[510];
/**
 * 多重背包
 * 
 * */
int main(int argc, char const *argv[])
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> v[i] >> w[i] >> s[i];
    for (int i = 1; i <= n; i++)
    {
        for (int k = 1; k <= s[i]; k <<= 1)
        {
            for (int j = m; j > k * v[i]; j--)
            {
                f[j] = max(f[j], f[j - k * v[i]] + k * w[i]);
            }
            s[i] -= k;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (s[i] > 0)
            for (int j = m; j > s[i] * v[i]; j--)
            {
                f[j] = max(f[j], f[j - s[i] * v[i]] + s[i] * w[i]);
            }
    }
    cout<<f[m]<<endl;
    return 0;
}
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
const int inf = 0x3f3f3f3f, N = 1010, mod = 1e9 + 7;
int n, m, f[N], cnt[N], v[N], w[N];
int main(int argc, char const *argv[])
{
    cin >> n >> m;
    memset(f, -63, sizeof f);
    f[0] = 0;
    cnt[0] = 1;
    for (int i = 1; i <= n; i++)
        cin >> v[i] >> w[i];
    for (int i = 1; i <= n; i++)
    {
        for (int j = m; j >= v[i]; j--)
        {
            int maxv = max(f[j], f[j - v[i]] + w[i]);
            int count = 0;
            if (maxv == f[j])
                count += cnt[j];
            if (maxv == f[j - v[i]] + w[i])
                count += cnt[j - v[i]];
            cnt[j] = count % mod;
            f[j] = maxv;
        }
    }
    int res = f[m];
    int count = 0;
    for (int i = 0; i <= m; i++)
    {
        if (res == f[i])
        {
            count = (count + cnt[i]) % mod;
        }
    }
    cout << count << endl;
    return 0;
}
#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>
#include <vector>
#include <cstring>
#include <unordered_map>
#include <deque>
using namespace std;
const int inf = 0x3f3f3f3f, N = 1010;
int n, m, a[N], f[N], g[N];
int main(int argc, char const *argv[])
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
    {
        f[i] = 1;
        for (int j = 0; j < i; j++)
        {
            if (a[i] > a[j])
                f[i] = max(f[i], f[j] + 1);
        }
    }
    for (int i = n - 1; i >= 0; i--)
    {
        g[i] = 1;
        for (int j = i + 1; j < n; j++)
        {
            if (a[i] > a[j])
                g[i] = max(g[i], g[j] + 1);
        }
    }
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        res = max(f[i] + g[i] - 1, res);
    }

    cout << res << endl;
    return 0;
}
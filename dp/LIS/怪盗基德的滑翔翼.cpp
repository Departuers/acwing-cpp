#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
const int inf = 0x3f3f3f3f, N = 101000;
int n, m;
int a[N], f[N], g[N];
int main(int argc, char const *argv[])
{
    cin >> m;
    while (m--)
    {
        cin >> n;
        for (int i = 0; i < n; i++)
            cin >> a[i];

        int res = 0;
        for (int i = 0; i < n; i++)
        {
            f[i] = 1;
            for (int j = 0; j < i; j++)
            {
                if (a[i] > a[j])
                    f[i] = max(f[i], f[j] + 1);
            }
            res = max(res, f[i]);
        }
        for (int i = n - 1; i >= 0; i--)
        {
            g[i] = 1;
            for (int j = n; j > i; j--)
            {
                if (a[i] > a[j])
                {
                    g[i] = max(g[i], g[j] + 1);
                }
                res = max(g[i], res);
            }
        }
        cout << res << endl;
    }

    return 0;
}
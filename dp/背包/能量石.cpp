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
const int inf = 0x3f3f3f3f, N = 11000;
int n, m, T, f[N];
typedef pair<int, int> PII;
struct ST
{
    int s, e, l;
    bool operator<(const ST &W) const
    {
        return s * W.l < l * W.s;
    }
}stone[N];

int main(int argc, char const *argv[])
{
    
    cin >> T;

    for (int C = 1; C <= T; C++)
    {
        int n;
        cin >> n;
        int m = 0;
        for (int i = 0; i < n; i++)
        {
            int s, e, l;
            cin >> s >> e >> l;
            stone[i] = {s, e, l};
            m += s;
        }
        sort(stone, stone + n);
        memset(f, -63, sizeof f);
        f[0] = 0;
        
        for (int i = 0; i < n; i++)
        {
           int s = stone[i].s, e = stone[i].e, l = stone[i].l;
            for (int j = m; j >= s; j--)
            {
                f[j] = max(f[j], f[j - s] + e - (j - s) * l);
            }
        }
        int res = 0;
        for (int i = 0; i <= m; i++)
            res = max(res, f[i]);
        printf("Case #%d: %d\n", C, res);
    }

    return 0;
}
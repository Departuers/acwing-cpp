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
const int inf = 0x3f3f3f3f, N = 5401;
int n, m;
typedef pair<int, int> PII;
PII q[N];
int f[N];
int main(int argc, char const *argv[])
{
    cin >> n;
    int a, b;
    for (int i = 0; i < n; i++)
    {
        cin >> a >> b;
        q[i] = {a, b};
    }
    sort(q, q + n);
    int r = 0;
    for (int i = 0; i < n; i++)
    {
        f[i] = 1;
        for (int j = 0; j < i; j++)
        {
            if (q[i].y > q[j].y)
            {
                f[i] = max(f[i], f[j] + 1);
            }
        }
        r = max(r, f[i]);
    }
    cout << r << endl;
    return 0;
}
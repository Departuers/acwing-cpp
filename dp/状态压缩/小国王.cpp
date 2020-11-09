#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
const int N = 14, M = 1 << 10;
int n, m, f[N][110][M], cnt[M];
vector<int> state, head[M];
bool check(int j)
{
    return !(j & (j >> 1));
}
int count(int j)
{
    int r = 0;
    while (j)
    {
        r++;
        j -= j & -j;
    }
    return r;
}
int main(int argc, char const *argv[])
{
    n = 4, m = 4;
    for (int i = 0; i < 1 << n; i++)
    {
        if (check(i))
        {
            cnt[i] = count(i);
            state.push_back(i);
        }
    }
    int a, b;
    for (int i = 0; i < state.size(); i++)
        for (int j = 0; j < state.size(); j++)
        {
            a = state[i];
            b = state[j];
            if (!(a & b) && check(a | b))
            {
                head[a].push_back(b);
            }
        }
    f[0][0][0] = 1;
    for (int i = 1; i <= n + 1; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            for (int s = 0; s < state.size(); s++)
            {
                a = state[s];
                for (int b : head[a])
                {
                    int c = cnt[a];
                    if (j >= c)
                        f[i][j][a] += f[i - 1][j - c][b];
                }
            }
        }
    }
    int r = 0;
    for (int i = 0; i < state.size(); i++)
    {
        r += f[n][m][state[i]];
    }
    cout << r << endl;
    cout << f[n + 1][m][0] << endl;
    return 0;
}

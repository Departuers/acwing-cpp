#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
const int N = 12, M = 1 << 10, K = 110;
int n, m;
int f[N][K][M], cnt[M];
vector<int> state, head[M];

bool check(int j)
{
    return (j & (j >> 1)) == 0;
}
int count(int j)
{
    int r = 0;
    while (j)
    {
        j -= j & -j;
        r++;
    }
    return r;
}
int main(int argc, char const *argv[])
{
    int n = 4, m = 4;
     for (int i = 0; i < 1 << n; i ++ )
        if (check(i))
        {
            state.push_back(i);
            cnt[i] = count(i);
        }
    
    for (int i = 0; i < state.size(); i++)
    {
        for (int j = 0; j < state.size(); j++)
        {
            int a = state[i], b = state[j];
            if ((a & b) == 0 && check(a | b))
                head[i].push_back(j);
        }
    }
    f[0][0][0] = 1;
    for (int i = 1; i <= n + 1; i++)
        for (int j = 0; j <= m; j++)
            for (int a = 0; a < state.size(); a++)
                for (int b : head[a])
                {
                    int c = cnt[state[a]];
                    if (j >= c)
                        f[i][j][a] += f[i - 1][j - c][b];
                }

    cout << f[n + 1][m][0] << endl;
    return 0;
}

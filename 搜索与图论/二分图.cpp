#include <iostream>
using namespace std;
const int N = 1e5 + 10;
int color[N], h[N], idx = 1, e[N << 1], ne[N << 1];
void add(int a, int b)
{
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx++;
}
bool dfs(int u, int c)
{
    color[u] = c;
    for (int i = h[u]; i; i = ne[i])
    {
        int j = e[j];
        if (!color[j])
        {
            if (!dfs(j, 3 - c))
                return false;
        }
        else if (color[j] == c)
            return false;
    }
    return 1;
}
int main()
{
    int n, m;
    cin >> n >> m;
    int a, b;
    while (m--)
    {
        cin >> a >> b;
        add(a, b);
        add(b, a);
    }
    bool f = 1;
    for (int i = 1; i <= n; i++)
    {
        if (color[i] == 0)
        {
            if (!dfs(i, 1))
            {
                f = 0;
                break;
            }
        }
    }
    if (f)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}
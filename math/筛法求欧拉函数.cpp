#include <iostream>
using namespace std;
const int N = 1e7 + 10;
int n, cnt = 0;
int st[N], euler[N], pr[N];
long get(int n)
{
    euler[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        if (!st[i])
        {
            pr[cnt++] = i;
            euler[i] = i - 1;
        }
        for (int j = 0; pr[j] <= n/i; j++)
        {
            int t = pr[j] * i;
            st[t] = 1;
            if (i % pr[j] == 0)
            {
                euler[t] = euler[i] * pr[j];
                break;
            }
            euler[t] = euler[i] * (pr[j] - 1);
        }
    }
    long res = 0;
    for (int i = 1; i <= n; i++)
    {
        res += euler[i];
    }
    return res;
}
int main()
{
    cin >> n;
    cout << get(n) << endl;
    return 0;
}
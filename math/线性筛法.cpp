#include <cstdio>
using namespace std;
const int N = 1e8;
int n, q;
int st[N], pr[N];
void euler(int e)
{
    int cnt = 1;
    for (int i = 2; i <= N; i++)
    {
        if (!st[i])
            pr[cnt++] = i;
        for (int j = pr[i]; i <= N / pr[j]; j++)
        {
            st[i * pr[i]] = 1;
            if (i % pr[j] == 0)
                break;
        }
    }
}
int main()
{
    scanf("%d%d", &n, &q);
    euler(n);
    int f;
    while (q--)
    {
        scanf("%d", &f);
        printf("%d", pr[f]);
    }
}
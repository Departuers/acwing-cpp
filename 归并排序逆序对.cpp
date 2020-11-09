#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>
#include <vector>
#include <cstring>
#include <unordered_map>
#include <deque>
using namespace std;
const int inf = 0x3f3f3f3f, N = 101000;
int n, m;
int q[N], tem[N];
int merge(int l, int r)
{
    if (l == r)
        return 0;
    int mid = l + r >> 1;
    int res = merge(l, mid) + merge(mid + 1, r);
    int k = 0, i = l, j = mid + 1;
    while (i <= mid && j <= r)
    {
        if (q[i] <= q[j])
        {
            tem[k++] = q[i++];
        }
        else
        {
            tem[k++] = q[j++];
            res += mid - i + 1;
        }
    }
    while (i <= mid)
        tem[k++] = q[i++];
    while (j <= r)
        tem[k++] = q[j++];
    for (i = l, j = 0; i <= r; i++, j++)
        q[i] = tem[j];
    return res;
}
int main(int argc, char const *argv[])
{
    
    return 0;
}
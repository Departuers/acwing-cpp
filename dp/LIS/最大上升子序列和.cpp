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
const int inf = 0x3f3f3f3f,N=1104;
int n, m,a[N],f[N];
int main(int argc, char const *argv[])
{
    cin>>n;
    int r=0;
    for (int i = 0; i < n; i++)cin>>a[i];
    for (int i = 0; i < n; i++)
    {
        f[i]=a[i];
        for (int j = 0; j < i; j++)
        {
            if(a[i]>a[j])f[i]=max(f[j]+a[i],f[i]);
        }
        r=max(r,f[i]);
    }
    cout<<r<<endl;
    return 0;
}
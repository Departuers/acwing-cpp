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
const int inf = 0x3f3f3f3f,N=2010;
int n, m,f[N],v[N],w[N],s[N];
int main(int argc, char const *argv[])
{
    cin>>n>>m;
    for (int i = 0; i < n; i++)cin>>v[i]>>w[i]>>s[i];
    for (int i = 0; i < n; i++)
    {
        for (int k = 1; k <=s[i]; k<<=1)
        {
            for (int j = m; j >=k*v[i]; j--)
            {
                f[j]=max(f[j-k*v[i]]+k*w[i],f[j]);
            }
            s[i]-=k;
        }
    }
    for (int i = 0; i < n; i++)
    {
        if(s[i]){
            for (int j = m; j >=s[i]*v[i]; j--)
            {
                f[j]=max(f[j-s[i]*v[i]]+s[i]*w[i],f[j]);
            }
        }
    }
    cout<<f[m]<<endl;    
    return 0;
}
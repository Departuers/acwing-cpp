#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
const int inf = 0x3f3f3f3f;
int n, m;
int f[55][66];
int main(int argc, char const *argv[])
{
    cin>>n;
    f[0][0]=1;
    cout<<1<<endl;
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            f[i][j]=f[i-1][j]+f[i-1][j-1];
            cout<<f[i][j]<<" ";
        }
        cout<<endl;
    }
    
    return 0;
}
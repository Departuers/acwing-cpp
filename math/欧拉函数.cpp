#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
const int inf = 0x3f3f3f3f;
int n, m;
int st[101000];

int main(int argc, char const *argv[])
{
    cin >> m;
    while (m--)
    {
        cin >> n;
        int res=n;
        for (int i = 2; i <=n/i; i++)
        {
            if (n%i==0)
            {
                res-=res/i;
                while (n%i==0)n/=i;
            }
        }
        if (n>1)res-=res/n;
        cout<<res<<endl;
    }

    return 0;
}
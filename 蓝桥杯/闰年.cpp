#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
const int inf = 0x3f3f3f3f;
int n, m;
int main(int argc, char const *argv[])
{
    int r;
    cin>>r;
    if (!(r%400)||(r%4==0&&r%400!=0))
    cout<<"yes";
    else
    {
        cout<<"no";
    }
        
    return 0;
}
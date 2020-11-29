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
    for (int i = 0; i < 32; i++)
    {
        for (int j = 4; j >=0; j--)
        {
            if (i>>j&1)
            {
                cout<<1;
            }else
            {
                cout<<0;
            }
        }
             cout<<endl;           
    }
    return 0;
}
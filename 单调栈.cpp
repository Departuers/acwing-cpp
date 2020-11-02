#include <iostream>
using namespace std;
int a[100100];
int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {

        cin >> a[i];
        if (i == 0)
            cout << -1 << " ";
        else
        {
            bool f=1;
            for (int j = i - 1; j >= 0; j--)
            {
                if (a[j]<a[i])
                {
                    f=0;
                    cout<<a[j]<<" ";
                    break;
                }
            }
            if (f)  cout << -1 << " " ;
        }
    }
    return 0;
}

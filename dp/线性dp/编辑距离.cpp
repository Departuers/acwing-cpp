#include <iostream>
#include <cstring>
using namespace std;

int n, m,f[1010][1010];
char s[1041], t[1040];
int main()
{
    cin >> n;
    char a;
    for (int i = 1; i <= n; i++)
    {
        cin>>a;
        s[i]=a;
    }
    cin>>m;
    for (int i = 1; i <= m; i++)
    {
        cin>>a;
        t[i]=a;
    }
    for(int i=0;i<=n;i++)
        f[i][0]=i;
    for(int i=0;i<=m;i++)
        f[0][i]=i;
    
    for(int i=1;i<=m;i++){
        for(int j=1;j<=m;j++){
            if(s[i]==t[j])f[i][j]=f[i-1][j-1];
            else f[i][j]=min(min(f[i-1][j],f[i][j-1]),f[i-1][j-1])+1;
        }
    }
    cout<<f[n][m]<<endl;
    return 0;
}
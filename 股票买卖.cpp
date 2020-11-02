#include<iostream>
#include<cstring>
using namespace std;
int a[100100],f[100010][3];
int main(){
    int n;
    cin>>n;
    f[0][1]=-1e9;
    f[0][0]=-1e9;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++){
        f[i][0]=max(f[i-1][0],f[i-1][2]-a[i]);
        f[i][1]=f[i-1][0]+a[i];
        f[i][2]=max(f[i-1][2],f[i-1][1]);
    }
    cout<<max(f[n][1],f[n][2])<<endl;
    return 0;
}
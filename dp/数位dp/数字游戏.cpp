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
const int inf = 0x3f3f3f3f,N=11,M=110;
int n, m,P;
typedef pair<int, int> PII;
int f[N][10][M];
int mod(int x, int y)
{
    return (x % y + y) % y;
}
void init(){
    for(int i=0;i<=9;i++)f[1][i][i%P]++;
    for(int i=2;i<N;i++){//枚举位数
        for(int j=0;j<=9;j++){//枚举最高位
            for(int k=0;k<P;k++){//枚举余数
                for(int x=0;x<=9;x++){//枚举次高位
                    //i-1位,最高位填x,余数是k
                    //为使得余数是k,(k-j)%P加上最高位的j就等于k
                    //
                    f[i][j][k]+=f[i-1][x][mod(k-j,P)];
                }
            }
        }
    }
}
int dp(int n){
    if(!n)return 1;//0符合mod P为0
    vector<int> num;
    while(n){
        num.push_back(n%10);
        n/=10;
    }
    int res=0,last=0;//last代表前面数的和
    for(int i=num.size()-1;i>=0;i--){
        int x=num[i];
        for(int j=0;j<x;j++){
            res+=f[i+1][j][mod(-last,P)];            
            //last_____%P=0 所以后面的就是-last
        }
        last+=x;
        if(!i&&last%P==0)res++;
    }
    return res;
}
int main(int argc, char const *argv[])
{
    int l,r;
    while (cin>>l>>r>>P)
    {
        memset(f,0,sizeof f);//多组测试数据清空
        init();
        cout<<dp(r)-dp(l-1)<<endl;
    }
    return 0;
}
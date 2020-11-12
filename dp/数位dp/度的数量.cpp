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
const int inf = 0x3f3f3f3f, N = 40;
int n, m,K,B;
typedef pair<int, int> PII;
int f[N][N];
void init()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            if(j==0)f[i][j]=1;
            else f[i][j]=f[i-1][j]+f[i-1][j-1];
        }
    }
}
int dp(int n){
    if(n==0)return 0;
    vector<int> num;
    while(n){
        num.push_back(n%B);
        n/=B;
    }
    int res=0,last=0;//last存前面有多少个1
    for(int i=num.size()-1;i>=0;i--){
        int x=num[i];
        if(x){//x不为0
            res+=f[i][K-last];//加上x这一位填0的情况
            if(x>1){
                //这一位能填1,最多K个1
                if(K-last-1>=0)res+=f[i][K-last-1];
                break;//数字超过了,没了
            }else{
                last++;
                if(last>K)break;
            }
        }
        if(!i&&last==K)res++;
    }
    return res;
}
int main(int argc, char const *argv[])
{
    init();
    int l,r;
    cin>>l>>r>>K>>B;
    cout<<dp(r)-dp(l-1)<<endl;
    return 0;
}
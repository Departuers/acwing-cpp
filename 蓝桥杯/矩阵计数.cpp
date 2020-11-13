#include <iostream>
using namespace std;

int n, sum, m, cs[10][10];
bool juede(int i,int j){
    if(n>2&&i>=2){
        if(cs[i-1][j]==cs[i-2][j]&&cs[i-1][j]==1)
        return 0;
    }
    if(m>2&&j>=2){
        if(cs[i][j-1]==cs[i][j-2]&&cs[i][j-2]==1)
        return 0;
    }
    return 1;
}
void dfs(int i, int j)
{
    if (i == n)//搜到了结果
    {
        sum++;
        return;
    }
    if (juede(i, j))
    {
        cs[i][j] = 1;
        dfs(i + (j + 1) / m, (j + 1) % m);
        cs[i][j] = 0;
    }
    dfs(i + (j + 1) / m, (j + 1) % m);
}
int main()
{
    cin >> n >> m;
    dfs(0, 0);
    cout<<sum<<endl;
    return 0;
}
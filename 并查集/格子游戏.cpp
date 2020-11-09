#include<iostream>
using namespace std;
int p[42010];
int n,m;
int find(int x){
    if(p[x]!=x)p[x]=find(p[x]);
    return p[x];
}
int get(int x,int y){
    return x*n+y;
}
int main(){
    scanf("%d%d",&n,&m);  
    for(int i=1;i<=n*n+n;i++)p[i]=i;
    int a,b,x,y;char op[2];
    int res=0;
    for(int i=1;i<=m;i++){
        scanf("%d%d%s",&a,&b,op);
        a--,b--;//下标都从0开始
        x=get(a,b);
        if(*op=='D'){
            y=get(a+1,b);
        }else y=get(a,b+1);
        x=find(x),y=find(y);
        if(x==y){
            res=i;
            break;
        }p[x]=y;
    }
    if(!res)printf("draw");
    else printf("%d",res);
    return 0;
}
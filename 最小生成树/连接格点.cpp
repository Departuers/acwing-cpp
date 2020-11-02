#include<cstdio>
#include<algorithm>

using namespace std;

int p[1010*1001];
int find(int x){
    if(p[x]!=x)p[x]=find(p[x]);
    return p[x];
}

int main(){
    int n,m;
    scanf("%d%d",&m,&n);
    for(int i=0;i<=n*m+1;i++){
        p[i]=i;
    }
    int a,b,c,d,e,f;
    while(scanf("%d%d%d%d",&a,&b,&c,&d)!=EOF){
        e=(a-1)*n+b;
        f=(c-1)*n+d;
        e=find(e);
        f=find(f);
        p[e]=f;
    }
    int r=0;
    for(int i=1;i<=n*m-n;i++){
        a=find(i),b=find(i+n);
        if(a!=b){
            p[a]=b;
            r++;
        }
    }

    for(int i=1;i<=n*m;i++){
        if(i%n==0)continue;
        a=find(i),b=find(i+1);
        if(a!=b){
            p[a]=b;
            r+=2;
        }
    }
    printf("%d",r);
    return 0;
}
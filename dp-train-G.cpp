#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;
const int INF=1<<20;
int t,n,m,r;
int r1[4]={0,0,-1,1},r2[4]={1,-1,0,0};
int d[10005][10005],vis[10005][10005];
int dp(int i,int j){
    if(i<1||i>n||j<1||j>m) return INF;
    if(i==n&&j==m) return d[i][j]=0;
    int &ans=d[i][j];
    if(ans>0) return ans;
    ans=INF;
    for(int k=0;k<4;k++) {
            ans=min(ans,dp(i+r1[k],j+r2[k])+1);
            if(i==2&&j==3) printf("%d %d %d&\n",i+r1[k],j+r2[k],d[i+r1[k]][j+r2[k]]);
    }return ans;
}

void find(int i,int j){
    int ans=d[i][j];
    vis[i][j]=1;
    for(int k=0;k<4;k++){
        if(ans==d[i+r1[k]][j+r2[k]]+1&&ans<INF&&!vis[i+r1[k]][j+r2[k]]){
            r+=1;
            find(i+r1[k],j+r2[k]);
        }
    }
}


int main(){
    scanf("%d",&t);
    while(t--){
        r=1;
        scanf("%d%d",&n,&m);
        memset(d,-1,sizeof(d));
        memset(vis,0,sizeof(vis));
        for(int i=1;i<=n;i++){
            int f=1,c;
            char ch;
            for(;scanf("%d%c",&c,&ch)==2&&ch!='\n';){
                if(f) f=0;
                else d[i][c]=INF;
            }
            if(!f) d[i][c]=INF;
        }
        dp(1,1);
        for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) printf("%d %d %d*\n",i,j,d[i][j]);
        find(1,1);
        printf("%d\n",r);
    }
}

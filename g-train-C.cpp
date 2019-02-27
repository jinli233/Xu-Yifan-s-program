#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

int main(){
    int n,m,t,kase=0,dp[105][105],f=1;
    while(scanf("%d%d%d",&n,&m,&t)&&n){
        int a,b,num;
        if(f) f=0;
        else printf("\n");
        for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) dp[i][j]=1<<30;
        for(int j=0;j<m;j++){
            scanf("%d%d%d",&a,&b,&num);
            dp[a][b]=dp[b][a]=num;
        }
        for(int k=1;k<=n;k++){
            for(int i=1;i<=n;i++){
                for(int j=1;j<=n;j++){
                    dp[i][j]=min(dp[i][j],max(dp[i][k],dp[k][j]));
                }
            }
        }
        printf("Case #%d\n",++kase);
        for(int i=0;i<t;i++){
            scanf("%d%d",&a,&b);
            if(dp[a][b]==1<<30) printf("no path\n");
            else printf("%d\n",dp[a][b]);
        }
    }
}

#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<vector>
using namespace std;

const int INF=1<<30;

int main(){
    int n,r,dp[105][105],kase=0;
    while(scanf("%d%d",&n,&r)&&n){
        int a,b,x;
        for(int i=1;i<=n;i++) for(int j=1;j<=n;j++){
            if(i==j) dp[i][i]=0;
            else dp[i][j]=-INF;
        }
        for(int i=1;i<=r;i++){
            scanf("%d%d%d",&a,&b,&x);
            dp[a][b]=dp[b][a]=x;
        }
        for(int k=1;k<=n;k++){
            for(int i=1;i<=n;i++){
                for(int j=1;j<=n;j++){
                    if(dp[k][j]>-INF){
                        dp[i][j]=max(dp[i][j],min(dp[i][k],dp[k][j]));
                    }
                }
            }
        }
        scanf("%d%d%d",&a,&b,&x);
        printf("Scenario #%d\nMinimum Number of Trips = ",++kase);
        if(x%(dp[a][b]-1)==0) printf("%d\n\n",x/(dp[a][b]-1));
        else printf("%d\n\n",x/(dp[a][b]-1)+1);
    }
}

#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

int T,n,t,kase=0,time[55],dp[60][10000];

int main()
{
    scanf("%d",&T);
    while(T--){
        int ans=0;
        scanf("%d%d",&n,&t);
        for(int i=1;i<t;i++) dp[n+1][i]=-1;
        dp[n+1][0]=0;
        for(int i=1;i<=n;i++) scanf("%d",time+i);
        for(int i=n;i>=1;i--){
            for(int j=0;j<t;j++){
                dp[i][j]=dp[i+1][j];
                if(j>=time[i]&&dp[i+1][j-time[i]]>=0){
                    dp[i][j]=max(dp[i][j],dp[i+1][j-time[i]]+1);
                }
                ans=max(ans,dp[i][j]);
            }
        }
        for(int i=t-1;i>=0;i--)
        {
            if(dp[1][i]==ans)
            {
                printf("Case %d: %d %d\n",++kase,ans+1,i+678);
                break;
            }
        }
    }
    return 0;
}

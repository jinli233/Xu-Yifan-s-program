#include<stdio.h>
#include<algorithm>
using namespace std;
const int INF=1<<30;
int main()
{
    int dp[15][150],a[15][150],next[15][150],n,m,first;
    while(scanf("%d%d",&n,&m)==2)
    {
        int ans=1<<30;
        for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) scanf("%d",&a[i][j]);
        for(int i=m;i>=1;i--)
        {
            for(int j=1;j<=n;j++)
            {
                if(i==m) dp[j][i]=a[j][i];
                else
                {
                    int rows[3]={j,j-1,j+1};
                    if(j==1) rows[1]=n;
                    if(j==n) rows[2]=1;
                    sort(rows,rows+3);
                    dp[j][i]=INF;
                    for(int index=0;index<3;index++)
                    {
                        if(dp[rows[index]][i+1]+a[j][i]<dp[j][i])
                        {
                            dp[j][i]=dp[rows[index]][i+1]+a[j][i];
                            next[j][i]=rows[index];
                        }
                    }
                }
            }
        }
        ans=dp[1][1];
        first=1;
        for(int i=2;i<=n;i++)
        {
            if(dp[i][1]<ans)
            {
                ans=dp[i][1];
                first=i;
            }
        }
        printf("%d",first);
        for(int i=next[first][1],j=1;j<m;j++,i=next[i][j])
        {
            printf(" %d",i);
        }
        printf("\n%d\n",ans);
    }
    return 0;
}

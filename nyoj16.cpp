#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

struct Re
{
    int a;
    int b;
}re[1000];
int g[1000][1000],v[1000],n;

int dp(int i)
{
    if(v[i]>0) return v[i];
    int& ans=v[i];
    for(int j=1;j<=n;j++) if(g[i][j]) ans=max(ans,dp(j)+1);
    return ans;
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        memset(g,0,sizeof(g));
        memset(v,0,sizeof(v));
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%d%d",&re[i].a,&re[i].b);
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if((re[i].a>re[j].a&&re[i].b>re[j].b)||(re[i].a>re[j].b&&re[i].b>re[j].a)) g[i][j]=1;
            }
        }
        int ans=0;
        for(int i=1;i<=n;i++) ans=max(ans,dp(i));
        printf("%d\n",ans+1);
    }
    return 0;
}


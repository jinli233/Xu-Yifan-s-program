#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;
int s,n,c[1000],d[1000];

int dp_max(int s)
{
    if(d[s]!=-1) return d[s];
    int& ans=d[s];
    ans=-(1<<30);
    for(int i=1;i<=n;i++)
    {
        if(s>=c[i]) ans=max(ans,dp_max(s-c[i])+1);
    }
    return ans;
}
int dp_min(int s)
{
    if(d[s]!=-1) return d[s];
    int& ans=d[s];
    ans=1<<30;
    for(int i=1;i<=n;i++)
    {
        if(s>=c[i]) ans=min(ans,dp_min(s-c[i])+1);
    }
    return ans;
}


int main()
{
    int t,min,max;
    scanf("%d",&t);
    while(t--)
    {
        memset(d,-1,sizeof(d));
        d[0]=0;
        scanf("%d",&s);
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%d",c+i);
        sort(c+1,c+1+n);
        dp_max(s);
        printf("%d ",d[s]);
        memset(d,-1,sizeof(d));
        d[0]=0;
        dp_min(s);
        printf("%d\n",d[s]);
    }
    return 0;
}

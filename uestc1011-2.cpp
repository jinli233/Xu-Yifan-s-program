#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
int a[101][101],d[101][101],n;

int solve(int i,int j)
{
    if(d[i][j]>=0) return d[i][j];
    return d[i][j]=a[i][j]+(i==n?0:max(solve(i+1,j),solve(i+1,j+1)));
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int ans;
        memset(d,-1,sizeof(d));
        scanf("%d",&n);
        for(int i=1;i<=n;i++) for(int j=1;j<=i;j++) scanf("%d",&a[i][j]);
        solve(1,1);
        printf("%d\n",d[1][1]);
    }
    return 0;
}

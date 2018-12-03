#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
int a[101][101];

int main()
{
    int t,n;
    scanf("%d",&t);
    while(t--)
    {
        int d[101][101];
        memset(d,0,sizeof(d));
        scanf("%d",&n);
        for(int i=1;i<=n;i++) for(int j=1;j<=i;j++) scanf("%d",&a[i][j]);
        for(int i=1;i<=n;i++) d[n][i]=a[n][i];
        for(int i=n-1;i>=0;i--)
        {
            for(int j=0;j<=i;j++)
            {
                d[i][j]=a[i][j]+max(d[i+1][j],d[i+1][j+1]);
            }
        }
        printf("%d\n",d[0][0]);
    }
}

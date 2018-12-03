#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

int main()
{
    int t,n,s,a[1000],maxv[10000],minv[10000];
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&s,&n);
        maxv[0]=minv[0]=0;
        for(int i=1;i<=s;i++)
        {
            minv[i]=1<<30;
            maxv[i]=-(1<<30);
        }
        for(int i=0;i<n;i++) scanf("%d",a+i);
        for(int i=1;i<=s;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i>=a[j])
                {
                    maxv[i]=max(maxv[i],maxv[i-a[j]]+1);
                    minv[i]=min(minv[i],minv[i-a[j]]+1);
                }
            }
        }
        printf("%d %d\n",maxv[s],minv[s]);
    }
    return 0;
}

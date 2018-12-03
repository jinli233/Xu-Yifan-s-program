#include<stdio.h>

int main()
{
    int n,a[20],kase=0;
    while(scanf("%d",&n)!=EOF)
    {
        long long m=0;
        for(int i=0;i<n;i++) scanf("%d",a+i);
        for(int i=0;i<n;i++)
        {
            long long  t=1;
            for(int j=i;j<n;j++)
            {
                t*=a[j];
                if(t>m) m=t;
            }
        }
        printf("Case #%d: The maximum product is %lld.\n\n",++kase,m);
    }
    return 0;
}

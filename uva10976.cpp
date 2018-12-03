#include<stdio.h>

int main()
{
    long long n,a[20000],b[20000],ans=0;
    while(scanf("%lld",&n)!=EOF)
    {
        ans=0;
        for(long long i=n+1;i<=2*n;i++)
        {
            if((n*i)%(i-n)==0)
            {
                b[ans]=i;
                a[ans++]=n*i/(i-n);
            }
        }
        printf("%d\n",ans);
        for(int i=0;i<ans;i++) printf("1/%lld = 1/%lld + 1/%lld\n",n,a[i],b[i]);
    }
    return 0;
}

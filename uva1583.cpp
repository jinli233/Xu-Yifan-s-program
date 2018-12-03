#include<stdio.h>

int a[100050]={0};

int main()
{
    int t;
    scanf("%d",&t);
    for(int i=1;i<=100000;i++)
    {
        int x=i,sum=i;
        while(x>0)
        {
            sum+=x%10;
            x/=10;
        }
        if(sum<=100000&&(sum<a[sum]||a[sum]==0)) a[sum]=i;
    }
    while(t--)
    {
        int n;
        scanf("%d",&n);
        printf("%d\n",a[n]);
    }
    return 0;
}

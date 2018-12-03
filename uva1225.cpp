#include<stdio.h>

int main()
{
    int t,n;
    scanf("%d",&t);
    while(t--)
    {
        int n,a[10]={0};
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
        {
            int x=i;
            while(x>0)
            {
                a[x%10]+=1;
                x/=10;
            }
        }
        for(int i=0;i<9;i++)
        {
            printf("%d ",a[i]);
        }
        printf("%d\n",a[9]);
    }
    return 0;
}

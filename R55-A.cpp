#include<stdio.h>
#include<stdlib.h>

int main()
{
    int t,n,x,y,p,a,b;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d%d%d",&n,&x,&y,&p);
        if(abs(x-y)%p==0)
        {
            printf("%d\n",abs(x-y)/p);
        }
        else if(y==1||y==n) printf("%d\n",(abs(y-x)+p-1)/p);
        else
        {
            int a=y-1,b=n-y;
            if(a%p==0&&b%p==0)
            {
                if( (a+p-1)/p + (x+p-2)/p > (b+p-1)/p + (n-x+p-1)/p) printf("%d\n",(b+p-1)/p+(n-x+p-1)/p);
                else printf("%d\n",(a+p-1)/p+(x+p-2)/p);
            }
            else if(a%p==0) printf("%d\n",(a+p-1)/p+(x+p-2)/p);
            else if(b%p==0) printf("%d\n",(b+p-1)/p+(n-x+p-1)/p);
            else printf("-1\n");
        }
    }
    return 0;
}

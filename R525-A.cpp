#include<stdio.h>

int main()
{
    int x;
    scanf("%d",&x);
    for(int i=1;i<=x;i++)
    {
        for(int j=i;j<=x;j+=i)
        {
            if(j*i>x&&j/i<x)
            {
                printf("%d %d",j,i);
                return 0;
            }
        }
    }
    printf("-1");
    return 0;
}

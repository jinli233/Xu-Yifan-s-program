#include<stdio.h>
#include<string.h>

int main()
{
    int n,a[10],kase=0;
    while(scanf("%d",&n)==1&&n)
    {
        if(kase++) printf("\n");
        int f=0;
        for(int i=1234;;i++)
        {
            if(i*n<=12345) continue;
            if(i*n>=98765) break;
            int x=i*n,y=i,ok=1;
            memset(a,0,sizeof(a));
            for(int j=0;j<5;j++)
            {
                if(a[x%10]) ok=0;
                else a[x%10]=1;
                if(a[y%10]) ok=0;
                else a[y%10]=1;
                x/=10;
                y/=10;
            }
            if(ok) {printf("%5d / %05d = %d\n",i*n,i,n);f=1;}
        }
        if(!f) printf("There are no solutions for %d.\n",n);
    }
    return 0;
}

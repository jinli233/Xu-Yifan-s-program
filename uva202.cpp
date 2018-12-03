#include<stdio.h>
#include<string.h>
int main()
{
    int a,b;
    while(scanf("%d",&a)!=EOF)
    {
        scanf("%d",&b);
        if(a==0)
        {
            printf("%d/%d = 0.(0)",a,b);
            printf("   1 = number of digits in repeating cycle\n");
            continue;
        }
        printf("%d/%d = ",a,b);
        int dv[3001];
        memset(dv,-1,sizeof(dv));
        char s[3000];
        int x=a/b,ans=0,pos=0,len;
        printf("%d/%d = %d.",a,b,x);
        a%=b;
        while(1)
        {
            dv[a]=pos;
            a*=10;
            x=a/b;
            a%=b;
            s[pos]=x;
            pos+=1;
            if(dv[a]>=0)
            {
                s[pos]='\0';
                ans=pos-dv[a];
                len=dv[a];
                break;
            }

        }
        for(int i=0;i<pos;i++)
        {
            if(i==len) printf("(");
            printf("%d",s[i]);
            if(i==49)
            {
                printf("...");
                break;
            }
        }
        printf(")\n");
        printf("   %d = number of digits in repeating cycle\n",ans);
    }
    return 0;
}

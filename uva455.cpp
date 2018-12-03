#include<stdio.h>
#include<string.h>

int main()
{
    int t;
    char s[85];
    scanf("%d",&t);
    while(t--)
    {
        scanf("%s",s);
        int len=strlen(s);
        for(int i=1;i<=len;i++)
        {
            if(len%i==0)
            {
                int ok=1;
                for(int j=0;j<i;j++)
                {
                    for(int index=1;index<len/i;index++)
                    {
                        if(s[j]!=s[j+index*i])
                        {
                            ok=0;break;
                        }
                    }
                }
                if(ok)
                {
                    printf("%d\n",i);
                    if(t) printf("\n");
                    break;
                }
            }
        }
    }
}

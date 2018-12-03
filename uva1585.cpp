#include<stdio.h>
#include<string.h>

int main()
{
    int t;
    char s[81];
    scanf("%d",&t);
    while(t--)
    {
        int sum=0,f=0;
        scanf("%s",s);
        int len=strlen(s);
        for(int i=0;i<len;i++)
        {
            if(s[i]=='O')
            {
                f+=1;
                sum+=f;
            }
            if(s[i]=='X') f=0;
        }
        printf("%d\n",sum);
    }
}

#include<cstdio>
#include<string.h>

bool cmp(int len,char *s,int p,int q)
{
    for(int i=0;i<len;i++)
    {
        if(s[(p+i)%len]!=s[(q+i)%len])
            return s[(p+i)%len]<s[(q+i)%len];
    }
    return 0;
}
int main()
{
    int t;
    char s[105];
    scanf("%d",&t);
    while(t--)
    {
        scanf("%s",s);
        int ans=0;
        int len=strlen(s);
        for(int i=1;i<len;i++)
        {
            if(cmp(len,s,i,ans)) ans=i;
        }
         for(int i=0;i<len;i++)
        {
            printf("%c",s[(ans+i)%len]);
        }
        printf("\n");
    }
    return 0;
}

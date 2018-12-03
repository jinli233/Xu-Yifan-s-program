#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

int main()
{
    char s[101],x[101];
    while(scanf("%s",s)!=EOF)
    {
        int a[26]={0},b[26]={0};
        scanf("%s",x);
        int len=strlen(s);
        for(int i=0;i<len;i++)
        {
            a[s[i]-'A']+=1;
            b[x[i]-'A']+=1;
        }
        sort(a,a+26);
        sort(b,b+26);
        int ok=1;
        for(int i=0;i<26;i++)
        {
            if(a[i]!=b[i])
            {
                printf("NO\n");
                ok=0;
                break;
            }
        }
        if(ok) printf("YES\n");
    }
    return 0;
}

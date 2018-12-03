#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

int main()
{
    char a[101],b[101];
    while(scanf("%s",a)!=EOF)
    {
        scanf("%s",b);
        int len1=strlen(a);
        int len2=strlen(b);
        int x,y;
        int mi=min(len1,len2);
        int ma=max(len1,len2);
        for(int i=0;i<=len2;i++)
        {
            int ok=1;
            for(int j=0;j<len1&&j+i<len2;j++)
            {
                if(a[j]=='2'&&b[j+i]=='2') {ok=0;break;}
            }
            if(ok) {x=i;break;}
        }
        for(int i=1;i<=len1;i++)
        {
            int ok=1;
            for(int j=0;j+i<len1&&j<len2;j++)
            {
                if(a[j+i]=='2'&&b[j]=='2') {ok=0;break;}
            }
            if(ok) {y=i;break;}
        }
        if(len1==ma)
        {
            x+=ma;
            if(y+mi<ma) y=ma;
            else y+=mi;
        }
        else
        {
            y+=ma;
            if(x+mi<ma) x=ma;
            else x+=mi;
        }
        printf("%d\n",x<y?x:y);
    }
    return 0;
}

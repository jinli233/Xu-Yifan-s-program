#include<stdio.h>
#include<string.h>

int bad,good;

void check(char *s,char *x,int le,int cho)
{
    int ans=le;
    int len=strlen(x);
    for(int i=0;i<len;i++)
    {
        int ok=0;
        for(int j=0;j<ans;j++)
        {
            if(x[i]==s[j])
            {
                s[j]=' ';
                le--;
                ok=1;
                if(!le) {good=1;return;}
            }
        }
        if(!ok) cho--;
        if(!cho) {bad=1;return;}
    }
}

int main()
{
    int kase;
    while(scanf("%d",&kase)==1&&kase!=-1)
    {
        bad=good=0;
        char s[80],x[80];
        scanf("%s%s",s,x);
        int left=strlen(s);
        int choice=7;
        check(s,x,left,choice);
        printf("Round %d\n",kase);
        if(bad) printf("You lose.\n");
        else if(good) printf("You win.\n");
        else printf("You chickened out.\n");
    }
    return 0;
}

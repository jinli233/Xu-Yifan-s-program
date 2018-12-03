#include<stdio.h>
#include<string.h>
#include<ctype.h>

char s[]="A   3  HIL JM O   2TUVWXY51SE Z  8 ";

char r(char ch)
{
    if(isalpha(ch)) return s[ch-'A'];
    else return s[ch-'0'+25];
}

int main()
{
    char x[30];
    while(scanf("%s",x)!=EOF)
    {
        int p=1,q=1;
        int len=strlen(x);
        for(int i=0;i<(len+1)/2;i++)
        {
            if(x[i]!=x[len-i-1]) p=0;
            if(r(x[i])!=x[len-i-1]) q=0;
        }
        if(p&&q) printf("%s -- is a mirrored palindrome.\n\n",x);
        else if(p&&q==0) printf("%s -- is a regular palindrome.\n\n",x);
        else if(p==0&&q)  printf("%s -- is a mirrored string.\n\n",x);
        else printf("%s -- is not a palindrome.\n\n",x);
    }
}

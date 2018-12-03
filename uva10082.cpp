#include<stdio.h>
#include<string.h>

int main()
{
    char s[]="`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";
    char ch;
    int len=strlen(s);
    while((ch=getchar())!=EOF)
    {
        for(int i=0;i<len;i++)
        {
            if(s[i]==ch)
            {
                ch=s[i-1];
                break;
            }
        }
        putchar(ch);
    }
    return 0;
}

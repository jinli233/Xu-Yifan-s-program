#include<stdio.h>

int main()
{
    char ch;
    int flag=1;
    while((ch=getchar())!=EOF)
    {
        if(ch=='"') {printf("%s",flag?"``":"''");flag=!flag;}
        else putchar(ch);
    }
    return 0;
}

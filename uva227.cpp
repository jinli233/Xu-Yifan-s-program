#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<iostream>
using namespace std;

int main()
{
    char s[5][6],q[80];
    char p[5]="ARLB";
    int p1[4]={-1,0,0,1};
    int p2[4]={0,1,-1,0};
    int kase=0,f=1;
    while(1)
    {
        int x,y,ok=1,ans=0;
        char ch;
        for(int i=0;i<5;i++)
        {
            cin.getline(s[i],6);
            if(s[0][0]=='Z') return 0;
        }
        for(int i=0;i<5;i++)
        {
            for(int j=0;j<5;j++)
            {
                if(s[i][j]==' ')
                {
                    x=i;
                    y=j;
                }
            }
        }
        if(!f) printf("\n");
        else f=0;
        printf("Puzzle #%d:\n",++kase);
        while(1)
        {
            cin.getline(q,80);
            int len=strlen(q);
            for(int index=0;index<len;index++)
            {
                ch=q[index];
                if(ch=='0')
                {
                    ans=1;
                    break;
                }
                if(ok==0) continue;
                int pos;
                for(int i=0;i<5;i++) if(p[i]==ch) pos=i;
                if(x+p1[pos]<0||x+p1[pos]>4||y+p2[pos]<0||y+p2[pos]>4)
                {
                    ok=0;
                    continue;
                }
                s[x][y]=s[x+p1[pos]][y+p2[pos]];
                s[x+p1[pos]][y+p2[pos]]=' ';
                x+=p1[pos];
                y+=p2[pos];
            }
            if(ans) break;
        }
        if(ok)
        {
            for(int i=0;i<5;i++)
            {
                printf("%c %c %c %c %c\n",s[i][0],s[i][1],s[i][2],s[i][3],s[i][4]);
            }
        }
        else printf("This puzzle has no final configuration.\n");
    }
    return 0;
}

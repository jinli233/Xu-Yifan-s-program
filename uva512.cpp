#include<stdio.h>

int main()
{
    int dx[51][51];
    int dy[51][51];
    char s[4];
    int c,r,n;
    scanf("%d% d",c,r);
    for(int i=1;i<=c;i++)
    {
        for(int j=1;j<=l;j++)
        {
            int dx[i][j]=i;
            int dy[i][j]=j;
        }
    }
    scanf("%d",&n);
    while(n--)
    {
        int k,x;
        scanf("%s",s);
        if(!strcmp(s,"DR"))
        {
            scanf("%d",&k);
            while(k--)
            {
               scanf("%d",&x);
               for(int i=1;i<=c;i++) dx[x][i]=0;
               for(int i=x+1;i<=r;i++) for(int j=1;j<=c;j++) dx[i][j]-=1;
            }
        }
        else if(!strcmp(s,"DC"))
        {
            scanf("%d",&k);
            while(k--)
            {
                scanf("%d",&x);
                for(int i=1;i<=r;i++) dy[i][x]=0;
                for(int i=x+1;i<=c;i++) for(int j=1;j<=r;j++) dy[j][i]-=1;
            }
        }
        else if(!strcmp(s,"IR"))
        {
            scanf("%d",&k);
            while(k--)
            {
                scanf("%d",&x);
                for(int i=x-1;i<=c;i++) for(int j=1;j<=r;j++) dx[i][j]+=1;
                r++;
            }
        }
    }
}

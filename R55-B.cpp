#include<stdio.h>
char x[100001];

int main()
{
    int n,g=0,s=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%c",x[i]);
        if(x[i]=='G') g+=1;
        else if(x[i]=='S') s+=1;
    }
    int pos=-1,m=0,t;
    for(int i=0;i<n;i++)
    {
        if(x[i])
        if(x[i]=='S')
        {
            t=i-pos;
            while()
        }
    }
    return 0;
}

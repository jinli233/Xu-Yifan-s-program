#include<stdio.h>
#include<string.h>
int n,k,cnt;
char a[85];

int find(int cur)
{
    if(cnt++==n) {a[cur]='\0';return 0;}
    for(int i=0;i<k;i++)
    {
        a[cur]='A'+i;
        int ok=1;
        for(int j=1;j<=(cur+1)/2;j++)
        {
            int f=0;
            for(int index=0;index<j;index++)
            {
                if(a[cur-index]!=a[cur-j-index]) {f=1;break;}
            }
            if(!f) {ok=0;break;}
        }
        if(ok) if(!find(cur+1)) return 0;
    }
    return 1;
}

int main()
{
    while(scanf("%d%d",&n,&k)==2&&n)
    {
        cnt=0;
        memset(a,0,sizeof(a));
        find(0);
        int len=strlen(a);
        for(int i=0;i<len;i++)
        {
            if(i&&i%64==0) printf("\n");
            else if(i&&i%4==0) printf(" ");
            printf("%c",a[i]);
        }
        printf("\n%d\n",len);
    }
    return 0;
}

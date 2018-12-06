#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
int main()
{
    int n,k,a[100000],sum=0,ans=0;
    scanf("%d%d",&n,&k);
    memset(a,0,sizeof(a));
    for(int i=0;i<n;i++) scanf("%d",a+i);
    sort(a,a+n);
    for(int i=0;i<n;i++) {a[i]-=sum;sum+=a[i];}
    for(int i=0;i<n;i++)
    {
        while(a[i]<=0) i++;
        if(i<n&&a[i]>0)
        {
            printf("%d\n",a[i]);
            k--;
            if(k==0) break;
        }
    }
    for(int i=0;i<k;i++) printf("0\n");
    return 0;
}

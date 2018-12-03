#include<stdio.h>
#include<algorithm>
using namespace std;

int main()
{
    int a[47];
    int t,n;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        for(int i=0;i<n;i++) scanf("%d",a+i);
        sort(a,a+n);
        if(n==1)
        {
            if(a[0]==1) printf("Brother\n");
            else printf("John\n");
            continue;
        }
        if(a[n-1]==1)
        {
            if(n%2) printf("Brother\n");
            else printf("John\n");
        }
        else
        {
            int ok=a[0];
            for(int i=1;i<n;i++) ok^=a[i];
            if(ok) printf("John\n");
            else printf("Brother\n");
        }
    }
    return 0;
}

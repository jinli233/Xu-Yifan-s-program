#include<stdio.h>
#include<algorithm>
using namespace std;

int main()
{
    int a[100];
    int n;
    while(~scanf("%d",&n))
    {
        for(int i=0;i<n;i++) scanf("%d",a+i);
        sort(a,a+n);
        if(n==1)
        {
            if(a[0]==1) printf("No\n");
            else printf("Yes\n");
            continue;
        }
        if(a[n-1]==1)
        {
            if(n%2) printf("No\n");
            else printf("Yes\n");
        }
        else
        {
            int ok=a[0];
            for(int i=1;i<n;i++) ok^=a[i];
            if(ok) printf("Yes\n");
            else printf("No\n");
        }
    }
    return 0;
}

#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;

int main(){
    int n,d1[10005],d2[10005];
    long long a[10005],low1[10005],low2[10005];
    while(scanf("%d",&n)!=EOF){
        int ans=1,pos1=1,pos2=1;
        for(int i=1;i<=n;i++) scanf("%lld",a+i);
        for(int i=1;i<=n;i++){
            if(i==1){
                d1[1]=1;
                low1[1]=a[1];
            }
            else{
                if(a[i]>low1[pos1]) low1[++pos1]=a[i];
                else{
                    *lower_bound(low1+1,low1+pos1+1,a[i])=a[i];
                }
                d1[i]=pos1;
            }
        }
        for(int i=n;i>=1;i--){
            if(i==n) {d2[n]=1;low2[1]=a[i];}
            else{
                if(a[i]>low2[pos2]) low2[++pos2]=a[i];
                else{
                    *lower_bound(low2+1,low2+pos2+1,a[i])=a[i];
                }
                d2[i]=pos2;
            }
        }
        for(int i=2;i<=n-1;i++){
            ans=max(ans,2*min(d1[i],d2[i])-1);
        }
        printf("%d\n",ans);
    }
}

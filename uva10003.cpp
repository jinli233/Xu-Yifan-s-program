#include<stdio.h>
#include<algorithm>
using namespace std;

int main(){
    int L;
    int a[55],d[55][55];
    while(scanf("%d",&L)==1&&L){
        int n;
        scanf("%d",&n);
        a[0]=0;
        a[n+1]=L;
        for(int i=1;i<=n;i++) scanf("%d",a+i);
        for(int i=0;i<=n+1;i++) for(int j=0;j<=n+1;j++) d[i][j]=1<<30;
        for(int len=1;len<=n+1;len++) for(int i=0;i+len<=n+1;i++){
            if(len==1) d[i][len+i]=0;
            else{
                for(int k=i+1;k<i+len;k++){
                    d[i][len+i]=min(d[i][len+i],d[i][k]+d[k][len+i]+a[len+i]-a[i]);
                }
            }
        }
        printf("The minimum cutting is %d.\n",d[0][n+1]);
    }
}

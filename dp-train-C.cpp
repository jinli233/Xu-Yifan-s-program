#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;

int dp[105][55500];

int main(){
    int t,sum;
    scanf("%d",&t);
    while(t--){
        memset(dp,0,sizeof(dp));
        dp[0][0]=1;
        int n,a[105];
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%d",a+i);
        for(int i=1;i<=n;i++) for(int j=0;j<=55000;j++){
            dp[i][j]=max(dp[i-1][abs(j-a[i])],dp[i-1][abs(j+a[i])]);
        }
        for(int i=0;i<=55000;i++) if(dp[n][i]) {
            printf("%d\n",i);
            break;
        }
    }
}

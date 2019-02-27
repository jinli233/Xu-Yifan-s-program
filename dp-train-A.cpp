#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;

int main(){
    int t;
    long long vis[205][205],dp[205];
    char s[550];
    scanf("%d",&t);
    while(t--){
        memset(vis,0,sizeof(vis));
        memset(dp,-1,sizeof(dp));
        scanf("%s",s);
        int len=strlen(s);
        for(int i=1;i<=len;i++) for(int j=i;j<=len;j++){
            if(j==i) vis[i][j]=s[i-1]-'0';
            else{
                vis[i][j]=vis[i][j-1]*10+s[j-1]-'0';
                if(vis[i][j]>((1<<31)-1)){
                    vis[i][j]=-1;
                    break;
                }
            }
        }
        for(int i=1;i<=len;i++){
            dp[i]=vis[1][i];
            for(int j=1;j<i;j++){
                dp[i]=max(dp[i],dp[j]+vis[j+1][i]);
            }
        }
        printf("%lld\n",dp[len]);
    }
}

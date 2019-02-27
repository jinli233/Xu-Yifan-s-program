#include<stdio.h>

int dp[1000005];
const int  INF=1<<30;

int main(){
    int n,m,s[15];
    while(scanf("%d",&n)!=EOF){
        for(int i=0;i<=n;i++) dp[i]=i;
        scanf("%d",&m);
        for(int i=0;i<m;i++) scanf("%d",s+i);
        for(int i=1;i<=n;i++){
            int ok=0;
            for(int j=0;j<m;j++){
                if(s[j]<=i){
                    if(dp[i-s[j]]==0) ok=1;
                }
            }
            if(ok) dp[i]=1;
            else dp[i]=0;
        }
        if(!dp[n]) printf("Ollie wins\n");
        else printf("Stan wins\n");
    }
}

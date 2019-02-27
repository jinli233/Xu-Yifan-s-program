#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

int t,dp[1050];
char s[1050];
int vis[1050][1050];

int is_Palindrome(int L,int R){
    int &ans=vis[L][R];
    if(L>=R) ans=1;
    if(ans>=0) return ans;
    if(s[L-1]==s[R-1]&&is_Palindrome(L+1,R-1)) vis[L][R]=1;
    else vis[L][R]=0;
    return ans;
}

int main()
{

    scanf("%d",&t);
    while(t--){
        scanf("%s",s);
        int len=strlen(s);
        memset(vis,-1,sizeof(vis));
        dp[0]=0;
        for(int i=1;i<=len;i++){
            for(int j=i;j<=len;j++){
                is_Palindrome(i,j);
            }
        }
        for(int i=1;i<=len;i++){
            dp[i]=dp[i-1]+1;
            for(int j=i-1;j>=1;j--){
                if(vis[j][i]) dp[i]=min(dp[i],dp[j-1]+1);
            }
        }
        printf("%d\n",dp[len]);
    }
    return 0;
}

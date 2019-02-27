#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

int w[1005],s[1005],d[1005],G[1005][1005];

int dp(int i,int n){
    int &ans=d[i];
    if(ans>=0) return ans;
    ans=1;
    for(int j=1;j<=n;j++){
        if(G[i][j]) ans=max(ans,dp(j,n)+1);
    }
    return ans;
}

void print(int pos,int i,int n){
    for(int j=1;j<=n;j++){
        if(d[j]==pos&&G[i][j]){
            printf("%d\n",j);
            print(pos-1,j,n);
            break;
        }
    }
}

int main(){
    memset(G,0,sizeof(G));
    memset(d,-1,sizeof(d));
    int ans=1,pos=0;
    while(scanf("%d",w+ans)!=EOF) {scanf("%d",s+ans);ans++;}
    ans--;
    for(int i=1;i<=ans;i++) G[0][i]=1;
    for(int i=1;i<=ans;i++) for(int j=1;j<=ans;j++) {
        if(w[i]<w[j]&&s[i]>s[j]) G[i][j]=1;
    }
    for(int i=1;i<=ans;i++) pos=max(pos,dp(i,ans));
    printf("%d\n",pos);
    print(pos,0,ans);
    return 0;
}

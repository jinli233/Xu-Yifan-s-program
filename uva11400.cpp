#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
const int INF=1<<30;
struct light
{
    int v;
    int k;
    int c;
    int l;
    bool operator < (const light& b) const{
        if(this->v<b.v) return true;
        else return false;
    }
}Light[1050];

int dp[100050];

int main(){
    int n,sum,ans;
    while(scanf("%d",&n)==1&&n){
        sum=ans=0;
        for(int i=1;i<=n;i++) {scanf("%d%d%d%d",&Light[i].v,&Light[i].k,&Light[i].c,&Light[i].l);sum+=Light[i].l;}
        for(int i=1;i<=sum;i++) dp[i]=INF;
        dp[0]=0;
        sort(Light+1,Light+1+n);
        for(int i=1;i<=n;i++){
            ans+=Light[i].l;
            int pos=0;
            for(int j=i;j>=1;j--){
                pos+=Light[j].l;
                dp[ans]=min(dp[ans],dp[ans-pos]+Light[i].c*pos+Light[i].k);
            }
        }
        printf("%d\n",dp[sum]);
    }
    return 0;
}

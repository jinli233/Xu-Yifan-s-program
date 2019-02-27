#include<stdio.h>
#include<queue>
#include<algorithm>
#include<string.h>
using namespace std;
const int INF=1<<30;
struct Edge{
    int u,v,t;
}edge[2005];

int main(){
    int t,inq[1005],cnt[1005],d[1005];
    scanf("%d",&t);
    while(t--){
        int n,m,ok=0;
        queue<int> q;
         scanf("%d %d",&n,&m);
        memset(inq,0,sizeof(inq));
        memset(cnt,0,sizeof(cnt));
        for(int i=0;i<n;i++) d[i]=INF;
        for(int i=0;i<m;i++) scanf("%d%d%d",&edge[i].u,&edge[i].v,&edge[i].t);
        inq[0]=1;
        d[0]=0;
        q.push(0);
        while(!q.empty()){
            int x=q.front();q.pop();
            inq[x]=0;
            for(int i=0;i<m;i++){
                if(edge[i].u==x&&d[x]<INF&&d[edge[i].v]>d[x]+edge[i].t){
                    d[edge[i].v]=d[x]+edge[i].t;
                    if(!inq[edge[i].v]){
                        q.push(edge[i].v);
                        inq[edge[i].v]=1;
                        if(++cnt[edge[i].v]>n){
                            printf("possible\n");
                            ok=1;
                            break;
                        }
                    }
                }
            }
            if(ok) break;
        }
        if(!ok) printf("not possible\n");
    }
}

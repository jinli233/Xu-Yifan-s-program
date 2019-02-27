#include<stdio.h>
#include<string.h>
#include<queue>
#include<algorithm>
#include<stdlib.h>
using namespace std;

struct node{
    int f,dis,last;
    bool operator <(const node &rhs) const{
        return dis>rhs.dis;
    }
};

int n,k,w[7],e[7][150],done[7][150],d[7][150];
priority_queue<node>q;

int main(){

    while(scanf("%d",&n)!=EOF){
        scanf("%d",&k);
        getchar();
        while(!q.empty()) q.pop();
        memset(e,0,sizeof(e));
        memset(d,0,sizeof(d));
        memset(done,0,sizeof(done));
        for(int i=0;i<n;i++) scanf("%d",w+i);
        getchar();
        for(int i=0;i<n;i++){
            char ch,x;
            for(;scanf("%d%c",&x,&ch)&&ch!='\n';){
                e[i][x]=1;
            }
            e[i][x]=1;
        }
        if(k==0){
            printf("0\n");
            continue;
        }
        struct node temp;
        temp.f=0;
        temp.last=-1;
        temp.dis=0;
        q.push(temp);
        int ok=0;
        while(!q.empty()){
            struct node x=q.top();q.pop();
            if(done[x.last][x.f]) continue;
            done[x.last][x.f]=1;
            if(x.f==k){
                printf("%d\n",x.dis);
                ok=1;
                break;
            }
            for(int i=0;i<n;i++){
                if(e[i][x.f]){
                    for(int index=0;index<=99;index++){
                        if(index==x.f) continue;
                        if(e[i][index]&&!done[i][index]){
                            struct node newnode=x;
                            newnode.f=index;
                            if(newnode.last!=i&&newnode.last!=-1) newnode.dis+=60;
                            newnode.last=i;
                            newnode.dis+=abs(index-x.f)*w[i];
                            if(!d[i][newnode.f]|d[i][newnode.f]>newnode.dis){
                                q.push(newnode);
                                d[i][newnode.f]=newnode.dis;
                            }
                        }
                    }
                }
            }
        }
        if(!ok) printf("IMPOSSIBLE\n");
    }
    return 0;
}

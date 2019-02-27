#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<map>
#include<queue>
using namespace std;

struct node{
    int w,bugs;
    bool operator < (const node & rhs) const{
     return w>rhs.w;
    }
};

char from[105][25],to[105][25];
int n,m,t[105],kase=0,done[1<<20],M[1<<20];

int main(){
    struct node temp;
    while(scanf("%d%d",&n,&m)&&n){
        int f=0;
        memset(done,0,sizeof(done));
        memset(M,0,sizeof(M));
        priority_queue<node> q;
        for(int i=0;i<m;i++) scanf("%d%s%s",&t[i],from[i],to[i]);
        temp.bugs=(1<<n)-1;
        temp.w=0;
        q.push(temp);
        while(!q.empty()){
            struct node x;
            x=q.top();q.pop();
            if(x.bugs==0){
                printf("Product %d\nFastest sequence takes %d seconds.\n\n",++kase,x.w);
                f=1;
                break;
            }
            if(done[x.bugs]) continue;
            done[x.bugs]=1;
            for(int i=0;i<m;i++){
                int ok=1;
                for(int j=0;j<n;j++){
                    if(from[i][j]=='-'&&((1<<j)&x.bugs)){
                        ok=0;
                        break;
                    }
                    if(from[i][j]=='+'&&!((1<<j)&x.bugs)){
                        ok=0;
                        break;
                    }
                }
                if(ok){
                    struct node newnode;
                    newnode.bugs=x.bugs;
                    for(int j=0;j<n;j++){
                        if(to[i][j]=='+'){
                            newnode.bugs|=(1<<j);
                        }
                        if(to[i][j]=='-'){
                            newnode.bugs&=~(1<<j);
                        }
                    }
                    newnode.w=x.w+t[i];
                    if(M[newnode.bugs]==0||newnode.w<M[newnode.bugs]){
                        q.push(newnode);
                        M[newnode.bugs]=newnode.w;
                    }
                }
            }
        }
        if(!f){
            printf("Product %d\nBugs cannot be fixed.\n\n",++kase);
        }
    }
}

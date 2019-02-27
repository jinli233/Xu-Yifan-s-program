#include<stdio.h>
#include<queue>
#include<map>
#include<string.h>
#include<algorithm>
using namespace std;

struct node{
    int pos,ans,ID;
    char state[30][20];
};

deque<node> q;
deque<node> wait;
map<char,int> M;

int main(){
    int t,n,t1,t2,t3,t4,t5,Q,lock;
    scanf("%d",&t);
    while(t--){
        scanf("%d %d %d %d %d %d %d\n",&n,&t1,&t2,&t3,&t4,&t5,&Q);
        M.clear();
        lock=0;
        for(int i=1;i<=n;i++){
            struct node temp;
            temp.ID=i;
            temp.pos=0;
            temp.ans=0;
            while(fgets(temp.state[temp.ans],20,stdin)&&!strstr(temp.state[temp.ans],"end")) {temp.ans++;}
            q.push_back(temp);
        }
        while(!q.empty()){
            struct node x=q.front();q.pop_front();
            int t=0;
            for(int i=x.pos;i<x.ans;i++){
                x.pos=i;
                if(strstr(x.state[i],"=")){
                    if(t1+t>Q){
                        q.push_back(x);
                        break;
                    }
                    int num=0;
                    for(int j=4;;j++){
                        if(x.state[i][j]=='\n') break;
                        else num=num*10+x.state[i][j]-'0';
                    }
                    M[x.state[i][0]]=num;
                    t+=t1;
                }
                else if(strstr(x.state[i],"print")) {
                    if(t2+t>Q){
                        q.push_back(x);
                        break;
                    }
                    printf("%d: %d\n",x.ID,M[x.state[i][6]]);
                    t+=t2;
                }
                else if(strcmp(x.state[i],"lock\n")==0){
                    if(t3+t>Q){
                        q.push_back(x);
                        break;
                    }
                    if(lock){
                        wait.push_back(x);
                        break;
                    }
                    lock=1;
                    t+=t3;
                }
                else if(strstr(x.state[i],"unlock")){
                    if(t4+t>Q){
                        q.push_back(x);
                        break;
                    }
                    lock=0;
                    while(!wait.empty()){
                        struct node temp=wait.back();
                        wait.pop_back();
                        q.push_front(temp);
                    }
                    t+=t4;
                }
            }
        }
        if(t) printf("\n");
    }
}

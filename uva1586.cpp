#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<map>
using namespace std;
map<int,double> cnt;

int main()
{
    cnt['C']=12.01;
    cnt['H']=1.008;
    cnt['O']=16.00;
    cnt['N']=14.01;
    int t;
    char s[81];
    scanf("%d",&t);
    while(t--)
    {
        double sum=0;
        scanf("%s",s);
        int len=strlen(s);
        for(int i=0;i<len;i++)
        {
            int A=1,pos=0;
            while(i+pos+1!=len&&!isalpha(s[i+pos+1]))
            {
                if(!pos) A=s[i+pos+1]-'0';
                else A=A*10+s[i+pos+1]-'0';
                pos++;
            }
            sum+=cnt[s[i]]*A;
            printf("%d\n",A);
            i+=pos;
        }
        printf("%0.3f\n",sum);
    }
}

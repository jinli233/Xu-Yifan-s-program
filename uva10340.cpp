#include<iostream>
#include<string>
using namespace std;

int main()
{
    string s,t;
    int L1,L2;
    while(cin>>s)
    {
        cin>>t;
        L1=s.length();
        L2=t.length();
        int pos=0,ans=0;
        for(int i=0;i<L1;i++)
        {
            for(int j=pos;j<L2;j++)
            {
                if(s[i]==t[j])
                {
                    pos=j+1;
                    ans+=1;
                    break;
                }
            }
        }
        if(ans<L1) cout<<"No"<<endl;
        else cout<<"Yes"<<endl;
    }
    return 0;
}

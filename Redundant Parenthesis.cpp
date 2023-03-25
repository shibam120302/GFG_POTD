class Solution{   
public:
    string removeBrackets(string s){
        
        int n=s.size();
        int ans[n+1];
        memset(ans,1,sizeof(ans));
        int lasta[n+1];
        int nxta[n+1];


        int l=-1;
        for(int i=0;i<n;i++){
            lasta[i]=l;
            if(s[i]=='*'||s[i]=='+'||s[i]=='-'||s[i]=='/')
                    l=s[i];
        }
        l=-1;
        for(int i=n-1;i>=0;i--){
            nxta[i]=l;
            if(s[i]=='*'||s[i]=='+'||s[i]=='-'||s[i]=='/')
                    l=s[i];
        }


        stack<int> st;
        int sign[256],mp[256]={0};
        memset(sign,-1,sizeof(sign));
        vector<char> operand={'*','+','-','/'};

        for(int p=0;p<s.size();p++)
        {
            for(auto j:operand){
                mp[j]=0;
                if(j==s[p])
                    sign[j]=p;
            }
            if(s[p]=='(')
                st.push(p);

            else if(s[p]==')'){
                int i=st.top();
                int j=p;

                int nxt=nxta[j];
                int last=lasta[i];
                st.pop();
                for(auto j:operand){
                    if(sign[j]>=i){
                        mp[j]=1;
                    }
                }
                int ok=0;
                
                if(i>0&&j+1<s.size()&&s[i-1]=='('&&s[j+1]==')')
                    ok=1;
                if(mp['+']==0&&mp['*']==0&&mp['-']==0&&mp['/']==0)
                    ok=1;
               

                if(last==-1&&nxt==-1)
                    ok=1;
                if(last=='/'){

                }
                else if(last=='-'&&(mp['+']==1||mp['-']==1)){
                    
                }
                else if(mp['-']==0&&mp['+']==0){
                    ok=1;
                }
                else{
                    if((last==-1||last=='+'||last=='-')&&(nxt==-1||nxt=='+'||nxt=='-'))
                        ok=1;
                }
                if(ok==1){
                    ans[i]=0;
                    ans[j]=0;
                }
                               
            }
        }
        string res="";
        for(int i=0;i<n;i++){
            if(ans[i]){
                res.push_back(s[i]);
            }
        }
        return res;
    }
};

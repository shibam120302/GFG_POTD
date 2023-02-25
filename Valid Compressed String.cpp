class Solution {
  public:
    int checkCompressed(string s, string t) {
        int n = 0;
        int flag = 1;
        int j = 0;
        for(int i=0; i<t.length(); i++)
        {
            if (t[i]>='0' && t[i]<='9')
            {
                n *= 10;
                if(n>100000)
                    return 0;
                n += t[i] - '0';
                j--;
            }
            else
            {
                j += n;
                if(t[i]!=s[j])
                {
                    flag = 0;
                    break;
                }
                n = 0;
            }
            j++;
        }
        j += n;
        if(j != s.length())
            flag = 0;

        if(flag)
            return 1;
        else
            return 0;
    }
};

# include<cstring>;
class Solution {
public:
int t[1001][1001];
bool solve(string & s,int i,int j){
    if(i>=j){
        return 1;
    }
    if(t[i][j]!=-1){
        return t[i][j];
    }
    if(s[i]==s[j]){
        return t[i][j]=solve(s,i+1,j-1);
    }
    return t[i][j]= 0;
}

    string longestPalindrome(string s) {
        int st=0;
        int maxLen=0;
        memset(t,-1,sizeof(t));

        for(int i=0;i<s.length();i++){
            for(int j=i;j<s.length();j++){
                    if(solve(s,i,j)==true){
                        if(j-i+1>maxLen){
                            maxLen=j-i+1;
                            st=i;
                        }
                    }
            }
        }
        return s.substr(st,maxLen);

    }
};
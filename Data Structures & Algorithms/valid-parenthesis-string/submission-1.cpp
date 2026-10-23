#include<cstring>
class Solution {
public:
int t[101][101];
    bool solve(string& s, int i, int open, int n) {

        if(i == n){
            return open == 0;
        }
        if(t[i][open]!=-1){
            return t[i][open];
        }

        bool isValid = false;

        if(s[i] == '('){

            isValid |= solve(s, i+1, open+1, n);

        }
        else if(s[i] == ')'){

            if(open > 0){
                isValid |= solve(s, i+1, open-1, n);
            }

        }
        else if(s[i] == '*'){

            // * as '('
            isValid |= solve(s, i+1, open+1, n);

            // * as empty
            isValid |= solve(s, i+1, open, n);

            // * as ')'
            if(open > 0){
                isValid |= solve(s, i+1, open-1, n);
            }
        }

        return t[i][open]= isValid;
    }

    bool checkValidString(string s) {
        int n = s.length();
        memset(t,-1,sizeof(t));
        return solve(s, 0, 0, n);
    }
};
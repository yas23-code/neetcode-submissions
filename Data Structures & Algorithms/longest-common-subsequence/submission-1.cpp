#include<cstring>
class Solution {
public:
int t[1001][1001];
int solve(int i,int j,string text1,string text2){
    int m=text1.size(), n=text2.size();
    if(i>=m||j>=n){
        return 0;
    }
    if(t[i][j] != -1) {
    return t[i][j];
}
    if(text1[i]==text2[j]){
        return t[i][j]= 1+solve(i+1,j+1,text1,text2);
    }
    return t[i][j]= max(solve(i,j+1,text1,text2),solve(i+1,j,text1,text2));
}
    int longestCommonSubsequence(string text1, string text2) {
        memset(t,-1,sizeof(t));
        return solve(0,0,text1,text2);

        
    }
};

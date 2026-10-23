class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(),strs.end());
        string str1=strs[0];
        string str2=strs[strs.size()-1];
        int index=0;
        while(index<str1.length()&& index<str2.length()){
            if(str1[index]==str2[index]){
                index++;
            }else{
                break;
            }
        }
        return str1.substr(0,index);

        
    }
};
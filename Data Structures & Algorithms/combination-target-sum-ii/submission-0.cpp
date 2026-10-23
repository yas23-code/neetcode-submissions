class Solution {
public:
void comb(vector<int>& candidates,vector<vector<int>>& ans,vector<int>& curr,int idx,int target){
    if(target<0){
        return;
    }
    if(target==0){
        ans.push_back(curr);
        return;
    }
    for(int i=idx;i<candidates.size();i++){
        if(i>idx && candidates[i]==candidates[i-1]){
            continue;
        }
        curr.push_back(candidates[i]);//do
        comb(candidates,ans,curr,i+1,target-candidates[i]);//explore
        curr.pop_back();//undo
    }
}
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {\
    vector<vector<int>>ans;
    vector<int>curr;
    sort(candidates.begin(),candidates.end());
    comb(candidates,ans,curr,0,target);

    return ans;
        
    }
};

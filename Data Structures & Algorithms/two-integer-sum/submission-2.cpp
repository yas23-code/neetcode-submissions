class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++){
            int no=target-nums[i];
            if(mp.find(no)!=mp.end()){
                return {mp[no],i};
                
            }
            mp[nums[i]]=i;
        }
        return {};
    }
};
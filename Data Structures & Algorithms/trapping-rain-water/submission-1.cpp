class Solution {
public:
    int trap(vector<int>& height) {
      int l=0;
      int r=height.size()-1;
      int leftMax=0;
      int rightMax=0;
      int ans=0;
      while(l<r){
        leftMax=max(height[l],leftMax);
        rightMax=max(height[r],rightMax);
        if(leftMax<rightMax){
            ans+=leftMax-height[l];
            l++;

        }else{
            ans+=rightMax-height[r];
            r--;
        }


      }
      return ans;
        
    }
};

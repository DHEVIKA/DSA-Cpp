class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left=0;
        int right=0;
        int sum=0;
        int minlen=INT_MAX;
        while(right<nums.size()){
            sum+=nums[right];
            while(sum>=target){
                sum-=nums[left];
                minlen=min(right-left+1,minlen);
                left++;
            }
            right++;
        }
        if(minlen==INT_MAX){
            return 0;
        }
        return minlen;
    }
};
class Solution {
public:
    int minPairSum(vector<int>& nums) {
        int n = nums.size();
        //1. sorting 
        sort(nums.begin(),nums.end());
        //2. l = 0;r = n-1
        int l = 0 , r = n-1;
        int result = 0;
        //3. condition 
        while(l < r){
            int sum = nums[l]+nums[r];
            result = max(result, sum);
            l++;
            r--;
        }
        return result;
        
    }
};
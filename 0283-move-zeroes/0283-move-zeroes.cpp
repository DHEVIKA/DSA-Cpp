class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        
        /* two pointer approach
        [0,1,0,3,12] -->
        both left and right r at the index 0 and here we need to keep track of right point.. the left pointer should have the non zero and the right pointer should have zeos at the end 

        if u found the zeros are at the left pointer n non zeros in the right pointer jus swap it and increment the left++ */

        int n = nums.size();
        int left = 0;
        for(int right = 0;right<n;right++){
            if(nums[right] !=0){
                int temp = nums[right];
                nums[right] = nums[left];
                nums[left] = temp;
                left++;
            }
        }
    
    }
};
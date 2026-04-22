class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int n = nums.size();
        int maxSum = nums[0];
        int currMax = nums[0];
        int minSum =  nums[0];
        int currMin = nums[0];
        int maximum_abs_sum = INT_MIN;
        
        for(int i = 1 ; i < n ; i++){
          
            currMax = max(nums[i], currMax + nums[i]);
            maxSum = max(maxSum, currMax);

            currMin = min(nums[i], currMin + nums[i]);
            minSum = min(minSum, currMin);
        }
        
        maximum_abs_sum = max(abs(maxSum), abs(minSum));
        return maximum_abs_sum;
    }
};

// For each index i:
            // Either extend the prev subarray if the current sum is greater, 
            // or start a new one since there is no point of adding an element if it reduces the sum.
            // We calculate it for both the maximum and minimum since we are finding the absolute sum
            // (the maximum absolute sum could come from a highly negative subarray).
            // For example: maximumAbs = max(abs(3), abs(-8)) = 8


/*
1. Track Maximum Subarray (Kadane's for Max): For each element, we decide whether to add it to the existing currMax subarray or start a new subarray from the current element. We do this by setting currMax = max(nums[i], currMax + nums[i]). We then update our global maxSum.
2. Track Minimum Subarray (Kadane's for Min): Simultaneously, we do the exact same logic but look for the lowest possible sum. We set currMin = min(nums[i], currMin + nums[i]) and update our global minSum.
3. Calculate Absolute Maximum: Once the loop finishes, we compare the absolute values of our global maxSum and minSum. We return max(abs(maxSum), abs(minSum)).

*/
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int minLen = INT_MAX;
        int left = 0;
        int curSum = 0;

        for (int right = 0; right < nums.size(); right++) {
            curSum += nums[right]; // EXPAND RIGHT

            while (curSum >= target) {
                if (right - left + 1 < minLen) {  // SHRINK LEFT
                    minLen = right - left + 1; 
                }
                curSum -= nums[left]; // REMOVE LEFT MOST
                left++;
            }
        }

        return minLen != INT_MAX  ? minLen : 0;        
    }
};

/* use 2 pointers to maintain the sliding window either left or right or keep left n track right
Expand the window (right++) to increase the sum until it becomes >= target
once the sum is larger enough:
    shrink the window from the left(left++) to making it smaller
    Track the minimum size of window
Repeat until right reaches to end */
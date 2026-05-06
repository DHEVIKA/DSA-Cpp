class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l = 0, zeroCount = 0, maxLen = 0;

        for (int r = 0; r < nums.size(); r++) {
            if (nums[r] == 0) zeroCount++; // if the right has zeros increment 0s count

            while (zeroCount > k) { // edge case be careefull 0scount > k and left == 0 decrement the 0s count and increment the left
                if (nums[l] == 0) zeroCount--;
                l++;
            }

            maxLen = max(maxLen, r - l + 1); // length calculating right - left +1
        }

        return maxLen;
    }
};
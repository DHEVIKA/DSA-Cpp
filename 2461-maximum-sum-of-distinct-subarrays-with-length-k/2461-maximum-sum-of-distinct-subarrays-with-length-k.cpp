class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> freq; // to calculate duplicates
        long long windowSum = 0, maxSum = 0;
        int l = 0;

        for (int r = 0; r < nums.size(); r++) {
            windowSum += nums[r];
            freq[nums[r]]++;

            if (r - l + 1 > k) {  //if the length is exceeded k 
                windowSum -= nums[l];
                freq[nums[l]]--;
                if (freq[nums[l]] == 0) {
                    freq.erase(nums[l]);
                }
                l++;
            }

            if (r - l + 1 == k && freq.size() == k) {
                maxSum = max(maxSum, windowSum);
            }
        }

        return maxSum;
    }
};

/* Here, we need to find a subarray of length k such that:
-> All elements are distinct
-> The sum is maximized

A brute-force approach would check every subarray of size k and verify if all elements are distinct, but that would take O(n · k) time, which is too slow.

Instead, we observe that:
-> We are only dealing with fixed-size windows (k)
-> So we can use a sliding window to efficiently move from one subarray to the next

As we slide the window:
-> We add the new element entering the window
-> We remove the element leaving the window
-> We maintain a frequency map to track occurrences of elements in the current window
-> We also maintain the current sum of the window

To check if all elements are distinct:
If the number of unique elements(length of frequency map) in the map equals k, then all elements are distinct
Otherwise, duplicates exist

This avoids rechecking the entire window every time and allows us to update everything in constant time per step.

Thus, we efficiently compute the answer in O(n) time using a sliding window and hash map.

*/
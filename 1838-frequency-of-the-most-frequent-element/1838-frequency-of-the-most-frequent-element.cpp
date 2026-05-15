class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        
        int maxSum = 0;
        sort(nums.begin(),nums.end());
        long sum = 0;
        int left = 0,right = 0;

        while(right<nums.size()){
            sum +=nums[right];

            while((long)nums[right]*(right-left+1)-sum > k){
                sum -= nums[left];
                left++;
            }
            maxSum = max(maxSum,right-left+1);
            right++;
        }
        return maxSum;
    }
};

/* 
Main Intuition

After sorting:

1 2 4

We try to make all elements equal to the largest element in the window.

Example:
Make [1,2,4] become [4,4,4]

Operations needed:

(4−1)+(4−2)+(4−4)=5

If operations ≤ k, window is valid.  

Important Formula

This line checks how many operations are needed:

nums[right]×window size−sum

Explanation:

nums[right] * window size
→ total sum needed if all become biggest element
sum
→ current window sum
difference
→ operations needed
Dry Run

Input:

nums = [1,2,4]
k = 5

After sorting:

[1,2,4]
Step 1
right = 0
sum = 1

Operations:

1×1−1=0

Valid.

maxSum = 1
Step 2
right = 1
sum = 3

Operations:

2×2−3=1

Valid.

maxSum = 2
Step 3
right = 2
sum = 7

Operations:

4×3−7=5

Valid because 5 <= k.

maxSum = 3

Final Answer:

3
Time Complexity

Sorting:

O(N log N)

Sliding Window:

O(N)

Total:

O(N log N)
Space Complexity
O(1)

*/
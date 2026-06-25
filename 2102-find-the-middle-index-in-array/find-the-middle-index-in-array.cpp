class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        int n = nums.size(), sum = 0, leftSum = 0, rightSum = 0;

        for (int i = 0; i < n; i++) {
            sum += nums[i]; // add all sum of nums
        }

        for (int i = 0; i < n; i++) {
            leftSum += nums[i];
            rightSum = sum - leftSum + nums[i];

            if (leftSum == rightSum) return i;
        }

        return -1;
    }
};

/* We need to find an index such that the sum of elements on its left is equal to the sum of elements on its right.

A brute force approach would be to calculate left and right sums for every index, but that would be inefficient (O(n²)).

Instead, we observe that:

If we know the total sum of the array,
And we keep a running left sum while iterating,
Then we can compute the right sum in constant time using:
rightSum = totalSum - leftSum + nums[i]

This allows us to check the condition efficiently in a single pass.

🚀 Approach
First, compute the total sum of the array.
Initialize leftSum = 0.
Traverse the array:
Add current element to leftSum.
Compute rightSum = totalSum - leftSum + nums[i].
If leftSum == rightSum, return the current index.
If no such index is found, return -1.
⏱️ Complexity
Time complexity: O(n)
One pass to calculate total sum + one pass to find the index

Space complexity: O(1)
No extra space used, only variables

Step 1: Calculate Total Sum
sum = 0

sum += 2  -> 2
sum += 3  -> 5
sum += -1 -> 4
sum += 8  -> 12
sum += 4  -> 16

So:

sum = 16

Initialize:

leftSum = 0
Step 2: Traverse Array
i = 0
leftSum += nums[0]
leftSum = 0 + 2 = 2
rightSum = sum - leftSum + nums[i]
         = 16 - 2 + 2
         = 16

Check:

2 == 16 ? NO  do for all untill left sum == right sum

*/
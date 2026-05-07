class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n = nums.size();
        if (k<=1) return 0; // negative numbers
        int left = 0;
        int right = 0 ;
        int product = 1;
        int count = 0;
        while(right<n){
            product*=nums[right];  
         
            while(product>=k){
                product/=nums[left];
                left++;

            }
            count+= right-left+1;
            right++;
        }
        return count;

        
    }
};


/* In brute force, we recompute product again and again.

Instead:

Reuse the previous product

Maintain a window

Adjust it when product becomes invalid

When prod >= k, remove elements from the left
Keep expanding from the right
Example
nums = [10, 5, 2, 6], k = 100
Step-by-step:

Step 1:

i = 0
prod = 10
subarrays: [10]
count += 1
Step 2:


i = 1
prod = 10 * 5 = 50
subarrays: [5], [10,5]
count += 2
Step 3:

i = 2
prod = 50 * 2 = 100 (>= k) → shrink window
prod = 100 / 10 = 10, lp = 1
subarrays: [2], [5,2]
count += 2
Step 4:

i = 3
prod = 10 * 6 = 60
subarrays: [6], [2,6], [5,2,6]
count += 3

Total = 1 + 2 + 2 + 3 = 8
Total = 8

*/
class Solution {
public:
    int countPairs(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int left =0;
        int right = n-1;
        int count = 0;
        while(left<right){
            int sum = nums[left]+nums[right];
            if(sum<target){
                count = count +(right-left);
                left++;
            }
            else{
                right--;
            }

        }
        
    return count;
        
    }
};

/*

Complexity Analysis:
⏱ Time Complexity O(nlogn)
 Space Complexity O(log n)
Example: nums = [-1, 1, 2, 3], target = 3
Explanation:
After sorting: [-1, 1, 2, 3]
Step i j nums[i] nums[j] sum Sum < target ? Acttion count
1. 0 3 -1 3 2 Yes Add(3 - 0) = 3 →
i++
3
2. 1 3 1 3 4 No j-- 3
3. 1 2 1 2 3 No j-- 3
4. 1 1 - - - Stop - Final count
= 3
 Intuition:
When the array is sorted, one comparison tells you not just about one pair — but about many pairs at once.
 Quote
“Count less, think more — that’s how efficient algorithms work.”


*/
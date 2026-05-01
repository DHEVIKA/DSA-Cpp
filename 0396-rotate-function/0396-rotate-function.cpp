class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size();

        long long sum = 0;       // F(0)
        long long mx = 0;
        long long totalSum = 0;  // sum of all elements

        for(int i = 0; i < n; i++) {
            sum += (long long)i * nums[i]; // indexes * nums[i]
            totalSum += nums[i]; // add up
        }

        mx = sum; // upate it once reached

        for(int i = n - 1; i >= 0; i--) {     // for roattion
            sum = sum + totalSum - (long long)n * nums[i];
            mx = max(mx, sum);
        }

        return (int)mx;
    }
};


/* steps:

compute sum = total sum of all elements and F(0) = sum (i*nums[i])
2. formula: F(k) = F(k-1) + sum - n*nums[n-k] (explained in video how we get the formula)
then iterate k from 1 to n-1 and find all values of F
update maximum everytime   */

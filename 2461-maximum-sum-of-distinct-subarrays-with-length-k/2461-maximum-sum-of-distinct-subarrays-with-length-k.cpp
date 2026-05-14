class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_set<int> elements;
        long long current_sum = 0;
        long long max_sum = 0;
        int left = 0;
        
        for (int right = 0; right < n; right++) {
            if (elements.find(nums[right]) == elements.end()) {   // to avoid duplicate  we use set checks if the current element (nums[right]) is NOT present in the set elements
                current_sum += nums[right]; // add the right element 
                elements.insert(nums[right]); // put inside the set
                
                if (right -left + 1 == k) { //codition length == k
                    max_sum = max(max_sum, current_sum); //update the max
                    current_sum -= nums[left ]; // remove the left most 
                    elements.erase(nums[left ]); // remove from set also
                    left ++;
                }
            } else {
                while (nums[left ] != nums[right]) {
                    current_sum -= nums[left ];
                    elements.erase(nums[left ]);
                    left ++;
                }
                left ++;
            }
        }
        
        return max_sum;
    }
};
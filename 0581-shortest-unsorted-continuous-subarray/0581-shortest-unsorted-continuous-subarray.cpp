class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        int left = -1, right = -1;
        int maxSeen = nums[0];
        int minSeen = nums[n-1];
        // left scan to find the end boundary of the unsorted array
        for(int i = 1; i < n ; i++){
            maxSeen = max(maxSeen , nums[i]);
            // if an element is smaller than the maxSeen 
            // it is in the wrong position globally
            if(nums[i] < maxSeen){
                right = i;
            }
        }
        // right scan to find the start boundary of the unsorted array 
        for(int i = n - 2; i >= 0 ; i--){
            minSeen = min(minSeen ,nums[i]);
            // if an element is greater than the minSeen its in wrong position globally
            if(nums[i] > minSeen){
                left = i;
            }
        }   
        // if right hasn't moved a bit , it means the array is already sorted 
        if(right == -1) return 0;
        return right - left + 1;
    }
};


/*

We are checking for global violations, not adjacent ones.
In a correctly sorted array:
Every element should be greater than or equal to all elements on its left
Every element should be less than or equal to all elements on its right

So,during the left scan, we track maxSeen.If we find an element smaller than maxSeen,it means a larger element exists before it,so this element cannot be in its correct sorted position.

Similarly during the right scan, we track minSeen.If we find an element greater than minSeen,it means a smaller element exists after it,so this element cannot be in its correct sorted position.

These violations define the smallest unsorted window. */
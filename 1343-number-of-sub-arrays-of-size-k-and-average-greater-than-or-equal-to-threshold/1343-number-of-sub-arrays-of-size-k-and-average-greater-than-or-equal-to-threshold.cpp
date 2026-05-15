class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int start = 0;
        int end = 0;
        double sum = 0;
        int avg_count = 0;

        while(end <= arr.size() - 1){
            while(end - start + 1 <= k){
                sum += arr[end++]; // expanding the right (end) pointer
            }
            double avg = sum / k;

            if(avg >= threshold){
                avg_count++; // condition satifies 
            }

            sum -= arr[end - k]; // shrink left(start)
            start++; // then increment the left
        }
        return avg_count;
    }
};

/*
Our first intuition was yo solve with Sliding Window .
Approach
Step 1 :- We initialize start and end with 0 . Calculate sum until the length of the subarray is less than equal to k .
Step 2 :- When this condition breaks , we calculate average . If average is greater equal to threshold , we count that subarray .
Step 3 :- We finally return the total count of subarrays .
Complexity
Time complexity:
O(N)
Space complexity:
O(1)
Code
*/
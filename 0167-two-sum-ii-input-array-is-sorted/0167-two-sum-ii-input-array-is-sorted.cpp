class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
       // Two pointers
    //    1. Array is sorted
    //    2. array,target
    //    3. no extra space
    //    4. pairs
        int n = numbers.size();
        int left = 0 , right = n-1; // coz if we put n which is the last nums of arr the right will be exceeded
        while(left < right){
            int sum = numbers[left]+numbers[right];
            if(sum == target)
                return {left+1,right+1};
            else if (sum > target) // if the target num exceeds u have to do the decrement of right
                right--;
            else       // if sum is less than target move the left..increment left
                left++;
        
            
        }
        return {-1,-1}; // no pairs didnt found jus return -1,-1 we need both indexes(in pairs so two -1)

    }
};
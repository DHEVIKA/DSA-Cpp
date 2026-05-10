class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n);
        int left =0 ;
        int right = n-1;
        int position = n-1;
        while(left<=right){
            int leftSquare = nums[left] * nums[left];
            int rightSquare = nums[right] * nums[right];
            if (leftSquare > rightSquare ){
                result[position]= leftSquare;
                left++;
            }
            else{
                result[position]= rightSquare;
                right--;
            }
            position --;
        }
        return result;
    }
};

/* 

 Time Complexity – O(n)
 Space Complexity – O(1)

Example: nums = [-4,-1,0,3,10] –
Step Left
Pointer(nums[left])
Right
Pointer(nums[right])
Left^2 Right^2 Larger
Sqaure
Chosen
Placed at
result[position]
Result

Array
Next
move
1. -4 10 16 100 100 result[4] = 100 [ _, -, _,
_, 100]
right-
-
2. -4 3 16 9 16 result[3] = 16 [_, _, _,
16, 100]
left++
3. -1 3 1 1 9 result[2] = 9 [_, _, 9,
16, 100]
right-
-
4. -1 0 1 0 1 result[1] = 1 [_, 1, 9,
16, 100]
left++
5. 0 0 0 0 0 result[0] = 0 [0, 1, 9,
16, 100]
left++

*/
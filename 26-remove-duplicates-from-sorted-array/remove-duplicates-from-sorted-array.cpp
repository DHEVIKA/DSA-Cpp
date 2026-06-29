class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
       int n = nums.size();
       int i= 0 ,  j =  1;
       while(j<n){
        if(nums[i] != nums[j]){
            i++;
            nums[i]=nums[j];
        }
        j++;
       }
       return i+1;
    }
};

/* to check teh duplicates the 1st avlue will be unique so starts with second value if both i and j are not equal u have move both the pointers if not equal move j alone i as static (condition j != i-1 )
 nums = [0,0,1,1,1,2,2,3,3,4]
             i j

nums[j] = 1
nums[i - 1] = 0 ( i before num)

Since `nums[j] != nums[i - 1]`, we set `nums[i] = nums[j]`.
Increment `i` to 2 and `j` to 3

nums = [0,0,1,1,1,2,2,3,3,4]
            i j 

nums[j] = 1
nums[i - 1] = 0 ( i before num)

Since `nums[j] != nums[i - 1]`, we set `nums[i] = nums[j]`.
Increment `i` to 3 and `j` to 4


nums = [0,0,1,1,1,2,2,3,3,4]
              i j 
nums[j] = 1
nums[i - 1] = 1 ( i before num)

move j to 5 ias static coz both i n j are equal so move only j 


nums = [0,0,1,1,1,2,2,3,3,4]
              i   j 

nums[j] = 2
nums[i - 1] = 1 ( i before num) 
move both the pointers in j are different 


nums = [0,0,1,1,1,2,2,3,3,4]
                i   j 
nums[j] = 2
nums[i - 1] = 1 ( i before num) differentmove both tilll j reaches the end the loop stops

*/
class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int n = nums.size();

        for(int i=1;i<n;i++){
            nums[i]=nums[i-1] +nums[i];
        }
        return nums;
    }
};

/* for prefix array u have to calculate the before num with present num no need recalculate from starting 
nums = [1,2,3,4]
nums[0] => is a array[0]
        => 1
// prefix sumcalculationprevious num + current num  nums[i]=nums[i-1] +nums[i]
nums[1]=> nums[0]+nums[1]
       => 1 + 2 = 3
nums[2]=> nums[1]+nums[2]
       => 3 + 3
       = 6
nums[3]=> nums[2]+nums[3]
       => 6 + 4
       = 10

o/p [1,3,6,10]

*/
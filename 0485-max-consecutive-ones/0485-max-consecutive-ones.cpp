class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {

        int count = 0, ans = 0;

        for(int num : nums){
            if(num == 1){  //if u found 1 increment the count 
                count++;
            } else {
                count = 0; //if u found 0 decrement the count 
            }
            ans = max(ans, count); // update the max one s count
        }

        return ans;
    }
};
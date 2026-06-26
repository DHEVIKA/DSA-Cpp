class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        
        int n = nums.size();
        int ans = 0;
        int cnt = 0;
        for(int i=0;i<n;i++){
            if(nums[i]==1){
                cnt ++; // if theres 1 continuously increment the cnt
            }
            else{
                cnt = 0; // if theres not 1 do reset as 0
                
            }
            ans = max(ans,cnt); // only maximize the highest continuous of 1s 

        }
        return ans ;

    }
};
class Solution {
public:
    int singleNumber(vector<int>& nums) { 
       int ans=0;
	   for(auto x:nums)
	   ans^=x;//xor--->2^2^1==0^1==1
	   return ans;
    }
};
class Solution {
    
public:
    vector<int> twoSum(vector<int>& nums, int target) {

    
        unordered_map<int,int>map;
        int n = nums.size();
        for(int i=0;i<n;i++){
            int rem = target-nums[i];
            if(map.find(rem)!=map.end()){
                return {map[rem],i};
            }
            map[nums[i]]=i;
        }
        return {-1,-1};


        
    }
};



/**

nums = [11,15,2,7], target = 9

u have to do ..
we r using ##hash map## for fast look up since they didnt tell its in inplace

11-9 = 2 its present in  map no then return it with num an that particular index
15-9 = 6 not 
2-9 = -7 not 
7-9 = -2 not 
if all the cases doent not satisfy return {-1,-1}
[
    11:0 
    15:1
    2:2


]
*/
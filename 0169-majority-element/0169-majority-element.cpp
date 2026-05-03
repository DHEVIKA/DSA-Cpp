class Solution {
public:
    int majorityElement(vector<int>& nums) {

    //   for fast look up u can use map 
    //     [3,2,3]
    //     [
    //         3: 1
    //         2: 1
    //         3: 1+1 ->already above totally 2 
    //     ]
    unordered_map <int,int>map;
    int n = nums.size() / 2;
    for(int num:nums){
        map[num]++;
    }
    for(int num:nums){
        if(map[num]>n)
            return num;
    }
    return -1;
    }
};
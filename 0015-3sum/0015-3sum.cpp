class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); i++) {
            if (i > 0 && nums[i] == nums[i-1]) {
                continue;
            }
            
            int j = i + 1;
            int k = nums.size() - 1;

            while (j < k) {
                int total = nums[i] + nums[j] + nums[k];

                if (total > 0) {
                    k--;
                } else if (total < 0) {
                    j++;
                } else {
                    res.push_back({nums[i], nums[j], nums[k]});
                    j++;

                    while (nums[j] == nums[j-1] && j < k) {
                        j++;
                    }
                }
            }
        }
        return res;        
    }
};

/*

 0   1  2  3  4  5
-1, -1, 0, 1, 2, 4

[-1, -1, 2]
[-1, 0, 1]

i = 0 fix
j = 3
k = 2

curSum = -1 -1 + 4 = 2 > 0 k--
       = -1 - 1 + 2 = 0 (Add to result) j++ k--


curSum = -1 + 0 + 1 = 0 (Add to result) j++ k--

-------

i = 1
if (nums[i] == nums[i - 1]) continue

j = 2
k = 5

-----
 0   1  2  3  4  5
-1, -1, 0, 1, 2, 4

i = 2
j = 3
k = 3

curSum = 0 + 1 + 4 = 5 > 0 k--
        = 0 + 1 + 2 = 3 > 0 k--


---------

i = 3
j = 4
k = 4

curSum = 1 + 2 + 4 = 7 > 0 k--


-------

i = 4
j = 5
k = 5


------
*/ 

/* The i should be as static and the j and k are moving indexes 

   if the total > 0 then we need to move k as back k--
   if the total < 0 then we need to  move  j as forward j++
   if the total == 0 the the we found triplet
   if the j and k reaches to the same then only u have to increment i if not then i will be as static
*/
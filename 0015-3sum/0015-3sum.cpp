class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& arr) {
        
        // Time : (NLogN + N^2) = N^2 | Space: O(N) sorting pace

        sort(arr.begin(), arr.end()); // NLogN Time, N Space
        vector<vector<int>> res; // outspace is not included in space complexity
        int n = arr.size();

        for (int i = 0; i < n; i++) {

            if (i > 0 && arr[i] == arr[i - 1]) continue;

            int j = i + 1, k = n - 1;

            while (j < k) {

                int cur = arr[i] + arr[j] + arr[k];

                if (cur < 0) {
                    j++;
                } else if (cur > 0) {
                    k--;
                } else {

                    res.push_back({arr[i], arr[j], arr[k]});

                    j++;
                    k--;

                    // skip duplicates for j
                    while (j < k && arr[j] == arr[j - 1]) j++;

                    // skip duplicates for k
                    while (j < k && arr[k] == arr[k + 1]) k--;
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
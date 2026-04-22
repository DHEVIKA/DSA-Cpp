class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int n = arr.size();
        
        int no_delete = arr[0];
        int one_delete = 0;
        int ans = arr[0];

        for(int i = 1; i < n; i++) {
            one_delete = max(one_delete + arr[i], no_delete);
            no_delete = max(arr[i], no_delete + arr[i]);
            
            ans = max(ans, max(no_delete, one_delete));
        }
        
        return ans;
    }
};


// this is by using kadanes Algo coz there is an array with the negative values , ita an subarray at max 
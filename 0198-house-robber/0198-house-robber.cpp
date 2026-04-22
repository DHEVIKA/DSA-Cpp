
class Solution {
public:
    unordered_map<int, int> mp;   

    int rob(vector<int>& nums) {
        return f(0, nums.size(), nums);
    }

    int f(int i, int n, vector<int>& nums) {

        if (i >= n) return 0;

        
        if (mp.find(i) != mp.end()) return mp[i];

        int rob = nums[i] + f(i + 2, n, nums);
        int noRob = f(i + 1, n, nums);

       
        return mp[i] = max(rob, noRob);
    }
};

/**
  0  1  2  3  4
[ 1, 2, 3, 4, 10]   
                f(index)

                    f(0)
                   /. \
                  /    \
                 /       \   
            14   /         \ 
           1 + f(2)         f(1) 14
            13  / \         
               /    \     2 + f(3) , f(2) 
             /       \ 10     10     14   
        3 + f(4)     f(3)
         10 / \      /  \
           /   \ 4 + f(5) f(4)
          /     \.     |   |
      10 + f(6)  f(5). 0   10
            |      |
            0      0

map: {

    f[4]: 10
    f[5] : 0
    f[3]: 10
    f[2] : 14


}


*/      
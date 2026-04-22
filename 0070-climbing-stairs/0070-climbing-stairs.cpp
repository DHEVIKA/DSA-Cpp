class Solution {
public:
    unordered_map<int, int> mp;

    int climbStairs(int n) {

     return f(0, n);
     
    }

    int f(int step, int n) {
        if (step == n) return 1; // reached top so return 1
        if (step > n) return 0; // invalid step, we have to reach till only n

        // Check if already computed
        if (mp.find(step) != mp.end()) {
            return mp[step];
        }

        // Store result in map
        mp[step] = f(step + 1, n) + f(step + 2, n);

        return mp[step];
    }
};

/***

    f(step, n)
                                    return 8
                                        f(0,5)
                                      /        \
                            8        /           \
                     climb(1)    f(0+1, 5)    +  f(0+2, 5) cimb(2)
                                |                  |
                          5      f(1, 5)            f(2, 5)     
                                /      \            |
                       3     f(2, 5) + f(3,5)       return 3
                            /   \       return 2
                           /     \
                   2   f(3, 5) + f(4,5)  
                        /  \       |
                       /    \      return 1
                      /      \  
               1    f(4,5) + f(5,5) 
                    /   \       |
                  /      \      return 1
             f(5, 5) + f(6, 5)
                |         |  
            return 1    return 0


   map: {

    step: value
    5 : 1
    6 : 0
    4 : 1
    3 : 2
    2 : 3
    1 : 8



   }         

**/             
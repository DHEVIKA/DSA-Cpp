class Solution {
public:
    int rotatedDigits(int n) {
        vector<int> dp(n + 1, 0);
        int count = 0;

        for (int i = 0; i <= n; i++) {
            if (i < 10) {
                if (i == 0 || i == 1 || i == 8) dp[i] = 1;  // for 0,1,8 considering value as 1
                else if (i == 2 || i == 5 || i == 6 || i == 9) { //for 2,5,6,9 considering value as 2
                    dp[i] = 2;
                }
                else dp[i] = 0; 
            } else {
                int last = i % 10; // last digit
                int rem = i / 10; // remaining

                if (dp[rem] == 0) {
                    dp[i] = 0;
                } 
                else if (last == 0 || last == 1 || last == 8) { // these 0,1,8 wont change while rotating
                    dp[i] = dp[rem];
                } 
                else if (last == 2 || last == 5 || last == 6 || last == 9) { // 2 as 5 | 5 as 2 | 6 as 9 | 9 as 6
                    if (dp[rem] == 1) dp[i] = 2;   // becomes good
                    else if (dp[rem] == 2) dp[i] = 2; // already good
                } 
                else {
                    dp[i] = 0;
                }
            }

            if (dp[i] == 2) count++;  
        }

        return count;
    }
};
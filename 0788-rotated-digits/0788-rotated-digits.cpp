class Solution {
public:
    int rotatedDigits(int n) {
        vector<int> dp(n + 1, 0);
        int count = 0;

        for (int i = 0; i <= n; i++) {
            if (i < 10) {
                if (i == 0 || i == 1 || i == 8) dp[i] = 1;
                else if (i == 2 || i == 5 || i == 6 || i == 9) {
                    dp[i] = 2;
                }
                else dp[i] = 0;
            } else {
                int last = i % 10;
                int rem = i / 10;

                if (dp[rem] == 0) {
                    dp[i] = 0;
                } 
                else if (last == 0 || last == 1 || last == 8) {
                    dp[i] = dp[rem];
                } 
                else if (last == 2 || last == 5 || last == 6 || last == 9) {
                    dp[i] = 2;
                } 
                else {
                    dp[i] = 0;
                }
            }

            if (dp[i] == 2) count++;   // ✅ count here ONLY
        }

        return count;
    }
};
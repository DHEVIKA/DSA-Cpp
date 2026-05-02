class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if(n == 0) return ""; // if the string is empty no palindrome return empty string(Edge case)

        int start = 0, maxLen = 1;  // maxlen = 1 means even a single character is a palindrome

        for(int i = 0; i < n; i++) {

            // Odd length palindrome both left & right will be at same index
            int left = i, right = i;
            while(left >= 0 && right < n && s[left] == s[right]) {
                if(right - left + 1 > maxLen) {
                    start = left;
                    maxLen = right - left + 1;
                }
                left--;
                right++;
            }

            //  Even length palindrome left at 1st index right will be at i+1 (next ) index
            
            left = i;
            right = i + 1;
            while(left >= 0 && right < n && s[left] == s[right]) {
                if(right - left + 1 > maxLen) {
                    start = left;
                    maxLen = right - left + 1;
                }
                left--;
                right++;
            }
        }

        return s.substr(start, maxLen);
    }
};

/*
when to use this template 
1.“palindromic substring”
2.“longest palindrome”
3.“count palindromic substrings”
4.“substring” (not subsequence ⚠️)
constraints like n ≤ 1000

👉 Immediately think: Expand Around Center
for(int i = 0; i < n; i++) {

    // odd
    expand(i, i);

    // even
    expand(i, i+1);
}
 */
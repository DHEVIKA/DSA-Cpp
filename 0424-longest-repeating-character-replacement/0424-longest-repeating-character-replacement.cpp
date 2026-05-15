class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int l = 0, r = 0, maxlen = 0;
        int maxf = 0;
        vector<int> count(26, 0);

        while (r < n) {
            count[s[r] - 'A']++;
            maxf = max(maxf, count[s[r] - 'A']);

            // If more than k chars need replacement, shrink window
            if ((r - l + 1) - maxf > k) {
                count[s[l] - 'A']--;
                l++;
            }

            maxlen = max(maxlen, r - l + 1);
            r++;
        }
        return maxlen;
    }
};

/* 

We need the longest substring where we can replace at most k characters so that all characters in it are the same.

The key idea is to use a sliding window and keep track of:

The frequency of each character in the window.
The count of the most frequent character in the current window.
If the number of characters to change (window size - max frequency) is more than k, we shrink the window from the left.

Approach 🔍
Use two pointers l and r for the sliding window.
Maintain a frequency array count[26] for characters.
Track the maximum frequency maxf of any character in the current window.
If (window size - maxf) > k, shrink the window from the left.
Update the maximum length of a valid window.
Complexity 📊
Time complexity: (O(n)) — Each character is processed at most twice (expand and shrink).
Space complexity: (O(1)) — Fixed size frequency array of 26 letters.

*/
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> map;
        int l = 0, r = 0, maxLen = 0;
        int n = s.length();

        while (r < n) {
            if (map.find(s[r]) != map.end()) {
                l = max(l, map[s[r]] + 1);
            }
            int len = r - l + 1;
            maxLen = max(maxLen, len);
            map[s[r]] = r;
            r++;
        }
        return maxLen;
    }
};


/*
Hint 1 - What is this question asking?
You're asked to find the length of the longest substring in a given string that contains no repeated characters. A substring is a continuous part of the string.
Hint 2 - What kind of approach can help?
You can use the sliding window technique — it's perfect for problems involving substrings and checking conditions as you move through the string.
Hint 3 - What is a sliding window?
Think of it like a moving window over the string. You expand it to include more characters and shrink it when you find a problem (like a duplicate character).
Hint 4 - How do you track characters?
Use a map to remember the last index where each character appeared. If a character repeats, move the start of the window just past its last seen position.
Hint 5 - When do you update the answer?
After adjusting the window to ensure all characters inside are unique, update the maximum length if the current window is longer than the previous best.
*/
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxLength = 0;
        int left = 0;
        unordered_map<char, int> map ;
// its a dymanic sliding window without size k
        for (int right = 0; right < s.length(); right++) {
            char c = s[right]; //expand the right window
            map[c] = map[c] + 1;
            
            while (map[c] > 1) { // check condition
                char leftChar = s[left];
                map[leftChar] = map[leftChar] - 1; // shirnk the left window
                left++;
            }
            
            maxLength = max(maxLength, right - left + 1); // update the len
        }
        
        return maxLength;        
    }
};
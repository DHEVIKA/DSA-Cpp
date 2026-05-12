class Solution {
public:
    bool isPalindrome( string s , int left,int right) {
        
        while (left < right) {
            if (s[left++] != s[right--]) return false;
        }
        return true;
    }
    
    bool validPalindrome(string s) {
        int left = 0, right = s.size() - 1;
        while (left < right) {
            if (s[left] != s[right]) {
                return isPalindrome(s, left + 1, right) || isPalindrome(s, left, right - 1);
            }
            left++;
            right--;
        }
        return true;
    }
};

/* Initialize two pointers: left = 0 and right = s.length() - 1.
While left < right:
If s[left] == s[right], move left++ and right--.
If s[left] != s[right], check if skipping left (s[left+1..right]) or right (s[left..right-1]) results in a palindrome using a helper function.
If either skip works or no mismatches occur, return true; otherwise, return false.
Helper function isPalindrome(s, left, right):

Checks if substring s[left..right] is a palindrome by moving two pointers inward.
⏱️ Complexity
Time complexity: O(n)
— each character is visited at most twice (once in main loop, once in helper)

Space complexity: O(1)
— only pointers and loop variables are used

*/
/* Intuition
A palindrome reads the same forward and backward. If we are allowed to delete at most one character, we can use two pointers from the start and end of the string. Whenever characters match, we move inward. At the first mismatch, we have the option to skip either the left or the right character to try forming a palindrome.
🚀 Approach
Initialize two pointers: left = 0 and right = s.length() - 1.
While left < right:
If s[left] == s[right], move left++ and right--.
If s[left] != s[right], check if skipping left (s[left+1..right]) or right (s[left..right-1]) results in a palindrome using a helper function.
If either skip works or no mismatches occur, return true; otherwise, return false.
Helper function isPalindrome(s, left, right):

Checks if substring s[left..right] is a palindrome by moving two pointers inward. */

class Solution {
public:
    bool PalindromeHelper(int i, int j, string &s) {
        while(i < j) {
            if(s[i] != s[j]) {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }

    bool validPalindrome(string s) {
        int i = 0;
        int j = s.length() - 1;

        while(i < j) {
            if(s[i] != s[j]) {
                return PalindromeHelper(i + 1, j, s) || 
                       PalindromeHelper(i, j - 1, s);
            }
            i++;
            j--;
        }
        return true;
    }
};
class Solution {
public:
    int countSubstrings(string s) {
        int res = 0;

        for (int i = 0; i < s.length(); i++) {
            res += count_palindrome(s, i, i); // Odd-length palindromes (like "aba")
            res += count_palindrome(s, i, i + 1); //  Even-length palindromes (like "aa")
        }

        return res;        
    }

private:
    int count_palindrome(string s, int left, int right) {
        int count = 0;
        while (left >= 0 && right < s.length() && s[left] == s[right]) {
            count++;
            left--;
            right++;
        }
        return count;
    }

};  


// same as the problem longest palindrome substring 

/*  Intuition
The problem asks for the total number of palindromic substrings within a given string. A naive approach would be to check every possible substring, which takes time.

The Expand Around Center technique is much more efficient. The core idea is that every palindrome has a center. By picking every possible center in the string and expanding outwards as long as the characters match, we can find all palindromes.

Odd-length palindromes have a single character as the center (e.g., "aba", center is 'b').
Even-length palindromes have the gap between two characters as the center (e.g., "abba", center is between 'b' and 'b').

 Approach

Iterate through Centers: Loop through each index i from 0 to n-1.
Odd Length Expansion: Call the expand helper with left = i and right = i. This checks for palindromes like "a", "aba", "abcba".
Even Length Expansion: Call the expand helper with left = i and right = i + 1. This checks for palindromes like "aa", "abba", "abccba".
Helper Function (count_palindrome):
While the left and right pointers are within bounds and the characters at these pointers match:
Increment the count (we found a valid palindrome).
Move left one step left and right one step right to check the next outer layer.
Accumulate: Sum all counts returned from the expansion calls.

 Dry Run Illustration
Input: s = "aaa"

i=0: * count_palindrome(0,0): "a" (match), Count=1.

count_palindrome(0,1): "aa" (match), Count=2.

i=1:

count_palindrome(1,1): "a" (match), "aaa" (match), Count=4.

count_palindrome(1,2): "aa" (match), Count=5.

i=2:

count_palindrome(2,2): "a" (match), Count=6.

count_palindrome(2,3): No match.
Result: 6

*/
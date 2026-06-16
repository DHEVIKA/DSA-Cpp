#include <iostream>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false; // Negative numbers can't be palindrome

        int original = x;
        long reversed = 0;

        while (x != 0) {
            reversed = reversed * 10 + x % 10;
            x /= 10;
        }

        return reversed == original;
    }
};
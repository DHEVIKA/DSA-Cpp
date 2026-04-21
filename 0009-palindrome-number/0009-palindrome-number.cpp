class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) { // to avoid negative number
            return false;
        }

        long reverse = 0;
        int num = x;

        while (num !=0) {
            reverse = (reverse * 10) + (num % 10);
            num /= 10;
        }

        return reverse == x;        
    }
};


// to extract the last digit  reverse *10 + num%10 to remove the last digit  num /10
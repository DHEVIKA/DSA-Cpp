class Solution {
public:
    int countDigits(int num) {
        // Convert the integer to a string
    string str = to_string(num);

    // Initialize a count to keep track of the number of digits that divide num
    int count = 0;

    // Iterate through the digits in the string
    for (char c : str) {
      // Convert the current character to an integer
      int digit = c - '0';

      // Check if the digit divides num
      if (num % digit == 0) {
        // If it does, increment the count
        count++;
      }
    }

    // Return the count
    return count;
    }
};


/* For example, if the input integer is 121, the digits are 1 and 2. The digit 1 divides 121, so the count is incremented to 1. The digit 2 does not divide 121, so the count is not incremented. The final count is 1, which is the number of digits in 121 that divide 121.

# Approach
Initialize a count to 0 to keep track of the number of digits that divide the integer.

Iterate through the digits in the integer. For each digit:

Check if the digit divides the integer.
If it does, increment the count.
Return the count. */
class Solution {
public:

    bool isHappy(int n) {
// afst & slow pointer technique
        int slow = n, fast = n;

        while (fast != 1) {

            slow = happyNum(slow); // slow moves 1 step ahead

            fast = happyNum(happyNum(fast)); // fast =moves 2 step ahead

            if (fast == 1) { // its a happy number
                return true;
            }

            if (slow == fast) { // low == fast → cycle detected → Not Happy Number
                return false;
            }
        }

        return true;
    }

    int happyNum(int n) { // happy number calculation

        int sum = 0;

        while (n > 0) {

            int digit = n % 10; //remainder %

            sum += digit * digit;

            n = n / 10; // quotient /
        }

        return sum;
    }
};

/* Example

For n = 19

Sequence:

19
1² + 9² = 82
8² + 2² = 68
6² + 8² = 100
1² + 0² + 0² = 1

So return true.

Time Complexity

Each transformation processes digits:

O(log n)

Cycle detection is small/constant iterations overall.

Overall:
Time: O(log n)
Space: O(1)

*/

class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> res;

        for (int num : nums) {
            vector<int> digits = getDigits(num);
            res.insert(res.end(), digits.begin(), digits.end());
        }

        return res;
    }

private:
    vector<int> getDigits(int num) {
        vector<int> digits;

        while (num > 0) {  // num = 13
            digits.push_back(num % 10); // to extract the last digit 13%10 -> 3
            num /= 10; //  to extract the 1st digit 13/10 -> 1
        }

        reverse(digits.begin(), digits.end()); //3 1 came need to change as 13 so do reverse

        return digits;
    }
};

class Solution {
public:
    void reverseString(vector<char>& s) {
        int n = s.size();
        int start = 0;
        int end = n - 1;

        while(start <= end){

            swap(s[start], s[end]);//Using two pointers from both ends, we swap characters until the pointers meet.This allows us to reverse the array in-place without extra memory, making it both efficient and optimal.

            start++;
            end--;
        }
    }
};
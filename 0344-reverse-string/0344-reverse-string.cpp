class Solution {
public:
    void reverseString(vector<char>& s) {
        int n = s.size();
        int left = 0;
        int right = n-1;
        while(left <= right){
            char temp = s[left];
            s[left] =s[right];
            s[right] = temp;
// or swap(s[left],s[right]);
            left++;
            right--;
        }        
    }
};

/*

 Time Complexity – O(n)
 Space Complexity – O(1)

Example: s = ["h","e","l","l","o"] –

Step Left Pointer(left) Right Pointer(right) Characters
Swapped
Array After Swap
1. 0 4 h ↔ o ['o', 'e', 'l', 'l', 'h']
2. 1 3 e ↔ l ['o', 'l', 'l', 'e', 'h']
3. 2 2 (middle element,
stop)
['o', 'l', 'l', 'e', 'h']

*/
class Solution {
public:
    bool isPalindrome(string s) {
        /* Intuition
By reading the question you may think that first we need to convert the string to desired form and then check if its a valid palindrome or not.

But all of that is just distraction you can check valid palindrome by simply using two pointers no need to convert.

Approach:

If a character is not alphanumeric we can simply ignore it and update our pointer to next character (for both pointers)
and then we check by converting the alphanumeric character to lowercase (tolower() function on numbers has no change)
if those two are not equal then return false(not palindrome)
else update both pointers and continue.

Finally after all checking if reach at last then string must be a valid palindrome so return true.

Complexity
Time complexity:O(n)
Space complexity:O(1) since only use two pointers */
       int n = s.size();
       int left = 0;
       int right = n-1;
       while(left <= right){
           if(!isalnum(s[left]))
           {
            left++; 
            continue;  ///skip it If a character is not alphanumeric
            }
           if(!isalnum(s[right]))
           {
            right--;
            continue; ///skip it If a character is not alphanumeric
            }
           if(tolower(s[left])!=tolower(s[right])) // then we check by converting the alphanumeric character to lowercase (tolower() function on numbers has no change)
            return false;
           else{
               left++;
               right--;
           }
       }
       return true;
}
};
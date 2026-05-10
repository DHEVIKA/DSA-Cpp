class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.size();
        int left = 0;
        int right = n-1;
        while(left<=right){
            if(!isalnum(s[left])){
                left++;
                continue;
            }
            if(!isalnum(s[right])){
                right--;
                continue;
            }
            if(tolower(s[left]) != tolower(s[right])){
                return false;
            }
            else{
                left++;
                right--;
            }
        }
        return true;
    }
};

/*  “A man, a plan, a canal: Panama” -
Step Operation Result/ Explanation
1. Remove non-alphanumeric (isalnum)
characters
"AmanaplanacanalPanama"
2. Convert all to lowercase "amanaplanacanalpanama" (tolower)
3. Compare characters Compare from both ends → all
characters match
4. Final Check Reads same forward & backward
 Output:
true
*/
class Solution {
public:
    string reverseWords(string s) {
        //two pointers
        int n = s.length();
        int left =0 , right =0; 
        while(right<=n){
            if(right==n || s[right]==' '){ //when u see the right reaches to end of string or it has spaces thats the boundary space u have to reverse the word in-place.
                reverse(s.begin() + left ,s.begin() + right);
                left = right+1;
            }
            right ++;
        }    
        return s;   
    }
};

/* Approach
Convert the input string into a char array for direct access.
Iterate through the array using two indices:
left: tracks the start of the current word.
right: moves through the string until it hits a space ' ' or the end.
Once a word boundary is detected, reverse the characters from index i to j - 1.
Continue the process by updating i = j + 1 to begin the next word.
After all words are reversed in-place, convert the char array back into a string and return the result. */
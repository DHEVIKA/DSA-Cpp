class Solution {
public:
    string reverseWords(string s) {
        int n = s.length();
        string  ans = "";
// string reversing  entire string 
        reverse(s.begin(),s.end());

        for(int i=0;i<n;i++){
            string word = ""; // to track each words
            while( i<n && s[i]!=' '){ // if theres no space do increment
                word +=s[i]; // valid char
                i++;
            }
//word reversing 
            reverse(word.begin(),word.end());
            if(word.length()>0){
                ans += " " + word;

            }
        }
        return ans.substr (1);
    }
};
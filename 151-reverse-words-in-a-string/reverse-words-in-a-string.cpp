class Solution {
public:
    string reverseWords(string s) {
        // story
        // 1. reverse the whole string 
        reverse(s.begin(),s.end());
        int i =0;// to reverse whoe string
        int l = 0;
        int r = 0;
        int n = s.length();
        while(i<n){
            while(i<n && s[i]!=' '){ //i has a character and r together i++ r++
                s[r] = s[i];
                i++;
                r++;

            }
            if(l < r){ // word reverse
                reverse(s.begin()+l,s.begin()+r);
                s[r]=' ';
                r++;
                l=r;
            }
            i++;

        }
        s =s.substr(0,r-1);
        return s;
    }
};
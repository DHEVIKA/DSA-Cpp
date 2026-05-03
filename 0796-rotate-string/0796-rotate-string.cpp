class Solution {
public:
    bool rotateString(string s, string goal) {
        if (s.length() != goal.length()) return false;

        int n = s.length();

        for (int i = 0; i < n; i++) {

            // store first character
            char first = s[0];

            
            for (int j = 0; j < n - 1; j++) { // shift it to left
                s[j] = s[j + 1];
            }

            
            s[n - 1] = first; //1st char at end

           
            if (s == goal) return true;
        }

        return false;
    }
};
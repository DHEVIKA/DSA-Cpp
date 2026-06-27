class Solution {
public:
    bool isSubsequence(string s, string t) {
        int m = s.size();
        int n = t.size();
        int i = 0, j=0;
        while(i<m && j<n){
            if(s[i]==t[j]){
                i++;
            }
            j++;
        }
        return i == m;
        
    }
};
// two pointer
/* s = "abc"
t = "ahbgdc"

i=0 ('a'), j=0 ('a') -> match -> i=1
j=1 ('h') -> no match j++
j=2 ('b') -> match -> i=2 
j=3 ('g') -> no match
j=4 ('d') -> no match
j=5 ('c') -> match -> i=3

i == s.size() => true

s = a b c
    ^
    i

t = a h b g d c
    ^
    j

if both s and t matches mob=ve the both i++ j++ if j doesnt match keep i as static move j++

*/
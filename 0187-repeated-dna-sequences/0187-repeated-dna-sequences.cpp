class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {

        // if length < 10 impossible to form sequence //edge case
        if(s.size() < 10) return {};

        // stores hashes already seen
        unordered_set<int> seen;

        // stores repeated hashes
        unordered_set<int> repeated;

        // final answer
        vector<string> ans;

        // mapping DNA chars to base-4 digits
        unordered_map<char,int> mp = {
            {'A',0},
            {'C',1},
            {'G',2},
            {'T',3}
        };

        // rolling hash
        int hash = 0;

        // build first 9 characters hash
        for(int i=0; i<9; i++) {

            // shift left in base 4 and add digit
            hash = hash * 4 + mp[s[i]];
        }

        // power = 4^9
        int power = 1;

        for(int i=0; i<9; i++) {
            power *= 4;
        }

        // sliding window starts
        for(int i=9; i<s.size(); i++) {

            // add new character to hash
            hash = hash * 4 + mp[s[i]];

            // remove leftmost character contribution
            if(i >= 10) {

                hash -= mp[s[i-10]] * power * 4;
            }

            // if already seen => repeated
            if(seen.count(hash)) {

                // avoid duplicate insertion
                if(!repeated.count(hash)) {

                    // extract substring of length 10
                    ans.push_back(s.substr(i-9,10));

                    // mark as repeated
                    repeated.insert(hash);
                }
            }

            // store current hash
            seen.insert(hash);
        }

        return ans;
    }
};

/* 
1. Since DNA has only 4 letters (`A,C,G,T`), we convert them into numbers (`0,1,2,3`) and treat every 10-letter sequence like a base-4 number.

2. We use a sliding window of size 10 to move through the string.

3. Rolling hash helps update the next sequence hash quickly by removing the left character and adding the new right character.

4. If the same hash appears again, that DNA sequence is repeated, so we add it to the answer.


calculation

Sequence:

ACGT

becomes:

0 1 2 3

Mathematically:

0⋅4^3 + 1⋅4^2 + 2⋅4^1 + 3⋅4^0

This creates a unique integer hash.

So instead of storing strings 
*/
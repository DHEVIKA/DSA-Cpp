class Solution {
public:
    bool isValid(string s) {
        unordered_map<char, char> map = {
            {')', '('},
            {'}', '{'},
            {']', '['}
        };

        stack<char> st;

        for (char ch : s) {
            if (map.find(ch) == map.end()) {
                st.push(ch);
            } else {
                if (st.empty() || map[ch] != st.top()) {
                    return false;
                }
                st.pop();
            }
        }

        return st.empty();
    }
};

/**




map: 
) : (
] : [
} : {
---

( [ ) ]

stack: 
[
    
]

    for (char ch in s) 
        if (map[ch]) {
            push_to_stack(ch)
        } else {
            if (stack_not_empty) {
                if (map[ch] == top_of_stack) {
                    pop();
                } else {
                    return false // inbalance
                }
            } 
        }

    return st_is_empty()



**/
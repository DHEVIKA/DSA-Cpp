class Solution {
public:
    string clearDigits(string s) {
        string res = ""; // Acts like a stack
        for (char c : s) {
            if (isdigit(c)) {
                if (!res.empty()) {
                    res.pop_back(); // Remove the last character
                }
            } else {
                res.push_back(c); // Add character to stack
            }
        }
        return res;
    }
};

/* Intuition
Think of a stack like a pile of plates: Last In, First Out (LIFO) 🍽️.
We process characters in a string like a clean-up operation 🧹, removing digits based on their position.

Stack helps when order matters, and we might need to undo things ⏪.
If a digit follows a letter, we remove both!
*/
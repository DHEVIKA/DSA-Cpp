class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.size() != goal.size())
            return 0;
        string cat = goal + goal;
        return cat.find(s) != -1;
    }
};

// First check if size of s is equal to goal, if no then return false. Concatenate goal twice and check if s is a part of goal and return it.
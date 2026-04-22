class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        
        for(auto x: strs){
            string word = x;
            sort(word.begin(), word.end());
            mp[word].push_back(x);
        }
        
        vector<vector<string>> ans;
        for(auto x: mp){
            ans.push_back(x.second);
        }
        return ans;
    }
};



/* The intuition is to group words that are anagrams of each other together. Anagrams are words that have the same characters but in a different order.*/

/* input: ["eat","tea","tan","ate","nat","bat"]

1. key = sort(str[i])
2. map[key].push(str[i])

---
k = abt

map: {
    aet: [eat, tea, ate]
    ant: [tan, nat]
    abt: [bat]
}

return map.values()



*/
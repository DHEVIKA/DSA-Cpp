class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int left = 0;
        int maxLen = 0;
        int n = fruits.size();
        unordered_map<int,int>basket;

        for(int right=0;right<n;right++){
            basket[fruits[right]]++;
            
            while(basket.size()>2){ // This is a classic sliding window problem, where we expand the window to include more fruits and shrink it when the number of distinct fruits exceeds 2.
                basket[fruits[left]]--;
                if(basket[fruits[left]]==0){
                    basket.erase(fruits[left]);
                }
                left++;

            }
            maxLen = max(maxLen,right-left+1);

        }
        return maxLen;
    }
};

// u have to take 2 different fruits in 2 differnt basket which shoyld be continuous so that u can achieve max of 2 diiferent fruits...it should exceed 2 if exceeds u have to minimize the left if u founf 0 erase it

// Use two pointers: left and right to represent a sliding window.

// Expand right and add fruits into a frequency map.

// If number of distinct fruits > 2:

// shrink window from left

// decrease frequency

// remove fruit from map if frequency becomes 0

/* 🍇 Problem Description
You're walking along a row of fruit trees 🍎🍌🍐... and can pick fruits with only two baskets 🧺🧺.

Each basket can only carry one type of fruit, but unlimited quantity of that type.

Starting from any tree, you must pick exactly one fruit per tree, moving only to the right 👉.

You stop picking when a tree has a fruit type that doesn't fit in your two baskets.

Your task?
Return the maximum number of fruits you can collect under these rules.

💡Intuition
This problem is a variation of the Longest Subarray with at most Two Distinct Elements problem.
We can use the sliding window technique to keep track of the current window of fruit types we can collect, and update the answer accordingly.

Approach
We initialize two pointers: start and end to define our sliding window.

A HashMap stores the count of each fruit type in the current window.

Expand the window by moving end ➡️ and adding fruits to the map.

If the map has more than 2 fruit types, shrink the window from start until we're back to only two types 🍎🍌.

Keep updating the maximum length (maxLen) at each valid window.

🧮 Complexity
Time complexity: O(n)
👉 Each fruit is added and removed from the map at most once.

Space complexity: O(1)
👉 The map stores at most 3 keys at any point (though 2 is the limit, temporarily it might hold 3 during adjustment).

🎉 Example
👉 Input:

fruits = [🍎, 🍌, 🍌, 🍇, 🍇, 🍇, 🍌, 🍌, 🍎, 🍎, 🍎, 🍇]
             0   1   2   3   4   5   6   7   8   9  10  11
✅ Pick : Picked window: [🍌, 🍌, 🍇, 🍇, 🍇, 🍌, 🍌]
Index range :                1   2   3   4   5   6   7

*/
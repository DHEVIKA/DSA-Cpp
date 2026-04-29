class Solution {
public:
    void reverseString(vector<char>& s) {
        int n = s.size();
        int left = 0;
        int right = n-1;
        while(left<right){
            swap(s[left],s[right]);
            left++;
            right--;
        }
        
    }
};

/*
We use two pointers:

start → beginning of the array
end   → end of the array
Steps:

1️⃣ Swap characters at start and end.

2️⃣ Move pointers inward:

start++
end--
3️⃣ Continue until the pointers meet.

This gradually reverses the array.

Step-by-Step Example
s = ['h','e','l','l','o']
Start:

left = 0
right  = 4
Swap:

h ↔ o
Array becomes:

[o,e,l,l,h]
Move pointers:

left = 1
right  = 3
Swap:

e ↔ l
Array becomes:

[o,l,l,e,h]
Move pointers again:

left = 2
right  = 2
Now pointers meet → stop.

Final result:

['o','l','l','e','h']
⏱️ Complexity Analysis
Time Complexity
O(n)
We traverse half of the array once.

Space Complexity
O(1)
No extra memory is used because we reverse the array in-place. */
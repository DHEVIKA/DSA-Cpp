class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int n = people.size();
        // 1. sort
        sort(people.begin(),people.end());
        //2. l = 0;r=n-1
        int l=0 , r = n-1;
        int count = 0;
        //3. condition
        while(l <= r){
            int sum = people[l]+people[r];
            if(sum <= limit){
                count++;
                l++;
                r--;
            }
            else{
                count++;
                r--;
            }
        }
        return count;
    }
};

/*To minimize the number of boats, we should always try to place the heaviest person with the lightest person who can still fit within the weight limit.

After sorting the array:

The heaviest person is at the end.
The lightest person is at the beginning.
If they can share a boat, we send them together. Otherwise, the heaviest person must go alone because they cannot be paired with anyone else.

This greedy strategy ensures every boat is used as efficiently as possible.

Approach
Sort the people array in ascending order.
Use two pointers:
left points to the lightest person.
right points to the heaviest person.
While left <= right:
If people[left] + people[right] <= limit, both can share one boat.
Increment left.
Decrement right.
Otherwise, the heaviest person goes alone.
Decrement right.
In both cases, increment the boat count.
Return the total number of boats used.
Complexity
Time complexity:

O(n log n) due to sorting the array.
The two-pointer traversal takes O(n).
Overall: O(n log n).
Space complexity:

O(1) (excluding the space used by the sorting algorithm).*/
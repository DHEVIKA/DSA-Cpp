class Solution {
public:
    int majorityElement(vector<int>& nums) {

        int count = 0;
        int candidate = 0;
        for(auto num : nums){
            if(count == 0){
                candidate = num;

            }
            if(num == candidate){
                count++;
            }
            else{
                count--;
            }
        }
    
    return candidate;

   
    }
};

/* Think of this array as a collection of votes from the voters for different political parties.
Now as we know the party which has >50% votes can form the government.

So , our above question is analogous to this situation.
Now , if we are certain that one party has > 50% votes . Then , if :

We increment a count variable every time we see the vote from the majority party and decrement it whenever a vote from some other party is occured , we can guarantee that ,
count>0.

Approach 

Initialize candidate and count.

Traverse array:

If count == 0, set candidate = num.
If num == candidate, increment count, else decrement count.
Return candidate as majority element.

Complexity
Time Complexity: O(n) (single pass)
Space Complexity: O(1) (no extra space used)  */
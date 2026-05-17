class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList,
                                             vector<vector<int>>& secondList) {

        vector<vector<int>> ans;

        int i = 0, j = 0;

        while(i < firstList.size() && j < secondList.size()) {

            int start1 = firstList[i][0];
            int end1 = firstList[i][1];

            int start2 = secondList[j][0];
            int end2 = secondList[j][1];

            // intersection start
            int start = max(start1, start2);

            // intersection end
            int end = min(end1, end2);

            // valid intersection (overlapping case)
            if(start <= end) {
                ans.push_back({start, end});
            }

            // move the interval which ends first
            if(end1 < end2) {
                i++;
            }
            else {
                j++;
            }
        }

        return ans;
    }
};

// refer this only(merge intervals) https://leetcode.com/problems/merge-intervals/submissions/2005369964

/* Main Idea

We compare one interval from both lists.

Example:

[0,2] and [1,5]

Common overlapping part:

[1,2]

Store it in answer.

Then move the interval that finishes first.

Important Formula
Intersection Start

Take bigger starting point:

start=max(start1,start2)

Example:

[0,2] and [1,5]
start = max(0,1) = 1
Intersection End

Take smaller ending point:

end=min(end1,end2)

Example:

end = min(2,5) = 2

Intersection:

[1,2]
Overlap Condition

start≤end

If true → overlap exists.

Dry Run

Input:

firstList  = [[0,2],[5,10],[13,23],[24,25]]

secondList = [[1,5],[8,12],[15,24],[25,26]]
Step 1

Compare:

[0,2] and [1,5]
start = max(0,1) = 1
end = min(2,5) = 2

Valid:

1 <= 2

Add:

[1,2]

Since:

2 < 5

Move i++

Step 2

Compare:

[5,10] and [1,5]
start = 5
end = 5

Add:

[5,5]

Since:

10 > 5

Move j++

Step 3

Compare:

[5,10] and [8,12]
start = 8
end = 10

Add:

[8,10]

Move i++

Step 4

Compare:

[13,23] and [15,24]

Intersection:

[15,23]

Move i++

Step 5

Compare:

[24,25] and [15,24]

Intersection:

[24,24]

Move j++

Step 6

Compare:

[24,25] and [25,26]

Intersection:

[25,25]
Final Answer
[[1,2],[5,5],[8,10],[15,23],[24,24],[25,25]]
Why Move Smaller End?

If one interval ends first,
it can never overlap again later.

Example:

[0,2] and [1,5]

2 ends first,
so move first interval.

Time Complexity
O(n + m)

Because both pointers move only once.

Space Complexity
O(1)

Ignoring answer array.*/
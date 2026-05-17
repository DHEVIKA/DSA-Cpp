class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {

        // sort based on starting day
        sort(meetings.begin(), meetings.end());

        int maxEnd = meetings[0][1];

        int gap = 0;

        for(int i = 1; i < meetings.size(); i++) {

            int start = meetings[i][0];
            int end = meetings[i][1];

            // no overlap
            if(start > maxEnd) {

                // count free days between intervals
                gap = gap + (start - maxEnd - 1);
            }

            // update farthest ending day
            maxEnd = max(maxEnd, end);
        }

        // free days before first meeting
        gap = gap + (meetings[0][0] - 1);

        // free days after last meeting
        gap = gap + (days - maxEnd);

        return gap;
    }
};

/* 
Main Idea

Instead of counting meeting days,
this code directly counts free days (gaps).

Gap Formula

Between two meetings:  gap condition means non overlapping if (start > end)

gap=start−maxEnd−1

Example:

[1,3] and [5,7]

Free day:

4

Calculation:

5 - 3 - 1 = 1

One free day.

Line by Line
Sorting
sort(meetings.begin(), meetings.end());

Sort meetings by start time.

Store current maximum ending
int maxEnd = meetings[0][1];

Tracks farthest ending day covered till now.

Example:

[1,3]

Then:

maxEnd = 3
Free days counter
int gap = 0;

Stores answer.

Loop through meetings
for(int i = 1; i < meetings.size(); i++)

Start from second meeting.

Current interval
int start = meetings[i][0];
int end = meetings[i][1];
No Overlap Condition

start>maxEnd

Means there is a free gap.

Example:

[1,3] and [5,7]

Since:

5 > 3

Gap exists.

Count gap days
gap += (start - maxEnd - 1);

Example:

5 - 3 - 1 = 1

Free day:

4
Update maximum ending
maxEnd = max(maxEnd, end);

Keeps farthest covered day.

Example:

max(7,10) = 10
Free days before first meeting
gap += (meetings[0][0] - 1);

Example:

first meeting = [3,5]

Free days:

1 2

Calculation:

3 - 1 = 2
Free days after last meeting
gap += (days - maxEnd);

Example:

days = 10
maxEnd = 7

Free days:

8 9 10

Calculation:

10 - 7 = 3
Dry Run

Input:

days = 10

meetings = [[5,7],[1,3],[9,10]]
After Sorting
[[1,3],[5,7],[9,10]]
Initial
maxEnd = 3
gap = 0
Compare [5,7]
5 > 3

Gap:

5 - 3 - 1 = 1
gap = 1

Update:

maxEnd = 7
Compare [9,10]
9 > 7

Gap:

9 - 7 - 1 = 1
gap = 2

Update:

maxEnd = 10
Before first meeting
1 - 1 = 0
After last meeting
10 - 10 = 0
Final Answer
2

*/

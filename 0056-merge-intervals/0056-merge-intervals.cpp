class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {

        // sort based on starting value
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> ans;

        // add first interval
        ans.push_back(intervals[0]);

        for(int i = 1; i < intervals.size(); i++) {

            int start = intervals[i][0];
            int end = intervals[i][1];

            // previous merged interval
            int prevStart = ans.back()[0];
            int prevEnd = ans.back()[1];

            // overlap exists
            if(start <= prevEnd) {

                // merge intervals
                ans.back()[0] = min(prevStart, start);
                ans.back()[1] = max(prevEnd, end);
            }
            else {
                // no overlap
                ans.push_back({start, end});
            }
        }

        return ans;
    }
};
/* merge intervals

Approach: Interval patttern

1. u have sort the given array 1st
2. store the merged value in separate place 
3. make the 1st seeing interval into the array current push_back
4. start iterating 
5. make the 2nd seeing interval into the array previous push_back
// now process start 
  1. u have to compare both the current element and the previous element
      [[1,3],[2,6],[8,10],[15,18]]
      process 1. already sorted so need to sort also
              2. 1st [1,3] in ans array
              3. 2nd [2,6] in ans array
             4. check the [1,3],[2,6]
                   3 as the ending(e1) 2 as starting (s2)
                   so s2<=e1 (3<=2)
                   thats the condition of overlapping
            5. update the min n max element
            6. there s no overlapping which means s2>=e1 (no overlapping condition)
            7. put that directly into the ans array
            8. finally merge happen if the overlapping conditions occurs true

*/

                               
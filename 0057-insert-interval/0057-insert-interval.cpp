class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals,
                               vector<int>& newInterval) {

        vector<vector<int>> ans;

        int i = 0;
        int n = intervals.size();

        // add all intervals before overlap
        while(i < n && intervals[i][1] < newInterval[0]) {
            ans.push_back(intervals[i]);
            i++;
        }

        // merge overlapping intervals
        while(i < n && intervals[i][0] <= newInterval[1]) {
//start
            newInterval[0] = min(newInterval[0], intervals[i][0]);
// end
            newInterval[1] = max(newInterval[1], intervals[i][1]);

            i++;
        }

        // add merged interval
        ans.push_back(newInterval);

        // add remaining intervals
        while(i < n) {
            ans.push_back(intervals[i]);
            i++;
        }

        return ans;
    }
};
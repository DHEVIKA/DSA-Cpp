class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {

        int n = cardPoints.size();

        int total = 0;

        for(int x : cardPoints)
            total += x; //Find Total Sum

        if(k == n) // special case answer = total sum
            return total;

        vector<int> prefix(n);

        prefix[0] = cardPoints[0];

        for(int i = 1; i < n; i++)
            prefix[i] = prefix[i-1] + cardPoints[i];

        int len = n - k;//len = 7-3 = 4 Need to leave 4 consecutive cards  

        int minWindow = INT_MAX;

        for(int i = 0; i + len - 1 < n; i++) {

            int l = i;
            int r = i + len - 1;

            int windowSum = prefix[r];

            if(l > 0) // special cases if the l is not equalto 0 use need to subtract if its zero take the right alone no need to calculate left
                windowSum -= prefix[l-1];

            minWindow = min(minWindow, windowSum);
        }

        return total - minWindow;
    }
};

/* Maximum Taken Sum
=
Total Sum
-
Minimum Remaining Sum*/
class Solution {
public:
    int countMajoritySubarrays(vector<int>& values, int key) {
        int size = values.size();
        int currentState = size + 1;

        vector<int> occurrence(2 * size + 2, 0);
        vector<int> cumulative(2 * size + 2, 0);

        occurrence[currentState] = 1;
        cumulative[currentState] = 1;

        int result = 0;

        for (int element : values) {
            if (element == key) {
                currentState++;
            } else {
                currentState--;
            }

            occurrence[currentState]++;
            cumulative[currentState] =
                cumulative[currentState - 1] + occurrence[currentState];

            result += cumulative[currentState - 1];
        }

        return result;
    }
};
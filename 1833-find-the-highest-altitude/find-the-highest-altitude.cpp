class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int max_height = 0;
        int curr_height=0;

        for(int i=0;i<gain.size();i++){
            curr_height += gain[i];
            if(curr_height> max_height) max_height = curr_height;
        }

        return max_height;
    }
};

/*we are given height of point 0 and gain[0] which is net gain between point 0 and point 1. so
height of point 1 = height of point 0 + gain[0]
so this way using previous point height and gain we will compute the next point height.
height of point i+1 = height of point i + gain[i]
img1.png
3. find all points height and store the max height
4.at the end return the max height
*/
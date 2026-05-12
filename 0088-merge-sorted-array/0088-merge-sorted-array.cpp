class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int  i = m-1;
        int j = n-1;
        int k = m+n-1; // position from last 
        while(i>=0 && j>=0){
            if(nums1[i]>nums2[j]){
                nums1[k] = nums1[i];
                i--;
            }
            else{
                nums1[k] = nums2[j];
                j--;
            }
            k--;

        }
        while(j>=0){
            nums1[k] = nums2[j];
            k--;
            j--;
        }
    }
};


/*  Intuition:
Think of nums1 and nums2 as two sorted queues waiting to be merged.
Instead of starting from the front (which could overwrite data), we start from the back — the largest elements
first — and place them at the end of nums1.
This way, every position is safely filled without disturbing the remaining unmerged elements.

Quote
“Sometimes stepping back (or iterating backward) is the smartest way forward.” 

nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
Explanation:
Step i j k nums1(after
operation)
Action
1. 2 2 5 [1,2,3,0,0,6] 6 from nums2
placed
2. 2 1 4 [1,2,3,0,5,6] 5 from nums2
placed
3. 2 0 3 [1,2,3,3,5,6] 3 from nums1
placed
4. 1 0 2 [1,2,2,3,5,6] 2 from nums2
placed
5. 0 -1 1 [1,2,2,3,5,6] Done (nums2
exhausted

*/
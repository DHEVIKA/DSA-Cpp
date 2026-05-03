class Solution {
public:
    void merge(vector<int>& a, int m, vector<int>& b , int n) {
     int index = m+n-1 ;	 // Position to insert at in nums1
   int i = m - 1;      	 // Last index of actual elements in nums1
   int j = n - 1;       	 // Last index of nums2


   // Merge both arrays starting from the back
   while (i >= 0 && j >= 0) {
       if (a[i] >= b[j]) {
           a[index--] = a[i--];
       } else {
           a[index--] = b[j--];
       }
   }


   // If any elements left in nums2, copy them over
   while (j >= 0) {
       a[index--] = b[j--];
   }

        
    }
};

// TC -> O(M+N)
// SC -> O(1)
/* noo need use extra space theres a space in arr1 so we can reuse it so we r tracking from last infex m+n-1 __ , __ , __
nums1 = [1,2,3,_,_,_]
nums2 = [2,5,6]

nums1: [1, 2, 3, _, _, _]
              ↑        ↑
             p1      curr

nums2: [2, 5, 6]
              ↑
             p2

“I always place the largest element at curr and move backwards.”
 nums1[p1]=3 vs nums2[p2]=6
6 is bigger place it
 nums1: [1, 2, 3, _, _, 6]
                       ↑
                     curr
  p2--, curr--
 3 vs 5
 5 is bigger place it
  nums1: [1, 2, 3, _, 5, 6]
                    ↑
                  curr      
3 vs 2
3 is bigger place it
nums1: [1, 2, 3, 3, 5, 6]
                 ↑
               curr

2 vs 2
take nums2 (or either) */

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size();
        int result = 0;
        for(auto n : nums){
            result = result  ^ n;

        }
        return result;
    }
};

/* BITWISE MAGIC if want to xtract the unique num with out using algo use bitwise xor

see in this question u have to return the single element there will m=be twice or thrice element in that array .. u should not use the extra s[pace an d u should not use the different dasta structure like map / set
  
Approach :
    Doing XOR calculation
1. a ^ a => same number so ans will be 0
2. a ^ b => different number ans will be  1

similarly 

1. a ^ 0 => a number XOR with 0 then it will come as 0
2. Commutative property
    (a ^ b) = (b ^ a)
3. Associative Property
    (a ^ b)^c = a ^ (b ^ c)

 Input: nums = [4,1,2,1,2]   

 use the commutative  n associative property

 nums = [4,1,2,1,2]
     [4 ,    (1 ^ 1),      (2 ^ 2)]
      |      |                 |
      [4]   [same num = 0]   [same num = 0] 

this can be calculated as the  4 ^ result => 4 ^ 0 = 4
                             (1 ^ 1) ^ result => 0 ^ 0 = 0
                             (2 ^ 2) ^ result => 0 ^ 0 = 0


final output as 4 only 
*/
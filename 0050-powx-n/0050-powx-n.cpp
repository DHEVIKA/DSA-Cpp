class Solution {
public:
    double myPow(double x, int n) {
        long binForm = n;
        double ans = 1;

        if(n<0){ // powers r negative
            x = 1/x; // x for powers
            binForm = - binForm;
        }
        
        while(binForm > 0){ // powers r positive
            if(binForm % 2 == 1){ // only take the last digit as 1
                ans = ans * x;
            }
            x = x * x; // update the x as  x square
            binForm = binForm / 2; // birary form updated
        }  
        return ans;
    }
};

/*
negative powers :(edge case)

 x ^-n = (1/x)^n  => 3^-5 => (1/3)^5
  n < 0

positive powers:

3 ^ 5 => 3*3*3*3*3 
it takes too long 
1. make the power as binary number
to convert binary=> 1 2 4 8 16 32 64 ...
  5  => 101
  ignore the zero places consider the 1 places
ans = 3^1 * 3^4 = (base r equal add the powers)
    = 1 + 4
    = 5

   ans = ans * [x] powers
1. 3^1 = 3
2. x = x*x
     = 9
3.   = 9^2
     = 81 (last digit as 1)
     =3*81
     =243

n = 5
log 5 base 2 + 1 = 3 (within 3 steps ans reached )
no need to calculate 3 for 5 times

until find last digit as 1 do the x * x
once reached the last digit as 1 update the ans = ans * x

*/
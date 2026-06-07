class Solution {
public:
    int pivotInteger(int n) {
        int leftValue = 1 , rightValue = n;
        int leftSum = leftValue , rightSum =rightValue;

        // base case;
        if(n==1) return n;
        while(leftValue<rightValue){
            if(leftSum<rightSum){
                leftValue++;
                leftSum += leftValue;
            }
            else{
                rightValue--;
                rightSum += rightValue;
            }
            if(leftSum == rightSum && leftValue+1 == rightValue-1){
                return leftValue +1;

            }

        }
        return -1;
        
    }
};
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int lsf = INT_MAX; // least so for (lsf)
        int op = 0; //overall profit  (op)
        int pist = 0; //  profit if sold today (pist)

        for(int i = 0; i < prices.size(); i++){
            if(prices[i] < lsf){ // if we found new buy value which is more smaller then previous one
                lsf = prices[i]; // update our least so far
            }
            pist = prices[i] - lsf; // calculating profit if sold today by, Buy - sell
            if(op < pist){ // if pist is more then our previous overall profit
                op = pist; // update overall profit
            }
        }
        return op; // return op 
    }
};

/*
 Remember one rule :- You can only buy one time & sell one time

So, if buy at 7 & sell at any time in the future, we'll face loss. Because buying price is way higher then selling price available we have

Now, I have seen a dip & I buy at 1 & sell at 5 my overall profit will be 5 - 1 = 4

But what if, I had buy at 1 & sell at 6 my profit will be 6 - 1 = 5. Which is greater then my overall profit. So, i will update my overall profit with new value.

Now we have done as further we don't have any higher point to sell. We will return our answer.

*/
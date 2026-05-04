class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = INT_MAX;
        int maxProfit = 0;

        for (int price : prices) {
            minPrice = min(minPrice, price);
            maxProfit = max(maxProfit, price - minPrice);
        }
        return maxProfit;
    }
};

/*
1 . To get the maximum profit, we need to buy at the lowest price and sell at a higher price later.
2 . So, the main idea is to keep track of the lowest price seen so far, and at each step, calculate the potential profit if we were to sell at the current price.
3 . If this profit is higher than our previous maximum, we update it.

 Approach 
We want to maximize profit by buying and selling the stock once (buy before sell). To solve this in a single pass:

1 . Initialize min with the highest possible value (Int_MAX) to keep track of the lowest price (best buying point) so far.
2 . Initialize maxProfit to 0 to track the maximum profit encountered.
3 . Loop through the prices array:

Update min to be the smaller of the current price and the previous min.
Calculate the profit if we sell at the current price: price - min.
Update maxProfit if this profit is greater than the previous maxProfit.
This greedy approach ensures we always make the most profitable decision at each point without needing to check every pair.

*/
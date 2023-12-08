#include<bits/stdc++.h>
using namespace std;
int climbStairs(int n)
{
    int dp[n + 1];
    dp[0] = 1;
    dp[1] = 1;
    for (int i = 2; i < n + 1; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}
int rob(vector<int> &nums)
{
    if (nums.size() == 1)
        return nums[0];
    int n = nums.size();
    int dp[n];

    dp[0] = nums[0];
    dp[1] = max(nums[0], nums[1]);

    for (int i = 2; i < nums.size(); i++)
    {
        dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
    }

    return dp[n - 1];
}
int fib(int n) {
        if(n==0 || n==1) return n;
        int dp[n+1];
        dp[0]=0;
        dp[1]=1;
    for(int i=2;i<=n;i++){
        dp[i]=dp[i-1]+dp[i-2];
}
return dp[n];
}
int coinChange(vector<int>& coins, int amount) {
        //Edge case
        if(amount<1){
            return 0;
        } 

        vector<int> minCoinsDP(amount+1,INT_MAX);
        minCoinsDP[0]=0;

        for(int i=1;i<=amount;i++){
            for(int coin: coins){
                if(coin<=i && minCoinsDP[i-coin]!=INT_MAX){
                    minCoinsDP[i]=min(minCoinsDP[i], 1+minCoinsDP[i-coin]);
                }
            }
        }

        if(minCoinsDP[amount]==INT_MAX){
            return -1;
        }

        return minCoinsDP[amount];

    }


int knapsack(vector<int> &weight, vector<int> &value, int index, int maxWeight,vector<vector<int>> &dp) 
{
	
    if(index==0){
         if(weight[0]<=maxWeight)
            return value[0];
        else
            return 0;
    }

    // Step 3:Check if subproblem result is already stored or not
    if(dp[index][maxWeight] != -1)
        return dp[index][maxWeight];
    
    
    int include=0;
    if(weight[index]<=maxWeight)
        include=value[index]+knapsack(weight,value,index-1,maxWeight-weight[index],dp);

    int exclude=0+knapsack(weight,value,index-1,maxWeight,dp);

    // Step 2: Store the recursive results in dp array 
    dp[index][maxWeight]=max(include,exclude);
    return dp[index][maxWeight]; 

}
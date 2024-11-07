
#include <iostream>
#include <vector>
using namespace std;

int knapSack(int W, const vector<int>& weights, const vector<int>& values, int items) {
    vector<vector<int>> table(items + 1, vector<int>(W + 1, 0));
    
    for (int i = 0; i <= items; i++) {
        for (int w = 0; w <= W; w++) {
            if (i == 0 || w == 0) {
                table[i][w] = 0;
            } else if (weights[i - 1] <= w) {
                table[i][w] = max(values[i - 1] + table[i - 1][w - weights[i - 1]], table[i - 1][w]);
            } else {
                table[i][w] = table[i - 1][w];
            }
        }
    }
    return table[items][W];
}
 int recursiveSoln(int w,vector<int>&wt,vector<int>&val,int n,   vector<vector<int>>&dp){
        if(n==0){
            if(wt[0]<=w){
                return val[0];
            }
            else{
                return 0;
            }
        }
        if(dp[n][w]!=-1){
            return dp[n][w];
        }
        int include=0;
        
        if(wt[n]<=w){
            include=val[n]+recursiveSoln(w-wt[n],wt,val,n-1,dp);
        }
        int exclude=0+recursiveSoln(w,wt,val,n-1,dp);
        
        
        dp[n][w]=max(include,exclude);
        
        return dp[n][w];
    }

int main() {
    int n;
    cout << "Enter the number of items: ";
    cin >> n;

    vector<int> values(n), weights(n);
    cout << "Enter values of items: ";
    for (int i = 0; i < n; i++) {
        cin >> values[i];
    }

    cout << "Enter weights of items: ";
    for (int i = 0; i < n; i++) {
        cin >> weights[i];
    }

    cout << "Enter Knapsack Capacity: ";
    int W;
    cin >> W;

    vector<vector<int>>dp(n,vector<int>(W+1,-1));


    // int maxProfit = knapSack(W, weights, values, n);
    int maxProfit=recursiveSoln(W,weights,values,n-1,dp);
    cout << "Maximum profit that can be achieved: " << maxProfit << endl;

    return 0;
}

/*
capacity = 4, val[] = [1, 2, 3], wt[] = [4, 5, 1] 
Output: 3


You are given the weights and values of items, and you need to put these items in a knapsack 
of capacity capacity to achieve the maximum total value in the knapsack. 
Each item is available in only one quantity.

In other words, you are given two integer arrays val[] and wt[], 
which represent the values and weights associated with items, respectively. 
You are also given an integer capacity, which represents the knapsack capacity.
 Your task is to find the maximum sum of values of a subset of val[] such that the sum 
 of the weights of the corresponding subset is less than or equal to capacity. 
 You cannot break an item; you must either pick the entire item or leave it (0-1 property).

*/
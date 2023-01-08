//A THEIF IS ROBBING A STORE AND CAN CARRY A MAXIMUM WEIGHT OF W INTO HIS KNAPSACK. THERE ARE N ITEMS AND THE IT'H ITEM
//WEIGHS Wi AND IS OF VALUE Vi.

//--------------------------RECURSION+MEMOIZATION------------------------------------//
//--RTC==O(2^N)----RSC==O(N)-------------------------MTC==O(N*W)--MSC==O(N*M)+O(N)---//

#include <bits/stdc++.h> 
int f(vector<int> &weight, vector<int> &value, int idx, int w,  vector<vector<int>>&dp){
    if(w<=0){
        return 0;
    }
    if(idx==0){
        if(w-weight[idx]>=0){
            return value[idx];
        }
        else{
        return 0;
        }
    }
    if(dp[idx][w]!=-1)
    {
        return dp[idx][w];
    }    
    int nottake=f(weight,value,idx-1,w,dp);
    int take=0;
    if(w>=weight[idx]){
        take=value[idx]+f(weight,value,idx-1,w-weight[idx],dp);
    }
    return dp[idx][w]=max(take,nottake);
}
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
    vector<vector<int>>dp(n,vector<int>(maxWeight+1,-1));
	
    return f(weight,value,n-1,maxWeight,dp);
    
}



//------------------------------TABULATION-----------------------//
//-----TC=O(N*W)-----SC==O(N*W)----------------------------------//

#include <bits/stdc++.h> 
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
    vector<vector<int>>dp(n,vector<int>(maxWeight+1,0));
	
    for(int i=weight[0];i<=maxWeight;i++){
        dp[0][i]=value[0];
    }
    for(int i=1;i<n;i++){
        for(int j=0;j<=maxWeight;j++){
           int nottake=dp[i-1][j];
    int take=0;
    if(j>=weight[i]){
        take=value[i]+dp[i-1][j-weight[i]];
    }  
            dp[i][j]=max(take,nottake);
        }
    }
    return dp[n-1][maxWeight];
}

//-----------------------------------------------------SPACE OPTIMIZATION--------------------------------/
//------------------TC==O(N*W)---SC==O(W)-------------------------------------------//

#include <bits/stdc++.h> 
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
        vector<int>prev(maxWeight+1,0),curr(maxWeight+1,0);
    
    for(int i=weight[0];i<=maxWeight;i++){
        prev[i]= value[0];
    }
    for(int i=1;i<n;i++){
        for(int j=0;j<=maxWeight;j++){
           int nottake=prev[j];
    int take=0;
    if(j>=weight[i]){
        take=value[i]+prev[j-weight[i]];
    }  
            curr[j]=max(take,nottake);
        }
        prev=curr;
    }
    return prev[maxWeight];
}





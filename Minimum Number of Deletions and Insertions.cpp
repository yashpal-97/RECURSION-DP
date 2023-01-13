// EXTENSION OF LCS
#include <bits/stdc++.h> 

int canYouMake(string &str, string &ptr)
{
    // Write your code here.
    int n=str.size();
    int m=ptr.size();
    vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
    for(int i=0;i<=m;i++){
        dp[0][i]=0;
    }
     for(int i=0;i<=n;i++){
        dp[i][0]=0;
     }
          for(int idx1=1;idx1<=n;idx1++){
            for(int idx2=1;idx2<=m;idx2++){
 if(str[idx1-1]==ptr[idx2-1]){
         dp[idx1][idx2]=1+dp[idx1-1][idx2-1];
    }
    else{
 dp[idx1][idx2]=max(dp[idx1-1][idx2],dp[idx1][idx2-1]);
    }
            }
          }
    int yk=dp[n][m];
    return n+m-(2*yk);
}

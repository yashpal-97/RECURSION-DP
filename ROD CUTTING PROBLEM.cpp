//--------------------------------------RECURSION----------------------------------------//
//------TC==EXPONENTIAL---------------------------------SC==O(N)-------------------------//
int f(int idx,vector<int>&price,int n){
    if(idx==0){
         return n*price[idx];
        }
    
    int nottake=0+f(idx-1,price,n);
    int take=INT_MIN;
    if((idx+1)<=n){
        take=price[idx]+f(idx,price,n-(idx+1));
    }
    return max(take,nottake);
}
int cutRod(vector<int> &price, int n)
{
	// Write your code here.
    return f(n-1,price,n);
}

//------------------------------------MEMOIZATION--------------------------------------//
//---------TC==O(N*(N+1))---------------------------------SC==O(N*N)+O(N)--------------------//

int f(int idx,vector<int>&price,int n,vector<vector<int>>&dp){
    if(idx==0){
         return n*price[idx];
        }
    if(dp[idx][n]!=-1){
        return dp[idx][n];
    }
    
    int nottake=0+f(idx-1,price,n,dp);
    int take=INT_MIN;
    if((idx+1)<=n){
        take=price[idx]+f(idx,price,n-(idx+1),dp);
    }
    return dp[idx][n]=max(take,nottake);
}
int cutRod(vector<int> &price, int n)
{
	// Write your code here.
    vector<vector<int>>dp(n,vector<int>(n+1,-1));
    return f(n-1,price,n,dp);
}

//------------------------------------------TABULATION----------------------------------------//
//-----TC==O(N*(N+1))-----SC==O(N*N)------------------------------------------------------------------------//


int cutRod(vector<int> &price, int n)
{
	// Write your code here.
    vector<vector<int>>dp(n,vector<int>(n+1,0));
    for(int i=0;i<=n;i++){
        dp[0][i]=i*price[0];
    }
    for(int i=1;i<n;i++){
        for(int j=0;j<=n;j++){
              int nottake=0+dp[i-1][j];
    int take=INT_MIN;
    if((i+1)<=j){
        take=price[i]+dp[i][j-i-1];
    }
            dp[i][j]=max(take,nottake);
        }
    }
    return dp[n-1][n];
}

//------------------------------SPACE OPTIMISATION------------------------------//
//----------TC==O(N*N)---------------------------------SC==O(N)--------------//
int cutRod(vector<int>& price,int N) {

    vector<int> cur (N+1,0);
    
    for(int i=0; i<=N; i++){
        cur[i] = i*price[0];
    }
    
    for(int ind=1; ind<N; ind++){
        for(int length =0; length<=N; length++){
        
             int notTaken = 0 + cur[length];
    
             int taken = INT_MIN;
             int rodLength = ind+1;
             if(rodLength <= length)
                taken = price[ind] + cur[length-rodLength];
        
             cur[length] = max(notTaken,taken);   
        }
    }
    
    return cur[N];
}
























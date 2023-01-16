//-------------------------------------RECURSION----------------------------------------//
class Solution {
public:
int f(string &s1, string &s2,int idx1,int idx2){
if(idx1<0) return idx2+1;
if(idx2<0) return idx1+1;

if(s1[idx1]==s2[idx2]){
    return 0+f(s1,s2,idx1-1,idx2-1);
}
 return 1+min(f(s1,s2,idx1-1,idx2),min(f(s1,s2,idx1-1,idx2-1),f(s1,s2,idx1,idx2-1)));
}
    int minDistance(string word1, string word2) {
        return f(word1,word2,word1.size()-1,word2.size()-1);
    }
};


//----------------------------------------MEMOIZATION----------------------------------------//
class Solution {
public:
int f(string &s1, string &s2,int idx1,int idx2, vector<vector<int>>&dp){
if(idx1<0) return idx2+1;
if(idx2<0) return idx1+1;

if(dp[idx1][idx2]!=-1){
    return dp[idx1][idx2];
}

if(s1[idx1]==s2[idx2]){
    return dp[idx1][idx2]=0+f(s1,s2,idx1-1,idx2-1,dp);
}
 return dp[idx1][idx2]=1+min(f(s1,s2,idx1-1,idx2,dp),min(f(s1,s2,idx1-1,idx2-1,dp),f(s1,s2,idx1,idx2-1,dp)));
}
    int minDistance(string word1, string word2) {
      int n=  word1.size()-1;
      int m=word2.size()-1;
      vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return f(word1,word2,word1.size()-1,word2.size()-1,dp);
    }
};

//-------------------------------TABULATION---------------------------------//
int editDistance(string& S1, string& S2){
    
    int n = S1.size();
    int m = S2.size();
    
    vector<vector<int>> dp(n+1,vector<int>(m+1,0));
    
    for(int i=0;i<=n;i++){
        dp[i][0] = i;
    }
    for(int j=0;j<=m;j++){
        dp[0][j] = j;
    }
    
    for(int i=1;i<n+1;i++){
        for(int j=1;j<m+1;j++){
            if(S1[i-1]==S2[j-1])
                dp[i][j] = 0+dp[i-1][j-1];
            
            else dp[i][j] = 1+min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]));
        }
    }
    
    return dp[n][m];
    
}

//----------------------------------SPACE OPTIMISED-----------------------------------------------//
int editDistance(string& S1, string& S2){
    
    int n = S1.size();
    int m = S2.size();
    
    vector<int> prev(m+1,0);
    vector<int> cur(m+1,0);
    
    for(int j=0;j<=m;j++){
        prev[j] = j;
    }
    
    for(int i=1;i<n+1;i++){
        cur[0]=i;
        for(int j=1;j<m+1;j++){
            if(S1[i-1]==S2[j-1])
                cur[j] = 0+prev[j-1];
            
            else cur[j] = 1+min(prev[j-1],min(prev[j],cur[j-1]));
        }
        prev = cur;
    }
    
    return prev[m];
    
}













//EXTENSION OF LCS
class Solution {
public:
int f(int idx1,int idx2,string &s1,string &s2, vector<vector<int>>&dp){
    if(idx1<0||idx2<0){return 0;}
    if(dp[idx1][idx2]!=-1){
        return dp[idx1][idx2];
    }
    if(s1[idx1]==s2[idx2]){
        return dp[idx1][idx2]=1+f(idx1-1,idx2-1,s1,s2,dp);
    }
    else{
        return dp[idx1][idx2]=max(f(idx1-1,idx2,s1,s2,dp),f(idx1,idx2-1,s1,s2,dp));
    }
}
int func(string &s1,string &s2){
    int n=s1.size();
    int m=s2.size();
    vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
    return f(n-1,m-1,s1,s2,dp);
}
    int longestPalindromeSubseq(string &s) {
        string t=s;
        reverse(t.begin(),t.end());
        return func(s,t);
    }
    int minInsertions(string s) {
        return s.size()-longestPalindromeSubseq(s);
    }
};

class Solution {
public:
    int maxProfit(vector<int>&a) {
        int n=a.size();
        vector<vector<int>>dp(n+1,vector<int>(2,0));
        dp[n][0]=0; dp[n][1]=0;
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<2;j++){
                int p=0;
                if(j){
                    p=max(-a[i]+dp[i+1][0],dp[i+1][1]);
                }
                else{
                    p=max(a[i]+dp[i+1][1],dp[i+1][0]);
                }
                dp[i][j]=p;
            }
        }
        return dp[0][1];
    

    }
};
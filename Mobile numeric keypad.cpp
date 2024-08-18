class Solution {
  public:
    long long getCount(int n) {
        vector<vector<int>>moves = {
            {0,8},
            {1,2,4},
            {2,1,3,5},
            {3,2,6},
            {4,1,5,7},
            {4,2,5,6,8},
            {6,3,5,9},
            {7,4,8},
            {8,5,7,9,0},
            {9,6,8}
        };
        
         vector<vector<long long>> dp(n+1, vector<long long>(10, 0));
        
        for(int i=0;i<=9;i++){
            dp[1][i] = 1;
        }
        
        for(int i=2;i<=n;i++){
            for(int j=0;j<=9;j++){
                dp[i][j] = 0;
                for(int k: moves[j]){
                    dp[i][j] += dp[i-1][k];
                }
            }
        }
        
        long long result = 0;
        
        for(int j=0;j<=9;j++){
            result += dp[n][j];
        }
        
        return result;
    }
};

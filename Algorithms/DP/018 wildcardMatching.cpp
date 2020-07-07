class Solution {
public:
    bool isMatch(string s, string p) {

        int n = s.length();
        int m = p.length();

        // If pattern is empty
        if(n!=0 && m==0){
            return 0;
        }
        // If string is empty but pattern consists of only *
        if(n==0 && m==1 && (p[m-1] =='*')){
            return 1;
        }
        // If string is empty but pattern consists of only ?
         if(n==0 && m==1 && (p[m-1] =='?')){
            return 0;
        }
        // If both are empty
        if(n==0 && m==0){
            return 1;
        }
        bool dp[n+1][m+1];
        memset(dp,0,sizeof(dp));
        // Both are empty case
        dp[0][0] = true;

        // We'll treat * as empty, and check if previous part matched
        for(int i = 1;i<=m;i++){
            if(p[i-1]=='*'){
            dp[0][i] = dp[0][i-1];
            }
        }

        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){

                if(p[j-1]=='?' || s[i-1]==p[j-1]){
                    dp[i][j] = dp[i-1][j-1];
                }
                else if(p[j-1] =='*'){
                    // dp[i-1][j] - treat * as empty string
                    // dp[i][j-1]
                    dp[i][j] = ( dp[i-1][j] || dp[i][j-1] );
                }
                // else
                //     dp[i][j] = false;
            }
        }        return dp[n][m];
    }
};


// DP memoized
class Solution {
public:
    int superEggDropUtil(int k, int n, vector<vector<int> >& dp){

        // base case
        // if eggs are 1

        if(n<=1)
            return dp[k][n] = n;
        if(k==1)
            return dp[k][n] = n;
        // if floors are 0 or 1


        if(dp[k][n]!=-1)
            return dp[k][n];

        int res = INT_MAX;
        for(int j=1; j<=n; j++){

            // case when egg broke
            int a = dp[k-1][j-1]!=-1?dp[k-1][j-1]:superEggDropUtil(k-1, j-1, dp);
            // case when egg doesnot break
            int b = dp[k][n-j]!=-1?dp[k][n-j]:superEggDropUtil(k, n-j, dp);

            // we have to consider the worst case for total attempts
            int temp = 1+max(a, b);
            res = min(res, temp);
        }

        return dp[k][n] = res;

    }
    int superEggDrop(int K, int N) {

        vector<vector<int> > dp(K+1, vector<int>(N+1, -1));
        return superEggDropUtil(K, N, dp);

    }
};

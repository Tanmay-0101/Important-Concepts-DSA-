class Solution {
    public int numTilings(int n) {
        //A quite tricky DP problem on Leetcode
      
        //n=1 -> ans=1

        //till n=2, we cant place any tromino

        //for any n, we can place 1 domino vertically(|) or two dominoes horizontally(=) and futher fetch the values of n-1 or n-2 respectively(suggests dp). But some intermediate values will repeat. So we need to track those also. That is why n-2 will give 1 way only

        //for n>=3, we will get new results only in the cases where tromino was placed, domino ones will be repeated from some case like n=1 or n=2

        /*generating all these cases, we will find the following function:
        
        F(N)=F(N-1)+F(N-2)+.           2*F(N-3)           +2*F(N-4)+ ------ +2*F(0) -(1)
               (|)   (=)   (|=|)->(2 trominoes in two ways)
        
        putting N=N-1
        
        F(N-1)=F(N-2)+F(N-3)+2*F(N-4)+2*F(N-5)+ ----- +2*F(0) -(2)
        
         (1)-(2)
        
        F(N)-F(N-1)=F(N-1)+F(N-3)
        
        F(N) = 2*F(N-1)+F(N-3) -> Required recursive relation!!! 
        */
        int mod = (int) 1e9 + 7;
        if (n == 1)
            return 1;
        if (n == 2)
            return 2;
        if (n == 3)
            return 5;
        long[] dp = new long[n + 1];
        dp[0] = 1l;
        dp[1] = 1l;
        dp[2] = 2l;
        dp[3] = 5l;
        for (int i = 4; i <= n; i++) {
            dp[i] = (2 * dp[i - 1] + dp[i - 3]) % mod;
        }
        return (int)dp[n];
    }
}

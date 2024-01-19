class Solution {
    public int minFallingPathSum(int[][] matrix) {
        int r = matrix.length;
        int c = matrix[0].length;
        int [][] dp = new int[r][c];

        for (int i = 0; i < c; i++) {
            dp[0][i] = matrix[0][i];
        }

        for (int i = 1; i < r; i++) {
            for (int j = 0; j < c; j++) {
                int ld = Integer.MAX_VALUE, rd = Integer.MAX_VALUE;
                int up = matrix[i][j] + dp[i-1][j];

                if (j-1 >= 0) {
                    ld = matrix[i][j] + dp[i-1][j-1];
                }
                if (j+1 < c) {
                    rd = matrix[i][j] + dp[i-1][j+1];
                }
                dp[i][j] = Math.min(up, Math.min(ld, rd));
            }
        }

        int m = Integer.MAX_VALUE;
        for (int i = 0; i < c; i++) {
            m = Math.min(m, dp[r-1][i]);
        }
        return m;
    }
}
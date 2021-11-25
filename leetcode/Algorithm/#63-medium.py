#
# https://leetcode.com/problems/unique-paths-ii/
# 63. Unique Paths II
# 

class Solution(object):
    def uniquePathsWithObstacles(self, obstacleGrid):
        """
        :type obstacleGrid: List[List[int]]
        :rtype: int
        """
        if obstacleGrid[0][0] == 1 : 
            return 0
        
        row, col = len(obstacleGrid), len(obstacleGrid[0])
        
        for i in range(0, row):
            for j in range(0, col):
                if obstacleGrid[i][j] is 1:
                    obstacleGrid[i][j] = 0
                else:
                    obstacleGrid[i][j] = 1
        
        for i in range(1, row):
            if obstacleGrid[i-1][0] == 0:
                obstacleGrid[i][0] = 0
        
        for i in range(1, col):
            if obstacleGrid[0][i-1] == 0:
                obstacleGrid[0][i] = 0
                
        for i in range(1, row):
            for j in range(1, col):
                if obstacleGrid[i][j] is not 0:
                    obstacleGrid[i][j] = obstacleGrid[i-1][j] + obstacleGrid[i][j-1]
                else:
                    obstacleGrid[i][j] = 0
        
        return obstacleGrid[row-1][col-1]
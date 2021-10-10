#
# https://programmers.co.kr/learn/courses/30/lessons/42898?language=cpp
# level : 3 / 등굣길
#

def solution(m, n, puddles):
    answer, mod = 0, 1e9+7
    map = [[1 for _ in range(m)] for _ in range(n)]
 
    for puddle in puddles:
        map[puddle[1]-1][puddle[0]-1] = 0
      
    for i in range(1, m-1):
        if map[0][i] == 0:
            map[0][i+1] = 0

    for i in range(1, n-1):
        if map[i][0] == 0:
            map[i+1][0] = 0
            
    
    for i in range(1,n):
        for j in range(1, m):
            if map[i][j] == 0:
                continue
            map[i][j] = int((map[i-1][j] + map[i][j-1]) % mod)
 
    return map[n-1][m-1]
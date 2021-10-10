#include <string>
#include <vector>
#include <queue>

#define INF 987654321

using namespace std;
struct Point{
    int row, col, cnt;
};

vector<vector<int>> b;
int dir[4][2]  =  {{1, 0},  {-1, 0}, {0,  1}, {0, -1}};

int bfs(Point from, Point to){
    queue<Point> q;
    bool visited[4][4] = {false};
    
    q.push(from);
    while(!q.empty()){
        Point cur = q.front(); q.pop();
        
        // 맨 위가 원하던 위치면 종료
        if (cur.row == to.row and cur.col == to.col)
            return cur.cnt;
        
        // 아니면 4방향으로 찾기
        for(int i = 0; i < 4; i++){
            int nr = cur.row  + dir[i][0], nc = cur.col + dir[i][1];
            
            if (nr > 3 or nc > 3 or nr <  0 or nc < 0) continue;
            
            // 한 칸 이동
            if (!visited[nr][nc]){
                visited[nr][nc] = true;
                q.push({nr, nc, cur.cnt + 1});
            }
            
            for (int j = 0; j < 2; j++){
                if (b[nr][nc]) break;
                if (nr + dir[i][0] > 3 or nc + dir[i][1] > 3 or 
                    nr + dir[i][0] < 0 or nc + dir[i][1] < 0) 
                    break;
                nr += dir[i][0];
                nc += dir[i][1];
            }
            
            // ctrl 이동
            if (!visited[nr][nc]){
                visited[nr][nc] = true;
                q.push({nr, nc, cur.cnt + 1});
            }
        }
    }
    return INF;
}

int permutate(Point src){
    int ret = INF;
    
    for(int card = 1; card <= 6; card++){
        vector<Point> v;
        
        // 현재 카드 위치 2개 찾기
        for(int i = 0; i < 4; i++){
            for(int j = 0; j < 4; j++){
                if (b[i][j] == card) v.push_back({i, j, 0});
            }
        }
        
        // 없을 수도 있음
        if (v.empty()) continue;
        
        // 있다면 (1, 2) or (2, 1)
        // 이동거리 bfs
        int one = bfs(src, v[0]) + bfs(v[0], v[1]) + 2;
        int two = bfs(src, v[1]) + bfs(v[1], v[0]) + 2;
        
        // card 제거
        for (int i = 0; i < 2; i++)
            b[v[i].row][v[i].col] = 0;
        
        // 각자 끝 지점에서 다시 시작
        ret = min(ret, one + permutate(v[1]));
        ret = min(ret, two + permutate(v[0]));
        
        // card 생성
        for (int i = 0; i < 2; i++)
            b[v[i].row][v[i].col] = card;
    }
    return ret == INF ? 0 : ret;
}

int solution(vector<vector<int>> board, int r, int c) {
    b = board;
    return permutate({r, c, 0});
}
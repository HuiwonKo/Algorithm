#include <stdio.h>
#include <queue>
#include <algorithm>

using namespace std;
int n, m, hx, hy, ex, ey, tmp_x, tmp_y, cur_x, cur_y, res, min_val = 2147000000;
int maze[2000][2000], ch[2000][2000], dist[2000][2000];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
queue<pair<int, int> > q;
int main(){
    scanf("%d %d", &n, &m);
    scanf("%d %d", &hx, &hy);
    scanf("%d %d", &ex, &ey);
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            scanf("%d", &maze[i][j]);
        }
    }

    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){

            if(maze[i][j] == 1){
                maze[i][j] = 0;
                q.push({hx, hy});
                ch[hx][hy] = 1;
                while(!q.empty()){
                    tmp_x = q.front().first;
                    tmp_y = q.front().second;
                    q.pop();
                    if(tmp_x == ex && tmp_y == ey){
                        res = dist[tmp_x][tmp_y];
                        break;
                    }
                    for(int dir=0; dir<4; dir++){
                        cur_x = tmp_x + dx[dir];
                        cur_y = tmp_y + dy[dir];
                        if(cur_x < 1 || cur_x > n || cur_y < 1|| cur_y > m) continue;
                        if(maze[cur_x][cur_y] == 0 && ch[cur_x][cur_y] == 0){
                            q.push({cur_x, cur_y});
                            dist[cur_x][cur_y] = dist[tmp_x][tmp_y] + 1;
                            ch[cur_x][cur_y] = 1;
                        }
                    }
                }
                min_val = min(min_val, res);
                maze[i][j] = 1;
            }
        }
    }

    if(res == 0){
        printf("-1\n");
    }
    else{
        printf("%d\n", min_val);
    }

    return 0;
}
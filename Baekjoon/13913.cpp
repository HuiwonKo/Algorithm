#include <stdio.h>
#include <queue>
#include <algorithm>

using namespace std;
int N, K, ch[100001], res, cnt;
int parent[100001];
queue<pair<int, int> > q;
vector<int> path;
int main(){
    scanf("%d %d", &N, &K);

    q.push(make_pair(N, 0));
    ch[N] = 1;

    while(!q.empty()){
        int pos = q.front().first;
        int depth = q.front().second;
        q.pop();
//        printf("pos = %d, depth = %d\n", pos, depth);
        if(pos == K){
            res = depth;
            path.push_back(pos);
            while(pos!=N){
                path.push_back(parent[pos]);
                pos = parent[pos];
            }
            break;
        }

        if(pos-1 >= 0 && ch[pos-1] == 0){
            q.push(make_pair(pos-1, depth+1));
            ch[pos-1] = 1;
            parent[pos-1] = pos;
        }
        if(pos+1 <= 100000 && ch[pos+1] == 0){
            q.push(make_pair(pos+1, depth+1));
            ch[pos+1] = 1;
            parent[pos+1] = pos;
        }
        if(pos*2 <= 100000 && ch[pos*2] == 0){
            q.push(make_pair(pos*2, depth+1));
            ch[pos*2] = 1;
            parent[pos*2] = pos;
        }
    }

    reverse(path.begin(), path.end());
    printf("%d\n", res);
    for(int i=0; i<path.size(); i++){
        printf("%d ", path[i]);
    }
    return 0;
}
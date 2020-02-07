#include <stdio.h>
#include <queue>

using namespace std;
int N, K, ch[100001], res;
queue<pair<int, int> > q;
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
            break;
        }

        if(pos-1 >= 0 && ch[pos-1] == 0){
            q.push(make_pair(pos-1, depth+1));
            ch[pos-1] = 1;
        }
        if(pos+1 <= 100000 && ch[pos+1] == 0){
            q.push(make_pair(pos+1, depth+1));
            ch[pos+1] = 1;
        }
        if(pos*2 <= 100000 && ch[pos*2] == 0){
            q.push(make_pair(pos*2, depth+1));
            ch[pos*2] = 1;
        }
//        printf("cnt = %d\n", cnt);
//        cnt ++;
    }
    printf("%d\n", res);
//    printf("%d\n", cnt);
    return 0;
}
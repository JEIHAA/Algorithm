#include <iostream>
#include <queue>
#include <vector>
#include <limits>

using namespace std;
int N, M;
vector<vector<int>> adj;

int Bfs(int start) {
    vector<int> dist(N + 1, -1);
    queue<int> Q;

    dist[start] = 0;
    Q.push(start);

    int totalDist = 0;

    while (!Q.empty()) {
        int curr = Q.front();
        Q.pop();

        for (int next : adj[curr]) {
            if (dist[next] == -1) {
                dist[next] = dist[curr] + 1;
                totalDist += dist[next];
                Q.push(next);
            }
        }
    }

    return totalDist;
}

int main() {
    cin >> N >> M;
    adj.resize(N + 1);

    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int minKevinBacon = numeric_limits<int>::max();
    int lowest = -1;

    // 모든 유저를 시작점으로 BFS 실행
    for (int i = 1; i <= N; i++) {
        int kevinBaconNumber = Bfs(i);

        if (kevinBaconNumber < minKevinBacon) {
            minKevinBacon = kevinBaconNumber;
            lowest = i;
        }
    }

    cout << lowest << endl;
    return 0;
}
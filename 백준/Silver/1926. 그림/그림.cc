#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int MAX = 500;
int paper[MAX][MAX];
bool visited[MAX][MAX];
int n, m;

// 상, 하, 좌, 우
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

int bfs(int x, int y) {
    queue<pair<int, int>> q;
    q.push({ x, y });
    visited[x][y] = true;

    int area = 0;
    while (!q.empty()) {
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();
        area++;

        for (int dir = 0; dir < 4; dir++) {
            int nx = cx + dx[dir];
            int ny = cy + dy[dir];

            if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
                if (!visited[nx][ny] && paper[nx][ny] == 1) {
                    visited[nx][ny] = true;
                    q.push({ nx, ny });
                }
            }
        }
    }

    return area;
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> paper[i][j];
            visited[i][j] = false;
        }
    }

    int maxArea = 0, count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!visited[i][j] && paper[i][j] == 1) {
                visited[i][j] = true;
                int area = bfs(i, j);
                maxArea = max(maxArea, area);
                count++;
            }
        }
    }

    cout << count << endl << maxArea;
}


#include <bits/stdc++.h>
using namespace std;

#define dbg(x) cerr << #x << " = " << (x) << endl;
#define raya cerr << " ==================== " << endl;
using ii = pair<int,int>;

int n, m, k;
vector<string> maze;

bool isIn(int i, int j) {
  return 0 <= i && i < n && 0 <= j && j < m;
}
bool libre(int i, int j) { return isIn(i,j) && maze[i][j] == '.'; }

vector<ii> vecinos(ii v) {
    int i = v.first, j = v.second;
    vector<ii> res;
    if (libre(i-1, j)) res.push_back({i-1, j});
    if (libre(i, j+1)) res.push_back({i,   j+1});
    if (libre(i+1, j)) res.push_back({i+1, j});
    if (libre(i, j-1)) res.push_back({i,   j-1});
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> k;

    maze.resize(n);
    ii start{-1,-1};
    for (int i = 0; i < n; ++i) {
      cin >> maze[i];           
      for (int j = 0; j < m; ++j)
        if (start.first == -1 && maze[i][j] == '.') start = {i,j};
    }

    vector<vector<ii>> levels;
    vector<vector<char>> vis(n, vector<char>(m, 0));
    queue<ii> q;

    q.push(start);
    vis[start.first][start.second] = 1;

    while (!q.empty()) {
      int cnt = q.size();
      levels.emplace_back();

      while (cnt--) {
        ii v = q.front(); q.pop();
        levels.back().push_back(v);

        for (auto nb : vecinos(v))
        if (!vis[nb.first][nb.second]) {
          vis[nb.first][nb.second] = 1;
          q.push(nb);
        }
      }
    }

    for (int d = (int)levels.size() - 1; d >= 0 && k; --d)
      for (auto [i,j] : levels[d])
        if (k != 0) {
          k--;
          // raya;
          maze[i][j] = 'X';
          // dbg(k);
          // dbg(maze[i][j]);
          // dbg(d);
        }
    // raya;
    for (auto& row : maze) cout << row << '\n';
}

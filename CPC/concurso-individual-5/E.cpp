#include <bits/stdc++.h>
#define int long long
using namespace std;

const int M = 7, S = 48;
int dr[4] = {1, -1, 0, 0}, dc[4] = {0, 0, 1, -1};
char dch[4] = {'D', 'U', 'R', 'L'};
bool vis[M][M];
string pat;
int64_t ans = 0;

inline bool ok(int r, int c) {
  return r >= 0 && r < M && c >= 0 && c < M;
}

bool cut(int r, int c) {
  bool u = !ok(r - 1, c) || vis[r - 1][c];
  bool d = !ok(r + 1, c) || vis[r + 1][c];
  bool l = !ok(r, c - 1) || vis[r][c - 1];
  bool rgt = !ok(r, c + 1) || vis[r][c + 1];
  return (u && d && !l && !rgt) || (l && rgt && !u && !d);
}

void go(int r, int c, int s) {
  if (s == S) {
    if (r == M - 1 && c == 0) ++ans;
    return;
  }
  if (r == M - 1 && c == 0) return;
  if (cut(r, c)) return;

  char need = pat[s];
  int cand[4], nc = 0;
  for (int d = 0; d < 4; ++d) {
    if (need != '?' && need != dch[d]) continue;
    int nr = r + dr[d], nc2 = c + dc[d];
    if (!ok(nr, nc2) || vis[nr][nc2]) continue;
    cand[nc++] = d;
  }
  if (nc == 0) return;
  if (nc == 1) {
    int d = cand[0];
    int nr = r + dr[d], nc2 = c + dc[d];
    vis[nr][nc2] = true;
    go(nr, nc2, s + 1);
    vis[nr][nc2] = false;
    return;
  }
  for (int i = 0; i < nc; ++i) {
    int d = cand[i];
    int nr = r + dr[d], nc2 = c + dc[d];
    vis[nr][nc2] = true;
    go(nr, nc2, s + 1);
    vis[nr][nc2] = false;
  }
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> pat;
  vis[0][0] = true;
  go(0, 0, 0);
  cout << ans << "\n";
  return 0;
}

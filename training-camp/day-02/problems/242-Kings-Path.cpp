  set<ii> res;

  for (int i = 0; i < n; ++i) {
    int r, a, b;
    cin >> r >> a >> b;
    for (int j = a; j <= b; ++j) {
      res.insert({r, j});
    }
  }

  queue<pair<ii, int>> q;
  set<ii> visited;

  q.push({{x0, y0}, 0});
  visited.insert({x0, y0});

  while (!q.empty()) {
    auto [pos, dist] = q.front(); q.pop();
    int x = pos.first, y = pos.second;

    if (x == x1 && y == y1) {
      cout << dist << '\n';
      return 0;
    }

    for (int dir = 0; dir < 8; ++dir) {
      int nx = x + dx[dir];
      int ny = y + dy[dir];
      ii next = {nx, ny};
      if (res.count(next) && !visited.count(next)) {
        visited.insert(next);
        q.push({next, dist + 1});
      }
    }
  }

  cout << -1 << '\n';
}

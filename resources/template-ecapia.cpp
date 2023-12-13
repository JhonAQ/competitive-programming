/*********** MANACHER ALGORTIHM  O(n)***********/
CALCULA EL MAXIMO PALINDROMO CENTRADO EN i (d[i])
d1[i] centrado en i longitud impar     /// SSOS d1[2] = 1
d2[i] centrado en i-1 longitud par  /// SSOS d2[1] = 1

pair<vector<int>, vector<int>> manacher(const string &s) {
	int n = s.size();
    vector<int> d1(n);
    int l=0, r=-1;
    for (int i=0; i<n; ++i) {
        int k = (i>r ? 0 : min (d1[l+r-i], r-i)) + 1;
        while (i+k < n && i-k >= 0 && s[i+k] == s[i-k])  ++k;
        d1[i] = --k;
        if (i+k > r)
               l = i-k,  r = i+k;
    }

    vector<int> d2 (n);
    l=0, r=-1;
    for (int i=0; i<n; ++i) {
        int k = (i>r ? 0 : min (d2[l+r-i+1], r-i+1)) + 1;
        while (i+k-1 < n && i-k >= 0 && s[i+k-1] == s[i-k])  ++k;
        d2[i] = --k;
        if (i+k-1 > r)
               l = i-k,  r = i+k-1;
    }
	return {d1, d2};
}


/****************LCA (O(nlogn))*************/
/// dp[i][j] es el 2^j-esimo padre de i
/// parent[source of the tree] = -1
/// level[source of the tree] = 0
int dp[N][20] , parent[N] , level[N] , dist[N];
int n;

void init(){

    for(int i = 0; i < n; ++i)
        for(int j = 0; 1<<j < n;++j)
        dp[i][j] = -1;

    for(int i = 0; i < n;++i)
    dp[i][0] = parent[i];

    for(int j = 1; 1<<j < n; ++j)
        for(int i = 0; i < n;++i)
            if(dp[i][j-1]!=-1)
            dp[i][j] = dp[dp[i][j-1]][j-1];
}

//level de menor a mayor cuidado (level[source] = 0 )
int lca(int a,int b){

    if(level[a] < level[b] )
    swap(a,b);

    int log;
    for(log = 1; level[a] - (1<<log) >= 0; log++);
    log--;

    for(int i = log; i >= 0; i--)
        if( level[a] - (1<<i) >= level[b] )
        a = dp[a][i];

    if(a == b) return a;

    for(int i = log; i >=0 ; i--)
        if(dp[a][i] != -1 && dp[a][i] != dp[b][i])
        a = dp[a][i] , b = dp[b][i];

    return parent[a];
}

int path(int a,int b,int num){ // KTH node a->b (0_idx)
    int x = lca(a,b);

    if( level[a] - num < level[x] )
    {   num = level[a] + level[b] - 2*level[x] - num ;
        a = b;
    }

    int log;
    for(log = 1;level[a] - (1<<log) >= 0; log++);
    log--;

    num = level[a] - num;
    for(int i = log; i>=0 ; i--)
        if(level[a] - (1<<i) >= num )
        a = dp[a][i];

return a;
}



/***************SUFFIX ARRAY O(nlogn) ****************/
//lcp[i] = suffix(i,i+1)

#define checkMod(i, n) (((i) < (n)) ? (i) : (i) - (n))
#define ALPH_SIZE 256
char s[MAXN];
int n;
int SA[MAXN], lcp[MAXN], cnt[MAXN], c[MAXN];
int pn[MAXN], cn[MAXN];

void build_suffix_array()
{
    memset(cnt, 0, ALPH_SIZE * sizeof(int));
    for(int i=0; i<n; ++i) ++cnt[(int)s[i]];
    for(int i=1; i<ALPH_SIZE; ++i) cnt[i] += cnt[i-1];
    for(int i=0; i<n; ++i) SA[--cnt[(int)s[i]]] = i;

    c[SA[0]] = 0;
    int classes = 1;
    for(int i=1; i<n; ++i){
        if(s[SA[i]] != s[SA[i-1]]) ++classes;
        c[SA[i]] = classes-1;
    }

    for(int h=0; (1<<h)<n; ++h){
        for(int i=0; i<n; ++i) pn[i] = checkMod(SA[i] - (1<<h) + n, n);

        memset(cnt, 0, classes * sizeof(int));
        for(int i=0; i<n; ++i) ++cnt[c[pn[i]]];
        for(int i=1; i<classes; ++i) cnt[i] += cnt[i-1];
        for(int i=n-1; i>=0; i--) SA[--cnt[c[pn[i]]]] = pn[i];

        for(int i=0; i<n; ++i) pn[i] = checkMod(SA[i] + (1<<h), n);

        cn[SA[0]] = 0;
        classes = 1;
        for(int i=1; i<n; ++i){
            if(c[SA[i]] != c[SA[i-1]] || c[pn[i]] != c[pn[i-1]]) ++classes;
            cn[SA[i]] = classes-1;
        }
        memcpy(c, cn, n * sizeof(int));
    }
}

void build_lcp() {
    int k = 0;
    for(int i = 0; i < n; i++) if (c[i]) {
        int j = SA[c[i] - 1];
        while(s[i + k] == s[j + k]) k++;
        lcp[c[i] - 1] = k;
        if (k) k--;
    }
    lcp[n - 1] = 0;
}

/************************ MAX FLOW  - EDMOND KARP O(V * E^2)************/
class MaximumFlow {
	const long long INF = 1e18;
	int s , f;
public:
	struct Edge {
		int u , v;
		long long capacity;
		Edge(){}
		Edge(int u_,int v_,long long capacity_):
			u(u_) , v(v_) , capacity(capacity_){}
	};

	vector<Edge> edges;
	vector< vector<int> > graph;
	vector<int> prt;
	vector<long long> dist;
	queue<int> Q;
	int n;

	MaximumFlow() {}
	
	MaximumFlow(int len) {
		n = len;
		graph.resize(n);
	}

	void addEdge(int u,int v,long long capacity) {
		int sz = edges.size();
		edges.push_back(Edge(u, v, capacity));
		edges.push_back(Edge(v, u, 0));
		graph[u].push_back(sz);
		graph[v].push_back(sz + 1);
	}
	
	long long getMaximumFlow(int start, int finish) {
		s = start , f = finish;
		long long ret = 0;
		while (true) {
			prt.assign(n , -1);
			dist.assign(n , 0);
			dist[s] = INF;
			Q.push(s);
			while (!Q.empty()) {
				int u = Q.front(); Q.pop();
				for (int idx : graph[u]) {
					int to = edges[idx].v;
					if (dist[to] == 0 && edges[idx].capacity > 0) {
						Q.push(to);
						dist[to] = min(dist[u] , edges[idx].capacity);
						prt[to] = idx;
					}
				}
			}
			if (dist[f] == 0) {
				break;
			}
			ret += dist[f];
			int u = f;
			while (u != s) {
				edges[prt[u]].capacity -= dist[f];
				edges[prt[u] ^ 1].capacity += dist[f];
				u = edges[prt[u]].u;
			}
		};
		return ret;
	}
};

//******************* MAX FLOW ***************//
// DINIC -  SDYA
class MaximumFlow {
	const long long INF = 1e18;
	int s, f;
public:
	struct Edge {
		int u, v;
		long long capacity, flow;
		Edge() { u = v = capacity = flow = 0;}
		Edge(int u_, int v_, long long capacity_, long long flow_) :
		  u(u_), v(v_), capacity(capacity_), flow(flow_) {}
	};

	vector <Edge> edges;
	vector <vector <int> > graph;
	vector <int> ptr, level;
	queue <int> q;
	int n;

	MaximumFlow() {}

	MaximumFlow(int number) {
		n = number;
		graph.resize(n);
		ptr.assign(n, 0);
		level.resize(n);
	}

	void addEdge(int u, int v, long long capacity) {
		int sz = (int)(edges.size());
		edges.push_back(Edge(u, v, capacity, 0));
		edges.push_back(Edge(v, u, 0, 0));
		graph[u].push_back(sz);
		graph[v].push_back(sz + 1);
	}

	void updateLevels() {
		level.assign(n, -1);
		q.push(s);
		level[s] = 0;
		while (!q.empty()) {
			int topq = q.front();
			q.pop();
			for (int index = 0; index < graph[topq].size(); ++index) {
				int i = graph[topq][index];
				int to = edges[i].v;
				if (edges[i].capacity - edges[i].flow == 0) {
					continue;
				}
				if (level[to] == -1) {
					level[to] = level[topq] + 1;
					q.push(to);
				}
			}
		}
	}

	long long pushFlow(int v, long long flow) {
		if (v == f || flow == 0) {
			return flow;
		}
		for (; ptr[v] < graph[v].size(); ++ptr[v]) {
			int index = graph[v][ptr[v]];
			int to = edges[index].v;
			if (level[v] + 1 == level[to]) {
				long long pushed = pushFlow(to, min(flow, edges[index].capacity - edges[index].flow));
				if (pushed > 0) {
					edges[index].flow += pushed;
					edges[index ^ 1].flow -= pushed;
					return pushed;
				}
			}
		}
		return 0;
	}

	long long dinicFlow(int start, int finish) {
		s = start, f = finish;
		long long result = 0;
		while (true) {
			updateLevels();
			if (level[f] == -1) {
				break;
			}
			while (true) {
				long long pushed = pushFlow(start, INF);
				if (pushed == 0) {
					break;
				}
				result += pushed;
			}
			ptr.assign(n, 0);
		}
		return result;
	}
};

///****************SEGMENT TREE - LAZY***********************///

class SegmentTree {
public:
	struct Node {
		long long sum;
		long long lazy;
		Node() {}
		Node(long long sum_, long long lazy_) {
			sum = sum_;
			lazy = lazy_;
		}
	};
	
	Node merge(const Node &le, const Node &ri) {
		Node ret;
		ret.sum = le.sum + ri.sum;
		ret.lazy = 0;
		return ret;
	}
	
	vector<Node> tree;

	SegmentTree(int n) {
		tree.assign(4*n, Node(0LL, 0LL));
	}

	SegmentTree(const vector<long long> &input) {
		int n = input.size();
		tree.resize(4*n);
		build(0, 0, n-1, input);
	}

	void build(int index, int b, int e, const vector<long long> &input) {
		if (b == e) {
			tree[index].sum = input[b];
			tree[index].lazy = 0;
		} else {
			int mid = (b+e)/2, le = 2*index+1, ri = le+1;
			build(le, b, mid, input);
			build(ri, mid+1, e, input);
			tree[index] = merge(tree[le], tree[ri]);
		}
	}

	void push(int index, int b, int e) {
		tree[index].sum += tree[index].lazy * (e - b + 1);
		if (b != e) {
			int le = 2*index+1, ri = le+1;
			tree[le].lazy += tree[index].lazy;
			tree[ri].lazy += tree[index].lazy;
		}
		tree[index].lazy = 0;
	}

	void update(int index, int b, int e, int i, int j, long long delta) {
		push(index, b, e);
		if (b > j || e < i) {
			return;
		}
		if (i <= b && e <= j) {
			tree[index].lazy += delta;
			push(index, b, e);
		} else {
			int mid = (b+e)/2, le = 2*index+1, ri = le+1;
			update(le, b, mid, i, j, delta);
			update(ri, mid+1, e, i, j, delta);
			tree[index] = merge(tree[le], tree[ri]);
		}
	}

	Node query(int index, int b, int e, int i, int j) {
		push(index, b, e);
		if (i <= b && e <= j) {
			return tree[index];
		}
		int mid = (b+e)/2, le = 2*index+1, ri = le+1;
		if (mid < i) {
			return query(ri, mid+1, e, i, j);
		} else if (mid+1 > j) {
			return query(le, b, mid, i, j);
		} else {
			Node leRet = query(le, b, mid, i, j);
			Node riRet = query(ri, mid+1, e, i, j);
			return merge(leRet, riRet);
		}
	}
};

/****************** BICONNECTED COMPONENTS ****************/
/// valores iniciales counter = 1 , t[i] = 0
vector<int> adj[N];
int t[N] , mini[N] , parent[N] , counter , root , childrenroot;
bool articulation[N];
stack< ii > pila;
vector< set<int> > biconnected_component; /// aqui guardamos las componentes (vertices)

void dfs(int v){
    t[v] = mini[v] = counter++;

    for(int j = 0; j < adj[v].size(); ++j){
        int where = adj[v][j];
        ii edge = ii(v,where);

        if(t[where] == 0){
            parent[where] = v;
            pila.push(edge); /// add edge
            if(root == v) childrenroot++; /// case special for root

            dfs(where);

            mini[v] = min(mini[v],mini[where]);

            if(mini[where] >= t[v]){ /// v is articulation
                articulation[v] = 1;

                set<int > c; /// conjunto de vertices
                while( true ){
                    ii current = pila.top(); pila.pop();
                    c.insert(current.first); c.insert(current.second);
                    /// current es una arista de la biconnected componente
                    /// tenemos todas las aristas de la biconnected componente
                    if(current == edge) break;
                }

                biconnected_component.push_back(c); /// add biconnected component

            }

        }else
            if(parent[v] != where && t[where] < t[v] ){
                /// back edge
                pila.push(edge);
                mini[v] = min(mini[v],t[where]);
            }
    }
}

int main(){
  // freopen("in.c","r",stdin);
            int n;
            counter = 1;
            for(int i = 0; i < n; ++i){
                if(t[i] == 0){
                    parent[i] = -1;
                    root = i; childrenroot = 0;
                    dfs(i);
                    articulation[root] = childrenroot > 1;
                }
            }

    return 0;
}


/******************PUENTES Y ARTICULACIONES********///

vector<int> adj[N];
int t[N] , mini[N] , parent[N], counter , root , childrenroot;
bool articulation[N];
void dfs(int u){

    t[u] = mini[u] = counter++;
    for(int j = 0; j < adj[u].size(); ++j){
    int where = adj[u][j];
        if(t[where] == 0){
            parent[where] = u;
            if(u == root) childrenroot++;

            dfs(where);
            mini[u] = min(mini[u],mini[where]);

            if(mini[where] >= t[u])
            articulation[u] = 1;
            if(mini[where] > t[u])
            printf("Bridge: %d - %d\n",u,where);
        }else
            if( parent[u] != where)
            mini[u] = min(mini[u],t[where]);
    }
}

int main(){

        for(int i = 0; i < n; ++i)
            t[i] =  articulation[i] = 0;

        counter = 1;
        for(int i = 0; i < n; ++i)
            if(t[i] == 0){
                parent[i] = -1;
                root = i; childrenroot = 0;
                dfs(i);
                articulation[i] = childrenroot >1;
            }

    return 0;
}



/****** STRONGLY COMPONENTES ******************/
/// valores iniciales counter = 1 ,  t[i] = 0 , scc = 0
vector<int> adj[N];
int t[N] , mini[N], counter , id[N] , scc;
vector<int> s;

void dfs(int u){
    t[u] = mini[u] = counter++;
    s.push_back(u);
    for(int j = 0; j < adj[u].size(); ++j){
    int where = adj[u][j];
        if(t[where] == 0)
        dfs(where);
        if(t[where] != -1)
        mini[u] = min(mini[u],mini[where]);
    }

    if(mini[u] == t[u]){
        int v;
        do{     v = s.back(); t[v] = -1; s.pop_back();
                id[v] = scc;
        }while( v != u);
    scc++;
    }
}


/***********HASH**************/
#define HASH unsigned long long

HASH pot[MAXN];
HASH HA[MAXN];
char a[MAXN];
int tama;

// es el hash de [a,b>
HASH readA(int a,int b){  return HA[b] - HA[a]*pot[b-a]; }

int main()
{
    pot[0] = 1;
    for(int i = 1; i < MAXN; ++i)
        pot[i] = pot[i-1] * B;

        for(int i = 1; i <= tama; ++i)
            HA[i] = HA[i-1] * B + a[i-1]-'a'+1;

    return 0;
}

/**********************MATCHING ***************//
/// CAMINOS AUMENTATIVOS O (E * V)
int le , ri; // cantidad nodo left and right
vector<int> adj[N];
int dueno[N]; // es de todo le + ri
int vis[N]; // solo es le
int path(int x){
    if(vis[x]) return 0;
    vis[x] = 1;

    for(int j = 0; j < adj[x].size(); ++j){
    int where = adj[x][j];
         if(dueno[where]==-1 || path(dueno[where])) {
            dueno[where] = x;
            return 1;
         }
    }
return 0;
}

int matching(){
    int ans = 0;
    for(int i = 0; i < le + ri; ++i)
        dueno[i] = -1;

    for(int i = 0; i < le; ++i){
        for(int k = 0; k < le; ++k)
            vis[k] = false;
    ans += path(i);
    }
return ans;
}

/**********MATCHING **********/
HOPCROFT O (E * sqrt(V))

vint adj[N + 1]; // (u, v) <=> (v, u)
int n, m, NIL, match[N + 1], dist[N + 1];
// Izquierda; nodos del 0 al n-1
// Derecha: Nodos del n al n+m-1
// NIL: Nodo n+m

bool bfs(){
    queue <int> Q;
    for(int i=0; i<n; i++) {
        if(match[i] == NIL) {
            dist[i] = 0;
            Q.push(i);
        }
        else dist[i] = INF;
    }
    dist[NIL] = INF;

    while(!Q.empty()) {
        int u = Q.front(); Q.pop();
        for(int i=0; i<(int)adj[u].size(); i++){
            int v = adj[u][i];
            if(dist[match[v]] == INF) {
                dist[match[v]] = dist[u] + 1;
                Q.push(match[v]);
            }
        }
    }
    return dist[NIL] != INF;
}

bool dfs(int u) {
	if(u != NIL) {
		for(int i=0; i<(int)adj[u].size(); i++) {
			int v = adj[u][i];
			if(dist[match[v]] == dist[u] + 1) {
				if(dfs(match[v])) {
					match[v] = u;
					match[u] = v;
					return true;
				}
			}
		}
		dist[u] = INF;
		return false;
	}
	return true;
}

int hopcroft_karp()
{
    NIL = n + m;
    for(int i=0; i<n+m; i++)
    	match[i] = NIL;

    int matching = 0;
    //Greedy Step
    for(int u=0; u<n; u++)
    {
    	for(int i=0; i<(int)adj[u].size(); i++)
    	{
    		int v = adj[u][i];
    		if(match[v] == NIL)
    		{
    			matching++;
    			match[u] = v;
    			match[v] = u;
    			break;
    		}
    	}
    }

    while(bfs())
        for(int u=0; u<n; u++)
            if(match[u] == NIL && dfs(u))
                matching++;

    return matching;
}

///**************** PRIM O (V^2) ******************/
/// valores iniciales who[i] = -1  , vis[i] = 0;
int who[N] , dist[N][N], n ;
bool visited[N];
void update(int u)
{       visited[u] = true;
        for(int i = 0; i < n; ++i)
            if(i != u){
                if(who[i] == -1 || dist[i][u] < dist[i][who[i]] )
                who[i] = u;
            }
}

int main(){

        update(0);
        for(int rep = 0; rep < n-1; rep++){
         int mn = -1;
                for(int i = 0; i < n; ++i)
                    if(!visited[i]){
                        if(mn == -1 || dist[i][who[i]] < dist[mn][who[mn]] )
                        mn = i;
                    }

        printf("%d %d\n",&mn,&who[mn]);
        update(mn);
        }

return 0;
}


/******************KMP************/

char T[N], P[N]; // T = text, P = pattern
int b[N], n, m; // b = back table, n = length of T, m = length of P

void kmpPreprocess() { // call this before calling kmpSearch()
  int i = 0, j = -1; b[0] = -1;
  while (i < m) {
    while (j >= 0 && P[i] != P[j]) j = b[j];
    i++; j++;
    b[i] = j;
} }

void kmpSearch() {
  int i = 0, j = 0;
  while (i < n) {
    while (j >= 0 && T[i] != P[j]) j = b[j];
    i++; j++;
    if (j == m) {
      printf("P is found at index %d in T\n", i - j);
      j = b[j];
    }
  }
}

/**********************BIT************/
//empieza en idx = 0
// BIT 1D
class BIT {
private:
	int n;
	vector<int> t;

public:
	BIT(int _n) {
		n = _n;
		t.assign(n, 0);
	}

	int sum(int pos) {
		int result = 0;
		for(int i = pos; i >= 0; i = (i & (i+1)) - 1) {
			result += t[i];
		}
		return result;
	}

	int sum(int le, int ri) {
		return sum(ri) - (le > 0 ? sum(le-1):0);
	}

	void update(int pos, int delta) {
		for(int i = pos; i < n; i = (i | (i+1))) {
			t[i] += delta;
		}
	}
};



// BIT 2D
int n, m;
int t[1024][1024], value[1024][1024];

int sum(int x, int y)
{	int result = 0;
	for(int i = x; i >= 0; i = (i & (i+1)) - 1)
        for(int j = y; j >= 0; j = (j & (j+1)) - 1)
            result += t[i][j];
    return result;
}

void inc(int x, int y, int delta)
{   for(int i = x; i < n; i = (i | (i+1)))
        for(int j = y; j < m; j = (j | (j+1)))
            t[i][j] += delta;
}

/******************+BIT************/
empieza en idx = 1
//1D
int tree[N], n ;

int read(int idx){
	int sum = 0;
	for( ; idx > 0 ; idx -= (idx & -idx))
		sum += tree[idx];
return sum;
}

void update(int idx ,int val){
	for (;idx <= n; idx += (idx & -idx))
		tree[idx] += val;
}
//2D
int tree[N][N];
int n;

void update(int x,int y,int val){
    for(int i = x;i <= n; i += i&-i)
        for(int j = y; j <= n; j += j&-j)
            tree[i][j] += val;
}

int read(int x,int y){
    int res = 0;
    for(int i = x; i > 0 ; i -= i&-i)
        for(int j = y; j > 0; j -= j&-j)
            res += tree[i][j];
return res;
}

///******************RMQ******************///
/// dp[i][j] = gcd[ i,i + (1<<j) >
int gcd(int a,int b){
    if(a + b == 0) return 0;
    return b == 0 ? a:gcd(b,a%b);
}
int dp[N][20] , log22[N];
int query(int a,int b){
    int len = log22[b-a+1];
    return gcd(dp[a][len],dp[b+1-(1<<len)][len]);
}

int a[N];
int main(){
 // freopen("in.c","r",stdin);
    for(int i = 1; i < N; ++i)
        log22[i] = log2(i);

    for(int i = 0; i < n; ++i)
        dp[i][0] = a[i];

    for(int j = 1; 1<<j <= n; ++j)
        for(int i = 0; i + (1<<j) <= n; ++i)
            dp[i][j] = gcd(dp[i][j-1] , dp[i + (1<<(j-1))][j-1]);
}


/***************MATEMATICAS*************/

CRIBA NORMAL


ll n;
bitset<10000010> bs;   // 10^7 should be enough for most cases
vint primes;   // compact list of primes in form of vector<int>

// first part

void sieve() {          // create list of primes in [0..upperbound]
  bs.set();                                                 // set all bits to 1
  bs[0] = bs[1] = 0;                                     // except index 0 and 1
  for (ll i = 2; i <= n; i++) if (bs[i]) {
    // cross out multiples of i starting from i * i!
    for (ll j = i * i; j <= n; j += i) bs[j] = 0;
    primes.push_back((int)i);  // also add this vector containing list of primes
} }                                           // call this method in main method

bool isPrime(ll N) {                 // a good enough deterministic prime tester
  if (N <= n) return bs[N];                   // O(1) for small primes
  for (int i = 0; i < (int)primes.size(); i++)
    if (N % primes[i] == 0) return false;
  return true;                    // it takes longer time if N is a large prime!
}                      // note: only work for N <= (last prime in vi "primes")^2


// second part

vint primeFactors(ll N) {   // remember: vi is vector of integers, ll is long long
  vint factors;                    // vi `primes' (generated by sieve) is optional
  ll PF_idx = 0, PF = primes[PF_idx];     // using PF = 2, 3, 4, ..., is also ok
  while (N != 1 && (PF * PF <= N)) {   // stop at sqrt(N), but N can get smaller
    while (N % PF == 0) { N /= PF; factors.push_back(PF); }    // remove this PF
    PF = primes[++PF_idx];                              // only consider primes!
  }
  if (N != 1) factors.push_back(N);     // special case if N is actually a prime
  return factors;         // if pf exceeds 32-bit integer, you have to change vi
}


// third part

ll numPF(ll N) {
  ll PF_idx = 0, PF = primes[PF_idx], ans = 0;
  while (N != 1 && (PF * PF <= N)) {
    while (N % PF == 0) { N /= PF; ans++; }
    PF = primes[++PF_idx];
  }
  if (N != 1) ans++;
  return ans;
}

ll numDiffPF(ll N) {
  ll PF_idx = 0, PF = primes[PF_idx], ans = 0;
  while (N != 1 && (PF * PF <= N)) {
    if (N % PF == 0) ans++;                           // count this pf only once
    while (N % PF == 0) N /= PF;
    PF = primes[++PF_idx];
  }
  if (N != 1) ans++;
  return ans;
}

ll sumPF(ll N) {
  ll PF_idx = 0, PF = primes[PF_idx], ans = 0;
  while (N != 1 && (PF * PF <= N)) {
    while (N % PF == 0) { N /= PF; ans += PF; }
    PF = primes[++PF_idx];
  }
  if (N != 1) ans += N;
  return ans;
}

ll numDiv(ll N) {
  ll PF_idx = 0, PF = primes[PF_idx], ans = 1;             // start from ans = 1
  while (N != 1 && (PF * PF <= N)) {
    ll power = 0;                                             // count the power
    while (N % PF == 0) { N /= PF; power++; }
    ans *= (power + 1);                              // according to the formula
    PF = primes[++PF_idx];
  }
  if (N != 1) ans *= 2;             // (last factor has pow = 1, we add 1 to it)
  return ans;
}

ll sumDiv(ll N) {
  ll PF_idx = 0, PF = primes[PF_idx], ans = 1;             // start from ans = 1
  while (N != 1 && (PF * PF <= N)) {
    ll power = 0;
    while (N % PF == 0) { N /= PF; power++; }
    ans *= ((ll)pow((double)PF, power + 1.0) - 1) / (PF - 1);         // formula
    PF = primes[++PF_idx];
  }
  if (N != 1) ans *= ((ll)pow((double)N, 2.0) - 1) / (N - 1);        // last one
  return ans;
}

ll EulerPhi(ll N) {
  ll PF_idx = 0, PF = primes[PF_idx], ans = N;             // start from ans = N
  while (N != 1 && (PF * PF <= N)) {
    if (N % PF == 0) ans -= ans / PF;                // only count unique factor
    while (N % PF == 0) N /= PF;
    PF = primes[++PF_idx];
  }
  if (N != 1) ans -= ans / N;                                     // last factor
  return ans;
}

//CRIBA EN O(n)

int n , lp[N] , primes[N] ,sz;
void sieve(){

        for(int i = 2; i <= n; ++i) {
                if (lp[i] == 0) {
                        lp[i] = i;
                        primes[sz++] = i;
                }
                for(int j = 0; j < sz && primes[j] <= lp[i] && (long long)i*primes[j] <= n; ++j)
                        lp[i * primes[j]] = primes[j];
        }

}


// return a % b (positive value)
int mod(int a, int b) {
  return ((a%b)+b)%b;
}

// computes gcd(a,b)
int gcd(int a, int b) {
  int tmp;
  while(b){a%=b; tmp=a; a=b; b=tmp;}
  return a;
}

// computes lcm(a,b)
int lcm(int a, int b) {
  return a/gcd(a,b)*b;
}

// returns d = gcd(a,b); finds x,y such that d = ax + by
int extended_euclid(int a, int b, int &x, int &y) {
  int xx = y = 0;
  int yy = x = 1;
  while (b) {
    int q = a/b;
    int t = b; b = a%b; a = t;
    t = xx; xx = x-q*xx; x = t;
    t = yy; yy = y-q*yy; y = t;
  }
  return a;
}

// finds all solutions to ax = b (mod n)
vint modular_linear_equation_solver(int a, int b, int n) {
  int x, y;
  vint solutions;
  int d = extended_euclid(a, n, x, y);
  if (!(b%d)) {
    x = mod (x*(b/d), n);
    for (int i = 0; i < d; i++)
      solutions.push_back(mod(x + i*(n/d), n));
  }
  return solutions;
}

// computes b such that ab = 1 (mod n), returns -1 on failure
int mod_inverse(int a, int n) {
  int x, y;
  int d = extended_euclid(a, n, x, y);
  if (d > 1) return -1;
  return mod(x,n);
}

// Chinese remainder theorem (special case): find z such that
// z % x = a, z % y = b.  Here, z is unique modulo M = lcm(x,y).
// Return (z,M).  On failure, M = -1.
pii chinese_remainder_theorem(int x, int a, int y, int b) {
  int s, t;
  int d = extended_euclid(x, y, s, t);
  if (a%d != b%d) return make_pair(0, -1);
  return make_pair(mod(s*b*x+t*a*y,x*y)/d, x*y/d);
}

// Chinese remainder theorem: find z such that
// z % x[i] = a[i] for all i.  Note that the solution is
// unique modulo M = lcm_i (x[i]).  Return (z,M).  On
// failure, M = -1.  Note that we do not require the a[i]'s
// to be relatively prime.
pii chinese_remainder_theorem(const vint &x, const vint &a) {
  pii ret = make_pair(a[0], x[0]);
  for (int i = 1; i < (int)x.size(); i++) {
    ret = chinese_remainder_theorem(ret.second, ret.first, x[i], a[i]);
    if (ret.second == -1) break;
  }
  return ret;
}

// computes x and y such that ax + by = c; on failure, x = y =-1
void linear_diophantine(int a, int b, int c, int &x, int &y) {
  int d = gcd(a,b);
  if (c%d) {
    x = y = -1;
  } else {
    x = c/d * mod_inverse(a/d, b/d);
    y = (c-a*x)/b;
  }
}


int main(){

    // expected: 2
  cout << gcd(14, 30) << endl;

  // expected: 2 -2 1
  int x, y;
  int d = extended_euclid(14, 30, x, y);
  cout << d << " " << x << " " << y << endl;

  // expected: 95 45
  vint sols = modular_linear_equation_solver(14, 30, 100);
  for (int i = 0; i < (int) sols.size(); i++) cout << sols[i] << " ";
  cout << endl;

  // expected: 8
  cout << mod_inverse(8, 9) << endl;

  // expected: 23 56
  //           11 12
  int xs[] = {3, 5, 7, 4, 6};
  int as[] = {2, 3, 2, 3, 5};
  pii ret = chinese_remainder_theorem(vint (xs, xs+3), vint(as, as+3));
  cout << ret.first << " " << ret.second << endl;
  ret = chinese_remainder_theorem (vint(xs+3, xs+5), vint(as+3, as+5));
  cout << ret.first << " " << ret.second << endl;

  // expected: 5 -15
  linear_diophantine(7, 2, 5, x, y);
  cout << x << " " << y << endl;


    return 0;
}


/**************TEOREMA CHINO DEL RESTO , FAST EXP E INVERSO MODULAR *******/

int exp(int a,int b,int c){
    int ans = 1;
    while(b){
        if(b&1) ans = ans * a % c;

        a = a * a % c;
        b>>=1;
    }
return ans;
}

int inv(int a,int b){
    return exp(a,b-2,b);
}

//todo bi es primo (hacer con euler para el otro caso)
//dados bi,coprimos para todo (bi,bj) 1 <= i < j <= k
// dados a = ai % bi
//retorna a % (b1*b2*...*bk)

int teorema_chino(vint bases,vint ai){
    int k = bases.size();
    int prod = 1;

    f(i,0,k)
    prod *= bases[i];

    int b = prod;
    int ans = 0;
    f(i,0,k){
    int  m = prod / bases[i];
       ans = (ans + ai[i] * m * inv(m , bases[i] ) )%b;
    }
return ans;
}

int main()
{
    vint bases;
    bases.pb(2);
    bases.pb(5);

    vint ai;
    ai.pb(0);
    ai.pb(2);

    int ans = teorema_chino(bases,ai);
    bug1(ans);

    return 0;
}


///****************GAUSS ECHELON ***************///
int gauss ( vector < vector < double > > a, vector < double > & ans ) {
	/****n = numero de ecuaciones m = numero de variables*/
	int n = ( int ) a. size ( ) ;
	int m = ( int ) a [ 0 ] . size ( ) - 1 ;

	vector < int > where ( m, - 1 ) ;
	for ( int col = 0 , row = 0 ; col < m && row < n ; ++ col ) {
		int sel = row ;
		for ( int i = row ; i < n ; ++ i )
			if ( abs ( a [ i ] [ col ] ) > abs ( a [ sel ] [ col ] ) )
				sel = i ;
		if ( abs ( a [ sel ] [ col ] ) < EPS )
			continue ;
		for ( int i = col ; i <= m ; ++ i )
			swap ( a [ sel ] [ i ] , a [ row ] [ i ] ) ;
		where [ col ] = row ;

		for ( int i = 0 ; i < n ; ++ i )
			if ( i != row ) {
				double c = a [ i ] [ col ] / a [ row ] [ col ] ;
				for ( int j = col ; j <= m ; ++ j )
					a [ i ] [ j ] -= a [ row ] [ j ] * c ;
			}
		++ row ;
	}

	ans. assign ( m, 0 ) ;
	for ( int i = 0 ; i < m ; ++ i )
		if ( where [ i ] != - 1 )
			ans [ i ] = a [ where [ i ] ] [ m ] / a [ where [ i ] ] [ i ] ;
	for ( int i = 0 ; i < n ; ++ i ) {
		double sum = 0 ;
		for ( int j = 0 ; j < m ; ++ j )
			sum += ans [ j ] * a [ i ] [ j ] ;
		if ( abs ( sum - a [ i ] [ m ] ) > EPS )
			return 0 ;
	}

	for ( int i = 0 ; i < m ; ++ i )
		if ( where [ i ] == - 1 )
			return INF ;
	return 1 ;
}



/**************AHO CORASICK****/
/************** Elvis Rusnel Capia Quispe ***************/
#include <bits/stdc++.h>
#define f(i,x,y) for (int i = (x); i < (y); i++)
#define fd(i,x,y) for(int i = x; i>= y; i--)
#define FOR(it,A) for(typeof A.begin() it = A.begin(); it!=A.end(); it++)
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define vint vector<int>
#define pii pair<int,int>
#define vpii vector<pii>
#define ll long long
#define clr(A,x) memset(A, x, sizeof A)
#define pb push_back
#define fst first
#define snd second
#define ones(x) __builtin_popcount(x)
#define MOD 1000000007
#define INF 1000000000
#define HASH unsigned long long
#define bug1(x) cout<<#x<<" = "<<x<<endl
#define bug2(x,y) cout<<#x<<" = "<<x<<" "<<#y<<" = "<<y<<endl
#define bug3(x,y,z) cout<<#x<<" = "<<x<<" "<<#y<<" = "<<y<<" "<<#z<<" = "<<z<<endl
#define bug4(x,y,z,m) cout<<#x<<" = "<<x<<" "<<#y<<" = "<<y<<" "<<#z<<" = "<<z<<" "<<#m<<" = "<<m<<endl
#define sc(x) scanf("%d",&x)
#define MAXN 1000005

using namespace std;
int toi(string a){	int ans;  sscanf(a.c_str(),"%d",&ans);  return ans;  }
string tos(int a){	ostringstream st; st<<a; string ans = st.str(); return ans;   }

bool ispal[MAXN];
int tree[MAXN][26] , T[MAXN] , padre[MAXN];
int node;

void add(string a){
    int n = a.size() , p = 0;

    f(i,0,n){
            if( tree[p][a[i]-'a'] == 0) tree[p][a[i]-'a'] = node++;

    padre[tree[p][a[i]-'a']] = p;
    p = tree[p][a[i]-'a'];
    }
    ispal[p] = true;
}

void aho(){

    queue<int> Q;
    int where = 0;

    f(i,0,26)
        if(tree[where][i]){
            Q.push(tree[where][i]); // tamaño 1
            T[tree[where][i]] = 0; // apunta al vacio
        }

    while(!Q.empty()){
        where = Q.front(); Q.pop();

        f(i,0,26)
            if(tree[where][i]){
                int v = tree[where][i];

                int p = T[where]; // link de where

                while(p && tree[p][i]==0)
                p = T[p];

                T[v] = tree[p][i];
                Q.push(v);
            }
    }
}

int dp[MAXN] , c[MAXN] , caso;
int solve(int p){
    if(p==0) return 0;
    int &ans = dp[p] , &aux = c[p];

    if(aux==caso) return dp[p];
    aux = caso;

    return ans = ispal[p] +  max(solve(padre[p]),solve(T[p]));
}

int solve2(int p){

    int ans = 0;
    if(ispal[p])
    ans = solve(p);

    f(i,0,26)
        if(tree[p][i])
        ans = max( ans , solve2(tree[p][i]));

return ans;
}

int main(){
    freopen("in.c","r",stdin);

    int n;
    string a;

    while(cin >> n , n ){

        node = 1;
        clr(ispal,0);
        clr(tree,0);

        f(i,0,n)
        {   cin >> a;
        add(a);
        }

        aho();

    caso++;
    cout << solve2(0) << endl;
    }

    return 0;
}




/***************    F *******************/

/************** Elvis Rusnel Capia Quispe ***************/
#include <bits/stdc++.h>
#define f(i,x,y) for (int i = (x); i < (y); i++)
#define fd(i,x,y) for(int i = x; i>= y; i--)
#define FOR(it,A) for(typeof A.begin() it = A.begin(); it!=A.end(); it++)
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define vint vector<int>
#define pii pair<int,int>
#define vpii vector<pii>
#define ll long long
#define clr(A,x) memset(A, x, sizeof A)
#define pb push_back
#define fst first
#define snd second
#define ones(x) __builtin_popcount(x)
#define MOD 1000000007
#define INF 1000000000
#define HASH unsigned long long
#define bug1(x) cout<<#x<<" = "<<x<<endl
#define bug2(x,y) cout<<#x<<" = "<<x<<" "<<#y<<" = "<<y<<endl
#define bug3(x,y,z) cout<<#x<<" = "<<x<<" "<<#y<<" = "<<y<<" "<<#z<<" = "<<z<<endl
#define bug4(x,y,z,m) cout<<#x<<" = "<<x<<" "<<#y<<" = "<<y<<" "<<#z<<" = "<<z<<" "<<#m<<" = "<<m<<endl
#define sc(x) scanf("%d",&x)
#define N 1005

using namespace std;
int toi(string a){	int ans;  sscanf(a.c_str(),"%d",&ans);  return ans;  }
string tos(int a){	ostringstream st; st<<a; string ans = st.str(); return ans;   }

vint S;                                    // additional global variables
bool vis[N] ;
int dfs_low[N] , dfs_num[N];
int numSCC ,dfsNumberCounter ;
vector<vpii> adj , G;
int id[N];

void tarjanSCC(int u) {
  dfs_low[u] = dfs_num[u] = dfsNumberCounter++;      // dfs_low[u] <= dfs_num[u]
  S.pb(u);           // stores u in a vector based on order of visitation
  vis[u] = true;
  for (int j = 0; j < adj[u].size(); j++) {
    pii v = adj[u][j];
    if (dfs_num[v.first] == -1)
      tarjanSCC(v.first);
    if (vis[v.first])                                // condition for update
      dfs_low[u] = min(dfs_low[u], dfs_low[v.first]);
  }

  if (dfs_low[u] == dfs_num[u]) {         // if this is a root (start) of an SCC
   // printf("SCC %d:", numSCC);            // this part is done after recursion
    while (1) {
      int v = S.back(); S.pop_back(); vis[v] = false;
     // printf(" %d", v);
      id[v] = numSCC;
      if (u == v) break;
    }
    ++numSCC;
    //printf("\n");
} }

void build(int x){
    vis[x] = true;

    f(j,0,adj[x].size()){
    pii where = adj[x][j];
        if(id[x] != id[where.fst])
        G[id[x]].pb(pii(id[where.fst],where.snd));

        if(!vis[where.fst])
        build(where.fst);
    }
}

void dfs2(int x){
    vis[x] = true;

    f(j,0,G[x].size()){
    pii where = G[x][j];
        if(!vis[where.fst])
            dfs2(where.fst);
    }
    S.pb(x);
}

ll dp[N];
int main(){

        int tc , n , m , w ,x  ,y;
        sc(tc);

        while(tc--){
            scanf("%d %d",&n,&m);

            adj.assign(n,vpii());
            f(i,0,m){
                scanf("%d %d %d",&x,&y,&w); x--; y--;
            adj[x].pb(pii(y,w));
            }

              f(i,0,n)
              { dfs_num[i] = -1;
                dfs_low[i] = 0;
                vis[i] = false;
              }

              dfsNumberCounter = numSCC = 0;
              f(i,0,n)
                if (dfs_num[i] == -1)
                  tarjanSCC(i);

             G.assign(numSCC,vpii());
             f(i,0,n)
             vis[i] = false;

             f(i,0,n)
                if(!vis[i])
                    build(i);

            /*********SCC*///
             n = numSCC;

              f(i,0,n)
              vis[i] = false;
              S.clear();

              f(i,0,n)
                if(!vis[i])
                    dfs2(i);

            reverse(all(S));

            f(i,0,n)
            dp[i] = 0;

            f(i,0,n)
            {   int v = S[i];
                f(j,0,G[v].size()){
                pii where = G[v][j];
                dp[where.fst] = max(dp[where.fst] , where.snd + dp[v]);
                }
            }

            ll ans = 0;
            f(i,0,n)
            ans = max(ans,dp[i]);

        cout << ans << endl;
        }


    return 0;
}





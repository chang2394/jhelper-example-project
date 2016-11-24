#include "../library/lib.hpp"

const int ND = 2e5+10;
vi edges[ND];
int f[ND], dp[ND], n;
long long cost[ND];
long long dist[20][ND];
int par[20][ND];

class AT {
public:

	int get(int x){
		int val = cost[x];
//		pr("called",x);
		for(int h = 19; h >= 0; --h){
			if (par[h][x] == -1) continue;
//			pr(h,x,dist[h][x],par[h][x],val);
			if (dist[h][x] > val) continue;
			val -= dist[h][x];
			x = par[h][x];
		}
//		pr("found",x, f[x]);
		return f[x];
	}

	void dfs1(int x){
//		pr("called",x,edges[x]);
		par[0][x] = f[x];
		for(int h = 1; h < 20; h++){
			if (par[h-1][x] == -1){
				par[h][x] = -1;
				continue;
			}

			int y = par[h-1][x];
			par[h][x] = par[h-1][y];
			dist[h][x] = dist[h-1][x] + dist[h-1][y];
		}

		for(int i = 0; i < edges[x].size(); ++i)
			dfs1(edges[x][i]);
		int y = get(x);
		if (f[x] != -1) dp[f[x]]++;
		if (y != -1) dp[y]--;

//		pr(x,y);
	}

	int dfs2(int x){
		int ans = 0;
		for(int i = 0; i < edges[x].size(); ++i)
			ans += dfs2(edges[x][i]);

		dp[x] += ans;
		return dp[x];
	}

	void solve(std::istream& in, std::ostream& out) {
		in >> n;
		for(int i = 0; i < n; ++i)
			in >> cost[i];

		f[0] = -1;
		for(int i = 1; i < n; ++i){
			int a,b;
			in >> a >> b;
			edges[a-1].pb(i);
			f[i] = a-1;
			dist[0][i] = b;
		}

		dfs1(0);
		dfs2(0);
		for(int i = 0; i < n; ++i)
			out << dp[i] << " \n"[i+1 == n];

		for(int i = 0; i < ND; ++i) {
			dp[i] = 0;
			edges[i].clear();
		}
	}
};

#include "../library/lib.hpp"

const int ND = 112;
int cost[ND];
int sub[ND];

class Flowers {
public:
	void solve(std::istream& in, std::ostream& out) {
		int n,m;
		in >> n >> m;

		int ans = 0;
		for(int i = 0; i < n; ++i)
			in >> cost[i];
		for(int i = 0; i < m; ++i){
			int st,en;
			in >> st >> en;

			int add = 0;
			for(int j = st-1; j < en; ++j)
				add += cost[j];
			ans += max(add,0);
		}
		out << ans << "\n";
	}
};

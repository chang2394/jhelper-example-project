#include "../library/lib.hpp"

class Sample {
public:
	void solve(std::istream& in, std::ostream& out) {
		long long n,a,b,c;
		in >> n >> a >> b >> c;

		if (n%4 == 0){
			out << "0\n";
			return;
		}

		long long req = 4 - (n%4);
		long long cost[4];
		cost[0] = 0;
		cost[1] = min(a, 3LL*c);
		cost[2] = min(b, 2LL*c);
		cost[3] = c;

		cost[2] = min(2LL*cost[1],cost[2]);
		cost[3] = min(cost[2] + cost[1],cost[3]);
		out << cost[req] << "\n";
	}
};

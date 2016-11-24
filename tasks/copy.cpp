#include "../library/lib.hpp"

class copy {
public:
	void solve(std::istream& in, std::ostream& out) {
        long long n,a,b,c;
		in >> n >> a >> b >> c;

		long long req = 4 - (n%4);

		long long cost[4];
		cost[0] = 0;
		cost[1] = a;
		cost[2] = min(2*cost[1],b);
		cost[3] = min(cost[2] + cost[1],c);
		out << cost[req] << "\n";
	}
};

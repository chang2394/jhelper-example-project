#include "../library/lib.hpp"

class Mex {
public:
	void solve(std::istream& in, std::ostream& out) {
	    int n,m;
		in >> n >> m;

		int smallest = oo;
		for(int i = 0; i < m; ++i){
			int st, en;
			in >> st >> en;
			smallest = min(smallest,en-st+1);
		}

		out << smallest << "\n";
		int st = 0;
		for(int i = 0; i < n; ++i){
			out << st << " \n"[i+1 == n];
			st = (st+1)%smallest;
		}
	}
};

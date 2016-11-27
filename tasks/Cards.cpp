#include "../library/lib.hpp"

class Cards {
public:
	void solve(std::istream& in, std::ostream& out) {
		int TC;
		in >> TC;

		for(int tc = 0; tc < TC; ++tc){
			long long num;
			in >> num;

			int cnt = 0;
			while(!(num & 1)){
				num = num/2LL;
				++cnt;
			}

			out << ((cnt & 1) ? "Second Box\n" : "First Box\n");
		}
	}
};

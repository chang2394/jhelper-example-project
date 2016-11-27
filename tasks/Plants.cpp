#include "../library/lib.hpp"

int ini[3][3] = {{1,4,7}, {2,5,8}, {3,6,9}};
void multiply(int a[3][3],int b[3][3]){
	int res[3][3];
	for(int i = 0; i < 3; ++i){
		for(int j = 0; j < 3; ++j)
			res[i][j] = 0;
	}

	for(int i = 0; i < 3; ++i){
		for(int j = 0; j < 3; ++j){
			for(int k = 0; k < 3; ++k){
				res[i][j] = (res[i][j] + mul(a[i][k],b[k][j],mod))%mod;
			}
		}
	}

	for(int i = 0; i < 3; ++i){
		for(int j = 0; j < 3; ++j){
			a[i][j] = res[i][j];
		}
	}
}

void fp(int n,int a[3][3]){
	if (n == 1) return;
	fp(n/2,a);
	multiply(a,a);
	if (n & 1) multiply(a,ini);
}

int go(int n){
	if (n == 1)
		return 3;
	int a[3][3] = {{1,4,7}, {2,5,8}, {3,6,9}};
	fp(n-1,a);

//	praa(a,3,3);
	int ans = 0;
	for(int i = 0; i < 3; ++i){
		for(int j = 0; j < 3; ++j){
			ans = add(ans,a[i][j],mod);
		}
	}

	return ans;
}

class Plants {
public:
	void solve(std::istream& in, std::ostream& out) {
		int tc;
		in >> tc;
		while(tc--){
			int n;
			in >> n;
			out << go(n) << "\n";
		}
	}
};

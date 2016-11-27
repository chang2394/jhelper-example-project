#include "../library/lib.hpp"

struct node{
	int F,S;
	node(int a,int b):F(a),S(b){}
};

bool operator < (node a,node b){
	if (b.F == a.F) return (a.S > b.S);
	return (a.F < b.F);
}

int conv(char ch){
	return (int)(ch-'0');
}

string smallest(string &msg,int len){
	int n = sz(msg);
	priority_queue<ii,vector<ii>, greater<ii> > pq;
	int prev = -1;

	string ans = "";
	for(int x = len, y = 0; x > 0; --x){
		for(; y+x-1 < n; y++)
			pq.push(mp(conv(msg[y]),y));

		while(!pq.empty() and pq.top().S < prev)
			pq.pop();
		int v = pq.top().F;
		prev = pq.top().S;
		pq.pop();
		ans.pb((char)(v + '0'));
	}

	return ans;
}

string largest(string &msg,int len){
	int n = sz(msg);
	priority_queue<node> pq;
	int prev = -1;

	string ans = "";
	for(int x = len, y = 0; x > 0; --x){
		for(; y+x-1 < n; y++)
			pq.push(node(conv(msg[y]),y));

		while(!pq.empty() and pq.top().S < prev)
			pq.pop();
		int v = pq.top().F;
		prev = pq.top().S;

//		pr(x,y,v,prev);
		pq.pop();
		ans.pb((char)(v + '0'));
	}

	return ans;
}

class Numbers {
public:
	void solve(std::istream& in, std::ostream& out) {
		ios_base::sync_with_stdio(false);
		int TC;
		in >> TC;
		while(TC--){
			string msg;
			int rem;
			in >> msg >> rem;

			string sm = smallest(msg,sz(msg)-rem);
			string lm = largest(msg,sz(msg)-rem);

			out << sm << "\n";
			out << lm << "\n";
		}
	}
};

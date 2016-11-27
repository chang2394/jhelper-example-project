#include "../library/lib.hpp"

const int ND = (1 << 20);
int cap[ND];
long long seg[ND];

void build(int node,int st,int en){
	if (st == en){
		seg[node] = cap[st];
//		pr(st,en,node,seg[node],cap[st]);
		return;
	}

	int mid = (st+en)/2;
	build(2*node,st,mid);
	build(2*node+1,mid+1,en);
	seg[node] = (seg[2*node] + seg[2*node+1]);
}

int get(int node,int st,int en,int L,int R,int &val){
	if (st > R or en < L or st > en) return -1;
	int mid = (st+en)/2;

	if (seg[node] <= 0) return -1;
	if (st >= L and en <= R){
//		pr(st,en,L,R,val,seg[node]);
		if (st == en and seg[node] > val) return st;
		if (seg[node] <= val) {
			val -= seg[node];
			return -1;
		}

		if (seg[2*node] <= val) {
			val -= seg[2*node];
			return get(2*node+1,mid+1,en,L,R,val);
		}
		return get(2*node,st,mid,L,R,val);
	}

	int temp = get(2*node,st,mid,L,R,val);
	if (temp != -1) return temp;
	return get(2*node+1,mid+1,en,L,R,val);
}

void rem(int node,int st,int en,int L,int R){
	if (st > R or en < L or st > en) return;
	if (seg[node] == 0) return;
	if (st == en){
		seg[node] = 0;
		return;
	}

	int mid = (st+en)/2;
	rem(2*node,st,mid,L,R);
	rem(2*node+1,mid+1,en,L,R);
	seg[node] = (seg[2*node] + seg[2*node+1]);
}

long long sum(int node,int st,int en,int L,int R){
	if (st > R or en < L or st > en) return 0LL;
	if (st >= L and en <= R) return seg[node];

	int mid = (st+en)/2;
	return sum(2*node,st,mid,L,R) + sum(2*node+1,mid+1,en,L,R);
}

void sub(int node,int st,int en,int x,int val){
	if (val == 0) return;
	if (st == en){
		seg[node] -= val;
		return;
	}

	int mid = (st+en)/2;
	if (mid >= x) sub(2*node,st,mid,x,val);
	else sub(2*node+1,mid+1,en,x,val);
	seg[node] = (seg[2*node] + seg[2*node+1]);
}

void debug(int n){
	for(int i = 0; i < n; ++i){
		int v1 = sum(1,0,n-1,i,i);
		pr(i,v1);
	}
}

class Cola {
public:
	void solve(std::istream& in, std::ostream& out) {
		ios_base::sync_with_stdio(false);
		int TC;
		in >> TC;
		while(TC--) {
			int n, m;
			in >> n >> m;

			long long waste = 0LL;
			for (int i = 0; i < n; ++i)
				in >> cap[i];
			build(1, 0, n - 1);
//			debug(n);
			for (int i = 0; i < m; ++i) {
				int x, y, temp;
				in >> x >> y;
				x -= 1, temp = y;

				int pos = get(1, 0, n - 1, x, n - 1, temp);
//				pr(pos,x,y,temp);
				if (pos == -1) {
					waste += temp;
					rem(1, 0, n - 1, x, n - 1);
				}
				else {
					rem(1, 0, n - 1, x, pos - 1);
					sub(1, 0, n - 1, pos, temp);
				}

//				debug(n);
			}

			out << waste << "\n";
			for(int i = 0; i < n; ++i){
				int vv = sum(1,0,n-1,i,i);
				out << cap[i]-vv << " \n"[i+1 == n];
			}
		}
	}
};

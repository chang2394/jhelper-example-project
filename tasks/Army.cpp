#include "../library/lib.hpp"

/**
    left side - n
    right side - m
**/

/* code */
const int ND = 102;
const int MD = 11234;

int head[ND], to[MD], nxt[MD];
int matchL[ND], matchR[MD];
bool seen[MD];
int n,m,nEdges = 0;

inline void init(){
    nEdges = 0;
    memset(head,-1,sizeof(head));
    memset(matchL,-1,sizeof(matchL));
    memset(matchR,-1,sizeof(matchR));
}

inline void addEdge(int x,int y){
    to[nEdges] = y, nxt[nEdges] = head[x];
    head[x] = nEdges++;
}

bool path(int x){
    for(int i = head[x]; i >= 0; i = nxt[i]){
        int y = to[i];
        if (seen[y]) continue;
        seen[y] = true;

        if (matchR[y] < 0 or path(matchR[y])){
            matchR[y] = x;
            matchL[x] = y;
            return true;
        }
    }
    return false;
}

int bpm(){
    int ans = 0;
    for(int i = 0; i < n; ++i){
        memset(seen,false,sizeof(seen));
        if (path(i)) ++ans;
    }
    return ans;
}

bool sp[ND][ND], sw[ND][ND], pw[ND][ND];

void input(int tot, bool a[ND][ND], std::istream& in){
    for(int i = 0; i < tot; ++i){
        int k,temp;
        in >> k;
        for(int j = 0; j < k; ++j){
            in >> temp;
            a[i][temp-1] = true;
//            pr(i,temp-1);
        }
    }
}

bool valid(int x,int y,int tot){
    if (!sp[x][y]) return false;
    for(int i = 0; i < tot; ++i){
        if (sw[x][i] and pw[y][i]) {
//            pr(x,y,i,sw[x][i],pw[y][i]);
            return true;
        }
    }
    return false;
}

class Army {
public:
	void solve(std::istream& in, std::ostream& out) {
        TCASE(in){
            int a,b,c;
            in >> a >> b >> c;

            for(int i = 0; i < ND; ++i){
                for(int j = 0; j < ND; ++j)
                    sp[i][j] = sw[i][j] = pw[i][j] = false;
            }

            init();
            input(a,sp,in);
            input(a,sw,in);
            input(b,pw,in);

            n = a, m = b;
            for(int i = 0; i < a; ++i){
                for(int j = 0; j < b; ++j){
                    if (valid(i,j,c))
                        addEdge(i,j);
                }
            }

            int ans = bpm();
            out << ans << "\n";
        }
	}
};

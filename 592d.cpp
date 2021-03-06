//joyneel
#include<bits/stdc++.h>

using namespace std;

typedef pair<int,int>   II;
typedef vector< II >      VII;
typedef vector<int>     VI;
typedef vector< VI > 	VVI;
typedef long long int 	LL;

#define PB push_back
#define MP make_pair
#define F first
#define S second
#define SZ(a) (int)(a.size())
#define ALL(a) a.begin(),a.end()
#define SET(a,b) memset(a,b,sizeof(a))

#define si(n) scanf("%d",&n)
#define dout(n) printf("%d\n",n)
#define sll(n) scanf("%lld",&n)
#define lldout(n) printf("%lld\n",n)
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)

#define TRACE

#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
	cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
	const char* comma = strchr(names + 1, ',');cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}
#else
#define trace(...)
#endif

//FILE *fin = freopen("in","r",stdin);
//FILE *fout = freopen("out","w",stdout);

int vs[200005];
bool m[200005];
VII g[200005];
VII ng[200005];
LL edge=0,diameter=0,farnode;

bool dfs(int u){
	vs[u]=1;
	bool fl;
	fl=(m[u])?(true):(false);
	for(int i=0;i<SZ(g[u]);i++){
		int w=g[u][i].F;
        int e=g[u][i].S;
		if(!vs[w]){
			bool var=dfs(w);
			fl|=var;
			if(var){
				ng[u].PB(MP(w,e));
				ng[w].PB(MP(u,e));
				edge+=e*1LL;
			}
		}
	}
	return fl;
}

void dia(int u,LL l){
	vs[u]=1;
	if(l>diameter){
		diameter=l;
		farnode=u;
	}
	else if(l==diameter){
		farnode=min(u,farnode);
	}
	for(int i=0;i<SZ(ng[u]);i++){
		LL w=ng[u][i].F,e=ng[u][i].S;
		if(!vs[w])
			dia(w,l+e);
	}
}

int main(){
	int n,q,a,b,c;
	si(n);si(q);
	for(int i=0;i<q;i++){
		si(a);
		m[a]=true;
	}
	for(int i=0;i<n-1;i++){
		si(a);si(b);si(c);
		g[a].PB(MP(b,c));
		g[b].PB(MP(a,c));
	}
	dfs(a);
	SET(vs,0);
	farnode=a;
	dia(a,0);
	SET(vs,0);
	diameter=0,a=farnode;
	dia(a,0);
	dout(2*edge-diameter);
	return 0;
}

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

//#define TRACE

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
const int N = 100005;
int a[N],b[N];
set<II> s;
int main(){
	int n,k;
	si(n);si(k);
	for(int i=0;i<n;i++) si(a[i]);
	for(int i=0;i<n;i++) si(b[i]);
	int mn = INT_MAX;
	for(int i=0;i<n;i++) s.insert(MP(b[i]/a[i],i));
	while(k and cnt<n){
		int j = s.begin()->S;
		if(!vs[j]){
			vs[j];
			cnt++;
		}
		s.erase(s.begin());
		trace(j,b[j]/a[j]);
		int add = min(a[j] - b[j]%a[j],k);
		b[j] += add;
		k -= add;
		s.insert(MP(b[j]/a[j],j));
		trace(j,b[j]/a[j]);
		for(auto it=s.begin();it!=s.end();it++) trace(it->F,it->S);
	}	
	for(int i=0;i<n;i++) mn = min(mn,b[i]/a[i]);
	cout<<mn<<endl;
	return 0;
}

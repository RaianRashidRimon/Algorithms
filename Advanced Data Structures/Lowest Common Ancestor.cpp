#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<cstring>
#include<queue>
#include<fstream>
#include<sstream>
#include<stack>
#include<list>
#include<deque>
#include<bitset>
#include<utility>
#include<climits>
#include<iomanip>
#include<ctime>
#include<complex>
using namespace std;
#define FOR(i,a,b) for (int i=(a);i<(b);i++)
#define RFOR(i,a,b) for (int i=(b)-1;i>=(a);i--)
#define REP(i,n) for (int i=0;i<(n);i++)
#define RREP(i,n) for (int i=(n)-1;i>=0;i--)
#define inf INT_MAX/3
#define pb push_back
#define MP make_pair
#define all(a) (a).begin(),(a).end()
#define SET(a,c) memset(a,c,sizeof a)
#define CLR(a) memset(a,0,sizeof a)
#define pii pair<int,int>
#define pcc pair<char,char>
#define pic pair<int,char>
#define pci pair<char,int>
#define VS vector<string>
#define VI vector<int>
#define debug(x) cout<<#x<<": "<<x<<endl
#define MIN(a,b) (a>b?b:a)
#define MAX(a,b) (a>b?a:b)
#define pi 2*acos(0.0)
#define INFILE() freopen("in0.txt","r",stdin)
#define OUTFILE()freopen("out0.txt","w",stdout)
#define in scanf
#define out printf
#define ll long long
#define ull unsigned long long
#define eps 1e-9
#define MOD 1E9 +7
#define lim 4
#define MOD 1000000000
template<typename T>inline string toString(T a){
    ostringstream os("");
    os<<a;
    return os.str();}
template<typename T>inline ll toLong(T a){
    ll res;
    istringstream os(a);
    os>>res;
    return res;}
template<typename T>inline T  SQ(T a){
    return a*a;}
template<typename T>inline T gcd(T a, T b){
    if (b == 0)return a;
    else return gcd(b, a % b);}
template<typename T>inline ull bigmod(T a, T b, T m){
    if (b == 0)return 1;
    else if (b % 2 == 0)return S(bigmod(a, b / 2, m)) % m;
    else return (a % m*bigmod(a, b - 1, m)) % m;}
template<typename T>inline VS parse(T str){
    VS res;
    string s;
    istringstream os(str);
    while(os>>s)res.pb(s);
    return res;}
template<typename T>inline ull  dist(T A,T B){
    ull res=(A.x-B.x)*(A.x-B.x)+(A.y-B.y)*(A.y-B.y);
    return res;}
template<typename T>inline double cosAngle(T a,T b,T c){
    double res=a*a+b*b-c*c;
    res=res/(2*a*b);
    res=acos(res);
    return res;}
template<typename T>inline T power(T base,int po){
    T res=1;
    if(base==0)return 0;
    FOR(i,0,po)res*=base;
    return res;}
template<typename T>inline bool isOn(T mask,T pos){
    return mask&(1<<pos);}
template<typename T>inline int Off(T mask,T pos){
    return mask^(1<<pos);}
template<typename T>inline int On(T mask,T pos){
    return mask|(1<<pos);}
int par[30009][20];
int cost[30009];
bool vis [30009];
int lev [30009];
int strt [30009];
int End [30009];
int fat[30009];
int n;
VI adj[30005];
int gt;
int tree[150000];
void dfs(int ind, int par, int l){
    vis[ind]=1;
    fat[ind]=par;
    lev[ind]=l;
    strt[ind]=++gt;
    int sz=adj[ind].size();
    for(int i=0; i<sz; i++){
        int u=adj[ind][i];
        if(vis[u])continue;
        dfs(u,ind,l+1);}
    End[ind]=++gt;
    return ;}
void LCA (){
    int i,j;
    memset(par,-1,sizeof par);
    FOR(i,0,n)par[i][0]=fat[i];
    for(int j=1; (1<<j)<n; j++ ){
        for(int i=0; i<n; i++){
            int x=par[i][j-1];
            if(x>=0){
                par[i][j]=par[x][j-1];}}}}
int ans(int x, int y){
    cout<<x<<" has level "<<lev[x]<<endl;
    cout<<y<<" has level "<<lev[y]<<endl;;
    if(lev[x]<lev[y])swap(x,y);
    int dif=lev[x]-lev[y];
    for(int i=17; i>=0; i--){
        if(dif & (1<<i))x=par[x][i];}
    if(x==y)return x;
    if(fat[x]==fat[y] && fat[x]!=-1)return fat[x];
    int low=1,high=17;
    int mid;
    int res=100;
    int p=x,q=y;
    int log=log2(lev[p]);
    for (int i = log; i >= 0; i--)
        if (par[p][i] != -1 && par[p][i] != par[q][i])
            p = par[p][i], q = par[q][i];
    return fat[p];;}
void ini(){
    CLR(vis);
    CLR(tree);
    for(int i=0; i<=n; i++)adj[i].clear();
    gt=0;}
main(){
    int i,j,k;
    int a,b;
    int ks,cas;
    ini();
    scanf("%d",&n);
    FOR(i,0,n-1){
        scanf("%d%d",&a,&b);
        adj[a].pb(b);
        adj[b].pb(a);}
    dfs(0,-1,0);
    LCA();
    int q,typ,x,y;
    scanf("%d",&q);
    FOR(i,0,q){
        //debug(i);
        scanf("%d%d",&x,&y);
        int lca=ans(x,y);
        cout<<"LCA is "<<lca<<endl;}
    return 0;}


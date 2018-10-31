// g++ -std=c++14

#include<bits/stdc++.h>

typedef long long ll;
typedef long double lld;
using namespace std;

#define sd(x) scanf("%d",&x)
#define sd2(x,y) scanf("%d%d",&x,&y)
#define sd3(x,y,z) scanf("%d%d%d",&x,&y,&z)
#define endl "\n"
#define fi first
#define se second
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define LET(x, a)  __typeof(a) x(a)
#define foreach(it, v) for(LET(it, v.begin()); it != v.end(); it++)
#define MEMS(a,b) memset(a,b,sizeof(a))
#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define __ freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#define inf 1000000000000000001

#define tr(...) cout<<__FUNCTION__<<' '<<__LINE__<<" = ";trace(#__VA_ARGS__, __VA_ARGS__)

template<typename S, typename T>
ostream& operator<<(ostream& out,pair<S,T> const& p){out<<'('<<p.fi<<", "<<p.se<<')';return out;}

template<typename T>
ostream& operator<<(ostream& out,vector<T> const& v){
ll l=v.size();for(ll i=0;i<l-1;i++)out<<v[i]<<' ';if(l>0)out<<v[l-1];return out;}

template<typename T>
void trace(const char* name, T&& arg1){cout<<name<<" : "<<arg1<<endl;}

template<typename T, typename... Args>
void trace(const char* names, T&& arg1, Args&&... args){
const char* comma = strchr(names + 1, ',');cout.write(names, comma-names)<<" : "<<arg1<<" | ";trace(comma+1,args...);}

int n,a,b,to;
int grp[2000][2000];

int main(){
  cin>>n>>a>>b;
  if(n==1){
    cout<<"YES\n";
    cout<<0<<endl;
    return 0;
  }
  if(a!=1 and b!=1){
    cout<<"NO\n";
    return 0;
  }
  if(a==1 and b==1 and n>3){

    cout<<"YES\n";
    for(int i=1;i<n;i++){
      grp[i][i+1] = 1;
      grp[i+1][i] = 1;
    }
    for(int i=1;i<=n;i++){
      for(int j=1;j<=n;j++){
        cout<<grp[i][j];
      }cout<<endl;
    }
    return 0;
  }
  if(a==1 and b==1 and n<=3){
    cout<<"NO\n";
    return 0;
  }
  if(a==1){
    to = b;
  }
  else{
    to = a;
  }
  for(int i=to;i<=n;i++){
    for(int j = to;j<=n;j++){
      grp[i][j] = 1;
    }
    grp[i][i] = 0;
  }
  if(to==a){
    cout<<"YES\n";
    for(int i=1;i<=n;i++){
      for(int j=1;j<=n;j++){
        cout<<grp[i][j];
      }cout<<endl;
    }
  }
  else{
    cout<<"YES\n";
    for(int i=1;i<=n;i++){
      grp[i][i] = 1;
      for(int j=1;j<=n;j++){
        cout<<1 - grp[i][j];
      }cout<<endl;
    }
  }
  return 0;
}
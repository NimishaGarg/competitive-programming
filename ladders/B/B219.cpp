// g++ -std=c++14

#include<bits/stdc++.h>

typedef long long ll;
typedef long double lld;
using namespace std;

#define sd(x) scanf("%d",&x)
#define sd2(x,y) scanf("%d%d",&x,&y)
#define sd3(x,y,z) scanf("%d%d%d",&x,&y,&z)

#define fi first
#define se second
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define LET(x, a)  __typeof(a) x(a)
#define foreach(it, v) for(LET(it, v.begin()); it != v.end(); it++)

#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define __ freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);

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

ll p,d,temp,t2;

ll get(ll a){
  ll c=0;
  while(a%10==9){
    a/=10;
    c++;
  }
  return ((a+1)%10)*pow(10,c);
}

int main(){
  cin>>p>>d;
  temp = p;
  while(d>0 and p%10!=9){
    p--;
    d--;
    // tr(d,p);
    if(p%10==9){
      temp = p;
      break;
    }
  }
  if(temp%10!=9){
    cout<<temp<<endl;
    return 0;
  }
  while(d>0){
    t2 = get(p);
    // tr(d,p,t2);
    if(t2<0){
      break;
    }
    if(d-t2>=0){
      p-=t2;
      temp = p;
      d-=t2;
    }
    else{
      break;
    }
  }
  cout<<temp<<endl;
  return 0;
}
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


int n,arr[2000];

int get_maximum(){
  int temp =-2;
  int ind;
  for(int i=0;i<n;i++){
    if(arr[i]>temp and arr[i]!=-1){
      temp = arr[i];
      ind = i;
    }
  }
  return ind;
}

int get_mini(){
  int temp = 10000000;
  int ind;
  for(int i=0;i<n;i++){
    if(arr[i]<temp and arr[i]!=-1){
      temp = arr[i];
      ind = i;
    }
  }
  return ind;
}
int main(){
  cin>>n;
  for(int i=0;i<n;i++){
    cin>>arr[i];
  }
  for(int i=0;i<n-1;i++){
    if(i%2==0)
      arr[get_maximum()] = -1;
    else{
      arr[get_mini()] = -1;
    }
  }
  for(int i=0;i<n;i++){
    if(arr[i]!=-1){
      cout<<arr[i]<<endl;
      return 0;
    }
  }
}
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

const ll N = 5005;
ll arr[N],brr[N],n,temp;
unordered_map<ll,ll> mp;
vector<ll> cost;
ll inde[N];
ll done[N];
int curr = 0;

void pre(){
    for(int ind=curr-2;ind>=0;ind--){
        cost[ind] = min(cost[ind],cost[ind+1]);
    }
}

ll get(ll no){
    int ind = inde[no];
    return cost[ind];
}

int main(){ _
    cin>>n;
    for(ll i=0;i<n;i++){
        cin>>arr[i];
        brr[i] = arr[i];
    }
    temp = arr[n-1];
    sort(brr,brr+n);
    for(int i=0;i<n;i++){
        if(mp.find(brr[i])==mp.end()){
            mp[brr[i]] = curr;
            curr++;
        }
    }
    cost.resize(curr);
    for(int i=0;i<n;i++){
        inde[i] = mp[arr[i]];
    }
    for(ll i=n-1;i>=0;i--){
        for(ll j=0;j<n;j++){
            if(done[inde[j]]==1)continue;
            ll c = abs(arr[i] - arr[j]);
            ll ind = get(j);
            cost[inde[j]] = c+ind;
            done[inde[j]] = 1;
        }
        for(int j=0;j<curr;j++){
            done[j] = 0;
        }
        pre();
    }
    cout<<cost[0]<<endl;
    return 0;
}
// g++ -std=c++14

/*

Today might be the chance to grasp the chance to let your talent bloom.
May be tomorrow, the day after, or next year...
May be even when you are 30. I'm not sure if physique has anything to do with it
but if you think that it will never come, it probably never will.

- Tooru Oikawa.

*/


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
#define all(c) c.begin(),c.end()
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

#define int ll

const int N = 2e6 + 10;
int n;
vector<string> v;
vector<int> arr;
map<int, vector<int> > m;
stack<pair<int, int> > s;

bool check(int i){
    auto temp = s.top();
    int diff = i - temp.fi;
    int sz = v[temp.se].size();
    if(diff <= sz-1){
        return true;
    }
    return false;
}

int32_t main(){ _
    cin >> n;
    arr.resize(N, -1);
    int mx = -1;
    for(int i = 0; i < n; i++){
        string temp;
        cin >> temp;
        v.pb(temp);
        int cnt;
        cin >> cnt;
        for(int j = 0; j < cnt; j++){
            int a;
            cin >> a;
            a--;
            if(arr[a] == -1){
                arr[a] = i;
            }
            else{
                if((int)v[arr[a]].size() < (int)temp.size()){
                    arr[a] = i;
                }
            }
            mx = max(mx, a + (int)temp.size());
        }
    }

    string ans = "";
    for(int i = 0; i < mx; i++){
        if(arr[i] != -1){
            s.push(mp(i, arr[i]));
        }
        while(!s.empty() and !check(i)){
            s.pop();
        }

        if(s.empty()){
            ans += 'a';
            continue;
        }
        auto temp = s.top();
        int diff = i - temp.fi;
        ans += v[temp.se][diff];
    }
    cout << ans << endl;
}
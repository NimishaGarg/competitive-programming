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

// #define int ll

const int N = 40;

int n;
int arr[N];
bool coor[301][301];
bool dp[8][301][301][5][30];
int q = 0;

void f(int dir, int x, int y, int len, int ind){
    coor[x][y] = 1;
    if(dp[dir][x][y][len][ind] != 0){
        return;
    }
    if(len == 0 and ind == n-1){
        return;
    }
    if(len == 0){
        if(dir == 0){
            f(1, x-1, y+1, arr[ind+1], ind+1);
            f(7, x+1, y+1, arr[ind+1], ind+1);
        }
        if(dir == 1){
            f(0, x, y+1, arr[ind+1], ind+1);
            f(2, x-1, y, arr[ind+1], ind+1);
        }
        if(dir == 2){
            f(1, x-1, y+1, arr[ind+1], ind+1);
            f(3, x-1, y-1, arr[ind+1], ind+1);
        }
        if(dir == 3){
            f(2, x-1, y, arr[ind+1], ind+1);
            f(4, x, y-1, arr[ind+1], ind+1);
        }
        if(dir == 4){
            f(3, x-1, y-1, arr[ind+1], ind+1);
            f(5, x+1, y-1, arr[ind+1], ind+1);
        }
        if(dir == 5){
            f(4, x, y-1, arr[ind+1], ind+1);
            f(6, x+1, y, arr[ind+1], ind+1);
        }
        if(dir == 6){
            f(5, x+1, y-1, arr[ind+1], ind+1);
            f(7, x+1, y+1, arr[ind+1], ind+1);
        }
        if(dir == 7){
            f(0, x, y+1, arr[ind+1], ind+1);
            f(6, x+1, y, arr[ind+1], ind+1);
        }
    }
    else{
        if(dir == 0){
            f(dir, x, y + 1, len - 1, ind);
        }
        if(dir == 1){
            f(dir, x-1, y+1, len-1, ind);
        }
        if(dir == 2){
            f(dir, x-1, y, len-1, ind);
        }
        if(dir == 3){
            f(dir, x-1, y-1, len-1, ind);
        }
        if(dir == 4){
            f(dir, x, y-1, len-1, ind);
        }
        if(dir == 5){
            f(dir, x+1, y-1, len-1, ind);
        }
        if(dir == 6){
            f(dir, x+1, y, len-1, ind);
        }
        if(dir == 7){
            f(dir, x+1, y+1,len-1, ind);
        }
    }
    dp[dir][x][y][len][ind] = 1;
}

int32_t main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        arr[i]--;
    }
    f(0, 149, 149, arr[0], 0);
    int cnt = 0;
    for(int i = 0; i <= 300; i++){
        for(int j = 0; j <= 300; j++){
            if(coor[i][j] == 1){
                cnt ++;
            }
        }
    }
    cout << cnt << endl;
}
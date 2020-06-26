//Compile: g++ -g -Wshadow -Wall main.cpp -o a.exe -O2 -Wno-unused-result
//Build: g++ -g -Wshadow -Wall -o "%e" "%f" -g -fsanitize=address -fsanitize=undefined -D_GLIBCXX_DEBUG
//Compile and run: g++ -g -Wshadow -Wall main.cpp -o a.exe -O2 -Wno-unused-result && a.exe

#include <bits/stdc++.h>

#define gc getchar_unlocked
#define ll long long
#define ld long double
#define pii std::pair<int,int>
#define pl std::pair<long,long>
#define vi std::vector<int>
#define vl std::vector<ll>
#define vpii std::vector<pii>
#define vpl std::vector<pl>
#define vvi std::vector<vi>
#define vvl std::vector<vl>
#define mii std::map<int, int>
#define pqb std::priority_queue<int>
#define pqs std::priority_queue<int, vi, std::greater<int>>

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define F first
#define S second

#define PI 3.14159265358979323846264
#define MOD 1e9+7
#define INF 1e18

#define fo(i, n) for (int i = 0; i < n; ++i)
#define Fo(i, k, n) for (int i = k; k < n ? i < n : i > n; k < n ? ++i: --i)
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, 0, sizeof(x))
#define deb(x) cout << #x << "=" << x << endl
#define sortall(x) sort(all(x))
#define tr(it, a) for(auto it = a.begin(); it != a.end(); ++it)
#define ps(x, y) std::fixed << setprecision(y) << x
#define setbits(x) __builtin_popcountll(x)
#define zrobits(x) __builtin_ctzll(x)
#define mk(arr, n, type) type *arr = new type[n]

std::mt19937_64 rng(std::chrono::high_resolution_clock::now().time_since_epoch().count());

void setup(){     
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);

    #ifdef LOCAL_PROJECT                    //run with -DLOCAL_PROJECT drung compilation
        freopen("input.txt", "r", stdin);
    #else
        #ifndef ONLINE_JUDGE               //runs automatically for supported online judges
            freopen("input.txt", "r", stdin);
            freopen("output.txt", "w", stdout);
        #endif
    #endif 
}

void solve();

int main(){
    setup();

    ll t = 1;

    std::cin>>t;    //Comment this if testCases = 1

    while(t--){
        solve();
        std::cout<<'\n';
    }
    return 0;
}

using namespace std;

void solve(){
}

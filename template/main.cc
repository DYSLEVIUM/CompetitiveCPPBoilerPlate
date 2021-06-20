#define _USE_MATH_DEFINES
#pragma GCC optimize("Ofast,fast-math,unroll-loops")

#include <bits/stdc++.h>

//  debuging
#ifdef DYSLEVIUM
#define deb(x) std::cerr << '\n' \
                         << #x << " = " << x << '\n'
#else
#define deb(x)
#endif

//  initial setup
inline void setup() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);

#ifdef DYSLEVIUM
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  freopen("error.txt", "w", stderr);
#endif
}

inline void solve();

int main(int argc, char* argv[]) {
    setup();

    long long t = 1;
    std::cin >> t;

    while (t--)
        solve();

    return 0;
}
//  Compile and run: g++ -std=c++17 -g -Wshadow -Wall practice.cpp -D DYSLEVIUM -o a -Ofast -Wno-unused-result && ./a

using namespace std;

inline void solve() {
}

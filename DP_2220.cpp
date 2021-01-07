#include "bits/stdc++.h"
using namespace std;
#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename \
  enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge { c b, e; };
sim > rge<c> range(c i, c j) { return rge<c> {i, j}; }
sim > auto dud(c* x) -> decltype(cerr << *x, 0);
sim > char dud(...);
struct debug {
#ifdef LOCAL
  ~debug() { cerr << endl; }
  eni( != ) cerr << boolalpha << i; ris;
}
eni( == ) ris << range(begin(i), end(i));
}
sim, class b dor(pair < b, c > d) {
  ris << "(" << d.first << ", " << d.second << ")";
}
sim dor(rge<c> d) {
  *this << "[";
  for (auto it = d.b; it != d.e; ++it)
    *this << ", " + 2 * (it == d.b) << *it;
  ris << "]";
}
#else
  sim dor(const c&) { ris; }
#endif
};
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
///////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////
#define int long long
int dp[20][12][2];

int calculate(string s) {

  int n = s.length();

  if (n == 1) {
    int curr = 0;
    for (int i = 1; i <= (s[0] - '0'); i++) {
      curr++;
    }
    return curr;
  }

  for (int i = n - 1; i >= 0; i--) {

    for (int type : {0, 1}) {
      for (int j = 0; j < 10; j++) {
        if (i == n - 1) {
          dp[i][j][type] = 1;
          continue;
        }
        for (int k = 0; k < 10; k++) {
          if (type == 1 && j == k && k == (s[i + 1] - '0'))
            break;
          if (j == k) {
            continue;
          }
          if (type == 1 && k == (s[i + 1] - '0')) {
            dp[i][j][1] += dp[i + 1][k][1];
            break;
          }
          dp[i][j][type] += dp[i + 1][k][0];
        }
      }
    }
  }
  int last = (s[0] - '0');
  int ans = 0;

  for (int i = 1; i < n; i++) {
    for (int j = 1; j < 10; j++) {
      ans += dp[i][j][0];
    }
  }
  for (int i = 1; i < last; i++) {
    ans += (dp[0][i][0]);
  }
  ans += dp[0][last][1];
  return ans;

}
int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int v1, v2;
  cin >> v1 >> v2;
  v1--;
  if (v1 == -1) {
    string tt =  to_string(v2);
    cout << calculate(tt) + 1 << endl;
    return 0;
  }
  string a = to_string(v1);
  string b = to_string(v2);

  int ans1 = calculate(b);
  memset(dp, 0, sizeof(dp));
  int ans2 = calculate(a);

  cout << ans1 - ans2 << endl;
}

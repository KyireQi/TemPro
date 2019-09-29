## 原理
[洛谷P4777题解](https://www.luogu.org/problemnew/solution/P4777)

## 实现
```cpp
#include<iostream>
using namespace std;
typedef __int128 ll;

void exgcd(ll a, ll b, ll& g, ll& x, ll& y) {
	if (b == 0) {
		g = a;
		x = 1;
		y = 0;
		return;
	}
	exgcd(b, a % b, g, y, x);
	y -= (a / b) * x;
}

bool flag = false;
ll a1, a2, n1, n2;

ll abs(ll x) {
	return x > 0 ? x : -x;
}

void china() {
	ll d = a2 - a1;
	ll g, x, y;
	exgcd(n1, n2, g, x, y);
	if (d % g == 0) {
		x = ((x * d / g) % (n2 / g) + (n2 / g)) % (n2 / g);
		a1 = x * n1 + a1;
		n1 = (n1 * n2) / g;
	}
	else
		flag = true;
}

int n;
long long as[100001];
long long ns[100001];

ll realchina() {
	a1 = as[0];
	n1 = ns[0];
	for (ll i = 1; i < n; i++) {
		a2 = as[i];
		n2 = ns[i];
		china();
		if (flag)
			return -1; //无解 
	}
	return a1;
}

int main() {
	cin >> n;
	flag = false;
	for (ll i = 0; i < n; i++)
		cin >> ns[i] >> as[i];
	cout << (long long)realchina() << endl; //不到输出不换int128 
}
```
* 注意：返回的是最小非负整数解，有些题目需要特判
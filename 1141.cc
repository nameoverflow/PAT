#include <bits/stdc++.h>
#include <cstring>
#include <cstdio>
#include <cmath>

using namespace std;
using ull = unsigned long long;

unordered_map<string, int> intern;
vector<string> trace;
string& tr(int i) {
	return trace[i];
}

int in(string &s) {
	if (intern.find(s) == intern.end()) {
		intern[s] = trace.size();
		trace.push_back(s);
	}
	return intern[s];
}
int in(string &&s) {
	if (intern.find(s) == intern.end()) {
		intern[s] = trace.size();
		trace.push_back(s);
	}
	return intern[s];
}

unordered_map<int, ull> sch;
unordered_map<int, int> num;
using P = pair<ull, int>;
bool comp(P l, P r) {
		return l.first > r.first || (l.first == r.first && num[l.second] < num[r.second]) || (l.first == r.first && num[l.second] == num[r.second] && tr(l.second) < tr(r.second));
	}
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		char id[30], ins[30];
		double sc;
		scanf("%s %lf %s", id, &sc, ins);
		
		switch (id[0]) {
			case 'T': sc *= 1.5; break;
			case 'B': sc /= 1.5; break;
			default:;
		}
		for (int i = 0; ins[i]; i++) {

			if (ins[i] >= 'A' && ins[i] <= 'Z') ins[i] = ins[i] - 'A' + 'a';
		}
		
		sch[in(ins)] += floor(sc);
		num[in(ins)] ++;
	}
	
	vector<P> rk;
	rk.reserve(sch.size());
	for (auto s : sch) {
		rk.push_back(make_pair(s.second, s.first));
	}
	
	sort(rk.begin(), rk.end(), comp);
	
	cout << rk.size() << endl;
	if (rk.empty()) return 0;
	
	int pre = rk[0].first;
	for (int i = 0, r = 1; i < rk.size(); i++) {
		if (rk[i].first != pre) {
			r = i + 1;
			pre = rk[i].first;
		}
		printf("%d %s %llu %d\n", r, tr(rk[i].second).c_str(), rk[i].first, num[rk[i].second]);

	}
}
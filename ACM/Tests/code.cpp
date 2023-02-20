#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
vector<int>ans[N]; 
int num[N];
int main(){
	int n, d, c;
	cin >> n >> d >> c;
		if (d == 0) {
		if (c != n) {cout << "No"; return 0;}
		cout << "Yes"; return 0;
	}
	if (d == 1) {
		if (n & 1) {cout << "No"; return 0;}
		if (c != n / 2) {cout << "No" ; return 0;}
		cout << "Yes" << endl;
		for (int i = 1; i <= n; i++) {
			cout << i + ((i & 1) ? 1 : -1) << endl;
		}return 0;
	}
	if (c * (d + 1) > n) {cout << "No"; return 0;}
	if ((n & 1) && (d & 1)) {cout << "No" ; return 0;}
	int nu = c - 1;
	int po = 1;
	while(nu --){
		for (int i = po; i <= po + d; ++i){
			for (int j = po; j <= po + d; ++j){
				if (i != j){
					ans[i].push_back(j);
				} 
			}
		}
		po += d + 1;
	}
	int res = n - po + 1;
	if ((res & 1) && (d & 1)){
		cout << "No";
		return 0;
	}
	int dd = d - 2;
	for (int i = po; i <= n; ++i){
            num[i] = 2;
            if (i == po){
                ans[i].push_back(n);
                ans[i].push_back(i + 1);
            }else if (i == n){
                ans[i].push_back(i - 1);
                ans[i].push_back(po);
            }else{
                ans[i].push_back(i + 1);
                ans[i].push_back(i - 1);
            }
        }
        int f = 0;
    	if (dd & 1){
    		for (int j = po; j <= n; ++j){
    			int xx = (j - po + res / 2) % res + po;
    			if (num[xx] >= d) continue;
    			num[j] ++;
    			num[xx] ++;
    			ans[j].push_back(xx);
				ans[xx].push_back(j);
			}
			dd --;
		}
		for (int i = 1; i <= dd; ++i){
			for (int j = po; j <= n; ++j){
			if (num[j] < d){
				int xx = (j - po + i + 1) % res + po;
				num[j]++;
				num[xx]++;
				ans[j].push_back(xx);
				ans[xx].push_back(j);	
			}
		}
		if (f) break;
	}
	if (f) cout << "No";
	else{
		cout << "Yes" << '\n';
		for (int i = 1; i <= n; ++i){
			sort(ans[i].begin(),ans[i].end());
			for (int j = 0; j < ans[i].size(); ++j){
				cout <<	ans[i][j] << ' ';
			}
			puts(""); 
		}
	}
}
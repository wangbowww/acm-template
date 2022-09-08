#include<iostream>
#define endl "\n"
using namespace std;
int tar[101];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	int m = 0, sign = 0, k = 0, l = 0, r = 0;
	cin >> m;//读入随机生成的操作次数（限定在1e6之内）
	for (int i = 1; i <= 100; ++i) cin >> tar[i];//读入随机生成的100个数
	for (int i = 1; i <= m; ++i) {
		cin >> sign;
		if (sign == 1) {//update
			cin >> l >> r >> k;//每次增加的数k限定在1-10
			for (int i = l; i <= r; ++i) {
				tar[i] += k;
			}
		}
		else if (sign == 2) {//ask区间l到r的和
			cin >> l >> r;
			int temp = 0;
			for (int i = l; i <= r; ++i) {
				temp += tar[i];
			}
			cout << temp << endl;
		}
	}
	return 0;
}
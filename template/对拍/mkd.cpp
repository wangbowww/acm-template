#include<iostream>
#include<ctime>
using namespace std;
int main()
{
	srand(time(nullptr));
	int m = rand() % 10000 + 1;
	cout << m << endl;
	int k = 0, l = 0, r = 0;
	for (int i = 1; i <= 100; ++i) {
		cout << rand() % 10 + 1 << " ";
	}
	cout << endl;
	for (int i = 1; i <= m; ++i) {
		int sign = rand() % 2;//生成奇数就调用update，生成偶数就调用ask
		if (sign == 0) sign = 2;
		cout << sign << endl;
		if (sign == 1) {//update
			l = rand() % 100 + 1;
			r = rand() % (101 - l) + l;//r>=l，保证区间合法
			k = rand() % 10 + 1;
			cout << l << " " << r << " " << k << endl;
		}
		else if (sign == 2) {//ask
			l = rand() % 100 + 1;
			r = rand() % (101 - l) + l;//r>=l，保证区间合法
			cout << l << " " << r << endl;
		}
	}
	return 0;
}
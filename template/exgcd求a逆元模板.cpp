//求ax同余1(mod b)的解，即a在mod b意义下的逆元

#include<bits/stdc++.h>
using namespace std;
void exgcd(int a, int b, int& x, int& y) {
  if (b == 0) {
    x = 1, y = 0;
    return;
  }
  exgcd(b, a % b, y, x);
  y -= a / b * x;
}
int main()
{
	int a,b,x,y;
	cin >> a >> b;
	exgcd(a,b,x,y);
	printf("%d",(x%b+b)%b);
	return 0;
 } 

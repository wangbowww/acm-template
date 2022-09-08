//浮点二分，限定次数

#include<bits/stdc++.h>
using namespace std;
int t;
int a,b,c;
double calc(double x){
	return a*x*x + b*x + c;
}
int main()
{
	
	cin >> t;
	while(t--){
		cin >> a >> b >> c;
		double l = -1e9, r = 1e9;
		for(int i=1;i<=200;i++){
			double m1 = (r-l) / 3 + l, m2 = (r-l) / 3 * 2 + l;
			if(calc(m1)>calc(m2)){	
				l = m1;
			}else r = m2;
		}
		printf("%.10f\n",calc(l));
	}
	return 0;
}
#include<iostream>
using namespace std;

int fun(int n){
	int cnt = 1;
	while(n != 1){
		if(n % 2 == 0){
			n = n / 2;
		}
		else{
			n = 3 * n + 1;
		}
		cnt++;
	}
	return cnt;
}

int main()
{

	int a = 0, b = 0;
	while(cin >> a >> b){
        if(a > b){
            int temp = a;
            a = b;
            b = temp;
        }
        int res = 0;
        for(int i = a; i <= b; ++i){
            if(res < fun(i))
            	res = fun(i);
        }
        cout << a << " " << b << " " << res << endl;
	}
	return 0;
}

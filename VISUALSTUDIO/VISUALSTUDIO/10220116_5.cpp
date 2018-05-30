#include<iostream>
#define MAX 1135
using namespace std;

int main() {
	int x,carry=0;
	int ans[MAX];
	bool t ;
	
	
	while (1) {//因為沒有設定結束(?
		t = false;
		memset(ans, 0, sizeof(int)*MAX);//初始化0
		ans[0] = 1;//設定1(因為相乘)
		cin >> x;//輸入階乘數
		cout << x << "!" << endl;
		while (x > 1) {//從最大開始乘
			for (int i = 0; i < MAX; i++)//每一位相乘
				if (ans[i] != 0)
					ans[i] = ans[i] * x;
			for (int i = 0,carry=0; i<MAX; ++i) {//對齊位數
				ans[i] += carry;
				carry = ans[i] / 10;
				ans[i] %= 10;
			}//for
			x--;
			
		}//while(x>1)
		 //--------輸出--------
		for (int i = MAX-1; i >= 0; i--) {
			if (ans[i] != 0)
				t = true;
			if (t) {

				cout << ans[i];
			}
			
			
		}//for
		cout << endl;
	}//while(1)


}//main


#include<iostream>
#define MAX 1135
using namespace std;

int main() {
	int x,carry=0;
	int ans[MAX];
	bool t ;
	
	
	while (1) {//�]���S���]�w����(?
		t = false;
		memset(ans, 0, sizeof(int)*MAX);//��l��0
		ans[0] = 1;//�]�w1(�]���ۭ�)
		cin >> x;//��J������
		cout << x << "!" << endl;
		while (x > 1) {//�q�̤j�}�l��
			for (int i = 0; i < MAX; i++)//�C�@��ۭ�
				if (ans[i] != 0)
					ans[i] = ans[i] * x;
			for (int i = 0,carry=0; i<MAX; ++i) {//������
				ans[i] += carry;
				carry = ans[i] / 10;
				ans[i] %= 10;
			}//for
			x--;
			
		}//while(x>1)
		 //--------��X--------
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


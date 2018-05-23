#include <iostream>
#include <stack>
#include "calculate.h"
using namespace std;

bool parenthesesCorrect(char*, int);
//bool opCorrect(char*, int);
double comput(char*, int);

struct node {
	char op = '/0';
	int number = 0;
	int type = 0;//type2 = operator,type1 = number
};
void inToPostfix(node*, node*); // 中序轉後序 
int priority(char); // 運算子優先權
double eval(node*);
double cal(char, double, double);

void calculate() {
	int num, x;
	char func[MAXfuncLen], now;
	cin >> num;	//輸入算式數
	now = cin.get();//讀掉第一個enter
	while (num > 0) {//輸入第num個算式

		x = 0;//initial

		memset(func, '\0', sizeof(char)*MAXfuncLen);//初始化NULL

		now = cin.get();

		while (now != '\n') {//如果還沒結束讀到enter繼續讀
			func[x] = now;
			x++;//next
			now = cin.get();
		}//while
		 /*for(int i=0;i<x+1;i++)
		 cout << func[i];*/
		 //測試是否錯誤
		 //1.括弧不成對
		 //2.運算子數量位置
		x++;
		if (parenthesesCorrect(func, x) /*&& opCorrect(func, x)*/)//沒錯運算輸出
			cout << comput(func, x)<<endl;
		else
			cout << "erro" << endl;

		num--;

	}
	cout << "fin";
	system("pause");


}
bool parenthesesCorrect(char* func, int x) {
	int temp = 0;
	for (int i = 0; i < x && temp >= 0; i++) {
		if (func[i] == '(') {
			temp++;

		}
		if (func[i] == ')')
			temp--;
	}//for

	if (temp != 0)
		return false;//不成對
	return true;//成對

}//bool parenthesesCorrect
 //bool opCorrect(char*) {
 //
 //
 //
 //
 //}
double comput(char* func, int x) {
	//轉成方便計算的陣列並計算後序
	node thearray[MAXfuncLen];
	int last = 1;
	for (int i = 0, j = 0; i < x; i++) {
		if (func[i] <= '9'&& func[i] >= '0') {//處理數字
			if (last == 1) {
				thearray[j].number = thearray[j].number * 10 + (int)func[i] - '0';

			}//if(last==1)
			else {
				j++;
				thearray[j].number = (int)func[i] - '0';
			}//else
			thearray[j].type = 1;
			last = 1;

		}//if 0~9
		else {//處理非數字
			if (i != 0)
				j++;
			thearray[j].op = func[i];
			thearray[j].type = 2;
			last = 0;
		}//else

	}



	return eval(thearray);

}//comput(char*,int)

void inToPostfix(node* infix, node* postfix) {
	stack<node> opstack;
	int i, j, top;
	node temp;
	for (i = 0, j = 0, top = 0; infix[i + 1].type != 0; i++) {
		
		if (infix[i].op == '(') {
			opstack.push(infix[i]);
		}
		else if (infix[i].op == '+' || infix[i].op == '-' || infix[i].op == '*' || infix[i].op == '/') {
			
			if (!opstack.empty()) {
				while (priority(opstack.top().op) >= priority(infix[i].op)) {
					postfix[j++] = opstack.top();
					opstack.pop();
					if (opstack.empty()) {
						break;
					}
				}
			}
			opstack.push(infix[i]); // 存入堆疊 
		}
		else if (infix[i].op == ')') {
			while (opstack.top().op != '(') { // 遇 ) 輸出至 ( 
				
				postfix[j++] = opstack.top();
				opstack.pop();
			}
			opstack.pop();  // 不輸出 ( 
		}
		else if(infix[i].type==1){
			postfix[j++] = infix[i];
			//cout <<" "<< infix[i].number;
		}

	}
	while (!opstack.empty()) {
		postfix[j++] = opstack.top();
		opstack.pop();
	}
}

int priority(char op) {
	switch (op) {
	case '+': case '-': return 1;
	case '*': case '/': return 2;
	default:            return 0;
	}
}

double eval(node* infix) {
	node postfix[MAXfuncLen];
	node opnd[2];
	double stack[MAXfuncLen];
	memset(stack, 0.0, sizeof(double)*MAXfuncLen);//初始化0.0

	inToPostfix(infix, postfix);
	//for (int j = 0; postfix[j].type != 0; j++) {
	//	if (postfix[j].type == 1)
	//		cout << postfix[j].number<<"("<<j << ")";
	//	else if (postfix[j].type == 2)
	//		cout << postfix[j].op << "(" << j << ")";
	////輸出debug碼
	//}
	int top, i;
	for (top = 0, i = 0; postfix[i].type != 0; i++) {
		if (postfix[i].op == '+' || postfix[i].op == '-' || postfix[i].op == '*' || postfix[i].op == '/') {
			stack[top - 1] = cal(postfix[i].op, stack[top - 1], stack[top]);
			top--;

		}
		else {
			opnd[0] = postfix[i];
			stack[++top] = (double)opnd[0].number; //將字串中的數字轉換為 double 型態的浮點數
		}
	}

	return stack[top];
}

double cal(char op, double p1, double p2) {
	switch (op) {
	case '+': return p1 + p2;
	case '-': return p1 - p2;
	case '*': return p1 * p2;
	case '/': return p1 / p2;
	}
}
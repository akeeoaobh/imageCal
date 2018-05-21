#include<iostream>
#define MAX 128
using namespace std;
bool parenthesesCorrect(char*,int);
//bool opCorrect(char*, int);
double comput(char*,int);

struct node {
	char op='/0';
	int number=0;
	int type=0;//type1 = operator,type2 = number
};
void inToPostfix(node*, node*); // �������� 
int priority(char); // �B��l�u���v
double eval(node*);
double cal(char, double, double);
int main() {
	int num,x;
	char func[MAX],now;
	cin >> num;	//��J�⦡��
	now = cin.get();//Ū���Ĥ@��enter
		while (num > 0) {//��J��num�Ӻ⦡
			
			x = 0;//initial

			memset(func, '\0', sizeof(char)*MAX);//��l��NULL

			now = cin.get();

			while (now!='\n') {//�p�G�٨S����Ū��enter�~��Ū
				func[x] = now;
				x++;//next
				now = cin.get();
			}//while
			/*for(int i=0;i<x+1;i++)
				cout << func[i];*/
			//���լO�_���~
			//1.�A��������
			//2.�B��l�ƶq��m
			x++;
			if (parenthesesCorrect(func, x ) /*&& opCorrect(func, x)*/)//�S���B���X
				cout<<comput(func,x);
			else
				cout << "erro";
			
			num--;
			
		}
		cout << "fin";
		system("pause");


}
bool parenthesesCorrect(char* func, int x) {
	int temp=0;
	for (int i = 0; i < x && temp>=0; i++) {
		if (func[i] == '(') {
			temp++;
			
		}
		if (func[i] == ')') 
			temp--;		
	}//for

	if (temp != 0)
		return false;//������
	return true;//����

}//bool parenthesesCorrect
//bool opCorrect(char*) {
//
//
//
//
//}
double comput(char* func,int x) {
	//�ন��K�p�⪺�}�C�íp����
	node thearray[MAX];
	int last = 1;
	for (int i = 0,j=0; i < x;i++) {
		if (func[i] <= '9'&& func[i] >= '0') {//�B�z�Ʀr
			if (last == 1) {
				thearray[j].number = thearray[j].number * 10 + (int)func[i] - '0';
				
			}//if(last==1)
			else {
				j++;
				thearray[j].number = (int)func[i]-'0';
			}//else
			thearray[j].type = 1;
			last = 1;

		}//if 0~9
		else {//�B�z�D�Ʀr
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
	node stack[MAX];
	int i, j, top;
	for (i = 0, j = 0, top = 0; infix[i+1].type != 0; i++) {
		if (infix[i].op=='(') {
			stack[++top] = infix[i];
		}
		else if (infix[i].op == '+' || infix[i].op == '-' || infix[i].op == '*' || infix[i].op == '/') {
			while (priority(stack[top].op) >= priority(infix[i].op)) {
				postfix[j++] = stack[top--];
			}
			stack[++top] = infix[i]; // �s�J���| 
		}
		else if(infix[i].op == ')') {
			while (stack[top].op != '(') { // �J ) ��X�� ( 
				postfix[j++] = stack[top--];
				}
				top--;  // ����X ( 
		}
		else {
			postfix[j++] = infix[i];
		}
		
	}
	while (top > 0) {
		postfix[j++] = stack[top--];
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
	node postfix[MAX];
	node opnd[2] ;
	double stack[MAX] ;
	memset(stack, 0.0 , sizeof(double)*MAX);//��l��0.0

	inToPostfix(infix, postfix);
	/*for (int j = 0; postfix[j].type != 0; j++) {
		if (postfix[j].type == 1)
			cout << postfix[j].number<<"-"<<j << "=";
		else if (postfix[j].type == 2)
			cout << postfix[j].op << "-" << j << "=";
			��Xdebug�X
	}*/
	int top, i;
	for (top = 0, i = 0; postfix[i].type != 0; i++) {
		if (postfix[i].op == '+' || postfix[i].op == '-' || postfix[i].op == '*' || postfix[i].op == '/') {
			stack[top - 1] = cal(postfix[i].op, stack[top - 1], stack[top]);
			top--;

		}
		else{
			opnd[0] = postfix[i];
			stack[++top] = (double)opnd[0].number; //�N�r�ꤤ���Ʀr�ഫ�� double ���A���B�I��
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
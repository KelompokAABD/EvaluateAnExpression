/* Tugas Kelompok Pemrograman Tersetruktur 2018-2019 ( Evaluate An Expression ) */
/* 1857051014 Muhammad Nur Ashiddiqi
   1817051005 Arfina Shella Meilany
   1817051021 Arafia Isnayu Akaf
   1817051049 Bobby Malela
*/
#include <iostream>
using namespace std;
//Yang Ini Berfungsi Untuk input Charakter pada infix
int N(char input){
	if(input == '^')
		return 3;
	else if(input == '*' || input == '/')
		return 2;
	else if(input == '+' || input == '-')
		return 1;
	else if(input == '(' || input == ')')
		return 0;
	else
		return -1;
}
// ini stacknya di batesin 
struct stack{
	int STACK[100000];
	char Stack[100000];
	int top;
};
//ini kelas untuk konversi
class konversi{
private:
	stack list;

public:
	void init(){
		list.top = -1;
	}

	void push(char input){
		list.top++;
		list.STACK[list.top] = input;
	}

	void pop(){
		list.top--;
	}

	char Top(){
		return list.STACK[list.top];
	}

	bool isEmpty(){
		if(list.top <= -1)
			return true;
		else
			return false;
	}
}; konversi SC;

//ini kelas untuk evaluasi
class Eval{
private:
	stack Data;

public:
	void push(int input){
		Data.top++;
		Data.Stack[Data.top] = input;
	}

	void pop(){
		Data.top--;
	}

	int Top(){
		return Data.Stack[Data.top];
	}
}; Eval SE;

//bagian ini untuk konversi
bool isOperand(char input);
bool isOperator(char input);
int N(char input);
bool persen(char input1, char input2);
string ITP(string input);


//bagian ini untuk evaluasi
double Operation(int op1, char c, int op2);
bool Operand(char input);
double Evaluate(string input);
double pow(double number, double exp);
// ini bagian proses konversi
bool isOperand(char input){
	int c = (int)input;
	if(c >= 48 && c <= 57 || c >= 65 && c <= 90 || c >= 97 && c <= 122)
		return true;
	else
		return false;
}

bool isOperator(char input){
	int c = (int)input;
	if(c == 94 || c >= 42 && c <= 43 || c == 45 || c == 47)//
		return true;
	else
		return false;
}
bool persen(char input1, char input2){
	int c1 = N(input1);
	int c2 = N(input2);

	if(c1 <= c2)
		return true;
	else
		return false;
}

string ITP(string input){
	SC.init();
	int i=0;
	string P = "";
	while(input[i] != '\0'){
		if(isOperand(input[i])){
			P += input[i];
		}
		if(input[i] == '('){
			SC.push(input[i]);
		}
		if(input[i] == ')'){
			while(!SC.isEmpty() && SC.Top() != '('){
				P = P + " " + SC.Top(); SC.pop();
			}
			SC.pop();
		}
		if(isOperator(input[i])){
			if(SC.isEmpty() || SC.Top() == '('){
				SC.push(input[i]);
			}else{
				while(!SC.isEmpty() && SC.Top() != '(' && persen(input[i], SC.Top())){
					P = P + " " + SC.Top(); SC.pop();
				}
				SC.push(input[i]);
			}
		}
		if(isOperator(input[i]))
			P += " ";
		i++;
	}
	while(!SC.isEmpty()){
		P = P + " " + SC.Top(); SC.pop();
	}
	return P;
}

// ini bagian proses evaluasi
double pwr(double num, double exp){
	for(int i=1; i<exp; i++)
		num *= num;
	return num;
}

bool Operand(char input){
	int c = (int)input;
	if(c >= 48 && c <= 57)
		return true;
	else if(c >= 65 && c <= 90 || c >= 97 && c <= 122){
		cout << "\nNot Evaluated" << endl;
		cin.get();
		exit(0);
	}
	else
		return false;
}
double Operation(int op1, char c, int op2){
	if(c == '^')
		return (pwr(op1,op2));
	else if(c == '*')
		return (op1 * op2);
	else if(c == '/')
		return (op1 / op2);
	else if(c == '+')
		return (op1 + op2);
	else if(c == '-')
		return (op1 - op2);
	else return 0;
}

double Evaluate(string input){
	int i = 0;
	while(input[i] != '\0'){
		if(Operand(input[i])){
			int operand = 0;
			while(input[i] != '\0' && Operand(input[i])){
				operand = (operand * 10) + (input[i] - 48);
				i++;
			}
			SE.push(operand);
		}
		if(isOperator(input[i])){
			int A = SE.Top(); SE.pop();
			int B = SE.Top(); SE.pop();
			int result = Operation(B,input[i],A);
			SE.push(result);
		}
		i++;
	}
	return SE.Top();
}
// ini bagian main nya
int main(){
	
	cout<<"||=====================================================||"<<endl;
	cout<<"||              EVALUATE AN EXPRESSION                 ||"<<endl;
	cout<<"||               DEVELOPED BY AABD                     ||"<<endl;
	cout<<"||=====================================================||"<<endl;
	cout<<"||             Github = https://github.com/KelompokAABD||"<<endl;
	cout<<"||Anggota :                                            ||"<<endl;
	cout<<"||       1857051014 Muhammad Nur Ashiddiqi             ||"<<endl;
	cout<<"||       1817051005 Arfina Shella Meilany              ||"<<endl;
	cout<<"||       1817051021 Arafia Isnayu Akaf                 ||"<<endl;
	cout<<"||       1817051049 Bobby Malela                       ||"<<endl;
	cout<<"||=====================================================||"<<endl<<endl;
	string I;
	cout<<"||Enter Infix Expression = ";
	getline(cin,I);
	string P = ITP(I);
	cout<<"\n||Infix Your Enter = "<< I;
	cout<<"\n||Postfix of Infix = "<< P;
	int result = Evaluate(P);
	cout<<"\n||Evaluate Expression = "<< result;
	return 0;
}

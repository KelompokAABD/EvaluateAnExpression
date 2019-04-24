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

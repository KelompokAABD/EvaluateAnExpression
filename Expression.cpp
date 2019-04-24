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

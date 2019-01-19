#include <string>
#include <stack>
#include <iostream>
using namespace std;

int precedence(char a){
	switch(a){
		case '(' : return 0;
			   break;
		case '+' : return 1;
			   break;
		case '-' : return 2;
			   break;
		case '*' : return 3;
			   break;
		case '/' : return 4;
			   break;
		case '^' : return 5;
			   break;
		default : return -1;
			  break;
	}
}

void printRPN(string &input,stack<char> &mystack){
	string output = "";
	for(unsigned int i=0;i<input.size();i++){
		if(input[i]>='a' && input[i] <='z')
			output += input[i];
		else if(input[i]=='(')
			mystack.push(input[i]);
		else if(input[i]==')'){
			while(!mystack.empty() && mystack.top()!='('){
				output+=mystack.top();
				mystack.pop();
			}
			mystack.pop();
		}
		else{
			while(!mystack.empty() && precedence(mystack.top()) > precedence(input[i])){
				output+=mystack.top();
				mystack.pop();
			}
			mystack.push(input[i]);
		}
	}
	while(!mystack.empty()){
		output+=mystack.top();
		mystack.pop();
	}
	cout << output <<endl;
}

int main(){
	int num_tests;
	string input;
	stack<char> mystack;
	scanf("%d",&num_tests);
	for(int i=0;i<num_tests;i++){
		cin >> input ;
		printRPN(input,mystack);
	}
	return 0;
}

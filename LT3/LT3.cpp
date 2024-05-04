#include <iostream>
#include <string>
using namespace std;

int outPrioryty(char c) {
	char alphavit[] = "zxcvbnmasdfghjklqwertyuiop";
	if(c == '+' || c == '-') return 1;
	if(c == '*' || c == '/') return 3;
	if(c == '^') return 6;
	if(c == '(') return 9;
	if(c == ')') return 0;
	for (int i = 0; i < 26; i++) {
		if(c == alphavit[i]) return 7;
	}
	return -1;
}


int inPrioryty(char c) {
	char alphavit[] = "zxcvbnmasdfghjklqwertyuiop";
	if(c == '+' || c == '-') return 2;
	if(c == '*' || c == '/') return 4;
	if(c == '^') return 5;
	if(c == '(') return 0;
	if(c == ')') return -1;
	for (int i = 0; i < 26; i++) {
		if(c == alphavit[i]) return 8;
	}
	return -1;
}


class Stack {
public:
	class Node {
	public:
		char data;
		Node* next;
	};

	Node* head;
	int size;

	Stack() {
		head = NULL;
		size = 0;
	}
	void push(char data) {
		Node* temp = new Node;
		temp->data = data;
		temp->next = head;
		head = temp;
		size++;
	}

	char pop() {
		if (size == 0) cerr<< "Stack is empty";
		char temp = head->data;
		Node* tempNode = head;
		head = head->next;
		delete tempNode;
		size--;
		return temp;
	}

	char peek() {
		if(size == 0) return '\0';
		return head->data;
	}
};

int getRank(string str) {
	int rank = 0;
	string alphavit = "zxcvbnmasdfghjklqwertyuiop";
	for (int i = 0; i < str.length(); i++) {

		for (int j = 0; j<alphavit.length(); j++) {
			if (str[i] == alphavit[j]) rank++;
		}
		if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/' || str[i] == '^') rank--;
	}
	return rank;

}

string getIPN(string inf_n) {
	int rank = getRank(inf_n);
	if (rank != 1) {
		cerr << "Incorrect input";
		return "";
	};
	Stack stack;
	string ipn = "";
	string stHead = "";
	for (int i = 0; i < inf_n.length(); i++) {
		if (inf_n[i] == ' ') continue;
		stHead = stack.peek();
		int ourPr = outPrioryty(inf_n[i]);
		int inPr = inPrioryty(stHead[0]);
		
		if (ourPr > inPr) {
			stack.push(inf_n[i]);
		}
		else {
			if (inf_n[i] == ')') {
				while (stack.peek() != '(') {
					ipn += stack.pop();
				}
				stack.pop();
			}
			else {
				while (ourPr <= inPr) {
					ipn += stack.pop();
					stHead = stack.peek();
					inPr = inPrioryty(stHead[0]);
				}
				stack.push(inf_n[i]);
			}

		}

	}
	while (stack.size != 0) {
		ipn += stack.pop();
	}
	return ipn;
}




int main() {
	cout << getIPN("(a + b)*c^n^y") << endl;
	while (true) {
		cout << "enter the expression: ";
		string str;
		getline(cin, str);
		cout << getIPN(str) << endl;
	}

}
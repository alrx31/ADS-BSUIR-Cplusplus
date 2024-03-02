//#include <iostream>
//
//using namespace std;
//
//// linked list (ring ) in one direction with a tail and a head and Data type int
//
//class LinkedList {
//	class Node {
//		int data;
//		Node* next;
//	public:
//		Node(int data) {
//			this->data = data;
//			next = nullptr;
//		}
//
//		int getData() {
//			return data;
//		}
//
//		Node* getNext() {
//			return next;
//		}
//
//		void setNext(Node* next) {
//			this->next = next;
//		}
//		void setData(int data) {
//			this->data = data;
//		}
//	};
//
//	Node* head;
//	Node* tail;
//	int size;
//public:
//	LinkedList() {
//		head = nullptr;
//		tail = nullptr;
//		size = 0;
//	};
//
//	void push(int data) {
//		Node* newNode = new Node(data);
//		if (head == nullptr) {
//			head = newNode;
//			tail = newNode;
//			tail->setNext(head);
//		}
//		else {
//			tail->setNext(newNode);
//			tail = newNode;
//			tail->setNext(head);
//		}
//		size++;
//	}
//
//	void print() {
//		Node* current = head;
//		for (int i = 0; i < size; i++) {
//			cout << current->getData() << " ";
//			current = current->getNext();
//		}
//		cout << endl;
//	}
//
//
//	// delete element by index
//
//	void remove(int index) {
//		if (index < 0 || index >= size) {
//			cout << "invalid index" << endl;
//			return;
//		}
//		if (index == 0) {
//			Node* temp = head;
//			head = head->getNext();
//			delete temp;
//			size--;
//			return;
//		}
//		Node* current = head;
//		for (int i = 0; i < index - 1; i++) {
//			current = current->getNext();
//		}
//		Node* temp = current->getNext();
//		current->setNext(temp->getNext());
//		delete temp;
//		size--;
//	}
//
//
//	int getLastAfterDeleteEveryK(int k) {
//		Node* current = head;
//		Node* prev = tail;
//		while (size > 1) {
//			for (int i = 0; i < k; i++) {
//				prev = current;
//				current = current->getNext();
//			}
//			prev->setNext(current->getNext());
//			delete current;
//			current = prev->getNext();
//			size--;
//		}
//		return current->getData();
//	}
//
//
//};
//
//int main() {
//	//test
//	/*LinkedList list;
//	for (int i = 1; i <= 5; i++) {
//		list.push(i);
//	}
//	list.print();
//	cout << list.getLastAfterDeleteEveryK(1) << endl;*/
//
//
//
//
//	// table
//	for (int i = 1; i <= 64; i++) {
//		LinkedList list;
//		for (int j = 1; j <= 64; j++) {
//			list.push(j);
//		}
//
//		cout << "N = \t" << i << " \t:\t " << list.getLastAfterDeleteEveryK(i) << endl;
//	}
//
//
//
//	return 0;
//}
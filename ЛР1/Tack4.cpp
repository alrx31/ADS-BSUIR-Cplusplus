#include <iostream>
using namespace std;

template <typename T>
class Node {
    T data;

    Node<T>* next;

public:
    Node(T data) {
        this->data = data;
        this->next = nullptr;
    }

    int getData() {
        return this->data;
    }

    Node<T>* getNext() {
        return this->next;
    }

    void setNext(Node<T>* next) {
        this->next = next;
    }
};
template <typename T>
class LinkedList {
    int size;
    Node<T>* head;
public:
    void append(T data) {
        Node<T>* newNode = new Node<T>(data);
        if (!this->head) {
            this->head = newNode;
            return;
        }
        Node<T>* current = this->head;

        while (current->getNext()) {
            current = current->getNext();
        }
        current->setNext(newNode);
    }

    int getSize() {
        Node<T>* current = this->head;
        int count = 0;
        while (current) {
            count++;
            current = current->getNext();
        }
        return count;
    }

    T getNodeData(int index) {
        Node<T>* current = this->head;
        int count = 0;
        while (current) {
            if (count == index) {
                return current->getData();
            }
            else {
                count++;
                current = current->getNext();
            }
        }
    }

    void display() {
        Node<T>* current = this->head;
        while (current) {
            cout << current->getData() << " ";
            current = current->getNext();
        }
        cout << endl;
    }

    void clear() {
        Node<T>* current = this->head;
        Node<T>* next = nullptr;
        while (current) {
            Node<T>* next = current->getNext();
            delete current;
            current = next;

        }
        this->head = nullptr;
    }



    void remove(T dataDel) {
        Node<T>* current = this->head;
        Node<T>* prev = nullptr;
        while (current) {
            if (current->getData() == dataDel) {
                if (prev) {
                    prev->setNext(current->getNext());
                }
                else {
                    this->head = current->getNext();
                }
                delete current;
                return;
            }
            else {
                prev = current;
                current = current->getNext();
            }
        }
    }


    ~LinkedList() {
        this->clear();
    }


};



class LinkedList2 {
	class Node {
		int data;
		Node* next;
		Node* prev;

	public:
		Node(int data) {
			this->data = data;
			next = nullptr;
			prev = nullptr;
		}

		int getData() {
			return data;
		}
		Node* getNext() {
			return next;
		}
		Node* getPrev() {
			return prev;
		}

		void setNext(Node* next) {
			this->next = next;
		}
		void setPrev(Node* prev) {
			this->prev = prev;
		}
		void setData(int data) {
			this->data = data;
		}
	};


	Node* head;
	Node* tail;
	int size;

public:
	LinkedList2() {
		head = nullptr;
		tail = nullptr;
		size = 0;
	};

	void push(int data) {
		if ((data < 100000000 && data > 999999) || data < 1000 && data > 99) {

			Node* temp = new Node(data);
			if (tail == nullptr) {
				head = temp;
				tail = temp;
			}
			else {
				temp->setPrev(tail);
				tail->setNext(temp);
				tail = temp;
			}
			size++;
		}
		else {
			cout<< "invalid number" << endl;
		}

	}

	void print() {
		Node* current = head;
		for (int i = 0; i < size; i++) {
			cout << current->getData() << " ";
			current = current->getNext();
		}
		cout << endl;
	}

	void printReverse() {
		Node* current = tail;
		for (int i = 0; i < size; i++) {
			cout << current->getData() << " ";
			current = current->getPrev();
		}
		cout << endl;
	}

    LinkedList<int>* getPhonesWithOutSpetial(){
        LinkedList<int>* list = new LinkedList<int>();
		Node* current = head;
        for (int i = 0; i < size; i++) {
            if (current->getData() > 1000) {
				list->append(current->getData());
			}
			current = current->getNext();
		}
		return list;
    }
	


};


int main() {
    LinkedList2 list;
	// push right numbers and some invalid
	list.push(1234567);
	list.push(1234569);
	list.push(1234568);
	list.push(1234566);
	list.push(1234565);
	list.push(123);
	list.push(122);
	list.push(121);
	list.push(120);
	list.push(12);
	list.push(1000);
	list.push(1999999999999999);
    // from left display
    cout << "from left" << endl;
    list.print();
    // from right display
    cout << "from right" << endl;

    list.printReverse();

    // only clients phones
    cout << "only clients phones" << endl;
    LinkedList<int>* list2 = list.getPhonesWithOutSpetial();
    list2->display();

	return 0;
}
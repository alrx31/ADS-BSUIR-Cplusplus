#include <iostream>

using namespace std;

class HashTable {

	// the linked list
	class LinkedList {
		// Node
	public:
		class Node {
			string K;
			string V;
			Node* next;
			LinkedList* nodes;
			int size;
		public:
			Node() {}
			Node(string K, string V) : K(K), V(V), next(nullptr), nodes(nullptr),size(0) {}
			string getK() { return K; }
			string getV() { return V; }
			Node* getNext() { return next; }
			LinkedList* getNodes() { return nodes; }
			void setNext(Node* next) { this->next = next; }
			void setNodes(LinkedList* nodes) { this->nodes = nodes; }
			int GetSize() {return size;}
			void SetSize(int size) {this->size = size;}
		};
		// constructor
		LinkedList() : head(nullptr), size(0) {}
		// add a new node
		Node* get(int index) {
			Node* curr = this->head;
			for (int i = 0; i < index; i++) {
				curr = curr->getNext();
			}
			return curr;
		}

		// add a new node
		void push(string K, string V) {
			if (head == nullptr) {
				head = new Node(K, V);
				size++;
				return;
			}
			Node* curr = head;
			while (curr->getNext() != nullptr) {
				curr = curr->getNext();
			}
			curr->setNext(new Node(K, V));
			size++;
		}


		//get size
		int GetSize() {
			return size;
		}

	private:
		// the head of the list
		Node* head;
		// the size of the list
		int size;
	
	};


	// the hash table

	// create an array of linked lists
	LinkedList * table;
	// the size of the table
	int size;



	// the hash function
	int Hash(string data) {
		int hash = 0;
		for (int i = 0; i < data.length(); i++) {
			hash += data[i];
		}
		return hash % size;
	}

public:
	// constructor
	HashTable(int size) {
		this->size = size;
		table = new LinkedList[size];
	}
	// add a new node
	
	void push(string V, string K) {
		int hash = Hash(K);
		table[hash].push(V,K);

	}




	// add a new node to the parent
	void pushToParent(string data, string key, string parent_key) {
		int hash = Hash(key);
		LinkedList::Node* parent = findContainer(parent_key);

		// ....
		parent->getNodes()->push(data, key);
		
	}
	
	// container to the first traversal of the table ( 1 level and put to all 2 method find)
	
	LinkedList::Node * findContainer(string key){
		int hash = Hash(key);
		LinkedList::Node* temp = nullptr;
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < table[i].get(i)->GetSize(); j++) {
				temp = find(key, table[i].get(i)->getNodes()->get(j));
			}
		}
	}

	// find the node by key after the first traversal

	LinkedList::Node* find(string key, LinkedList::Node* node) {
		if (node->getK() == key) return node;
		if (node->GetSize() == 0) return nullptr;
		LinkedList * list = node->getNodes();
		for (int i = 0; i < node->GetSize(); i++) {
			LinkedList::Node* res = find(key, list->get(i));
			if (res != nullptr) return res;
		}
	}

	void print() {
		for (int i = 0; i < size; i++) {
			LinkedList curr = table[i];
			if(curr.GetSize() == 0) continue;
			cout << "Hash: " << i << endl;
			cout << "Size: " << curr.GetSize() << endl;
			

		}
	}

};

int main() {
	HashTable table(20);
	table.push("V1", "K1");

	table.print();
	return 0;
}

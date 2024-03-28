#include <iostream>
#include <string>

using namespace std;

class Node {
private:
    string K;
    int V;
    Node* Next;
    int size_c;
    Node** arr;

public:
    Node() {
        this->K = "";
        this->V = 0;
        this->Next = nullptr;
        this->size_c = 0;
        this->arr = new Node * [size_c + 1]();
    }

    Node(string K, int V) {
        this->K = K;
        this->V = V;
        this->Next = nullptr;
        this->size_c = 0;
        this->arr = new Node * [size_c + 1]();
    }

    void setNext(Node* Next) {
        this->Next = Next;
    }

    void print() {
        cout << this->K << " : " << this->V << endl;
        if (size_c > 1) cout << "==========" << endl;
        for (int i = 0; i < size_c; i++) {
            cout << "\t";
            arr[i]->print();
        }
        if (size_c > 1) cout << "----------" << endl;
    }

    Node* getNext() {
        return Next;
    }

    string getK() const {
        return K;
    }

    int getV() const {
        return V;
    }

    int getSize() const {
        return size_c;
    }

    Node** getArr() const {
        return arr;
    }

    void push(string K, int V) {
        Node** temp = new Node * [size_c + 1];
        for (int i = 0; i < size_c; i++) {
            temp[i] = arr[i];
        }
        arr = new Node * [size_c + 1];
        for (int i = 0; i < size_c; i++) {
            arr[i] = temp[i];
        }
        arr[size_c] = new Node(K, V);
        size_c++;
    }

    void SortNodes() {
        for (int i = 0; i < size_c; i++) {
            this->arr[i]->SortNodes();
            for (int j = 0; j < size_c - 1 - i; j++) {
                if (arr[j]->getV() > arr[j + 1]->getV()) {
                    Node* temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }
    }
};

class LinkedList {
private:
    Node* Head;
    int size;

public:
    LinkedList() {
        this->Head = nullptr;
        this->size = 0;
    }

    void push(string K, int V) {
        Node* newNode = new Node(K, V);
        if (this->Head == nullptr) {
            this->Head = newNode;
        }
        else {
            newNode->setNext(Head);
            Head = newNode;
        }
        size++;
    }

    void print() {
        Node* temp = Head;
        while (temp != nullptr) {
            temp->print();
            temp = temp->getNext();
        }
    }

    Node* getHead() const {
        return Head;
    }

    int getSize() const {
        return size;
    }

    void sort() {
        Node* temp = Head;
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size - 1 - i; j++) {
                if (temp->getV() > temp->getNext()->getV()) {
                    Node* temp1 = temp;
                    temp = temp->getNext();
                    temp->setNext(temp1);
                }
                temp = temp->getNext();
            }
        }
    }
};

class HashTable {
private:
    LinkedList** table;
    int size;

public:
    HashTable() {
        this->size = 10;
        this->table = new LinkedList * [size]();
        for (int i = 0; i < size; i++) {
            table[i] = new LinkedList();
        }
    }

    HashTable(int size) {
        this->size = size;
        this->table = new LinkedList * [size]();
        for (int i = 0; i < size; i++) {
            table[i] = new LinkedList();
        }
    }

    int hash(const string& key) {
        int hash = 0;
        for (char c : key) {
            hash += c;
        }
        return hash % size;
    }

    void put(const string& key, int value) {
        int hash = this->hash(key);
        if (table[hash] == nullptr) {
            table[hash] = new LinkedList();
        }
        table[hash]->push(key, value);
    }

    void putToElem(const string& K, int V, const string& K_p) {
        Node* parent = getNode(K_p);
        if (parent == nullptr) return;
        parent->push(K, V);
    }

    Node* getNode(const string& K) {
        Node* res = nullptr;
        for (int i = 0; i < size; i++) {
            if (table[i] != nullptr) {
                Node* curr = table[i]->getHead();
                for (int j = 0; j < table[i]->getSize(); j++) {
                    res = get(curr, K);
                    if (res->getK() == K) return res;
                    curr = curr->getNext();
                }
            }
        }
        return res;
    }

    Node* get(Node* node, const string& K) {
        if (node->getK() == "") return nullptr;
        if (node->getK() == K) return node;
        for (int i = 0; i < node->getSize(); i++) {
            Node* res = get(node->getArr()[i], K);
            if (res->getK() == K) return res;
        }
        return node;
    }

    void print() {
        for (int i = 0; i < size; i++) {
            if (table[i] != nullptr) {
                table[i]->print();
            }
        }
    }

    void print(const string& K) {
        getNode(K)->print();
    }

    void sortNodes() {
        for (int i = 0; i < size; i++) {
            if (table[i]->getHead() != nullptr) {
                table[i]->sort();
                Node* temp = table[i]->getHead();
                for (int j = 0; j < table[i]->getSize(); j++) {
                    temp->SortNodes();
                    temp = temp->getNext();
                }
            }
        }
    }
};

int main() {
    HashTable ht(20);
    ht.put("a", 4);
    ht.put("b", 5);
    ht.putToElem("c", 3, "a");
    ht.putToElem("d", 6, "c");
    ht.putToElem("e", 2, "a");
    ht.putToElem("f", 1, "c");

    ht.print();
    cout << endl;
    ht.sortNodes();
    cout << endl;
    ht.print();

    return 0;
}

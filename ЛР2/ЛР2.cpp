#include <iostream>
#include <string>

using namespace std;

class Node {
private:
    string K;
    int *V;
    int size_v;

    Node* Next;
    int size_c;
    Node** arr;
public:
    Node() {
        this->K = "";
        this->size_v = 0;
        this->V = new int[size_v+1];
        this->Next = nullptr;
        this->size_c = 0;
        this->arr = new Node * [size_c + 1]();
    }

    Node(string K, int V) {
        this->K = K;
        this->size_v = 0;
        this->V = new int[size_v + 1];
        this->V[size_v++] = V;
        this->Next = nullptr;
        this->size_c = 0;
        this->arr = new Node * [size_c + 1]();
    }

    void remove() {
        K = "";
        size_v = 0;
        V = new int[size_v];

        Next = nullptr;
        for (int i = 0; i < size_c; i++) {
            arr[i]->remove();
        }
        size_c = 0;
        arr = new Node * [size_c];
    }
    void setNext(Node* Next) {
        this->Next = Next;
    }
    int getVsize() {
		return size_v;
	}

    void print() {
        cout << this->K << " : ";
        for (int i = 0; i < size_v; i++) {
			cout << this->V[i] << " ";
		}
        cout << endl;
        if (size_c > 1) cout << "==========" << endl;
        for (int i = 0; i < size_c; i++) {
            if (arr[i]->getK() != "") {
                cout << "\t";
                arr[i]->print();
            }
        }
        if (size_c > 1) cout << "----------" << endl;
    }

    Node* getNext() {
        return Next;
    }
    string getK()  {
        return K;
    }

    int* getV()  {
        return V;
    }

    int getSize()  {
        return size_c;
    }

    Node** getArr()  {
        return arr;
    }

    void push(string K, int V) {
        Node** temp = new Node * [size_c + 1];
        for (int i = 0; i < size_c; i++) {
            temp[i] = arr[i];
            if (temp[i]->getK() == K) {
                temp[i]->pushEl(V);
                return;
            }
        }

        arr = new Node * [size_c + 1];
        for (int i = 0; i < size_c; i++) {
            arr[i] = temp[i];
        }

        arr[size_c] = new Node(K, V);
        size_c++;
    }

    void SortNodes() {
        // sort numbers
        for (int i = 0; i < this->size_v; i++) {
            for (int j = 0; j < this->size_v - i - 1; j++) {
                if (this->V[j] > this->V[j + 1]) {
                    int temp = this->V[j];
                    this->V[j] = this->V[j + 1];
                    this->V[j + 1] = temp;
                }
            }
        }
        // sort childs
        for (int i = 0; i < size_c; i++) {
            this->arr[i]->SortNodes();
            for (int j = 0; j < size_c - 1 - i; j++) {
                if (arr[j]->getV()[0] > arr[j + 1]->getV()[0]) {
                    Node* temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }
    }
    void SortNodes(int r) {
        // sort numbers
        for (int i = 0; i < this->size_v; i++) {
            for (int j = 0; j < this->size_v - i - 1; j++) {
                if (this->V[j] > this->V[j + 1]) {
                    int temp = this->V[j];
                    this->V[j] = this->V[j + 1];
                    this->V[j + 1] = temp;
                }
            }
        }
        // sort childs
        for (int i = 0; i < size_c; i++) {
            this->arr[i]->SortNodes(1);
            for (int j = 0; j < size_c - 1 - i; j++) {
                if (arr[j]->getK().compare(arr[j + 1]->getK()) >0) {
                    Node* temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }
    }
    

    void pushEl(int V) {
        this->V[this->size_v++] = V;
    }
    void IncreaseSize() {
		this->size_v++;
	}
    void DecreaseSize() {
        this->size_c--;
    }
};

class HashTable {
private:
    Node** table;
    int size;

public:
    HashTable() {
        this->size = 10;
        this->table = new Node * [size];
        for (int i = 0; i < size; i++) {
            table[i] = new Node();
        }
    }

    HashTable(int size) {
        this->size = size;
        this->table = new Node * [size];
        for (int i = 0; i < size; i++) {
            table[i] = new Node();
        }
    }

    int hash(const string& key) {
        int hash = 0;
        for (char c : key) {
            hash += c;
        }
        return hash % size;
    }

    void put(string key, int value) {
        int hash = this->hash(key);
        if (table[hash]->getK() == "") {
            table[hash] = new Node(key,value);
            return;
        }
        table[hash]->pushEl(value);
    }

    void putToElem(string K, int V, string K_p) {
        Node* parent = getNode(K_p);
        if (parent == nullptr) return;
        parent->push(K,V);
    }

    Node* getNode(string K) {
        Node* res = nullptr;
        
        for (int i = 0; i < size; i++) {
            if (this->table[i]->getK() != "") {
                res = get(this->table[i], K);
                if (res->getK() == K) return res;
            }

        }
        return res;
    }

    Node* get(Node* node, string K) {
        if (node->getK() == "") return nullptr;
        if (node->getK() == K) return node;
        for (int i = 0; i < node->getSize(); i++) {
            Node* res = get(node->getArr()[i], K);
            if (res->getK() == K) return res;
        }
        return node;
    }

    void print() {
        for (int i = 16; i < size; i++) {
            if (table[i] != nullptr && table[i]->getK() != "" && table[i]->getVsize() != 0) {
                table[i]->print();
            }
        }
    }

    void print( string K) {
        getNode(K)->print();
    }

    void sortNodes() {
        for (int i = 0; i < size; i++) {
            table[i]->SortNodes();
        }
    }
    void sortNodes(int r) {
        for (int i = 0; i < size; i++) {
            table[i]->SortNodes(r);
        }
    }

    void Delete(string K) {
        for (int i = 16; i < size; i++) {
            if (table[i]->getK() != "") {
                if (table[i]->getK() == K) {
					table[i]->remove();
					return;
				}
				int res = Delete(table[i], K);
			    if (res == 1) return;
            }
        }
    }
    int Delete(Node* node, string K) {
        if (node->getK() == K) {
            node->remove();
			return 1;
		}
        for (int i = 0; i < node->getSize(); i++) {
            Delete(node->getArr()[i], K);
        }
        return 0;
    }

};

int main() {
    HashTable ht(20);
    ht.put("b", 5);
    ht.put("a", 4);
    ht.put("a", 2);
    ht.putToElem("c", 3, "b");
    ht.putToElem("c", 2, "b");
    ht.putToElem("d", 6, "c");
    ht.putToElem("e", 2, "b");
    ht.putToElem("f", 1, "c");

    /*ht.print();
    cout << endl;
    ht.sortNodes();
    cout << endl;
    ht.print();
    cout << endl << endl;
    ht.sortNodes(1);*/
    ht.print();

    ht.Delete("f");
    cout << endl;
    ht.print();

    return 0;
}

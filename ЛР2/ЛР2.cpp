#include <iostream>
#include <string>

using namespace std;

class Node {
private:
    string Key;
    int* Value;
    int size_val;

    Node* Next;
    int size_arr;
    Node** arr;
public:
    Node() {
        this->Key = "";
        this->size_val = 0;
        this->Value = new int[size_val + 1];
        this->Next = nullptr;
        this->size_arr = 0;
        this->arr = new Node * [size_arr + 1]();
    }

    Node(string K, int V) {
        this->Key = K;
        this->size_val = 0;
        this->Value = new int[size_val + 1];
        this->Value[size_val++] = V;
        this->Next = nullptr;
        this->size_arr = 0;
        this->arr = new Node * [size_arr + 1]();
    }

    void remove() {
        Key = "";
        size_val = 0;
        Value = new int[size_val];

        Next = nullptr;
        for (int i = 0; i < size_arr; i++) {
            arr[i]->remove();
        }
        size_arr = 0;
        arr = new Node * [size_arr];
    }
    void setNext(Node* Next) {
        this->Next = Next;
    }
    int getVsize() {
        return size_val;
    }

    void print(int c = 0) {
        for (int j = 0; j < c; j++) {
            cout << "\t";
        }
        cout << this->Key << " : ";
        for (int i = 0; i < size_val; i++) {
            cout << this->Value[i] << " ";
        }
        cout << endl;
        for (int i = 0; i < size_arr; i++) {
            if (arr[i]->getK() != "") {

                arr[i]->print(c + 1);
            }
        }
    }

    Node* getNext() {
        return Next;
    }
    string getK() {
        return Key;
    }

    int* getV() {
        return Value;
    }

    int getSize() {
        return size_arr;
    }

    Node** getArr() {
        return arr;
    }

    void push(string K, int V) {
        Node** temp = new Node * [size_arr + 1];
        for (int i = 0; i < size_arr; i++) {
            temp[i] = arr[i];
            if (temp[i]->getK() == K) {
                temp[i]->pushEl(K, V);
                return;
            }
        }

        arr = new Node * [size_arr + 1];
        for (int i = 0; i < size_arr; i++) {
            arr[i] = temp[i];
        }

        arr[size_arr] = new Node(K, V);
        size_arr++;
    }


    void SortNodes(bool key = false) {
        if (!key) {
            // sort numbers
            for (int i = 0; i < this->size_val; i++) {
                for (int j = 0; j < this->size_val - i - 1; j++) {
                    if (this->Value[j] > this->Value[j + 1]) {
                        int temp = this->Value[j];
                        this->Value[j] = this->Value[j + 1];
                        this->Value[j + 1] = temp;
                    }
                }
            }
            // sort childs
            for (int i = 0; i < size_arr; i++) {
                this->arr[i]->SortNodes();
                for (int j = 0; j < size_arr - 1 - i; j++) {
                    if (arr[j]->getV()[0] > arr[j + 1]->getV()[0]) {
                        Node* temp = arr[j];
                        arr[j] = arr[j + 1];
                        arr[j + 1] = temp;
                    }
                }
            }
            for (int i = 0; i < size_arr; i++) {
                this->arr[i]->SortNodes();
            }

        }
        else {
            // sort numbers
            for (int i = 0; i < this->size_val; i++) {
                for (int j = 0; j < this->size_val - i - 1; j++) {
                    if (this->Value[j] > this->Value[j + 1]) {
                        int temp = this->Value[j];
                        this->Value[j] = this->Value[j + 1];
                        this->Value[j + 1] = temp;
                    }
                }
            }
            // sort childs
            for (int i = 0; i < size_arr; i++) {
                this->arr[i]->SortNodes(key);
                for (int j = 0; j < size_arr - 1 - i; j++) {
                    if (arr[j]->getK().compare(arr[j + 1]->getK()) > 0) {
                        Node* temp = arr[j];
                        arr[j] = arr[j + 1];
                        arr[j + 1] = temp;
                    }
                }
            }
            for (int i = 0; i < size_arr; i++) {
                this->arr[i]->SortNodes(key);
            }
        }
    }


    void pushEl(string key, int V) {
        if (this->getK() != key) {
            this->setNext(new Node(key, V));
            return;
        }
        this->Value[this->size_val++] = V;
    }
    void IncreaseSize() {
        this->size_val++;
    }
    void DecreaseSize() {
        this->size_arr--;
    }
};

class HashTable {
private:
    Node** table;
    int size;

    int index;
public:
    HashTable() {
        this->size = 10;
        this->table = new Node * [size];
        for (int i = 0; i < size; i++) {
            table[i] = new Node();
        }
        this->index = 0;
    }

    HashTable(int size) {
        this->size = size;
        this->table = new Node * [size];
        for (int i = 0; i < size; i++) {
            table[i] = new Node();
        }
    }

    int hash(string key) {
        int hash = 0;
        for (char c : key) {
            hash += c;
        }
        return hash % size;
    }

    void put(string key, int value) {
        /*int hash = this->hash(key);
        if (table[hash]->getK() == "") {
            table[hash] = new Node(key, value);
            return;
        }
        table[hash]->pushEl(key, value);*/
        if(index == size) return;

        table[index++] = new Node(key,value);
    }

    void putToElem(string K, int V, string K_p) {
        Node* parent = getNode(K_p);
        if (parent == nullptr) return;
        parent->push(K, V);
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
        for (int i = 0; i < size; i++) {
            if (table[i] != nullptr && table[i]->getK() != "" && table[i]->getVsize() != 0) {
                table[i]->print();
                Node* temp = table[i];
                while (temp->getNext() != nullptr) {
                    temp = temp->getNext();
                    table[i]->print();
                }
            }
        }
    }

    void print(string K) {
        getNode(K)->print();
    }

    void sortNodes(bool key = false) {
        if (!key) {

            for (int i = 0; i < size; i++) {
                table[i]->SortNodes();
            }
            BubleSort();
        }
        else {
            for (int i = 0; i < size; i++) {
                table[i]->SortNodes(key);
            }
            BubleSort(true);
        }
    }

    void Delete(string K) {
        for (int i = 0; i < size; i++) {
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
    
    // sort the table array like array
    void BubleSort(bool sort = false) {
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size - 1; j++) {
                if (sort) {
                    if (table[j]->getK().compare(table[j + 1]->getK()) > 0) {
                        Node* temp = table[j];
                        table[j] = table[j + 1];
                        table[j + 1] = temp;
                    }
                }
                else {
                    if (table[j]->getV()[0] > table[j + 1]->getV()[0]) {
                        Node* temp = table[j];
                        table[j] = table[j + 1];
                        table[j + 1] = temp;
                    }
                }
            }
        }
    }

    void findTermsByParent(string K) {
        for (int i = 0; i < size; i++) {
            findTermsByParent(table[i], K);
        }

    }
    void findTermsByParent(Node* node, string K) {
        if (node->getK() == K) {
			cout << endl<<node->getK() << " ";
            for (int i = 0; i < node->getSize(); i++) {
                cout << node->getArr()[i]->getK() << " ";
            }
        }
        for (int i = 0; i < node->getSize(); i++) {
			findTermsByParent(node->getArr()[i], K);
		}
    }
    void findTermsBySubterm(string subterm) {
        for (int i = 0; i < size; i++) {
            findTermsBySubterm(table[i], subterm);
        }
    }

    void findTermsBySubterm(Node* node, string subterm) {
        
        for (int i = 0; i < node->getSize(); i++) {
            if (node->getArr()[i]->getK() == subterm) {
                cout << node->getK() << " ";
            }
            findTermsBySubterm(node->getArr()[i], subterm);
        }
    }

};


int main() {
    HashTable ht(20);
    ht.put("b", 1);
    ht.put("a", 4);
    ht.put("a", 2);
    ht.putToElem("d", 3, "b");
    ht.putToElem("d", 2, "b");
    ht.putToElem("c", 6, "c");
    ht.putToElem("e", 2, "b");
    ht.putToElem("f", 1, "c");
    ht.putToElem("a", 1, "c");
    ht.putToElem("c", 1, "f");
    ht.putToElem("c", 14, "b");

    ht.putToElem("aaaaaaaaaa", 2, "c");
    ht.putToElem("fdsf", 12, "aaaaaaaaaa");
    ht.putToElem("rt", 24, "aaaaaaaaaa");
    ht.print();
    cout << endl<< endl;
    while (true) {
        cout << endl<<"1 - sort by numbers" << endl << "2 - sort by alphabet" << endl << "3 - find by parent" << endl << "4 - find by subterm" << endl << "5 - delete" <<endl << "6 - add term"<< endl << "7 - add term to term" << endl;
        int key;
        cin >> key;
        system("cls");
        ht.print();
        cout << endl << endl;
        if (key == 1) {
			ht.sortNodes();
			ht.print();
		}
        else if (key == 2) {
			ht.sortNodes(true);
			ht.print();
		}
        else if (key == 3) {
			string K;
			cout << "Enter parent: ";
			cin >> K;
			ht.findTermsByParent(K);
		}
        else if (key == 4) {
			string K;
			cout << "Enter subterm: ";
			cin >> K;
			ht.findTermsBySubterm(K);
		}
        else if (key == 5) {
			string K;
			cout << "Enter term: ";
			cin >> K;
			ht.Delete(K);
			ht.print();
        }
        else if (key == 6) {
            			string K;
			int V;
			cout << "Enter term: ";
			cin >> K;
			cout << "Enter value: ";
			cin >> V;
			ht.put(K, V);
			ht.print();
		}
        else if (key == 7) {
			string K;
			int V;
			string K_p;
			cout << "Enter term: ";
			cin >> K;
			cout << "Enter value: ";
			cin >> V;
			cout << "Enter parent: ";
			cin >> K_p;
			ht.putToElem(K, V, K_p);
			ht.print();
        }

    }

    // true - alphabet sort, false - number sort
    /*ht.sortNodes();
    cout << endl << endl;
    ht.print();
    ht.sortNodes(true);
    cout << endl << endl;
    ht.print();
    cout << endl << endl;
    cout << endl << "Parent: c" << endl << "Children:" << endl;
    ht.findTermsByParent("b");
    cout << endl << endl;
    cout << endl << "Subterm: c" << endl << "Parents:";
    ht.findTermsBySubterm("c");
    cout << endl;*/
    return 0;


}

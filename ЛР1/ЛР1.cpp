//#include <iostream>
//#include <string>
//
//using namespace std;
//
//class LinkedList {
//    class Node {
//        int phone;
//        string name;
//        Node* next;
//    public:
//        Node(int phone, string name) {
//            this->phone = phone;
//            this->name = name;
//         next = nullptr;
//        }
//
//        int getPhone() {
//            return phone;
//        }
//
//        string getName() {
//            return name;
//        }
//
//        Node* getNext() {
//            return next;
//        }
//
//        void setNext(Node* next) {
//            this->next = next;
//        }
//        void setPhone(int phone) {
//            this->phone = phone;
//        }
//        void setName(string name) {
//            this->name = name;
//        }
//    };
//
//    Node* head;
//    int size;
//public:
//    LinkedList() {
//        head = nullptr;
//        size = 0;
//    };
//
//    void push(int phone, string name) {
//        if (phone < 100000000 && phone > 999999) {
//            Node* newNode = new Node(phone, name);
//            newNode->setNext(head); // set new node's next to current head
//            head = newNode; // update head to new node
//            size++;
//        }
//        else {
//            cout << "invalid number" << endl;
//        }   
//    }
//
//    // get all phones by name
//    int getSize() {
//        return size;
//    }
//
//    int* GetPhonesByName(string name, int& resultSize) {
//        int* phones = new int[size];
//        int i = 0;
//        Node* current = head;
//        while (current != nullptr) {
//            if (current->getName() == name) {
//                phones[i] = current->getPhone();
//                i++;
//            }
//            current = current->getNext();
//        }
//        resultSize = i;
//        return phones;
//    }
//
//
//    string* GetNamesByPhone(int phone, int& resultSize) {
//        string * names = new string[size];
//        int i = 0;
//        Node* current = head;
//        while (current != nullptr) {
//            if (current->getPhone() == phone) {
//				names[i++] = current->getName();
//			}
//			current = current->getNext();
//		}
//
//        resultSize = i;
//        return names;
//        
//        
//    }
//
//    // buble sort 
//
//    
//
//    string* getArrayString() {
//        string* arr = new string[size];
//        Node* current = head;
//        for (int i = 0; i < size; i++) {
//            arr[i] = current->getName();
//            current = current->getNext();
//        }
//        return arr;
//    }
//
//    void sortByName() {
//        if (!head || !head->getNext())
//            return;
//
//        Node* current = head, * index = nullptr;
//        string tempName;
//        int tempPhone;
//
//        while (current != nullptr) {
//            index = current->getNext();
//
//            while (index != nullptr) {
//                if (current->getName() > index->getName()) {
//                    // Swap names
//                    tempName = current->getName();
//                    current->setName(index->getName());
//                    index->setName(tempName);
//
//                    // Swap phones
//                    tempPhone = current->getPhone();
//                    current->setPhone(index->getPhone());
//                    index->setPhone(tempPhone);
//                }
//                index = index->getNext();
//            }
//            current = current->getNext();
//        }
//    }
//
//
//
//    void Print(){
//        Node* current = head;
//        while (current->getNext()) {
//            cout << current->getName() << " : " << current->getPhone() << endl;
//
//            current = current->getNext();
//        }
//    }
//
//    void clear() {
//		Node* current = head;
//        while (current) {
//			Node* next = current->getNext();
//			delete current;
//			current = next;
//		}
//		head = nullptr;
//		size = 0;
//	}
//
//};
//
//
//string* SortArrayStringByAlphabet(string* arr, int size) {
//    for (int i = 0; i < size - 1; i++) {
//        for (int j = 0; j < size - i - 1; j++) {
//            if (arr[j] > arr[j + 1]) {
//                string temp = arr[j];
//                arr[j] = arr[j + 1];
//                arr[j + 1] = temp;
//            }
//        }
//    }
//    return arr;
//}
//
//int main1() {
//
//
//
//
//    LinkedList list;
//    list.push(1234987, "Pavel");
//    list.push(1234987, "Pavel1");
//    list.push(1239876, "Ivan");
//    list.push(1231234, "Aidor");
//    list.push(1231236, "Bidor");
//    list.push(1236543, "Cidor");
//    list.push(1234432, "Ivan");
//
//    list.sortByName();
//    list.Print();
//
//
//
//
//    cout << "Enter a name " << endl;
//    string name;
//    cin >> name;
//    cout << "All phones with name: " << name<< endl;
//    int resultSize;
//    int* phones = list.GetPhonesByName(name, resultSize);
//    for (int i = 0; i < resultSize; i++) {
//        cout << phones[i] << endl;
//    }
//    cout << endl << endl;
//
//
//    cout << "Enter a phone" << endl;
//    int phone;
//    cin >> phone;
//    cout << "All names with phone "<< phone << endl;
//
//    string * names = list.GetNamesByPhone(phone, resultSize);
//
//    for (int i = 0; i < resultSize; i++) {
//		cout << names[i] << endl;
//	}
//
//    delete[] phones;
//
//
//    list.clear();
//    return 0;
//}

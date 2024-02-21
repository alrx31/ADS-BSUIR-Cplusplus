#include <iostream>
#include <cmath>
using namespace std;
struct Term {
    int coefficient; 
    int power;       
    Term* next;      
};

class Polynomial {
public:
    Polynomial() : head(nullptr) {}
    ~Polynomial() {
        Term* current = head;
        while (current) {
            Term* next = current->next;
            delete current;
            current = next;
        }
    }
    void addTerm(int coefficient, int power) {
        Term* newTerm = new Term{ coefficient, power, nullptr };
        if (!head) {
            head = newTerm;
        }
        else {
            Term* current = head;
            while (current->next) {
                current = current->next;
            }
            current->next = newTerm;
        }
    }

    bool isEqual(const Polynomial& other) const {
        Term* current1 = head;
        Term* current2 = other.head;
        while (current1 && current2) {
            if (current1->coefficient != current2->coefficient || current1->power != current2->power) {
                return false;
            }
            current1 = current1->next;
            current2 = current2->next;
        }
        return current1 == nullptr && current2 == nullptr;
    }

    int meaning(int x) const {
        int result = 0;
        Term* current = head;
        while (current) {
            result += current->coefficient * pow(x, current->power);
            current = current->next;
        }
        return result;
    }

    void add(const Polynomial& q, const Polynomial& r) {

        Term* current1 = q.head;
        Term* current2 = r.head;
        while (current1 || current2) {
            if (current1 && current2) {
                if (current1->power == current2->power) {
                    addTerm(current1->coefficient + current2->coefficient, current1->power);
                    current1 = current1->next;
                    current2 = current2->next;
                }
                else if (current1->power > current2->power) {
                    addTerm(current1->coefficient, current1->power);
                    current1 = current1->next;
                }
                else {
                    addTerm(current2->coefficient, current2->power);
                    current2 = current2->next;
                }
            }
            else if (current1) {
                addTerm(current1->coefficient, current1->power);
                current1 = current1->next;
            }
            else {
                addTerm(current2->coefficient, current2->power);
                current2 = current2->next;
            }
        }
    }


    Term* getHead() const {
        return head;
    }

private:
    Term* head;
};

int main() {
    setlocale(LC_ALL, "RU");
    Polynomial p;
    p.addTerm(-5, 6);
    p.addTerm(3, 2);
    p.addTerm(-1, 1);
    p.addTerm(7, 0);


    Polynomial q;
    q.addTerm(8, 5);
    q.addTerm(3, 2);
    q.addTerm(-1, 0);


    Polynomial r;
    r.addTerm(2, 3);
    r.addTerm(1, 2);
    r.addTerm(-3, 1);
    r.addTerm(4, 0);
    Term* current1 = p.getHead();
    while (current1) {
        cout << current1->coefficient << "x^" << current1->power << " ";
        current1 = current1->next;
    }
    cout << endl;
    Term* current2 = q.getHead();
    while (current2) {
        cout << current2->coefficient << "x^" << current2->power << " ";
        current2 = current2->next;
    }
    cout << endl;
    Term* current3 = r.getHead();
    while (current3) {
        cout << current3->coefficient << "x^" << current3->power << " ";
        current3 = current3->next;
    }
    cout << endl;
    cout << "p == q: " << (p.isEqual(q) ? "true" : "false") << endl;


    cout << "Значение многочлена p в x=2: " << p.meaning(2) << endl;


    p = Polynomial();
    p.add(q, r);


    cout << "Сумма многочлена q и r: ";
    Term* current = p.getHead();
    while (current) {
        cout << current->coefficient << "x^" << current->power << " ";
        current = current->next;
    }
    cout << endl;

    return 0;
}

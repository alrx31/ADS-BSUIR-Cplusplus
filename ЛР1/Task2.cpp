//#include <iostream>
//#include <cmath>
//using namespace std;
//// класс одночлена многочлена
//class Term {
//public:
//    double coefficient; // коэффициент
//    int power;       // степень
//    Term* next;      // указатель на следующий одночлен
//};
//
//// Класс, представляющий многочлен как односвязный список одночленов
//class Polynomial {
//private:
//    Term* head;
//public:
//    Polynomial() : head(nullptr) {}
//    ~Polynomial() {
//        Term* current = head;
//        while (current) {
//            Term* next = current->next;
//            delete current;
//            current = next;
//        }
//    }
//
//    // Метод для добавления одночлена к текущему
//    void addTerm(double coefficient, int power) {
//        Term* newTerm = new Term{ coefficient, power, nullptr };
//        if (!head) {
//            head = newTerm;
//        }
//        else {
//            Term* current = head;
//            while (current->next) {
//                current = current->next;
//            }
//            current->next = newTerm;
//        }
//    }
//
//    // Медод проверки эквивалентности
//    bool isEqual(Polynomial& other) {
//        Term* current1 = head;
//        Term* current2 = other.head;
//        while (current1 && current2) {
//            if (current1->coefficient != current2->coefficient || current1->power != current2->power) {
//                return false;
//            }
//            current1 = current1->next;
//            current2 = current2->next;
//        }
//        return current1 == nullptr && current2 == nullptr;
//    }
//
//    // Медот вычесления значения в определенной точке
//    double Calc(int x) {
//        int result = 0;
//        Term* current = head;
//        while (current) {
//            result += current->coefficient * pow(x, current->power);
//            current = current->next;
//        }
//        return result;
//    }
//
//    // для нецелых чисел
//    double Calc(double x) {
//        int result = 0;
//        Term* current = head;
//        while (current) {
//            result += current->coefficient * pow(x, current->power);
//            current = current->next;
//        }
//        return result;
//    }
//
//    // метод для добавления к текущему
//    Polynomial add(Polynomial& q) {
//        Polynomial Result;
//        Term* current1 = q.head;
//        Term* current2 = head;
//        while (current1 || current2) {
//            if (current1 && current2) {
//                if (current1->power == current2->power) {
//                    Result.addTerm(current1->coefficient + current2->coefficient, current1->power);
//                    current1 = current1->next;
//                    current2 = current2->next;
//                }
//                else if (current1->power > current2->power) {
//                    Result.addTerm(current1->coefficient, current1->power);
//                    current1 = current1->next;
//                }
//                else {
//                    Result.addTerm(current2->coefficient, current2->power);
//                    current2 = current2->next;
//                }
//            }
//            else if (current1) {
//                Result.addTerm(current1->coefficient, current1->power);
//                current1 = current1->next;
//            }
//            else {
//                Result.addTerm(current2->coefficient, current2->power);
//                current2 = current2->next;
//            }
//        }
//        return Result;
//
//
//    }
//
//
//    // метод для вывода многочлена
//    void Print() {
//        Term* current = head;
//        bool first = true;
//        while (current) {
//            if (first) {
//                if (current->power == 0) {
//                    cout << current->coefficient << " ";
//                }
//                else if (current->power == 1) {
//                    cout << current->coefficient << "x ";
//                }
//                else {
//                    cout << current->coefficient << "x^" << current->power << " ";
//                }
//                first = false;
//            }
//            else if (current->coefficient > 0) {
//                if (current->power == 0) {
//                    cout << "+ " << current->coefficient << " ";
//                }
//                else if (current->power == 1) {
//                    cout << "+ " << current->coefficient << "x ";
//                }
//                else {
//                    cout << "+ " << current->coefficient << "x^" << current->power << " ";
//                }
//            }
//            else {
//                if (current->power == 0) {
//                    cout << "- " << abs(current->coefficient) << " ";
//                }
//                else if (current->power == 1) {
//                    cout << "- " << abs(current->coefficient) << "x ";
//                }
//                else {
//                    cout << "- " << abs(current->coefficient) << "x^" << current->power << " ";
//                }
//            }
//            current = current->next;
//        }
//    }
//
//    Term* getHead() {
//        return head;
//    }
//};
//// функция для сложения многочленов и записи в другой
//void Add(Polynomial& p, Polynomial& q, Polynomial& r) {
//    Term* current1 = q.getHead();
//    Term* current2 = r.getHead();
//    while (current1 || current2) {
//        if (current1 && current2) {
//            if (current1->power == current2->power) {
//                p.addTerm(current1->coefficient + current2->coefficient, current1->power);
//                current1 = current1->next;
//                current2 = current2->next;
//            }
//            else if (current1->power > current2->power) {
//                p.addTerm(current1->coefficient, current1->power);
//                current1 = current1->next;
//            }
//            else {
//                p.addTerm(current2->coefficient, current2->power);
//                current2 = current2->next;
//            }
//        }
//        else if (current1) {
//            p.addTerm(current1->coefficient, current1->power);
//            current1 = current1->next;
//        }
//        else {
//            p.addTerm(current2->coefficient, current2->power);
//            current2 = current2->next;
//        }
//    }
//}
//
//
//int main() {
//    Polynomial p;
//    p.addTerm(-5, 6);
//    p.addTerm(3, 2);
//    p.addTerm(-1, 1);
//    p.addTerm(7, 0);
//
//
//
//    Polynomial q;
//    q.addTerm(8, 5);
//    q.addTerm(3, 2);
//    q.addTerm(-1, 0);
//
//
//    Polynomial r;
//    r.addTerm(2, 3);
//    r.addTerm(1, 2);
//    r.addTerm(-3, 1);
//    r.addTerm(4, 0);
//
//
//    p.Print();
//    cout << endl;
//    q.Print();
//    cout << endl;
//    r.Print();
//    cout << endl;
//    cout << "p == q: " << (p.isEqual(q) ? "true" : "false") << endl;
//
//
//    cout << "The value of p where x=2:" << p.Calc(2) << endl;
//    cout << "The Summ of polynomials: \t";
//
//    q.add(r).Print();
//    cout << "\nAnother summ method: \t\t";
//    Polynomial z;
//    Add(z, q, r);
//    z.Print();
//
//
//    cout << endl;
//
//    return 0;
//}

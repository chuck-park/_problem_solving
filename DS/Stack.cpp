#include <iostream>
using namespace std;

class UnderflowException{};

template<typename T>
class Node {
public:
    T value;
    Node<T> *next;

    Node<T>(T v, Node<T> *n): value(v), next(n){}
};

template<typename T>
class Stack {
public:
    int size;
    Node<T> *head;

    // 생성자
    Stack<T>(): size(0), head(nullptr){}

    // 소멸자
    ~Stack<T>() {
        Node<T> *t1 = head, *t2;
        while(t1 != nullptr) {
            t2 = t1->next;
            delete t1;
            t1 = t2;
        }
    }

    void push(T value) {
        head = new Node<T>(value, head); // 맨 위에 새 원소 삽입
        size++;
    }

    T top() {
        try {
            if(size == 0) throw UnderflowException();
            return head->value;
        }
        catch (UnderflowException e) {
            cerr << "스택이 비어있는데 top 연산을 시도했습니다." << endl;
            exit(1);
        }
    }

    int pop() { // 맨 위의 원소 제거
        try {
            // 예외 처리: 스택이 비어있는 경우
            if (size == 0) throw UnderflowException();
            Node<T> *temp = head->next;
            delete head;
            head = temp;
            size--;
        }
        catch (UnderflowException e) {
            cerr << "스택이 비어있는데 pop 연산을 시도했습니다." << endl;
            exit(2);
        }
    }
};

template<typename T>
ostream& operator <<(ostream &out, const Stack<T> &LL){ // 원소들을 한 줄에 차례대로 출력
    Node<T> *temp = LL.head;
    out << "top [";
    for(int i=0; i<LL.size; i++){
        out << temp->value;
        temp = temp->next;
        if(i < LL.size-1) out << ", ";
    }
    out << "] bottom";
    return out;
}

int main() {
    Stack<int> S;
    S.push(0); cout << S << endl;
    S.push(1); cout << S << endl;
    S.push(2); cout << S << endl;
    S.pop(); cout << S << endl;
    S.push(4); cout << S << endl;
    S.pop(); cout << S << endl;
    S.push(5); cout << S << endl;
    S.pop(); cout << S << endl;
    S.pop(); cout << S << endl;
    S.pop(); cout << S << endl;
}
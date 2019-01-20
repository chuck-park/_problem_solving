#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {

    int N;
    string str;
    int alphabet[26]; // 피연산자에 해당하는 값이 들어갈 배열
    stack<double> stack;

    cin >> N >> str;

    // 순서대로 각 알파벳에 해당하는 값을 넣어줌 ex) alphabet[1] = B에 해당하는 값
    for(int i=0; i<N; i++) {
        cin >> alphabet[i];
    }

    for(int i=0; i<str.length(); i++) {

        if(str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/') {
            double t1 = 0, t2 = 0;

            t1 = stack.top();
            stack.pop();
            t2 = stack.top();
            stack.pop();

            switch(str[i]) {
                case '+':
                    stack.push(t2 + t1);
                    break;
                case '-':
                    stack.push(t2 - t1);
                    break;
                case '*':
                    stack.push(t2 * t1);
                    break;
                case '/':
                    stack.push(t2 / t1);
                    break;
            }
        }
        else {
            stack.push(alphabet[str[i] - 'A']);
        }
    }
    printf("%.2f\n", stack.top());

//    cout을 이용한 위와 같은 표현
//    cout << fixed;
//    cout.precision(2);
//    cout << stack.top() << '\n';
}
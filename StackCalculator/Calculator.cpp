#include <iostream>
#include <string>
#include <cctype>
#include <stdexcept>
#include <sstream>

#define max_size 100

using namespace std;

template <typename T>
class Stack {
private:
    T array[max_size];
    int topindex;
public:
    Stack() : topindex(-1) {}

    void push(T value) {
        if (topindex >= max_size - 1) {
            throw overflow_error("Stack overflow");
        }
        array[++topindex] = value;
    }

    T pop() {
        if (!empty()) {
            return array[topindex--];
        } else {
            throw underflow_error("Stack is empty");
        }
    }

    T top() const {
        if (!empty()) {
            return array[topindex];
        } else {
            throw underflow_error("Stack is empty");
        }
    }

    bool empty() const {
        return topindex == -1;
    }

    int size() const {
        return topindex + 1;
    }
};

int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

string InfixToPostfix(const string& expression) {
    Stack<char> ops;
    string postfix;

    for (size_t i = 0; i < expression.length(); i++) {
        if (isspace(expression[i])) continue;

        if (isdigit(expression[i])) {
            // 숫자를 처리하는 부분
            while (i < expression.length() && isdigit(expression[i])) {
                postfix += expression[i++];
            }
            postfix += ' '; // 숫자 끝에 공백 추가
            i--; // 숫자 처리 후 증가된 i를 되돌림
        } else if (expression[i] == '(') {
            ops.push(expression[i]);
        } else if (expression[i] == ')') {
            while (!ops.empty() && ops.top() != '(') {
                postfix += ops.pop();
                postfix += ' ';
            }
            ops.pop(); // '(' 제거
        } else {
            while (!ops.empty() && precedence(ops.top()) >= precedence(expression[i])) {
                postfix += ops.pop();
                postfix += ' ';
            }
            ops.push(expression[i]);
        }
    }
    while (!ops.empty()) {
        postfix += ops.pop();
        postfix += ' ';
    }
    return postfix;
}

int EvaluatePostfix(const string& postfix) {
    Stack<int> values;
    istringstream iss(postfix);
    string token;
    while (iss >> token) {
        if (isdigit(token[0])) {
            values.push(stoi(token));
        } else {
            int b = values.pop();
            int a = values.pop();
            switch (token[0]) {
                case '+': values.push(a + b); break;
                case '-': values.push(a - b); break;
                case '*': values.push(a * b); break;
                case '/': values.push(a / b); break;
                default: throw invalid_argument("Invalid operator");
            }
        }
    }
    return values.top();
}

int main() {
    string expression;
    cout << "Stack 계산기" << endl;
    cout << "계산식을 입력해주세요 (괄호도 포함해주세요)(종료를 원하시면 exit을 입력해주세요)" << endl;

    while (true) {
        cout << "> ";
        getline(cin, expression);
        if (expression == "exit")
            break;

        try {
            string postfix = InfixToPostfix(expression);
            int result = EvaluatePostfix(postfix);
            cout << "결과는 : " << result << endl;
        } catch (const exception& e) {
            cout << "오류발생: " << e.what() << endl;
        }
    }
    return 0;
}

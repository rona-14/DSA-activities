#include <iostream>
using namespace std;

char stack[20];
int top = -1;
string stackOutput = "";

void push(char val) {
    stack[++top] = val;
    stackOutput += val;
}

char pop() {
   stackOutput.erase(top, 1); // Adjusted to erase the last char
    char val = stack[top--];
    return val;
}

char peek() {
    return stack[top];
}

int checkLevel(char operation) {
    if (operation == '(' || operation == ')') return 0;
    else if (operation == '^') return 1;
    else if (operation == '/' || operation == '*') return 2;
    else if (operation == '+' || operation == '-') return 3;
    return 0;
}

void convertToPostfix(string input) {
    string output = "";

    cout << "|  input | Stack  |  Output  |" << endl;
    cout << "|----------------------------|" << endl;

    for (int i = 0; i < input.length(); i++) {
        if (isdigit(input[i])) {
            output += input[i];
        } else {
            if (top == -1 || input[i] == '(' || peek() == '(') {
                push(input[i]);
            } else if (input[i] == ')') {
                while (top >= 0 && peek() != '(') {
                    output += pop();
                }
                if (top >= 0 && peek() == '(') {
                    pop(); // remove the '('
                }
            } else {
                while (top >= 0 && checkLevel(peek()) <= checkLevel(input[i])) {
                    output += pop();
                }
                push(input[i]);
            }
        }

        cout << "|   " << input[i] << "    |  " << stackOutput << "   |   " << output << "   |" << endl;
        cout << "|--------------------------|" << endl;
    }

    while (top >= 0) {
        output += pop();
    }

    cout << "The equivalent postfix is: " << output << endl;
}

int main() {
    string input = "(2+3)-5*4/5";
    convertToPostfix(input);
    return 0;
}
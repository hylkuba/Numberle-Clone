/**
 * @author Jakub Hýl <hylkuba@gmail.com>
 * @date 30.11.2023
*/

#include "controls.h"

#include <conio.h>
#include <string>
#include <iostream>

void CControls::waitForEnter() {
    while (true) {
        #ifdef _WIN32
            if (_kbhit()) {
                int key = _getch();
                if (key == 13) {  // Check if Enter key is pressed
                    break;
                }
            }
        #else
            // For non-Windows platforms, you may need to implement a different solution
            // based on terminal input handling libraries or system calls.
            // Example using standard input:
            char input;
            std::cin.get(input);
            if (input == '\n') {
                break;
            }
        #endif
    }
}

void CControls::printEquation(char equation[]) {
    separator();
    for (size_t i = 0; i < 8; i++) {
        std::cout << equation[i];
        separator();
    }
    std::cout << std::endl;
    separationLine();
}

void CControls::storeEquation(char equation[], int lNum1, int lNum2, int lNum3, int rNum, char op1, char op2) {
    int count = 0;
    int tmpCount = 0;
    for (size_t i = lNum1; i > 0; tmpCount++)
    {
        equation[count] = std::to_string(lNum1)[tmpCount];
        i /= 10;
        count++;
    }
    equation[count] = op1;
    count++;

    tmpCount = 0; 
    for (size_t i = lNum2; i > 0; tmpCount++)
    {
        equation[count] = std::to_string(lNum2)[tmpCount];
        i /= 10;
        count++;
    }

    // If Num3 exists, do the loop one more time
    if(lNum3 != -1) {
        equation[count] = op2;
        count++;

        tmpCount = 0; 
        for (size_t i = lNum3; i > 0; tmpCount++)
        {
            equation[count] = std::to_string(lNum3)[tmpCount];
            i /= 10;
            count++;
        }
    }
    equation[count] = '=';
    count++;

    tmpCount = 0; 
    for (size_t i = rNum; i > 0; tmpCount++)
    {
        equation[count] = std::to_string(rNum)[tmpCount];
        i /= 10;
        count++;
    }
}

void CControls::inputReset(int &num1, int &num2, int &num3, int &equal, char &op1, char &op2) {
    num1 = -1;
    num2 = -1;
    num3 = -1;
    equal = -1;
    op1 = '?';
    op2 = '?';
}

void CControls::input(int &num1, int &num2, int &num3, int &equal, char &op1, char &op2) {
    std::string input = "";
    num1 = -1;
    num2 = -1;
    num3 = -1;
    equal = -1;
    op1 = '?';
    op2 = '?';

    while(true) {
        std::cin >> input;
        if(splitEquation(input, num1, num2, num3, equal, op1, op2)) {
            break;
        }
    }
}

bool CControls::splitEquation(std::string equation, int &num1, int &num2, int &num3, int &equalVal, char &op1, char &op2) {
    if(equation.length() != 8) {
        std::cout << "Given equation is not long enough!" << std::endl;
        return false;
    }
    
    std::string tmp = "";
    bool num1exists = false;
    bool num2exists = false;
    bool equal = false;

    for (size_t i = 0; i < equation.length(); i++) {
        if(equation[i] == '+') {
            if(!numAssign(num1exists, num2exists, equal, num1, num2, num3, equalVal, tmp)) {
                return false;
            }

            if(!operatorAssign(num1exists, num2exists, equal, op1, op2, '+')) {
                return false;
            }
        } else if(equation[i] == '-') {
            if(!numAssign(num1exists, num2exists, equal, num1, num2, num3, equalVal, tmp)) {
                return false;
            }

            if(!operatorAssign(num1exists, num2exists, equal, op1, op2, '-')) {
                return false;
            }
        } else if(equation[i] == '*') {
            if(!numAssign(num1exists, num2exists, equal, num1, num2, num3, equalVal, tmp)) {
                return false;
            }

            if(!operatorAssign(num1exists, num2exists, equal, op1, op2, '*')) {
                return false;
            }
        } else if(equation[i] == '/') {
            if(!numAssign(num1exists, num2exists, equal, num1, num2, num3, equalVal, tmp)) {
                return false;
            }

            if(!operatorAssign(num1exists, num2exists, equal, op1, op2, '/')) {
                return false;
            }
        } else if(equation[i] == '=') {
            if(!num1exists || !num2exists || equal) {
                return false;
            }
            if(!numAssign(num1exists, num2exists, equal, num1, num2, num3, equalVal, tmp)) {
                return false;
            }
            equal = true;
        } else if(isdigit(equation[i])) {
            tmp += equation[i];
        } else {
            return false;
        }
    }
    if(tmp != "") {
        if(!numAssign(num1exists, num2exists, equal, num1, num2, num3, equalVal, tmp)) {
            return false;
        }
    }
    return checkSum(num1, num2, num3, op1, op2, equalVal);
}

 bool CControls::operatorAssign(bool num1Exists, bool num2Exists, bool equal, char &op1, char &op2, char operatorToBeAssigned) {
    if(equal) {
        return false;
    }

    if(num2Exists) {
        op2 = operatorToBeAssigned;
    } else if(num1Exists) {
        op1 = operatorToBeAssigned;
    } else {
        return false;
    }
    return true;
 }

 bool CControls::numAssign(bool &num1Exists, bool &num2Exists, bool &equal, int &num1, int &num2, int &num3, int &equalVal, std::string &value) {
    if(!num1Exists && !num2Exists && !equal) {
        num1 = stoi(value);
        num1Exists = true;
    } else if(num1Exists && !num2Exists && !equal) {
        num2 = stoi(value);
        num2Exists = true;
    } else if(num1Exists && num2Exists && !equal) {
        num3 = stoi(value);
    } else if(equal) {
        equalVal = stoi(value);
    } else {
        return false;
    }

    value = "";
    return true;
 }

 bool CControls::checkSum(int num1, int num2, int num3, char op1, char op2, int equal) {
    int sum = 0, val = 0;
    // Operator priority
    if(op2 == '*' || op2 == '/') {
        val = operation(num2, num3, op2);
        sum = operation(num1, val, op1);
    } else if(op2 != '?') {
        val = operation(num1, num2, op1);
        sum = operation(val, num3, op2);
    } else {
        sum = operation(num1, num2, op1);
    }
    return sum == equal;
 }

 bool CControls::gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a == 1 ? false : true;
}

int CControls::operation(int num1, int num2, char op) {
    switch(op) {
        case '+':
            return num1 + num2;
        case '-':
            return num1 - num2;
        case '/':
            if(num2 == 0 || !gcd(num1, num2)) {
                return -1;
            }
            return num1 / num2;
        case '*':
            return num1 * num2;
        default:
            return -1;
    }

    return -1;
}
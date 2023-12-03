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

void CControls::input(int &num1, int &num2, int &num3, int &equal, char &op1, char &op2) {
    std::string input = "";

    while(true) {
        std::cin >> input;
        if(splitEquation(input, num1, num2, num3, equal, op1, op2)) {
            break;
        }
        std::cout << "Given equation is invalid!" << std::endl;
    }
}

bool CControls::splitEquation(std::string equation, int &num1, int &num2, int &num3, int &equalVal, char &op1, char &op2) {
    if(equation.length() != 8) {
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
            equal = true;
            continue;
        } else if(isdigit(equation[i])) {
            tmp += equation[i];
        } else {
            return false;
        }
    }
    // TODO check the sum
    return true;
}

 bool CControls::operatorAssign(bool num1Exists, bool num2Exists, bool equal, char &op1, char &op2, char operatorToBeAssigned) {
    if(equal) {
        return false;
    }

    if(num1Exists) {
        op1 = operatorToBeAssigned;
    } else if(num2Exists) {
        op2 = operatorToBeAssigned;
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
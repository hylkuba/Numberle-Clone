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
    std::cout << "Equation is:" << std::endl;
    for (size_t i = 0; i < 8; i++)
    {
        std::cout << equation[i];
    }
    std::cout << std::endl;
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

    //std::cout << "Supposed: " << lNum1 << op1 << lNum2 << "=" << rNum << std::endl;
}
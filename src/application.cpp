/**
 * @author Jakub Hýl <hylkuba@gmail.com>
 * @date 30.11.2023
*/

#include "application.h"

#include <iostream>

int CApplication::run() {
    std::cout << "Program Started!" << std::endl;

    while(true) {
        generator.create(equation, leftEqNum1, leftEqNum2, leftEqNum3, rightEqNum);

        resetVar();
    }

    return 0;
}

void CApplication::resetVar() {
    leftEqNum1 = -1;
    leftEqNum2 = -1;
    leftEqNum3 = -1;
    rightEqNum = -1;

    for (size_t i = 0; i < 8; i++)
    {
        equation[i] = '0';
    }   
}
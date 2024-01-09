/**
 * @author Jakub Hýl <hylkuba@gmail.com>
 * @date 30.11.2023
*/

#include "application.h"

#include <iostream>

int CApplication::run() {
    ui.separationLine();
    resetVar();

    while(true) {
        generator.create(equation, leftEqNum1, leftEqNum2, leftEqNum3, rightEqNum, op1, op2);

        while(true) {
            controls.input(userNum1, userNum2, userNum3, userEqual, userOp1, userOp2);

            if(controls.equationEqual(leftEqNum1, leftEqNum2, leftEqNum3, rightEqNum, op1, op2,
                userNum1, userNum2, userNum3, userEqual, userOp1, userOp2)) {
                std::cout << "BREAKED" << std::endl;
                controls.waitForEnter();
            }
            controls.printEquation(equation);
            std::cout << leftEqNum1 << op1 << leftEqNum2  << "=" << rightEqNum << "  | " << leftEqNum3 << " " << op2 << std::endl;
            std::cout << userNum1 << userOp1 << userNum2 << "=" << userEqual << "  | " << userNum3 << " " << userOp2 << std::endl;

            controls.inputReset(userNum1, userNum2, userNum3, userEqual, userOp1, userOp2);
        }
        controls.congratulations(equation);

        std::cout << "Press ENTER to continue!" << std::endl;
        controls.waitForEnter();

        resetVar();
    }

    return 0;
}

void CApplication::resetVar() {
    leftEqNum1 = -1;
    leftEqNum2 = -1;
    leftEqNum3 = -1;
    rightEqNum = -1;
    op1 = '?';
    op2 = '?';

    for (size_t i = 0; i < 8; i++) {
        equation[i] = '0';
    }   
}
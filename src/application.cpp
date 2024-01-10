/**
 * @author Jakub Hýl <hylkuba@gmail.com>
 * @date 30.11.2023
*/

#include "application.h"

#include <iostream>
#include <cstdlib>

#ifdef _WIN32
    #define CLEAR_SCREEN "cls"
#else
    #define CLEAR_SCREEN "clear"
#endif


int CApplication::run() {
    
    std::system(CLEAR_SCREEN);
    resetVar();

    controls.welcomeMessage();

    while(true) {
        std::cout << "Please input your equation. Of length 8" << std::endl;
        controls.separationLine();

        generator.create(equation, leftEqNum1, leftEqNum2, leftEqNum3, rightEqNum, op1, op2);

        while(true) {
            std::string userEquation = controls.input(userNum1, userNum2, userNum3, userEqual, userOp1, userOp2);
            if(userEquation == "") {
                std::cout << "Invalid equation!!" << std::endl;
                continue;
            }

            if(controls.equationEqual(leftEqNum1, leftEqNum2, leftEqNum3, rightEqNum, op1, op2,
                userNum1, userNum2, userNum3, userEqual, userOp1, userOp2)) {
                break;
            }
            controls.equationCheck(equation, userEquation);
            controls.printEquation(equation);

            //controls.printEquation(equation);
            /*std::cout << "real: " << leftEqNum1 << op1 << leftEqNum2  << "=" << rightEqNum << "  | " << leftEqNum3 << " " << op2 << std::endl;
            std::cout << "user: " << userNum1 << userOp1 << userNum2 << "=" << userEqual << "  | " << userNum3 << " " << userOp2 << std::endl;*/

            controls.inputReset(userNum1, userNum2, userNum3, userEqual, userOp1, userOp2);
        }
        controls.congratulationsMessage(equation);

        std::cout << "Press ENTER to continue!" << std::endl;
        controls.waitForEnter();

        std::system(CLEAR_SCREEN);
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
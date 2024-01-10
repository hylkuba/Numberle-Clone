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

            prevEquations.push_back(userEquation);
            displayEquations();

            if(controls.equationEqual(leftEqNum1, leftEqNum2, leftEqNum3, rightEqNum, op1, op2,
                userNum1, userNum2, userNum3, userEqual, userOp1, userOp2)) {
                break;
            }

            //controls.printEquation(equation);

            controls.inputReset(userNum1, userNum2, userNum3, userEqual, userOp1, userOp2);
        }
        controls.congratulationsMessage(equation);

        std::cout << "Press ENTER to continue!" << std::endl;
        controls.waitForEnter();

        // Reset all important values
        std::system(CLEAR_SCREEN);
        resetVar();
    }

    return 0;
}

void CApplication::resetVar() {
    prevEquations.clear();

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

void CApplication::displayEquations() {
    std::system(CLEAR_SCREEN);
    
    for(const auto &eq : prevEquations) {
        controls.equationCheck(equation, eq);
    }
}
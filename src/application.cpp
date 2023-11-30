/**
 * @author Jakub Hýl <hylkuba@gmail.com>
 * @date 30.11.2023
*/

#include "application.h"

#include <iostream>

int CApplication::run() {
    std::cout << "Working" << std::endl;

    generator.create(equation, leftEqNum1, leftEqNum2, leftEqNum3, rightEqNum);

    return 0;
}
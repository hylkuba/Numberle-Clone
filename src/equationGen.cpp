/**
 * @author Jakub Hýl <hylkuba@gmail.com>
 * @date 30.11.2023
*/

#include "equationGen.h"

#include <iostream>
#include <random>
#include <cstdlib>
#include <ctime>

const char CEquationGen::operators[4] = {'+', '-', '*', '/'};
const char CEquationGen::digits[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

void CEquationGen::create(char equation[], int &lNum1, int &lNum2, int &lNum3, int &rNum) {
    int rndPos = spacePosition(generateProbability());

    if(rndPos == -1) return;
    
    switch(rndPos) {
        case 0:
            /*  
                *Equal sign on 5th index
                *Num1 and Num2 exists
                !Num3 doesn't
                ?Combinations of digit sizes (1-2), (2-1)
                ?rNum must be 3 digit
                *Only 2 options: Either multiplication of 2 numbers that exceeds 100 OR 91 + 9 and more
            */
        case 1:
            /*
                *Equal sign on 6th index
                *1st case:
                    *Num1 and Num2 exists
                    !Num3 doesn't
                    ?Combinations of digit sizes (1-3), (2-2), (3-1)
                *2nd case:
                    *Num1 and Num2 and Num3 all exists
                    ?The only possible combination (1-1-1)
                ?rNum must be 2 digits
            */
        case 2:
            /*
                *Equal sign on 7th index
                *1st case:
                    *Num1 and Num2 exists
                    !Num3 doesn't
                    ?Combinations of digit sizes (3-2), (2-3)
                *2nd case:
                    *Num1 and Num2 and Num3 all exists
                    ?Combinations of digit sizes (2-1-1), (1-2-1), (1-1-2)
                ?rNum must be 1 digit
            */
        default:
            // Shouldn't ever happen
            return;
    }
}

double CEquationGen::generateProbability() {
    std::srand(std::time(0));

    return static_cast<double>(std::rand()) / RAND_MAX;
}

int CEquationGen::generateRandomNumber(int numDigits) {
    if (numDigits <= 0) {
        std::cerr << "Invalid number of digits." << std::endl;
        return -1;
    }

    std::srand(static_cast<unsigned int>(std::time(0)));

    int minValue = static_cast<int>(std::pow(10, numDigits - 1));
    int maxValue = static_cast<int>(std::pow(10, numDigits) - 1);

    return std::rand() % (maxValue - minValue + 1) + minValue;
}

int CEquationGen::spacePosition(double rnd) {
    if(rnd < 0) {
        std::cerr << "Invalid number passed to generateProbability." << std::endl;
        return -1;
    }

    if(rnd < 0.3) return 0;
    
    if(rnd < 0.8) return 1;

    return 2;
}

void CEquationGen::fifthIndex(char equation[], int &lNum1, int &lNum2, int &lNum3, int &rNum) {

}

void CEquationGen::fifthIndex(char equation[], int &lNum1, int &lNum2, int &lNum3, int &rNum) {

}

void CEquationGen::fifthIndex(char equation[], int &lNum1, int &lNum2, int &lNum3, int &rNum) {

}
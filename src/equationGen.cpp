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

CEquationGen::CEquationGen() {
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
}

void CEquationGen::create(char equation[], int &lNum1, int &lNum2, int &lNum3, int &rNum, char &op1, char &op2) {
    int rndPos = spacePosition(generateProbability());

    if(rndPos == -1) return;

    //fifthIndex(equation, lNum1, lNum2, rNum, op1);
    switch(rndPos) {
        case 0:
           fifthIndex(equation, lNum1, lNum2, rNum, op1);
           lNum3 = -1;
           op2 = '?';
           break;
        case 1:
           sixthIndex(equation, lNum1, lNum2, lNum3, rNum, op1, op2);
           break;
        case 2:
            sixthIndex(equation, lNum1, lNum2, lNum3, rNum, op1, op2);
            //seventhIndex(equation, lNum1, lNum2, lNum3, rNum, op1, op2);
            break;
        default:
            // Shouldn't ever happen
            std::cerr << "Invalid value of rndPos in CEquationGen::create()." << std::endl;
    }
}

double CEquationGen::generateProbability() {
    int randomInt = std::rand();

    double randomDouble = static_cast<double>(randomInt) / RAND_MAX;

    return randomDouble;
}

int CEquationGen::generateRandomNumber(int numDigits) {
    if (numDigits <= 0) {
        std::cerr << "Invalid number of digits." << std::endl;
        return -1;
    }

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

/*  
    *Equal sign on 5th index
    *Num1 and Num2 exists
    !Num3 doesn't
    ?Combinations of digit sizes (1-2), (2-1)
    ?rNum must be 3 digit
    *Only 2 options: Either multiplication of 2 numbers that exceeds 100 OR 91 + 9 and more
*/
void CEquationGen::fifthIndex(char equation[], int &lNum1, int &lNum2, int &rNum, char &op1) {
    // Generate probability of which number is 2 digit
    if(generateProbability() < 0.5) {
        lNum1 = generateRandomNumber(2);
        lNum2 = generateRandomNumber(1);
        while(lNum1 * lNum2 < 100) {
            lNum1 = generateRandomNumber(2);
            lNum2 = generateRandomNumber(1);
        }
    } else {
        lNum1 = generateRandomNumber(1);
        lNum2 = generateRandomNumber(2);
        while(lNum1 * lNum2 < 100) {
            lNum1 = generateRandomNumber(1);
            lNum2 = generateRandomNumber(2);
        }
    }

    // If one number is bigger than or equal to 91, decide randomly if the binary operator will be multiplication or addition
    if(lNum1 >= 91 || lNum2 >= 91) {
        if(generateProbability() < 0.5) {
            rNum = lNum1 + lNum2;
            op1 = '+';
        } else {
            rNum = lNum1 * lNum2;
            op1 = '*';
        }
    } else {
        rNum = lNum1 * lNum2;
        op1 = '*';
    }
    controls.storeEquation(equation, lNum1, lNum2, -1, rNum, op1, '?');
}

/*
    *Equal sign on 6th index
    *1st case:
        *Num1 and Num2 exists
        !Num3 doesn't
        ?Combinations of digit sizes (1-3) (can't exist), (2-2), (3-1)
    *2nd case:
        *Num1 and Num2 and Num3 all exists
        ?The only possible combination (1-1-1)
    ?rNum must be 2 digits
*/
void CEquationGen::sixthIndex(char equation[], int &lNum1, int &lNum2, int &lNum3, int &rNum, char &op1, char &op2) {
    if(generateProbability() < 0.5) {
        // 1st case
        lNum3 = -1;
        op2 = '?';
        if(generateProbability() < 0.5) {
            // (2_2=2) xx+xx=xx || xx-xx=xx
            while(true) {
                lNum1 = generateRandomNumber(2);
                lNum2 = generateRandomNumber(2);

                if(lNum1 + lNum2 < 100) {
                    op1 = '+';
                    rNum = lNum1 + lNum2;
                    break;
                } else if(lNum1 - lNum2 > 0) {
                    op1 = '-';
                    rNum = lNum1 - lNum2;
                    break;
                }
            }

        } else {
            // (3_1=2) xxx-x=xx || xxx:x=xx
            while(true) {
                lNum1 = generateRandomNumber(3);
                lNum2 = generateRandomNumber(1);

                if(gcd(lNum1, lNum2)) {
                    op1 = '/';
                    rNum = lNum1 / lNum2;
                    break;
                } else if(lNum1 - lNum2 < 100) {
                    op1 = '-';
                    rNum = lNum1 - lNum2;
                    break;
                }
            }

        }
        controls.storeEquation(equation, lNum1, lNum2, -1, rNum, op1, '?');
    } else {
        // TODO: Keep it simple for now, no division here. Too complicated for now, add more variate generations
        // 2nd case (1_1_1=2) x+x+x=xx || x*x*x=xx || x*x-x=xx || x*x+x=xx
       while(true) {
            lNum1 = generateRandomNumber(1);
            lNum2 = generateRandomNumber(1);
            lNum3 = generateRandomNumber(1);

            if((lNum1 * lNum2 * lNum3 >= 10) && (lNum1 * lNum2 * lNum3 < 100)) {
                op1 = '*';
                op2 = '*';
                rNum = lNum1 * lNum2 * lNum3;
                break;
            } else if(lNum1 + lNum2 + lNum3 >= 10) {
                op1 = '+';
                op2 = '+';
                rNum = lNum1 + lNum2 + lNum3;
                break;
            }
        }

       controls.storeEquation(equation, lNum1, lNum2, lNum3, rNum, op1, op2);
    }
}

/*
    *Equal sign on 7th index
    *1st case:
        *Num1 and Num2 exists
        !Num3 doesn't
        ?Combinations of digit sizes (3-2), (2-3) (not possible to make valid equation)
    *2nd case:
        *Num1 and Num2 and Num3 all exists
        ?Combinations of digit sizes (2-1-1), (1-2-1), (1-1-2)
    ?rNum must be 1 digit
*/
void CEquationGen::seventhIndex(char equation[], int &lNum1, int &lNum2, int &lNum3, int &rNum, char &op1, char &op2) {
    if(generateProbability() < 0.5) {
        // 1st case
        lNum3 = -1;
        op2 = '?';

        // xxx-xx=x || xxx/xx=x
        while(true) {
            lNum1 = generateRandomNumber(3);
            lNum2 = generateRandomNumber(2);

            if(gcd(lNum1, lNum2) && (lNum1 / lNum2 < 10)) {
                op1 = '/';
                rNum = lNum1 / lNum2;
                break;
            } else if((lNum1 - lNum2 > 0) && (lNum1 - lNum2 < 10)) {
                op1 = '-';
                rNum = lNum1 - lNum2;
                break;
            }
        }
        controls.storeEquation(equation, lNum1, lNum2, -1, rNum, op1, '?');
    } else {
        // 2nd case
       double chance = generateProbability();
       if(chance < 0.4) {
            // (2_1_1=1) xx*x*x=x || xx+x+x=x || // TODO add more possibilitiess
            while(true) {
                lNum1 = generateRandomNumber(2);
                lNum2 = generateRandomNumber(1);
                lNum3 = generateRandomNumber(1);

                if(lNum1 * lNum2 * lNum3 < 10) {
                    op1 = '*';
                    op2 = '*';
                    rNum = lNum1 * lNum2 * lNum3;
                    break;
                } else if(lNum1 + lNum2 + lNum3 < 10) {
                    op1 = '+';
                    op2 = '+';
                    rNum = lNum1 + lNum2 + lNum3;
                    break;
                }
            }
       } else if(chance < 0.8) {
            // (1_2_1=1)
            while(true) {
                lNum1 = generateRandomNumber(1);
                lNum2 = generateRandomNumber(2);
                lNum3 = generateRandomNumber(1);

                if(lNum1 * lNum2 * lNum3 < 10) {
                    op1 = '*';
                    op2 = '*';
                    rNum = lNum1 * lNum2 * lNum3;
                    break;
                } else if(lNum1 + lNum2 + lNum3 < 10) {
                    op1 = '+';
                    op2 = '+';
                    rNum = lNum1 + lNum2 + lNum3;
                    break;
                }
            }
       } else {
            // (1_1_2=1)
            while(true) {
                lNum1 = generateRandomNumber(1);
                lNum2 = generateRandomNumber(1);
                lNum3 = generateRandomNumber(2);

                if(lNum1 * lNum2 * lNum3 < 10) {
                    op1 = '*';
                    op2 = '*';
                    rNum = lNum1 * lNum2 * lNum3;
                    break;
                } else if(lNum1 + lNum2 + lNum3 < 10) {
                    op1 = '+';
                    op2 = '+';
                    rNum = lNum1 + lNum2 + lNum3;
                    break;
                }
            }
       }
       controls.storeEquation(equation, lNum1, lNum2, lNum3, rNum, op1, op2);
    }
}

bool CEquationGen::gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a == 1 ? false : true;
}
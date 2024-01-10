/**
 * @author Jakub Hýl <hylkuba@gmail.com>
 * @date 30.11.2023
*/

#pragma once

#include "controls.h"

#define PROBABILITY_OF_TRUE 0.8

class CEquationGen {
public:
    /**
     * @brief Construct a new CEquationGen object
     * 
     */
    CEquationGen();
    
    /**
     * @brief Copy constructor, prohibited
     * 
     */
    CEquationGen(const CEquationGen &) = delete;

    /**
     * @brief Assignment operator, prohibited
     * 
     * @return CEquationGen&
     */
    CEquationGen & operator=(const CEquationGen &) = delete;

    /**
     * @brief Destroy the CEquationGen object set to default
     * 
     */
    ~CEquationGen() = default;

    /**
     * @brief Generates random equation
     * 
     * @param equation 
     * @param lNum1 
     * @param lNum2 
     * @param lNum3 
     * @param rNum 
     * @param op1
     * @param op2
     */
    void create(char equation[], int &lNum1, int &lNum2, int &lNum3, int &rNum, char &op1, char &op2);

private:
    /**
     * @brief Generates random double value between <0, 1)
     * 
     * @return Double value
     */
    double generateProbability();

    /**
     * @brief Generates random number
     * 
     * @param numDigits Number of digits of generated number
     * @return int 
     */
    int generateRandomNumber(int numDigits);

    /**
     * @brief Returns {0,1,2} based on the input value that must be between <0, 1)
     * 
     * @param rnd 
     * @return int Returns -1 if value in rnd is not in interval <0, 1)
     */
    int spacePosition(double rnd);

    /**
     * @brief Generates random equation
     * 
     * @param equation 
     * @param lNum1 
     * @param lNum2 
     * @param rNum 
     * @param op1
     */
    void fifthIndex(char equation[], int &lNum1, int &lNum2, int &rNum, char &op1);

    /**
     * @brief Generates random equation
     * 
     * @param equation 
     * @param lNum1 
     * @param lNum2 
     * @param lNum3 
     * @param rNum 
     * @param op1
     * @param op2
     */
    void sixthIndex(char equation[], int &lNum1, int &lNum2, int &lNum3, int &rNum, char &op1, char &op2);

    /**
     * @brief Generates random equation
     * 
     * @param equation 
     * @param lNum1 
     * @param lNum2 
     * @param lNum3 
     * @param rNum 
     * @param op1
     * @param op2
     */
    void seventhIndex(char equation[], int &lNum1, int &lNum2, int &lNum3, int &rNum, char &op1, char &op2);

    /**
     * @brief Checks whether 2 numbers are divisble by each other
     * 
     * @param a 
     * @param b 
     * @return true If they are
     * @return false If they aren't
     */
    bool gcd(int a, int b);
    
    CControls controls;
};
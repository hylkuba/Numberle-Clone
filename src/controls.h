/**
 * @author Jakub Hýl <hylkuba@gmail.com>
 * @date 30.11.2023
*/

#pragma once

#include "ui.h"

#include <string>

class CControls : public CUi {
public:
    /**
     * @brief Construct a new CControls object
     * 
     */
    CControls() = default;
    
    /**
     * @brief Copy constructor, prohibited
     * 
     */
    CControls(const CControls &) = delete;

    /**
     * @brief Assignment operator, prohibited
     * 
     * @return CControls&
     */
    CControls & operator=(const CControls &) = delete;

    /**
     * @brief Destroy the CControls object set to default
     * 
     */
    ~CControls() = default;

    /**
     * @brief Initiates loop that stops when the key "ENTER" is pressed
     * 
     */
    void waitForEnter();

    /**
     * @brief Prints entire equation
     * 
     * @param equation
     */
    void printEquation(char equation[]);

    /**
     * @brief Writes equation
     * 
     * @param equation 
     * @param lNum1 
     * @param lNum2 
     * @param lNum3 
     * @param rNum 
     * @param op1 
     * @param op2
     */
    void storeEquation(char equation[], int lNum1, int lNum2, int lNum3, int rNum, char op1, char op2);

    /**
     * @brief Asks user for input, checks if the equation is valid
     * 
     * @param num1 
     * @param num2 
     * @param num3 
     * @param equal 
     * @param op1 
     * @param op2 
     * @return std::string
     */
    std::string input(int &num1, int &num2, int &num3, int &equal, char &op1, char &op2);

    /**
     * @brief Resets all values of input
     * 
     * @param num1 
     * @param num2 
     * @param num3 
     * @param equal 
     * @param op1 
     * @param op2 
     */
    void inputReset(int &num1, int &num2, int &num3, int &equal, char &op1, char &op2);

    /**
     * @brief Checks whether the inputted equation is same as generated
     * 
     * @param leftEqNum1 
     * @param leftEqNum2 
     * @param leftEqNum3 
     * @param rightEqNum 
     * @param op1 
     * @param op2 
     * @param userNum1 
     * @param userNum2 
     * @param userNum3 
     * @param userEqual 
     * @param userOp1 
     * @param userOp2 
     * @return true 
     * @return false 
     */
    bool equationEqual(int leftEqNum1, int leftEqNum2, int leftEqNum3, int rightEqNum,
        char op1, char op2, int userNum1, int userNum2, int userNum3, int userEqual,
        char userOp1, char userOp2);

    /**
     * @brief Checks whether the position of characters are correct
     * 
     * @param equation 
     * @param userEquation 
     */
    void equationCheck(std::string equation, std::string userEquation);

    /**
     * @brief Congratulations message
     * 
     * @param equation 
     */
    void congratulationsMessage(char equation[]);

    /**
     * @brief Prints welcome message
     * 
     */
    void welcomeMessage();

private:
    /**
     * @brief Checks if equation is valid, Stores data to appropriate variables if it is
     * 
     * @param equation 
     * @param num1 
     * @param num2 
     * @param num3 
     * @param equal 
     * @param op1 
     * @param op2 
     * @return true 
     * @return false 
     */
    bool splitEquation(std::string equation, int &num1, int &num2, int &num3, int &equal, char &op1, char &op2);

    /**
     * @brief Checks which operator should be assigned
     * 
     * @param num1Exists 
     * @param num2Exists 
     * @param equal
     * @param op1 
     * @param op2 
     * @param operatorToBeAssigned 
     * @return true 
     * @return false 
     */
    bool operatorAssign(bool num1Exists, bool num2Exists, bool equal, char &op1, char &op2, char operatorToBeAssigned);

    /**
     * @brief Assigns number
     * 
     * @param num1Exists 
     * @param num2Exists 
     * @param equal
     * @param num1 
     * @param num2 
     * @param num3 
     * @param equalVal
     * @param value
     * @return true 
     * @return false 
     */
    bool numAssign(bool &num1Exists, bool &num2Exists, bool &equal, int &num1, int &num2, int &num3, int &equalVal, std::string &value);

    /**
     * @brief Checks if the equation is valid
     * 
     * @param num1 
     * @param num2 
     * @param num3 
     * @param op1 
     * @param op2 
     * @param equal 
     * @return true 
     * @return false 
     */
    bool checkSum(int num1, int num2, int num3, char op1, char op2, int equal);

    /**
     * @brief Find if two numbers are divisible by each other
     * 
     * @param a 
     * @param b 
     * @return true 
     * @return false 
     */
    bool gcd(int a, int b);

    /**
     * @brief Returns result of binary operation. -1 in case division doesnt work or there is division by 0
     * 
     * @param num1 
     * @param num2 
     * @param op 
     * @return int 
     */
    int operation(int num1, int num2, char op);

    /**
     * @brief Checks for occurance of character c in equation
     * 
     * @param equation 
     * @param c 
     * @return true 
     * @return false 
     */
    bool inEquation(std::string equation, char c);
};
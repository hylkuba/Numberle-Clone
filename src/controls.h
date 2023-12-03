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
     */
    void input(int &num1, int &num2, int &num3, int &equal, char &op1, char &op2);

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
};
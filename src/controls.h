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
};
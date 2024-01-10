/**
 * @author Jakub Hýl <hylkuba@gmail.com>
 * @date 30.11.2023
*/

#include "controls.h"
#include "ui.h"
#include "equationGen.h"

#include <vector>

class CApplication {
public:
    /**
     * @brief Construct a new CApplication object
     * 
     */
    CApplication() = default;
    
    /**
     * @brief Copy constructor, prohibited
     * 
     */
    CApplication(const CApplication &) = delete;

    /**
     * @brief Assignment operator, prohibited
     * 
     * @return CApplication&
     */
    CApplication & operator=(const CApplication &) = delete;

    /**
     * @brief Destroy the CApplication object set to default
     * 
     */
    ~CApplication() = default;

    /**
     * @brief Starts the game
     * 
     * @return 0 if game was successfully closed
     */
    int run();

private:
    /**
     * @brief Sets all nums to -1, equation to string of zeroes
     * 
     */
    void resetVar();

    /**
     * @brief Displays all previous equations
     * 
     */
    void displayEquations();

    /**
     * @brief Left equation numbers values
     * 
     */
    int leftEqNum1, leftEqNum2, leftEqNum3;
    
    /**
     * @brief Right equation number value
     * 
     */
    int rightEqNum;

    /**
     * @brief User inputted numbers
     * 
     */
    int userNum1, userNum2, userNum3, userEqual;

    /**
     * @brief User inputted char
     * 
     */
    char userOp1, userOp2;

    /**
     * @brief Chars representing binary operators. '?' when operator is null
     * 
     */
    char op1, op2;

    /**
     * @brief Equation to be found represented as array of 8 chars
     * 
     */
    char equation[8];

    /**
     * @brief Vector that stores all previous equations
     * 
     */
    std::vector<std::string> prevEquations;

    /**
     * @brief Equation generator object
     * 
     */
    CEquationGen generator;

    /**
     * @brief Ui controls
     * 
     */
    CUi ui;

    /**
     * @brief Control object
     * 
     */
    CControls controls;
};
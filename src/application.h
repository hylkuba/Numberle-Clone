/**
 * @author Jakub Hýl <hylkuba@gmail.com>
 * @date 30.11.2023
*/

#include "controls.h"
#include "ui.h"
#include "equation.h"
#include "equationGen.h"

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
     * @brief Equation to be found represented as array of 8 chars
     * 
     */
    char equation[8];

    CEquationGen generator;
};
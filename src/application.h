/**
 * @author Jakub Hýl <hylkuba@gmail.com>
 * @date 30.11.2023
*/

#include "controls.h"
#include "ui.h"

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
};
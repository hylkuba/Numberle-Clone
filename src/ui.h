/**
 * @author Jakub Hýl <hylkuba@gmail.com>
 * @date 30.11.2023
*/

#pragma once

class CUi {
public:
    /**
     * @brief Construct a new CUi object
     * 
     */
    CUi() = default;
    
    /**
     * @brief Copy constructor, prohibited
     * 
     */
    CUi(const CUi &) = delete;

    /**
     * @brief Assignment operator, prohibited
     * 
     * @return CUi&
     */
    CUi & operator=(const CUi &) = delete;

    /**
     * @brief Destroy the CUi object set to default
     * 
     */
    ~CUi() = default;

    /**
     * @brief Prints dash (-) symbols as a separator
     * 
     */
    void separationLine();

    /**
     * @brief Prints separator (|)
     * 
     */
    void separator();

    /**
     * @brief Prints character in green color
     * 
     * @param c Character to be displayed
     */
    void green(char c);

    /**
     * @brief Prints character in yellow color
     * 
     * @param c Character to be displayed
     */
    void yellow(char c);

    /**
     * @brief Prints character in gray color
     * 
     * @param c Character to be displayed
     */
    void gray(char c);
};
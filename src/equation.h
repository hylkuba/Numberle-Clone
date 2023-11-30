/**
 * @author Jakub Hýl <hylkuba@gmail.com>
 * @date 30.11.2023
*/

#pragma once

class CEquation {
public:
    /**
     * @brief Construct a new CEquation object
     * 
     */
    CEquation() = default;
    
    /**
     * @brief Copy constructor, prohibited
     * 
     */
    CEquation(const CEquation &) = delete;

    /**
     * @brief Assignment operator, prohibited
     * 
     * @return CEquation&
     */
    CEquation & operator=(const CEquation &) = delete;

    /**
     * @brief Destroy the CEquation object set to default
     * 
     */
    ~CEquation() = default;
};
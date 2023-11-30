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
};
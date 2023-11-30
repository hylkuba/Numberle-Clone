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
};
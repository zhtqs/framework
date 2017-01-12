#pragma once

#include "../definetions/role.h"

interface authentication_interface
{
public:
    virtual role& get_token() const;
    
public:
    authentication_interface();
    virtual ~authentication_interface();
};

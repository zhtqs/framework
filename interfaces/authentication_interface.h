#pragma once

#include "../definetions/role.h"

class authentication_interface
{
public:
    virtual role* get_token() const =0;
    
public:
    authentication_interface();
    virtual ~authentication_interface();
};

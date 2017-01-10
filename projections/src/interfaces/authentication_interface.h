#pragma once

#include "../definetions/role.h"

class __declspec(novtable) authentication_interface
{
public:
    virtual role* get_token() const;
    
public:
    authentication_interface();
    virtual ~authentication_interface();
};

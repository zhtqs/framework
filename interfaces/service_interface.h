#pragma once

#include "authentication_interface.h"
#include <string>

class service_interface : public authentication_interface
{
public:
    virtual std::wstring* get_name() const =0;
};

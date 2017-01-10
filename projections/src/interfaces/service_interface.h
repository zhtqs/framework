#pragma once

#include "authentication_interface.h"
#include "../object_memory_manager_interface.h"
#include <string>

class __declspec(novtable) service_interface : public authentication_interface,public object_memory_manager_interface
{
public:
    virtual std::wstring* get_name() const;
    
public:
    service_interface();
    virtual ~service_interface();
};

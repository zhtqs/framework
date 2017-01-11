#pragma once

#include "../definetions/role.h"
#include "authentication_interface.h"
#include "object_memory_manager_interface.h"

class __declspec(novtable) view_interface: public object_memory_manager_interface,public authentication_interface
{
public:
    virtual void set_view_visible(bool is_visible);
    virtual void reset_view();
    
public:
    view_interface();
    virtual ~view_interface();
};

#pragma once

#include "../definetions/role.h"
#include "authentication_interface.h"
#include "../object_memory_manager_interface.h"

class view_interface: public object_memory_manager_interface,public authentication_interface
{
public:
    virtual void set_view_visible(bool is_visible)=0;
    virtual void reset_view()=0;
    
public:
    view_interface();
    virtual ~view_interface();
};

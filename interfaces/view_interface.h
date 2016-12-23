#pragma once

#include "../definetions/role.h"

class view_interface
{
public:
    virtual void set_view_visible(bool is_visible)=0;
    virtual void reset_view()=0;
    virtual role* get_role() const =0;
    
public:
    view_interface();
    virtual ~view_interface();
};

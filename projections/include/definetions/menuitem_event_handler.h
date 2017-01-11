#pragma once

#include "../interfaces/object_memory_manager_interface.h"
#include <string>

class menuitem_event_handler: public object_memory_manager_interface
{
public:
    virtual void on_activicated(void* params)=0;
    
public:
    menuitem_event_handler();
    virtual ~menuitem_event_handler();
};

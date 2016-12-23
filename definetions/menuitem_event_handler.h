#pragma once

#include <string>

class menuitem_event_handler
{
public:
    virtual void on_activicated(void* params)=0;
    virtual void free()=0;
    virtual int get_object_size()=0;
    
public:
    menuitem_event_handler();
    virtual ~menuitem_event_handler();
};

#pragma once

#include <string>
#include <vector>
#include "menuitem_event_handler.h"

class subscriber_information final
{
private:
    bool is_remember_callback;
    
public:
    std::string id;
    std::wstring name;
    menuitem_event_handler* callback;
    
public:
    void remember_callback(menuitem_event_handler* callback);
    
public:
    subscriber_information();
    virtual ~subscriber_information();
};

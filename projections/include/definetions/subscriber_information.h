#pragma once

#include <string>
#include <vector>
#include "../public.h"
#include "menuitem_event_handler.h"

class FRAMEWORK_API subscriber_information final
{
    GET_PROPERTY(bool,is_remember_callback);
    POINTER_PROPERTY(std::string,id);
    POINTER_PROPERTY(std::wstring,name);
    POINTER_PROPERTY(menuitem_event_handler,callback);
    
public:
    subscriber_information();
    virtual ~subscriber_information();
};

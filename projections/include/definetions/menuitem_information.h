
#pragma once

#include <vector>
#include "menuitem_event_handler.h"

class FRAMEWORK_API menuitem_information final
{
    POINTER_PROPERTY(std::wstring,name);
    POINTER_PROPERTY(std::wstring,display_name);
    POINTER_PROPERTY(menuitem_event_handler,handler);
    POINTER_PROPERTY(std::vector<byte>,image_data);

public:
    menuitem_information();
    virtual ~menuitem_information();
};

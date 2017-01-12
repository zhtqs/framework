
#pragma once

#include <vector>
#include "menuitem_event_handler.h"

class menuitem_information final
{
    DATA_PROPERTY(std::wstring,name);
    DATA_PROPERTY(std::wstring,display_name);
    POINTER_PROPERTY(menuitem_event_handler,handler);
    DATA_PROPERTY(std::vector<byte>,image_data);

public:
    menuitem_information();
    virtual ~menuitem_information();
};

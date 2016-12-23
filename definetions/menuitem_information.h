
#pragma once

#include <vector>
#include "menuitem_event_handler.h"

class menuitem_information final
{
public:
    std::wstring name;
    std::wstring display_name;
    menuitem_event_handler* handler;
    std::vector<unsigned char> image_data;
    
public:
    void set_image_data(unsigned char* data,int length);
    
public:
    menuitem_information();
    virtual ~menuitem_information();
};

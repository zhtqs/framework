
#pragma once

#include <iostream>
#include "../definetions/menuitem_information.h"

class module_interface
{
public:
    virtual std::wstring* get_path() const =0;
    virtual std::wstring* get_version() const =0;
    virtual std::wstring* get_name() const =0;
    virtual std::vector<menuitem_information>* get_menuitems() const =0;
    virtual void regist_views()=0;
};

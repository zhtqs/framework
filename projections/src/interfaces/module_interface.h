
#pragma once

#include <iostream>
#include "../object_memory_manager_interface.h"
#include "../definetions/menuitem_information.h"
#include "view_manager_interface.h"
#include "event_manager_interface.h"
#include "service_manager_interface.h"

class module_interface: public object_memory_manager_interface
{
public:
    virtual std::wstring* get_path() const =0;
    virtual std::wstring* get_version() const =0;
    virtual std::wstring* get_name() const =0;
    virtual std::vector<menuitem_information>* get_menuitems() =0;
    virtual void regist_views(view_manager_interface* view_manager)=0;
    virtual void regist_services(service_manager_interface* service_manager)=0;
    virtual void regist_events(event_manager_interface* event_manager)=0;
    
public:
    module_interface();
    virtual ~module_interface();
};

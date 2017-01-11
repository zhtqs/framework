
#pragma once

#include <iostream>
#include "object_memory_manager_interface.h"
#include "../definetions/menuitem_information.h"
#include "view_manager_interface.h"
#include "event_manager_interface.h"
#include "service_manager_interface.h"

class __declspec(novtable) module_interface: public object_memory_manager_interface
{
public:
    virtual std::wstring* get_path() const ;
    virtual std::wstring* get_version() const ;
    virtual std::wstring* get_name() const ;
    virtual std::vector<menuitem_information>* get_menuitems() ;
    virtual void regist_views(view_manager_interface* view_manager);
    virtual void regist_services(service_manager_interface* service_manager);
    virtual void regist_events(event_manager_interface* event_manager);
    
public:
    module_interface();
    virtual ~module_interface();
};

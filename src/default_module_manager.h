#pragma once

#include <vector>
#include "interfaces/module_interface.h"
#include "default_service_manager.h"
#include "default_view_manager.h"
#include "default_event_manager.h"

class default_module_manager
{
private:
    std::vector<common_information<module_interface*> > modules;
    default_event_manager event_manager;
    default_service_manager service_manager;
    default_view_manager view_manager;
    
public:
    static default_module_manager instance;
    
public:
    service_manager_interface* get_service_manager() const;
    view_manager_interface* get_view_manager() const;
    event_manager_interface* get_event_manager() const;
    std::vector<common_information<module_interface*> > get_modules() &;
    
    void clear();
    module_interface* get_module(std::wstring& name);
    void regist(module_interface* module);
    
private:
    default_module_manager();
    ~default_module_manager();
};


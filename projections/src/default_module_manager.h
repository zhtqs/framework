#pragma once

#include <vector>
#include "interfaces/module_interface.h"
#include "definetions/common_information.h"

class default_module_manager
{
private:
    std::vector<common_information<module_interface*> > modules;
    event_manager_interface* event_manager;
    service_manager_interface* service_manager;
    view_manager_interface* view_manager;
    
public:
    static default_module_manager instance;
    
public:
    service_manager_interface* get_service_manager();
    view_manager_interface* get_view_manager();
    event_manager_interface* get_event_manager();
    std::vector<common_information<module_interface*> > get_modules() &;
    
public:
    void clear();
    module_interface* get_module(std::wstring& name);
    void regist(module_interface* module,std::wstring& name);
    void remove(module_interface* module);
    void remove(std::wstring& name);
    bool is_exists(std::wstring& name);
    bool is_exists(module_interface* module);
    void init_modules();
    
    void set_event_manager(event_manager_interface* const event_manager);
    void set_service_manager(service_manager_interface* service_manager);
    void set_view_manager(view_manager_interface* view_manager);
    
private:
    default_module_manager();
    ~default_module_manager();
};


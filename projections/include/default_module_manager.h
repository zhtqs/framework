#pragma once

#include <vector>
#include "interfaces/module_interface.h"
#include "definetions/common_information.h"

class FRAMEWORK_API default_module_manager
{
    GET_POINTER_PROPERTY(event_manager_interface,event_manager);
    GET_POINTER_PROPERTY(service_manager_interface,service_manager);
    GET_POINTER_PROPERTY(view_manager_interface,view_manager);
    GET_POINTER_PROPERTY(std::vector<common_information<module_interface*> >,modules);
    
private:
    static default_module_manager minstance;
    
public:
    void clear();
    module_interface* get_module(std::wstring& name);
    void regist(module_interface* module,std::wstring& name);
    void remove(module_interface* module);
    void remove(std::wstring& name);
    bool is_exists(std::wstring& name);
    bool is_exists(module_interface* module);
    void init_modules();
    
public:
    static default_module_manager& get_instance();
    
private:
    default_module_manager();
    ~default_module_manager();
};


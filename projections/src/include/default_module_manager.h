#pragma once

#include <vector>
#include "module_manager_interface.h"
#include "interfaces/module_interface.h"
#include "definetions/common_information.h"

class default_module_manager:public module_manager_interface
{
    GET_POINTER_PROPERTY(event_manager_interface,event_manager);
    GET_POINTER_PROPERTY(service_manager_interface,service_manager);
    GET_POINTER_PROPERTY(view_manager_interface,view_manager);
    GET_PROPERTY(std::vector<common_information<module_interface*> >,modules);
    
private:
    std::wstring path;
    std::wstring version;
    std::wstring name;
    std::vector<menuitem_information> menuitems;
    static default_module_manager minstance;
    
public:
    //default_module_manager_interface
    void clear();
    module_interface* get_module(std::wstring& name);
    void regist(module_interface* module,std::wstring& name);
    void remove(module_interface* module);
    void remove(std::wstring& name);
    bool is_exists(std::wstring& name);
    bool is_exists(module_interface* module);
    void init_modules();
    
public:
    std::wstring get_path() const ;
    std::wstring get_version() const ;
    std::wstring get_name() const ;
    std::vector<menuitem_information> get_menuitems() const;
    void regist_views(view_manager_interface* view_manager);
    void regist_services(service_manager_interface* service_manager);
    void regist_events(event_manager_interface* event_manager);
    
    //object_memory_manager_interface
    int get_size() const;
    void free();
    void clone(object_memory_manager_interface* object) const;
    
public:
    static default_module_manager& get_instance();
    
private:
    default_module_manager();
    ~default_module_manager();
};


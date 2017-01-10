#pragma once

#include <vector>
#include "interfaces/module_interface.h"
#include "definetions/common_information.h"

class default_module_manager
{
private:
    std::vector<common_information<module_interface*> > modules;
    service_manager_interface* mservice_manager;
    event_manager_interface* mevent_manager;
    view_manager_interface* mview_manager;
    static default_module_manager minstance;
    
public:
    __declspec(property(get=get_event_manager,put=set_event_manager)) event_manager_interface* event_manager;
    __declspec(property(get=get_service_manager,put=set_service_manager)) service_manager_interface* service_manager;
    __declspec(property(get=get_view_manager,put=set_view_manager)) view_manager_interface* view_manager;
    
public:
    void clear();
    module_interface* get_module(std::wstring& name);
    void regist(module_interface* module,std::wstring& name);
    void remove(module_interface* module);
    void remove(std::wstring& name);
    bool is_exists(std::wstring& name);
    bool is_exists(module_interface* module);
    void init_modules();
    
    view_manager_interface* get_view_manager() const;
    service_manager_interface* get_service_manager() const;
    event_manager_interface* get_event_manager() const;
    void set_event_manager(event_manager_interface* event_manager);
    void set_service_manager(service_manager_interface* service_manager);
    void set_view_manager(view_manager_interface* view_manager);
    std::vector<common_information<module_interface*> > get_modules() const &;
    
public:
    static default_module_manager& get_instance();
    
private:
    default_module_manager();
    ~default_module_manager();
};


#pragma once

#include "interfaces/service_manager_interface.h"
#include "definetions/common_information.h"
#include <vector>

class default_service_manager: public service_manager_interface
{
private:
    std::vector<common_information<service_interface*> > services;
    
public:
    //service_manager_interface
    void clear();
    service_interface* get_service_by_name(std::wstring& name);
    bool is_exists(std::wstring& name);
    bool is_exists(service_interface* service);
    void regist(service_interface* service,std::wstring& name);
    void remove(service_interface* service);
    void remove(std::wstring& name);
    
    //object_memory_manager_interface
    int get_size();
    void free();
    void clone(object_memory_manager_interface* object);
    
public:
    default_service_manager();
    virtual ~default_service_manager();
};

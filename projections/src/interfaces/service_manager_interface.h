#pragma once

#include "service_interface.h"
#include "../object_memory_manager_interface.h"

class __declspec(novtable) service_manager_interface: public object_memory_manager_interface
{
public:
    virtual void clear();
    virtual service_interface* get_service_by_name(std::wstring& name);
    virtual bool is_exists(std::wstring& name);
    virtual bool is_exists(service_interface* service);
    virtual void regist(service_interface* service,std::wstring& name);
    virtual void remove(service_interface* service);
    virtual void remove(std::wstring& name);
    
public:
    service_manager_interface();
    virtual ~service_manager_interface();
};

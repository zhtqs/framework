#pragma once

#include "service_interface.h"
#include "../object_memory_manager_interface.h"

class service_manager_interface: public object_memory_manager_interface
{
public:
    virtual void clear()=0;
    virtual service_interface* get_service_by_name(std::wstring& name)=0;
    virtual bool is_exists(std::wstring& name)=0;
    virtual bool is_exists(service_interface* service)=0;
    virtual void regist(service_interface* service,std::wstring& name)=0;
    virtual void remove(service_interface* service)=0;
    virtual void remove(std::wstring& name)=0;
    
public:
    service_manager_interface();
    virtual ~service_manager_interface();
};

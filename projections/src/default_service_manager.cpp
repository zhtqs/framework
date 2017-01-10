#include "default_service_manager.h"
#include <algorithm>

default_service_manager::default_service_manager()
{
}

default_service_manager::~default_service_manager()
{
    clear();
}

void default_service_manager::clear()
{
    for(auto it : services)
    {
        it.data->free();
    }
    services.clear();
}

bool default_service_manager::is_exists(service_interface* service)
{
    return std::find_if(services.begin(),services.end(),[=](common_information<service_interface*>& x)->bool
    {
        return x.data == service;
    })!=services.end();
}

bool default_service_manager::is_exists(std::wstring& name)
{
    return std::find_if(services.begin(),services.end(),[=](common_information<service_interface*>& x)->bool
    {
        return x.name==name;
    })!=services.end();
}

void default_service_manager::regist(service_interface* service, std::wstring& name)
{
    common_information<service_interface*> data;
    data.name=name;
    service->clone(data.data);
    services.push_back(data);
}

void default_service_manager::remove(service_interface* service)
{
    auto found=std::find_if(services.begin(),services.end(),[=](common_information<service_interface*>& x)->bool
    {
        return x.data == service;
    });
    if(found!=services.end())
    {
        services.erase(found);
    }
}

void default_service_manager::remove(std::wstring& name)
{
    auto found=std::find_if(services.begin(),services.end(),[=](common_information<service_interface*>& x)->bool
    {
        return x.name==name;
    });
    if(found!=services.end())
    {
        services.erase(found);
    }
}

service_interface* default_service_manager::get_service_by_name(std::wstring& name)
{
    auto found=std::find_if(services.begin(),services.end(),[=](common_information<service_interface*>& x)->bool
    {
        return x.name==name;
    });
    if(found!=services.end())
    {
        return found->data;
    }
    return NULL;
}

void default_service_manager::clone(object_memory_manager_interface* object)
{
    auto copy=new default_service_manager;
    copy->services=services;
    for(auto& service : copy->services)
    {
        service.data->clone(service.data);
    }
    object=copy;
}

void default_service_manager::free()
{
    clear();
    delete this;
}

int default_service_manager::get_size()
{
    return sizeof(default_service_manager);
}



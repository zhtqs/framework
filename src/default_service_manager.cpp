#include "default_service_manager.h"

default_service_manager::default_service_manager()
{
}

default_service_manager::~default_service_manager()
{
    clear();
}

void default_service_manager::clear()
{
    std::vector<common_information<service_interface*> >::iterator it=services.begin();
    while(it!=services.end())
    {
        it->data->free();
        it++;
    }
    services.clear();
}

bool default_service_manager::is_exists(service_interface* service)
{
    bool found=false;
    std::vector<common_information<service_interface*> >::iterator it=services.begin();
    while(it!=services.end())
    {
        if(it->data==service)
        {
            found=true;
            break;
        }
        it++;
    }
    return found;
}

bool default_service_manager::is_exists(std::wstring& name)
{
    bool found=false;
    std::vector<common_information<service_interface*> >::iterator it=services.begin();
    while(it!=services.end())
    {
        if(it->name==name)
        {
            found=true;
            break;
        }
    }
    return found;
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
    std::vector<common_information<service_interface*> >::iterator found=services.end();
    std::vector<common_information<service_interface*> >::iterator it=services.begin();
    for(;it!=services.end();it++)
    {
        if(it->data==service)
        {
            found=it;
            break;
        }
    }
    if(found!=services.end())
    {
        services.erase(found);
    }
}

void default_service_manager::remove(std::wstring& name)
{
    std::vector<common_information<service_interface*> >::iterator found=services.end();
    std::vector<common_information<service_interface*> >::iterator it=services.begin();
    for(;it!=services.end();it++)
    {
        if(it->name==name)
        {
            found=it;
            break;
        }
    }
    if(found!=services.end())
    {
        services.erase(found);
    }
}

service_interface* default_service_manager::get_service_by_name(std::wstring& name)
{
    std::vector<common_information<service_interface*> >::iterator found=services.end();
    std::vector<common_information<service_interface*> >::iterator it=services.begin();
    for(;it!=services.end();it++)
    {
        if(it->name==name)
        {
            found=it;
            break;
        }
    }
    if(found!=services.end())
    {
        return found->data;
    }
    return NULL;
}

void default_service_manager::clone(object_memory_manager_interface* object)
{
    default_service_manager* copy=new default_service_manager;
    copy->services=services;
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



#include "default_module_manager.h"
#include <algorithm>

default_module_manager::default_module_manager()
{
}

default_module_manager::~default_module_manager()
{
    clear();
}

service_manager_interface * default_module_manager::get_service_manager()
{
    return &service_manager;
}

view_manager_interface * default_module_manager::get_view_manager()
{
    return &view_manager;
}

event_manager_interface * default_module_manager::get_event_manager()
{
    return &event_manager;
}

std::vector<common_information<module_interface *> > default_module_manager::get_modules() &
{
    return modules;
}

void default_module_manager::clear()
{
    service_manager.clear();
    view_manager.clear();
    event_manager.clear();
    for(auto it : modules)
    {
        it.data->free();
    }
    modules.clear();
}

module_interface * default_module_manager::get_module(std::wstring& name)
{
    auto found=std::find_if(modules.begin(),modules.end(),[=](common_information<module_interface*>& x)->bool
    {
        return x.name==name;
    });
    if(found!=modules.end())
    {
        return found->data;
    }
    return nullptr;
}

void default_module_manager::regist(module_interface* module, std::wstring& name)
{
    common_information<module_interface *>  mi;
    mi.name=name;
    module->clone(mi.data);
    modules.push_back(mi);
}

void default_module_manager::remove(module_interface* module)
{
    auto found=std::find_if(modules.begin(),modules.end(),[=](common_information<module_interface*>& x)->bool
    {
        return x.data==module;
    });
    if(found!=modules.end())
    {
        modules.erase(found);
    }
}






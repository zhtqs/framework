#include "default_module_manager.h"
#include <algorithm>
#include "default_event_manager.h"
#include "default_service_manager.h"
#include "default_view_manager.h"

default_module_manager default_module_manager::minstance;

default_module_manager::default_module_manager()
{
    mservice_manager=new default_service_manager;
    mevent_manager=new default_event_manager;
    mview_manager=new default_view_manager;
}

default_module_manager::~default_module_manager()
{
    clear();
}

service_manager_interface * default_module_manager::get_service_manager() const
{
    return mservice_manager;
}

view_manager_interface * default_module_manager::get_view_manager() const
{
    return mview_manager;
}

event_manager_interface * default_module_manager::get_event_manager() const
{
    return mevent_manager;
}

std::vector<common_information<module_interface *> > default_module_manager::get_modules() const &
{
    return modules;
}

void default_module_manager::clear()
{
    service_manager->free();
    view_manager->free();
    event_manager->free();
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

void default_module_manager::remove(std::wstring& name)
{
    auto found=std::find_if(modules.begin(),modules.end(),[=](common_information<module_interface*>& x)->bool
    {
        return x.name==name;
    });
    if(found!=modules.end())
    {
        modules.erase(found);
    }
}

bool default_module_manager::is_exists(std::wstring& name)
{
    auto found=std::find_if(modules.begin(),modules.end(),[=](common_information<module_interface*>& x)->bool
    {
        return x.name==name;
    });
    return found!=modules.end();
}

bool default_module_manager::is_exists(module_interface* module)
{
    auto found=std::find_if(modules.begin(),modules.end(),[=](common_information<module_interface*>& x)->bool
    {
        return x.data==module;
    });
    return found!=modules.end();
}

void default_module_manager::init_modules()
{
    for(auto& module : modules)
    {
        module.data->regist_services(service_manager);
    }
    for(auto& module : modules)
    {
        module.data->regist_events(event_manager);
    }
    for(auto& module : modules)
    {
        module.data->regist_views(view_manager);
    }
}

void default_module_manager::set_event_manager(event_manager_interface * event_manager)
{
    event_manager->clone(mevent_manager);
}

void default_module_manager::set_service_manager(service_manager_interface* service_manager)
{
    service_manager->clone(mservice_manager);
}

void default_module_manager::set_view_manager(view_manager_interface* view_manager)
{
    view_manager->clone(mview_manager);
}

default_module_manager& default_module_manager::get_instance()
{
    return minstance;
}




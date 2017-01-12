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
    mmodules=new std::vector<common_information<module_interface*> >;
}

default_module_manager::~default_module_manager()
{
    clear();
}

IMPLEMENT_POINTER_PROPERTY(default_module_manager,event_manager_interface,event_manager)

IMPLEMENT_POINTER_PROPERTY(default_module_manager,service_manager_interface,service_manager)

IMPLEMENT_POINTER_PROPERTY(default_module_manager,view_manager_interface,view_manager)

IMPLEMENT_POINTER_PROPERTY(default_module_manager,std::vector<common_information<module_interface*> >,modules)

void default_module_manager::clear()
{
    service_manager->free();
    view_manager->free();
    event_manager->free();
    for(auto it : *mmodules)
    {
        it.data->free();
    }
    mmodules->clear();
    delete mmodules;
}

module_interface * default_module_manager::get_module(std::wstring& name)
{
    auto found=std::find_if(mmodules->begin(),mmodules->end(),[=](common_information<module_interface*>& x)->bool
    {
        return *x.name==name;
    });
    if(found!=mmodules->end())
    {
        return found->data;
    }
    return nullptr;
}

void default_module_manager::regist(module_interface* module, std::wstring& name)
{
    common_information<module_interface *>  mi;
    *mi.name=name;
    module->clone(mi.data);
    mmodules->push_back(mi);
}

void default_module_manager::remove(module_interface* module)
{
    auto found=std::find_if(mmodules->begin(),mmodules->end(),[=](common_information<module_interface*>& x)->bool
    {
        return x.data==module;
    });
    if(found!=mmodules->end())
    {
        mmodules->erase(found);
    }
}

void default_module_manager::remove(std::wstring& name)
{
    auto found=std::find_if(mmodules->begin(),mmodules->end(),[=](common_information<module_interface*>& x)->bool
    {
        return *x.name==name;
    });
    if(found!=mmodules->end())
    {
        mmodules->erase(found);
    }
}

bool default_module_manager::is_exists(std::wstring& name)
{
    auto found=std::find_if(mmodules->begin(),mmodules->end(),[=](common_information<module_interface*>& x)->bool
    {
        return *x.name==name;
    });
    return found!=mmodules->end();
}

bool default_module_manager::is_exists(module_interface* module)
{
    auto found=std::find_if(mmodules->begin(),mmodules->end(),[=](common_information<module_interface*>& x)->bool
    {
        return x.data==module;
    });
    return found!=mmodules->end();
}

void default_module_manager::init_modules()
{
    for(auto& module : *mmodules)
    {
        module.data->regist_services(service_manager);
    }
    for(auto& module : *mmodules)
    {
        module.data->regist_events(event_manager);
    }
    for(auto& module : *mmodules)
    {
        module.data->regist_views(view_manager);
    }
}

default_module_manager& default_module_manager::get_instance()
{
    return minstance;
}




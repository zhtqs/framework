#include "default_view_manager.h"

default_view_manager::default_view_manager()
{
}

default_view_manager::~default_view_manager()
{
}

void default_view_manager::clear()
{
    views.clear();
}

void default_view_manager::clone(object_memory_manager_interface* object)
{
    default_view_manager* copy=new default_view_manager;
    copy->views=views;
    object=copy;
}

void default_view_manager::free()
{
    for(std::vector<common_information<view_interface*> >::iterator it=views.begin();it!=views.end();it++)
    {
        it->data->free();
    }
    clear();
    delete this;
}


int default_view_manager::get_size()
{
    return sizeof(default_view_manager);
}


bool default_view_manager::is_exists(std::wstring& name)
{
    bool found=false;
    for(std::vector<common_information<view_interface*> >::iterator it=views.begin();it!=views.end();it++)
    {
        if(it->name==name)
        {
            found=true;
            break;
        }
    }
    return found;
}


bool default_view_manager::is_exists(view_interface* view)
{
    bool found=false;
    for(std::vector<common_information<view_interface*> >::iterator it=views.begin();it!=views.end();it++)
    {
        if(it->data==view)
        {
            found=true;
            break;
        }
    }
    return found;
}


void default_view_manager::regist(view_interface* view, std::wstring& name)
{
    common_information<view_interface*> data;
    data.name=name;
    view->clone(data.data);
    views.push_back(data);
}


void default_view_manager::remove(std::wstring& name)
{
    std::vector<common_information<view_interface*> >::iterator found=views.end(),it=views.begin();
    for(;it!=views.end();it++)
    {
        if(it->name==name)
        {
            found=it;
            break;
        }
    }
    if(found!=views.end())
    {
        found->data->free();
        views.erase(found);
    }
}


void default_view_manager::remove(view_interface* view)
{
    std::vector<common_information<view_interface*> >::iterator found=views.end(),it=views.begin();
    for(;it!=views.end();it++)
    {
        if(it->data==view)
        {
            found=it;
            break;
        }
    }
    if(found!=views.end())
    {
        found->data->free();
        views.erase(found);
    }
}

view_interface * default_view_manager::get_view_by_name(std::wstring& name)
{
    std::vector<common_information<view_interface*> >::iterator found=views.end(),it=views.begin();
    for(;it!=views.end();it++)
    {
        if(it->name==name)
        {
            found=it;
            break;
        }
    }
    if(found!=views.end())
    {
        return found->data;
    }
    return NULL;
}


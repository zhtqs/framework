#include "default_view_manager.h"
#include <algorithm>

default_view_manager::default_view_manager()
{
}

default_view_manager::~default_view_manager()
{
    clear();
}

void default_view_manager::clear()
{
    for(auto it : views)
    {
        it.data->free();
    }
    views.clear();
}

void default_view_manager::clone(object_memory_manager_interface* object)
{
    auto copy=new default_view_manager;
    copy->views=views;
    for(auto& view : copy->views)
    {
        view.data->clone(view.data);
    }
    object=copy;
}

void default_view_manager::free()
{
    clear();
    delete this;
}


int default_view_manager::get_size()
{
    return sizeof(default_view_manager);
}


bool default_view_manager::is_exists(std::wstring& name)
{
    return std::find_if(views.begin(),views.end(),[=](common_information<view_interface*>& x)->bool
    {
        return x.name==name;
    })!=views.end();
}


bool default_view_manager::is_exists(view_interface* view)
{
    return std::find_if(views.begin(),views.end(),[=](common_information<view_interface*>& x)->bool
    {
        return x.data==view;
    })!=views.end();
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
    auto found=std::find_if(views.begin(),views.end(),[=](common_information<view_interface*>& x)->bool
    {
        return x.name==name;
    });
    if(found!=views.end())
    {
        found->data->free();
        views.erase(found);
    }
}


void default_view_manager::remove(view_interface* view)
{
    auto found=std::find_if(views.begin(),views.end(),[=](common_information<view_interface*>& x)->bool
    {
        return x.data==view;
    });
    if(found!=views.end())
    {
        found->data->free();
        views.erase(found);
    }
}

view_interface * default_view_manager::get_view_by_name(std::wstring& name)
{
    auto found=std::find_if(views.begin(),views.end(),[=](common_information<view_interface*>& x)->bool
    {
        return x.name==name;
    });
    if(found!=views.end())
    {
        return found->data;
    }
    return NULL;
}


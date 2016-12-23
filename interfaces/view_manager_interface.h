#pragma once

#include <vector>
#include <string>
#include "view_interface.h"

class view_manager_interface
{
public:
    virtual void clear()=0;
    virtual view_interface* get_view_by_name(std::wstring& name)=0;
    template <typename T> T* get_view();
    virtual bool is_exists(std::wstring& name)=0;
    virtual bool is_exists(view_interface* view)=0;
    virtual void regist(view_interface* view,std::wstring& name)=0;
    virtual void remove(view_interface* view)=0;
    virtual void remove(std::wstring& name)=0;
    
public:
    view_manager_interface();
    virtual ~view_manager_interface();
};

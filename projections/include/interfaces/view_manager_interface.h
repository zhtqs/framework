#pragma once

#include <vector>
#include <string>
#include "view_interface.h"
#include "object_memory_manager_interface.h"

interface view_manager_interface: public object_memory_manager_interface
{
public:
    virtual void clear();
    virtual view_interface* get_view_by_name(std::wstring& name);
    virtual bool is_exists(std::wstring& name);
    virtual bool is_exists(view_interface* view);
    virtual void regist(view_interface* view,std::wstring& name);
    virtual void remove(view_interface* view);
    virtual void remove(std::wstring& name);
    
public:
    view_manager_interface();
    virtual ~view_manager_interface();
};

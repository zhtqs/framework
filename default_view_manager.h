#pragma once

#include <vector>
#include "definetions/common_information.h"
#include "interfaces/view_manager_interface.h"

class default_view_manager: public view_manager_interface
{
private:
    std::vector<common_information<view_interface*>> views;
    
public:
    
    //view_manager_interface
    void clear();
    view_interface* get_view_by_name(std::wstring& name);
    bool is_exists(std::wstring& name);
    bool is_exists(view_interface* view);
    void regist(view_interface* view,std::wstring& name);
    void remove(view_interface* view);
    void remove(std::wstring& name);
    
    //object_memory_manager_interface
    int get_size();
    void free();
    void clone(object_memory_manager_interface* object);
    
public:
    default_view_manager();
    virtual ~default_view_manager();
};

#pragma once

#include "public.h"
#include "interfaces/module_interface.h"

interface module_manager_interface: public module_interface
{
public:
    virtual void clear();
    virtual module_interface* get_module(std::wstring& name);
    virtual void regist(module_interface* module,std::wstring& name);
    virtual void remove(module_interface* module);
    virtual void remove(std::wstring& name);
    virtual bool is_exists(std::wstring& name);
    virtual bool is_exists(module_interface* module);
    virtual void init_modules();
};

#pragma once

#include <string>
#include "object_memory_manager_interface.h"
#include "../definetions/menuitem_event_handler.h"

interface event_manager_interface: public object_memory_manager_interface
{
public:
    virtual void clear();
    virtual void create_event(std::wstring& name);
    virtual int get_event_count();
    virtual int get_subscribe_count(std::wstring& name);
    virtual void subscribe(std::wstring& name,std::wstring& from,menuitem_event_handler* handler);
    virtual void fire(std::wstring& name,void* obj);
    virtual bool is_exists(std::wstring& name);
    virtual void unsubscribe(std::wstring& name,std::wstring& from);
    virtual void delete_event(std::wstring& name);
    
public:
    event_manager_interface();
    virtual ~event_manager_interface();
};

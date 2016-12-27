#pragma once

#include <string>
#include <uuid/uuid.h>
#include "../object_memory_manager_interface.h"
#include "../definetions/menuitem_event_handler.h"

class event_manager_interface: public object_memory_manager_interface
{
public:
    virtual void clear()=0;
    virtual void create_event(std::wstring name)=0;
    virtual int get_event_count()=0;
    virtual int get_subscribe_count(std::wstring name)=0;
    virtual void subscribe(std::wstring name,std::wstring from,menuitem_event_handler* handler)=0;
    virtual void fire(std::wstring name,void* obj)=0;
    virtual bool is_exists(std::wstring name)=0;
    virtual void unsubscribe(std::wstring name,std::wstring from)=0;
    virtual void delete_event(std::wstring name)=0;
    
public:
    event_manager_interface();
    virtual ~event_manager_interface();
};

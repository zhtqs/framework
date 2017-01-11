#pragma once

#include <vector>
#include "definetions/event_information.h"
#include "interfaces/event_manager_interface.h"

class default_event_manager : public event_manager_interface
{
private:
    std::vector<event_information> events;
    
public:
    //event_manager_interface
    void clear();
    void create_event(std::wstring& name);
    int get_event_count();
    int get_subscribe_count(std::wstring& name);
    void subscribe(std::wstring& name,std::wstring& from,menuitem_event_handler* handler);
    void fire(std::wstring& name,void* obj);
    bool is_exists(std::wstring& name);
    void unsubscribe(std::wstring& name,std::wstring& from);
    void delete_event(std::wstring& name);
    
    //object_memory_manager_interface
    int get_size() const;
    void free();
    void clone(object_memory_manager_interface* object) const;
    
public:
    default_event_manager();
    virtual ~default_event_manager();
};

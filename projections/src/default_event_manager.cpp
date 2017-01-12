#include "default_event_manager.h"
#include <algorithm>

default_event_manager::default_event_manager()
{
}

default_event_manager::~default_event_manager()
{
    clear();
}

void default_event_manager::clear()
{
    for(auto eit : events)
    {
        for(auto& sit : eit.subscribers)
        {
            sit.callback->free();
        }
        eit.subscribers.clear();
    }
    events.clear();
}

void default_event_manager::create_event(std::wstring& name)
{
    event_information ei;
    ei.name=name;
    events.push_back(ei);
}

int default_event_manager::get_event_count()
{
    return (int)events.size();
}

int default_event_manager::get_subscribe_count(std::wstring& name)
{
    auto found = std::find_if(events.begin(),events.end(),[=](event_information& x)->bool
    {
        return x.name==name;
    });
    if(found!=events.end())
    {
        return found->subscribers.size();
    }
    return -1;
}

void default_event_manager::subscribe(std::wstring& name, std::wstring& from, menuitem_event_handler* handler)
{
    auto found = std::find_if(events.begin(),events.end(),[=](event_information& x)->bool
    {
        return x.name==name;
    });
    if(found==events.end())
    {
        return;
    }
    subscriber_information subscriber;
    subscriber.name=from;
    handler->clone(subscriber.callback);
    found->subscribers.push_back(subscriber);
}

void default_event_manager::fire(std::wstring& name, void* obj)
{
    auto found = std::find_if(events.begin(),events.end(),[=](event_information& x)->bool
    {
        return x.name==name;
    });
    if(found==events.end())
    {
        return;
    }
    for(auto sit : found->subscribers)
    {
        sit.callback->on_activicated(obj);
    }
}

bool default_event_manager::is_exists(std::wstring& name)
{
    return std::find_if(events.begin(),events.end(),[=](event_information& x)->bool
    {
        return x.name==name;
    })==events.end();
}

void default_event_manager::unsubscribe(std::wstring& name, std::wstring& from)
{
    auto found = std::find_if(events.begin(),events.end(),[=](event_information& x)->bool
    {
        return x.name==name;
    });
    if(found==events.end())
    {
        return ;
    }
    std::remove_if(found->subscribers.begin(),found->subscribers.end(),[=](subscriber_information& x)->bool
    {
        return x.name==from;
    });
}

void default_event_manager::delete_event(std::wstring& name)
{
    auto found = std::find_if(events.begin(),events.end(),[=](event_information& x)->bool
    {
        return x.name==name;
    });
    if(found==events.end())
    {
        return ;
    }
    for(auto sit : found->subscribers)
    {
        sit.callback->free();
    }
    found->subscribers.clear();
    events.erase(found);
}

int default_event_manager::get_size() const
{
    return sizeof(default_event_manager);
}

void default_event_manager::free()
{
    clear();
    delete this;
}

void default_event_manager::clone(object_memory_manager_interface* object) const
{
    auto copy=new default_event_manager;
    copy->events=events;
    for(auto eit : events)
    {
        for(auto sit : eit.subscribers)
        {
            sit.callback->clone(sit.callback);
        }
    }
    object=copy;
}


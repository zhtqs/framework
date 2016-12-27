#include "default_event_manager.h"

default_event_manager::default_event_manager()
{
}

default_event_manager::~default_event_manager()
{
    clear();
}

void default_event_manager::clear()
{
    std::vector<event_information>::iterator eit=events.begin();
    for(;eit!=events.end();eit++)
    {
        std::vector<subscriber_information>::iterator sit=eit->subscribers.begin();
        for(;sit!=eit->subscribers.end();sit++)
        {
            sit->callback->free();
        }
        eit->subscribers.clear();
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
    std::vector<event_information>::iterator found=events.end();
    std::vector<event_information>::iterator it=events.begin();
    for(;it!=events.end();it++)
    {
        if(it->name==name)
        {
            found=it;
            break;
        }
    }
    if(found!=events.end())
    {
        return found->subscribers.size();
    }
    return -1;
}

void default_event_manager::subscribe(std::wstring& name, std::wstring& from, menuitem_event_handler* handler)
{
    std::vector<event_information>::iterator found=events.end();
    std::vector<event_information>::iterator it=events.begin();
    for(;it!=events.end();it++)
    {
        if(it->name==name)
        {
            found=it;
            break;
        }
    }
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
    std::vector<event_information>::iterator found=events.end();
    std::vector<event_information>::iterator it=events.begin();
    for(;it!=events.end();it++)
    {
        if(it->name==name)
        {
            found=it;
            break;
        }
    }
    if(found==events.end())
    {
        return;
    }
    std::vector<subscriber_information>::iterator sit=found->subscribers.begin();
    for(;sit!=found->subscribers.end();sit++)
    {
        sit->callback->on_activicated(obj);
    }
}

bool default_event_manager::is_exists(std::wstring& name)
{
    std::vector<event_information>::iterator found=events.end();
    std::vector<event_information>::iterator it=events.begin();
    for(;it!=events.end();it++)
    {
        if(it->name==name)
        {
            found=it;
            break;
        }
    }
    return found==events.end();
}

void default_event_manager::unsubscribe(std::wstring& name, std::wstring& from)
{
    std::vector<event_information>::iterator found=events.end();
    std::vector<event_information>::iterator it=events.begin();
    for(;it!=events.end();it++)
    {
        if(it->name==name)
        {
            found=it;
            break;
        }
    }
    if(found==events.end())
    {
        return ;
    }
    std::vector<subscriber_information>::iterator sit=found->subscribers.begin();
    while(sit!=found->subscribers.end())
    {
        if(sit->name==from)
        {
            found->subscribers.erase(sit);
            sit=found->subscribers.begin();
            continue;
        }
        sit++;
    }
}

void default_event_manager::delete_event(std::wstring& name)
{
    std::vector<event_information>::iterator found=events.end();
    std::vector<event_information>::iterator it=events.begin();
    for(;it!=events.end();it++)
    {
        if(it->name==name)
        {
            found=it;
            break;
        }
    }
    if(found==events.end())
    {
        return ;
    }
    std::vector<subscriber_information>::iterator sit=found->subscribers.begin();
    for(;sit!=found->subscribers.end();sit++)
    {
        sit->callback->free();
    }
    found->subscribers.clear();
    events.erase(found);
}

int default_event_manager::get_size()
{
    return sizeof(default_event_manager);
}

void default_event_manager::free()
{
    clear();
    delete this;
}

void default_event_manager::clone(object_memory_manager_interface* object)
{
    default_event_manager *copy=new default_event_manager;
    copy->events=events;
    std::vector<event_information>::iterator eit=copy->events.begin();
    for(;eit!=copy->events.end();eit++)
    {
        std::vector<subscriber_information>::iterator sit=eit->subscribers.begin();
        for(;sit!=eit->subscribers.end();sit++)
        {
            sit->callback->clone(sit->callback);
        }
    }
    object=copy;
}


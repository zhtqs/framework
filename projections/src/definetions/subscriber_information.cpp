#include "definetions/subscriber_information.h"
#include <malloc.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

subscriber_information::subscriber_information()
{
    is_remember_callback=false;
    mcallback=nullptr;
}

subscriber_information::~subscriber_information()
{
    if(mis_remember_callback&&callback!=nullptr)
    {
        mcallback->free();
    }
}

IMPLEMENT_DATA_PROPERTY(subscriber_information,bool,is_remember_callback)

IMPLEMENT_DATA_PROPERTY(subscriber_information,std::string,id)

IMPLEMENT_DATA_PROPERTY(subscriber_information,std::wstring,name)

menuitem_event_handler*& subscriber_information::get_callback()
{
    return mcallback;
}

void subscriber_information::set_callback(const menuitem_event_handler *& callback)
{
    callback->clone(mcallback);
}




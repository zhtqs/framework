#include "definetions/event_information.h"

event_information::event_information()
{
    
}

event_information::~event_information()
{
    for(auto& subscriber : subscribers)
    {
        subscriber.callback->free();
    }
    msubscribers.clear();
}

IMPLEMENT_DATA_PROPERTY(event_information,std::string,id)

IMPLEMENT_DATA_PROPERTY(event_information,std::wstring,name)

IMPLEMENT_DATA_PROPERTY(event_information,std::vector<subscriber_information>,subscribers)


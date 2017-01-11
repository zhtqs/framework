#include "definetions/event_information.h"

event_information::event_information()
{
    mid=new std::string;
    mname=new std::wstring;
    msubscribers=new std::vector<subscriber_information>;
}

event_information::~event_information()
{
    msubscribers->clear();
    delete mid;
    delete mname;
    delete msubscribers;
}

IMPLEMENT_POINTER_PROPERTY(event_information,std::string,id)

IMPLEMENT_POINTER_PROPERTY(event_information,std::wstring,name)

IMPLEMENT_POINTER_PROPERTY(event_information,std::vector<subscriber_information>,subscribers)


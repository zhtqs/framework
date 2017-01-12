
#pragma once

#include <string>
#include <vector>
#include "subscriber_information.h"

class event_information final
{
    DATA_PROPERTY(std::string,id);
    DATA_PROPERTY(std::wstring,name);
    DATA_PROPERTY(std::vector<subscriber_information>,subscribers);
    
public:
    event_information();
    virtual ~event_information();
};

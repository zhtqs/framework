
#pragma once

#include <string>
#include <vector>
#include "subscriber_information.h"

class event_information final
{
public:
    std::string id;
    std::wstring name;
    std::vector<subscriber_information> subscribers;
    
public:
    event_information();
    virtual ~event_information();
};

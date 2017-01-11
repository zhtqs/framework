
#pragma once

#include <string>
#include <vector>
#include "subscriber_information.h"

class FRAMEWORK_API event_information final
{
    POINTER_PROPERTY(std::string,id);
    POINTER_PROPERTY(std::wstring,name);
    POINTER_PROPERTY(std::vector<subscriber_information>,subscribers);
    
public:
    event_information();
    virtual ~event_information();
};

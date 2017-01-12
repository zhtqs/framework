#pragma once

#include "../public.h"
#include <string>

class role final
{
    DATA_PROPERTY(std::string,id);
    DATA_PROPERTY(std::wstring,name);
    DATA_PROPERTY(std::wstring,note);
    
public:
    role();
    virtual ~role();
};

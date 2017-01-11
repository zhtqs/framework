#pragma once

#include "../public.h"
#include <string>

class FRAMEWORK_API role final
{
    POINTER_PROPERTY(std::string,id);
    POINTER_PROPERTY(std::wstring,name);
    POINTER_PROPERTY(std::wstring,note);
    
public:
    role();
    virtual ~role();
};

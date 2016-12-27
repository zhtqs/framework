#pragma once

#include <string>

class role final
{
public:
    std::string id;
    std::wstring name;
    std::wstring note;
    
public:
    role();
    virtual ~role();
};

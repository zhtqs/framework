#pragma once

#include <string>

//T shoud not be pointer type, or manage variables' memory by caller
template<typename T>
class common_information
{
public:
    std::string id;
    std::wstring name;
    T data;
    
public:
    common_information()
    {
        
    }
    
    virtual ~common_information()
    {
    }
};

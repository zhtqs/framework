#pragma once

#include <string>
#include "../object_memory_manager_interface.h"

//T shoud not be pointer type, or manage variables' memory by caller
template<typename T=object_memory_manager_interface*>
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

#pragma once

#include <string>
#include "../interfaces/object_memory_manager_interface.h"

//T shoud not be pointer type, or manage variables' memory by caller
template<typename T=object_memory_manager_interface*>
class common_information
{
    SIMPLE_PROPERTY(std::string,id);
    SIMPLE_PROPERTY(std::wstring,name);
    PROPERTY(T,data);
    
public:
    T get_data()
    {
        return mdata;
    }
    
    void set_data(T data)
    {
        data->clone(mdata);
    }
    
public:
    common_information()
    {
    }
    
    virtual ~common_information()
    {
    }
};

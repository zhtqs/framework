#pragma once

#include <string>
#include "../interfaces/object_memory_manager_interface.h"

//T shoud not be pointer type, or manage variables' memory by caller
template<typename T=object_memory_manager_interface*>
class common_information
{
    SIMPLE_POINTER_PROPERTY(std::string,id);
    SIMPLE_POINTER_PROPERTY(std::wstring,name);
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
        mid=new std::string;
        mname=new std::wstring;
    }
    
    virtual ~common_information()
    {
        delete mid;
        delete mname;
    }
};

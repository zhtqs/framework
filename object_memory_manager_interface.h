
#pragma once

class object_memory_manager_interface
{
public:
    virtual int get_size()=0;
    virtual void free()=0;
    virtual void clone(object_memory_manager_interface* object)=0;
    
public:
    object_memory_manager_interface();
    virtual ~object_memory_manager_interface();
};

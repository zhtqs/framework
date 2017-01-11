
#pragma once

#include "../public.h"

interface object_memory_manager_interface
{
public:
    virtual int get_size() const;
    virtual void free();
    virtual void clone(object_memory_manager_interface* object) const;//function allocate memory and initialize, caller manage it
    
public:
    object_memory_manager_interface();
    virtual ~object_memory_manager_interface();
};

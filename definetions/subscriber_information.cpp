#include "subscriber_information.h"
#include <malloc.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

subscriber_information::subscriber_information()
{
    is_remember_callback=false;
    callback=nullptr;
}

subscriber_information::~subscriber_information()
{
    if(is_remember_callback&&callback!=nullptr)
    {
        callback->free();
    }
}

void subscriber_information::remember_callback(menuitem_event_handler* callback)
{
    int src_size=sizeof(*callback);
    int obj_size=callback->get_object_size();
    int size=(int)fmax(src_size,obj_size);
    callback=(menuitem_event_handler*)calloc(1,size);
    memcpy((void*)this->callback,(void*)callback,size);
}






#include "definetions/menuitem_information.h"

menuitem_information::menuitem_information()
{
}

menuitem_information::~menuitem_information()
{
    image_data.clear();
    if(mhandler)
        delete mhandler;
}

IMPLEMENT_DATA_PROPERTY(menuitem_information,std::wstring,name)

IMPLEMENT_DATA_PROPERTY(menuitem_information,std::wstring,display_name)

IMPLEMENT_POINTER_PROPERTY(menuitem_information,menuitem_event_handler,handler)

IMPLEMENT_DATA_PROPERTY(menuitem_information,std::vector<byte>,image_data)


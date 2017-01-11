#include "definetions/menuitem_information.h"

menuitem_information::menuitem_information()
{
    mname=new std::wstring;
    mdisplay_name=new std::wstring;
    mhandler=nullptr;
    mimage_data=new std::vector<unsigned char>;
}

menuitem_information::~menuitem_information()
{
    image_data->clear();
    delete mname;
    delete mdisplay_name;
    if(mhandler)
        delete mhandler;
    delete mimage_data;
}

IMPLEMENT_POINTER_PROPERTY(menuitem_information,std::wstring,name)

IMPLEMENT_POINTER_PROPERTY(menuitem_information,std::wstring,display_name)

IMPLEMENT_POINTER_PROPERTY(menuitem_information,menuitem_event_handler,handler)

IMPLEMENT_POINTER_PROPERTY(menuitem_information,std::vector<byte>,image_data)


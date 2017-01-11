#include "definetions/menuitem_information.h"

menuitem_information::menuitem_information()
{
    
}

menuitem_information::~menuitem_information()
{
}

void menuitem_information::set_image_data(unsigned char* data, int length)
{
    int i=0;
    this->image_data.clear();
    while(i<length&&i<INT_MAX)
        this->image_data.push_back(*(data+i++));
}






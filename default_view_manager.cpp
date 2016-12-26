#include "default_view_manager.h"

default_view_manager::default_view_manager()
{
}

default_view_manager::~default_view_manager()
{
}

void default_view_manager::clear()
{
}

void default_view_manager::clone(object_memory_manager_interface* object)
{
}

void default_view_manager::free()
{
}


int default_view_manager::get_size()
{
    return 0;
}


bool default_view_manager::is_exists(std::wstring& name)
{
    return false;
}


bool default_view_manager::is_exists(view_interface* view)
{
    return false;
}


void default_view_manager::regist(view_interface* view, std::wstring& name)
{
}


void default_view_manager::remove(std::wstring& name)
{
}


void default_view_manager::remove(view_interface* view)
{
}

view_interface * default_view_manager::get_view_by_name(std::wstring& name)
{
    return NULL;
}


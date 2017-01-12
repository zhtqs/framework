#include "definetions/role.h"

role::role()
{
}

role::~role()
{
}

IMPLEMENT_DATA_PROPERTY(role,std::string,id)

IMPLEMENT_DATA_PROPERTY(role,std::wstring,name)

IMPLEMENT_DATA_PROPERTY(role,std::wstring,note)

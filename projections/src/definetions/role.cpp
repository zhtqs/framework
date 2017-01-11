#include "definetions/role.h"

role::role()
{
    mid=new std::string;
    mname=new std::wstring;
    mnote=new std::wstring;
}

role::~role()
{
    delete mid;
    delete mname;
    delete mnote;
}

IMPLEMENT_POINTER_PROPERTY(role,std::string,id)

IMPLEMENT_POINTER_PROPERTY(role,std::wstring,name)

IMPLEMENT_POINTER_PROPERTY(role,std::wstring,note)

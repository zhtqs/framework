#pragma once

#include <string>
#include <vector>

#ifdef FRAMEWORK_LIBRARY
#define FRAMEWORK_API __declspec(dllexport)
#else
#define RRAMEWORK_API __declspec(dllimport)
#endif

#define interface class __declspec(novtable)
typedef unsigned char byte;

#define PROPERTY(type_name,variable_name) private:\
	type_name m##variable_name;\
	public:\
	__declspec(property(get=get_##variable_name,put=set_##variable_name)) type_name variable_name
#define DATA_PROPERTY(type_name,variable_name) public:\
	__declspec(property(get=get_##variable_name,put=set_##variable_name)) type_name variable_name;\
	private:\
	type_name m##variable_name;\
	public:\
	type_name& get_##variable_name();\
	void set_##variable_name(const type_name& variable_name)
#define POINTER_PROPERTY(type_name,variable_name) public:\
    __declspec(property(get=get_##variable_name,put=set_##variable_name)) type_name* variable_name;\
	private:\
	type_name* m##variable_name;\
	public:\
	type_name*& get_##variable_name();\
	void set_##variable_name(const type_name*& variable_name)
#define GET_PROPERTY(type_name,variable_name) public:\
	__declspec(property(get=get_##variable_name,put=set_##variable_name)) type_name variable_name;\
	private:\
	type_name m##variable_name;\
	public:\
	type_name& get_##variable_name();\
	private:\
	void set_##variable_name(const type_name& variable_name)
#define SIMPLE_PROPERTY(type_name,variable_name) public:\
	__declspec(property(get=get_##variable_name,put=set_##variable_name)) type_name variable_name;\
	private:\
	type_name m##variable_name;\
	public:\
	type_name& get_##variable_name(){return m##variable_name;}\
	void set_##variable_name(const type_name& variable_name){m##variable_name=variable_name;}
#define SIMPLE_POINTER_PROPERTY(type_name,variable_name) public:\
    __declspec(property(get=get_##variable_name,put=set_##variable_name)) type_name* variable_name;\
	private:\
	type_name* m##variable_name;\
	public:\
	type_name*& get_##variable_name(){return m##variable_name;}\
	void set_##variable_name(const type_name* variable_name){*m##variable_name=*variable_name;}
#define IMPLEMENT_DATA_PROPERTY(class_name,type_name,variable_name) \
	type_name& class_name::get_##variable_name(){return m##variable_name;}\
	void class_name::set_##variable_name(const type_name& variable_name){m##variable_name=variable_name;}
#define IMPLEMENT_POINTER_PROPERTY(class_name,type_name,variable_name) \
	type_name*& class_name::get_##variable_name(){return m##variable_name;}\
	void class_name::set_##variable_name(const type_name*& variable_name){*m##variable_name=*variable_name;}
	
	

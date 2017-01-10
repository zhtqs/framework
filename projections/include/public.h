#pragma once

#ifdef FRAMEWORK_LIBRARY
#define FRAMEWORK_API extern __declspec(dllexport)
#else
#define RRAMEWORK_API extern __declspec(dllimport)
#endif

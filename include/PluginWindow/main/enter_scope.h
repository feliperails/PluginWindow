
#ifndef PluginWindow_main_enter_scope_h
#define PluginWindow_main_enter_scope_h

#include <Gocad/utils/misc/defs.h>
#include <Gocad/utils/os/config.h>

#if defined(_WIN32)
#if !defined(_PluginWindow_main_decl)
#if defined(_PluginWindow_main_make)
#define _PluginWindow_main_decl __declspec(dllexport)
#else
#define _PluginWindow_main_decl __declspec(dllimport)
#endif
#endif
#else
#define _PluginWindow_main_decl
#endif

// Define the library initializer

namespace PluginWindow {

using namespace Gocad;

GOCAD_DECLARE_LIBRARY(PluginWindow,main)

} // namespace PluginWindow

#endif


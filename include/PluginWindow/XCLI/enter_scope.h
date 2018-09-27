
#ifndef PluginWindow_XCLI_enter_scope_h
#define PluginWindow_XCLI_enter_scope_h

#include <Gocad/utils/misc/defs.h>
#include <Gocad/utils/os/config.h>

#if defined(_WIN32)
#if !defined(_PluginWindow_XCLI_decl)
#if defined(_PluginWindow_XCLI_make)
#define _PluginWindow_XCLI_decl __declspec(dllexport)
#else
#define _PluginWindow_XCLI_decl __declspec(dllimport)
#endif
#endif
#else
#define _PluginWindow_XCLI_decl
#endif

// Define the library initializer

namespace PluginWindow {

using namespace Gocad;

GOCAD_DECLARE_LIBRARY(PluginWindow,XCLI)

} // namespace PluginWindow

#endif


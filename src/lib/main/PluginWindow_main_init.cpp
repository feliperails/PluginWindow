
#include <PluginWindow/main/enter_scope.h>

// It is absolutely necessary to force the include of the enter_scope of CLI
// and XCLI libraries in the main so that the Commands creators table is
// properly created. Otherwise, Gocad on Windows cannot run any CLI commands

#include <PluginWindow/CLI/enter_scope.h>
#include <PluginWindow/XCLI/enter_scope.h>

#include <Gocad/utils/misc/plugin_manager.h>

using namespace Gocad;

namespace PluginWindow {

GOCAD_DECLARE_PLUGIN_RUNTIME(PluginWindow)
GOCAD_IMPLEMENT_DEFAULT_PLUGIN_RUNTIME(PluginWindow)

GOCAD_LIBRARY_INITIALIZE(PluginWindow,main) { }
GOCAD_LIBRARY_TERMINATE(PluginWindow,main) { }

} // namespace PluginWindow


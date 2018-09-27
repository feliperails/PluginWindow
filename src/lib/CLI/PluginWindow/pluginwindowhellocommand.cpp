#if !defined(_CLI_decl)
#if defined(_WIN32)
#define _CLI_decl __declspec(dllexport)
#else
#define _CLI_decl
#endif
#endif

#include <Gocad/interpreter/commands.h>
#include <Gocad/qtools/gqactiondialog.h>

/*******************************************************************/

namespace Gocad{}

namespace PluginWindow {

    using namespace ::Gocad;

    class _CLI_decl PluginWindowHelloCommand_Command : public InteractiveCommand {
        GOCAD_DECLARE_RTTI( PluginWindowHelloCommand_Command );
    public :
        PluginWindowHelloCommand_Command(const CString&);
        PluginWindowHelloCommand_Command();
        ~PluginWindowHelloCommand_Command();

        virtual Command* create();

        virtual bool init_cmd_impl(const ICommandStub& cstub, bool re_init);
        virtual bool init_par(
            const ICommandStub&, IParameterStub*, const Selection&
        );
        virtual Format print() const;
        virtual bool do_execute()  ;

        void set_some_string(char*  some_string) { some_string_ = some_string ; }

        char*  get_some_string() { return some_string_ ; }

    protected :
        char*  some_string_ ;
    };

    GOCAD_IMPLEMENT_RTTI_1( PluginWindowHelloCommand_Command, InteractiveCommand );

    PluginWindowHelloCommand_Command::PluginWindowHelloCommand_Command() : InteractiveCommand() {
        some_string_ = 0;

    }

    PluginWindowHelloCommand_Command::PluginWindowHelloCommand_Command(const CString &name) : InteractiveCommand() {
        declare_proto(this,name);
        some_string_ = 0;

    }

    PluginWindowHelloCommand_Command::~PluginWindowHelloCommand_Command() {
        delete[]  (some_string_);

    }

    Command* PluginWindowHelloCommand_Command::create() {
        return new PluginWindowHelloCommand_Command();
    }

    bool PluginWindowHelloCommand_Command::init_cmd_impl(const ICommandStub& cstub, bool re_init) {

        {
            char*  some_string;
            cstub.get("some_string",some_string) ; 
            set_some_string(some_string);
        }

        return InteractiveCommand::init_cmd_impl(cstub, re_init);
    }

    bool PluginWindowHelloCommand_Command::init_par(
        const ICommandStub &cstub,IParameterStub* pstub, const Selection& s
    ) {

        return InteractiveCommand::init_par(cstub,pstub,s);
    }

    Format PluginWindowHelloCommand_Command::print() const {
        return InteractiveCommand::print();
    }

    // Disable "unreferenced formal parameter" warning
    // in generated code, to get cleaner CLI build output.
#if defined(_WIN32) && defined(_MSC_VER)
#pragma warning(push)
#pragma warning(disable: 4100)
#elif defined(__GNUC__)
    GCC_DIAGNOSTIC_OFF(unused-parameter)
#endif

    bool PluginWindowHelloCommand_Command::do_execute()  { 
        store_start();

        Logger::notice( Format( "Dialog said: \"%1\"" ) % some_string_ );

        return true;

    }

#if defined(_WIN32) && defined(_MSC_VER)
#pragma warning(pop)
#elif defined(__GNUC__)
    GCC_DIAGNOSTIC_ON(unused-parameter)
#endif

    /**********************************/

    class Nifty_Creator_PluginWindowHelloCommand {
        static PluginWindowHelloCommand_Command* proto_;
    public :
        Nifty_Creator_PluginWindowHelloCommand() {
            if( proto_ == nullptr ) {
                proto_ = new PluginWindowHelloCommand_Command("PluginWindowHelloCommand");
            }
        }
        ~Nifty_Creator_PluginWindowHelloCommand() {
            if( proto_ != nullptr ) {
                delete proto_;
                proto_ = nullptr;
            }
        }
    };

    PluginWindowHelloCommand_Command* Nifty_Creator_PluginWindowHelloCommand::proto_ = nullptr;
    static Nifty_Creator_PluginWindowHelloCommand nifty_creator_PluginWindowHelloCommand;

} // namespace PluginWindow


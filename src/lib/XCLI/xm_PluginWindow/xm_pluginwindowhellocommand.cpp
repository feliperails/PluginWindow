// Conditionally support gcc's unused attribute for variables.
//  used to remove spurious 'unused variable' warnings caused by the code
//  generation.
#if defined(__GNUC__)
#define GOCAD_UNUSED_ATTR  __attribute__ ((unused))
#else
#define GOCAD_UNUSED_ATTR
#endif

namespace Gocad {
    class ICommandStub;
    class CommandExecuter;
    class XMShell;
} // namespace Gocad

/**************************************************************/

namespace Gocad{}

namespace PluginWindow {

    using namespace ::Gocad;

    class XMPluginWindowHelloCommand_Builder : public XMCommandCreator {
    public :
        XMPluginWindowHelloCommand_Builder();
        virtual ~XMPluginWindowHelloCommand_Builder();

        XMShell* build(ICommandStub* c,CommandExecuter*);

    protected :
        XMShell* wrapped_build(ICommandStub* c,CommandExecuter*);

        virtual XMShell* do_create(ICommandStub* c, CommandExecuter*);
    };

    // register get_items() functions:

    XMPluginWindowHelloCommand_Builder::XMPluginWindowHelloCommand_Builder() : XMCommandCreator("PluginWindowHelloCommand") {
    }

    XMPluginWindowHelloCommand_Builder::~XMPluginWindowHelloCommand_Builder() {
    }

    XMShell* XMPluginWindowHelloCommand_Builder::do_create(ICommandStub* c,CommandExecuter* e) {
        XMShell* shell = build(c,e);
        connect_observers();
        clean_build_variables();
        return shell;
    }

    XMShell* XMPluginWindowHelloCommand_Builder::build(ICommandStub* cstub,CommandExecuter* exec) {
        XMShell* shell = wrapped_build(cstub, exec) ;
        if( shell != nullptr ) {
            QWidget* w = shell->impl_widget() ;
            set_gocad_owner(w);
        }
        return shell ;
    }

    // Disable "local variable is initialized but not referenced"
    // warning in generated code, to get cleaner XCLI build output.
#ifdef _MSC_VER
#  pragma warning(push)
#  pragma warning(disable: 4189)
#endif

    XMShell* XMPluginWindowHelloCommand_Builder::wrapped_build(ICommandStub* cstub,CommandExecuter* exec) {

        XMVBox* vbox = new XMVBox();
        vbox->impl_widget()->setSizePolicy(
            QSizePolicy::MinimumExpanding, // horizontal
            QSizePolicy::Fixed // vertical
        );

        XMActionDialog* d = new XMActionDialog(
            Gocad::XMActionDialog::tr(""),
            vbox,
            new CommandExecuterAction(cstub,exec)
        );
        {
            d-> set_help(cstub->def()->dialog().help());
        }
        d-> set_name("PluginWindowHelloCommand");

        d-> set_validate_action(new CommandValidateAction(cstub));

        bool start_with_indent_box =
        cstub->def()->dialog().starts_with_indent_box();

        if( cstub->def()->dialog().info().defined() ) {
            XMHBox* hbox = new XMHBox();
            vbox-> append(hbox);
            GQLabel* lbl = new GQLabel();
            lbl->setType(GQLabel::Info);
            lbl->setText(Gocad::XMActionDialog::tr(""));
            lbl->setAlignment( Qt::Alignment( Qt::AlignVCenter|Qt::AlignLeft ) );
            lbl->setWordWrap(true);
            hbox-> append(new XMQWidget(lbl));
            if( !start_with_indent_box ) {
                vbox-> append(new XMVGlue(5));
                vbox-> append(new XMHLine());
            }
        }
        if( !start_with_indent_box ) {
            vbox-> append(new XMVGlue(5));
        }

        IParameterStub* pstub = nullptr;

        // Not all CLI commands use all of these variables, resulting in spurious
        // warnings. Add the 'unused' attribute to silence these warnings under gcc.
        Value* GOCAD_UNUSED_ATTR v = nullptr;
        XMPixmapButton* GOCAD_UNUSED_ATTR picking_button = nullptr;
        ValueListToolAction* GOCAD_UNUSED_ATTR tool_action = nullptr;
        const char* GOCAD_UNUSED_ATTR parameter_name = nullptr;
        XMWidget* GOCAD_UNUSED_ATTR xmwidget = nullptr;

        {

        }
        {

            {
                pstub = cstub-> find("some_string");

                v = new IParameterSurrogateValue<StringValue>(pstub);
                ICommandDialogDef& dialog = cstub->def()->dialog();
                if( !dialog.in_invisible(pstub->def()) ) {
                    if (tool_action) tool_action-> append(v);
                    XMHBox* hbox = new XMHBox;
                    hbox-> append(
                        new XMLabel(Gocad::XMActionDialog::tr("Some string")), 
                        new XMTextField("some_string",10,v,nullptr) 
                    );
                    if (picking_button) {
                        hbox-> append(picking_button);
                        picking_button = nullptr;
                        tool_action = nullptr;
                    }
                    declare_parameter_widget(hbox,vbox,pstub,cstub);
                }

            }

        }

        d->set_extension(extension());
        cstub->restore_backup();

        QWidget* w = d->impl_widget() ;
        set_gocad_owner(w);

        return d;

    }

#ifdef _MSC_VER
#  pragma warning(pop)
#endif

    /**************************************************************/

    class Nifty_Creator_XMPluginWindowHelloCommand_Builder {
        static XMPluginWindowHelloCommand_Builder* proto_;
    public :
        Nifty_Creator_XMPluginWindowHelloCommand_Builder() {
            if( proto_ == nullptr ) {
                proto_ = new XMPluginWindowHelloCommand_Builder();
            }
        }
        ~Nifty_Creator_XMPluginWindowHelloCommand_Builder() {
            if( proto_ != nullptr ) {
                delete proto_;
                proto_ = nullptr;
            }
        }
    };

    XMPluginWindowHelloCommand_Builder* Nifty_Creator_XMPluginWindowHelloCommand_Builder::proto_ = nullptr;
    static Nifty_Creator_XMPluginWindowHelloCommand_Builder nifty_creator_XMPluginWindowHelloCommand_Builder;

} // namespace PluginWindow


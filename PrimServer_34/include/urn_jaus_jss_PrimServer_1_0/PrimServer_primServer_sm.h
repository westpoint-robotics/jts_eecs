#ifndef _H_PRIMSERVER_PRIMSERVER_SM
#define _H_PRIMSERVER_PRIMSERVER_SM

/*
 * ex: set ro:
 * DO NOT EDIT.
 * generated by smc (http://smc.sourceforge.net/)
 * from file : PrimServer_primServer_sm.sm
 */


#define SMC_USES_IOSTREAMS

#include <statemap.h>

namespace urn_jaus_jss_PrimServer_1_0
{
    // Forward declarations.
    class PrimServer_primServer_SM;
    class PrimServer_primServer_SM_Ready;
    class PrimServer_primServer_SM_Internally_Generated_State_DO_NOT_USE;
    class PrimServer_primServer_SM_Default;
    class PrimServer_primServerState;
    class PrimServer_primServerContext;
    class PrimServer_primServer;

    class PrimServer_primServerState :
        public statemap::State
    {
    public:

        PrimServer_primServerState(const char *name, int stateId)
        : statemap::State(name, stateId)
        {};

        virtual void Entry(PrimServer_primServerContext&) {};
        virtual void Exit(PrimServer_primServerContext&) {};

        virtual void ReportWrenchEffortTransition(PrimServer_primServerContext& context);

    protected:

        virtual void Default(PrimServer_primServerContext& context);
    };

    class PrimServer_primServer_SM
    {
    public:

        static PrimServer_primServer_SM_Ready Ready;
        static PrimServer_primServer_SM_Internally_Generated_State_DO_NOT_USE Internally_Generated_State_DO_NOT_USE;
    };

    class PrimServer_primServer_SM_Default :
        public PrimServer_primServerState
    {
    public:

        PrimServer_primServer_SM_Default(const char *name, int stateId)
        : PrimServer_primServerState(name, stateId)
        {};

    };

    class PrimServer_primServer_SM_Ready :
        public PrimServer_primServer_SM_Default
    {
    public:
        PrimServer_primServer_SM_Ready(const char *name, int stateId)
        : PrimServer_primServer_SM_Default(name, stateId)
        {};

        void ReportWrenchEffortTransition(PrimServer_primServerContext& context);
    };

    class PrimServer_primServer_SM_Internally_Generated_State_DO_NOT_USE :
        public PrimServer_primServer_SM_Default
    {
    public:
        PrimServer_primServer_SM_Internally_Generated_State_DO_NOT_USE(const char *name, int stateId)
        : PrimServer_primServer_SM_Default(name, stateId)
        {};

        void ReportWrenchEffortTransition(PrimServer_primServerContext& context);
    };

    class PrimServer_primServerContext :
        public statemap::FSMContext
    {
    public:

        PrimServer_primServerContext(PrimServer_primServer& owner)
        : FSMContext(PrimServer_primServer_SM::Ready),
          _owner(owner)
        {};

        PrimServer_primServerContext(PrimServer_primServer& owner, const statemap::State& state)
        : FSMContext(state),
          _owner(owner)
        {};

        virtual void enterStartState()
        {
            getState().Entry(*this);
            return;
        }

        PrimServer_primServer& getOwner() const
        {
            return (_owner);
        };

        PrimServer_primServerState& getState() const
        {
            if (_state == NULL)
            {
                throw statemap::StateUndefinedException();
            }

            return (dynamic_cast<PrimServer_primServerState&>(*_state));
        };

        void ReportWrenchEffortTransition()
        {
            setTransition("ReportWrenchEffortTransition");
            (getState()).ReportWrenchEffortTransition(*this);
            setTransition(NULL);
        };

    private:

        PrimServer_primServer& _owner;
    };
}


/*
 * Local variables:
 *  buffer-read-only: t
 * End:
 */

#endif // _H_PRIMSERVER_PRIMSERVER_SM
#ifndef _H_ADDITIONCLIENTSERVICEDEF_ADDITIONCLIENTFSM_SM
#define _H_ADDITIONCLIENTSERVICEDEF_ADDITIONCLIENTFSM_SM

/*
 * ex: set ro:
 * DO NOT EDIT.
 * generated by smc (http://smc.sourceforge.net/)
 * from file : AdditionClientServiceDef_additionClientFSM_sm.sm
 */


#define SMC_USES_IOSTREAMS

#include <statemap.h>

namespace urn_jaus_example_addition_client_1_0
{
    // Forward declarations.
    class AdditionClientServiceDef_additionClientFSM_SM;
    class AdditionClientServiceDef_additionClientFSM_SM_Init;
    class AdditionClientServiceDef_additionClientFSM_SM_Ready;
    class AdditionClientServiceDef_additionClientFSM_SM_Internally_Generated_State_DO_NOT_USE;
    class AdditionClientServiceDef_additionClientFSM_SM_Default;
    class AdditionClientServiceDef_additionClientFSMState;
    class AdditionClientServiceDef_additionClientFSMContext;
    class AdditionClientServiceDef_additionClientFSM;

    class AdditionClientServiceDef_additionClientFSMState :
        public statemap::State
    {
    public:

        AdditionClientServiceDef_additionClientFSMState(const char *name, int stateId)
        : statemap::State(name, stateId)
        {};

        virtual void Entry(AdditionClientServiceDef_additionClientFSMContext&) {};
        virtual void Exit(AdditionClientServiceDef_additionClientFSMContext&) {};

        virtual void InitToReadyEventDefTransition(AdditionClientServiceDef_additionClientFSMContext& context);
        virtual void InternalStateChange_To_AdditionClientServiceDef_additionClientFSM_InitTransition(AdditionClientServiceDef_additionClientFSMContext& context, JTS::InternalEvent* ie);
        virtual void InternalStateChange_To_AdditionClientServiceDef_additionClientFSM_ReadyTransition(AdditionClientServiceDef_additionClientFSMContext& context, JTS::InternalEvent* ie);
        virtual void ReportAdditionTransition(AdditionClientServiceDef_additionClientFSMContext& context);
        virtual void ReportAdditionTransition(AdditionClientServiceDef_additionClientFSMContext& context, ReportAddition& msg);

    protected:

        virtual void Default(AdditionClientServiceDef_additionClientFSMContext& context);
    };

    class AdditionClientServiceDef_additionClientFSM_SM
    {
    public:

        static AdditionClientServiceDef_additionClientFSM_SM_Init Init;
        static AdditionClientServiceDef_additionClientFSM_SM_Ready Ready;
        static AdditionClientServiceDef_additionClientFSM_SM_Internally_Generated_State_DO_NOT_USE Internally_Generated_State_DO_NOT_USE;
    };

    class AdditionClientServiceDef_additionClientFSM_SM_Default :
        public AdditionClientServiceDef_additionClientFSMState
    {
    public:

        AdditionClientServiceDef_additionClientFSM_SM_Default(const char *name, int stateId)
        : AdditionClientServiceDef_additionClientFSMState(name, stateId)
        {};

    };

    class AdditionClientServiceDef_additionClientFSM_SM_Init :
        public AdditionClientServiceDef_additionClientFSM_SM_Default
    {
    public:
        AdditionClientServiceDef_additionClientFSM_SM_Init(const char *name, int stateId)
        : AdditionClientServiceDef_additionClientFSM_SM_Default(name, stateId)
        {};

        void InitToReadyEventDefTransition(AdditionClientServiceDef_additionClientFSMContext& context);
        void InternalStateChange_To_AdditionClientServiceDef_additionClientFSM_ReadyTransition(AdditionClientServiceDef_additionClientFSMContext& context, JTS::InternalEvent* ie);
    };

    class AdditionClientServiceDef_additionClientFSM_SM_Ready :
        public AdditionClientServiceDef_additionClientFSM_SM_Default
    {
    public:
        AdditionClientServiceDef_additionClientFSM_SM_Ready(const char *name, int stateId)
        : AdditionClientServiceDef_additionClientFSM_SM_Default(name, stateId)
        {};

        void InternalStateChange_To_AdditionClientServiceDef_additionClientFSM_InitTransition(AdditionClientServiceDef_additionClientFSMContext& context, JTS::InternalEvent* ie);
        void ReportAdditionTransition(AdditionClientServiceDef_additionClientFSMContext& context, ReportAddition& msg);
    };

    class AdditionClientServiceDef_additionClientFSM_SM_Internally_Generated_State_DO_NOT_USE :
        public AdditionClientServiceDef_additionClientFSM_SM_Default
    {
    public:
        AdditionClientServiceDef_additionClientFSM_SM_Internally_Generated_State_DO_NOT_USE(const char *name, int stateId)
        : AdditionClientServiceDef_additionClientFSM_SM_Default(name, stateId)
        {};

        void InitToReadyEventDefTransition(AdditionClientServiceDef_additionClientFSMContext& context);
        void ReportAdditionTransition(AdditionClientServiceDef_additionClientFSMContext& context);
    };

    class AdditionClientServiceDef_additionClientFSMContext :
        public statemap::FSMContext
    {
    public:

        AdditionClientServiceDef_additionClientFSMContext(AdditionClientServiceDef_additionClientFSM& owner)
        : FSMContext(AdditionClientServiceDef_additionClientFSM_SM::Init),
          _owner(owner)
        {};

        AdditionClientServiceDef_additionClientFSMContext(AdditionClientServiceDef_additionClientFSM& owner, const statemap::State& state)
        : FSMContext(state),
          _owner(owner)
        {};

        virtual void enterStartState()
        {
            getState().Entry(*this);
            return;
        }

        AdditionClientServiceDef_additionClientFSM& getOwner() const
        {
            return (_owner);
        };

        AdditionClientServiceDef_additionClientFSMState& getState() const
        {
            if (_state == NULL)
            {
                throw statemap::StateUndefinedException();
            }

            return (dynamic_cast<AdditionClientServiceDef_additionClientFSMState&>(*_state));
        };

        void InitToReadyEventDefTransition()
        {
            setTransition("InitToReadyEventDefTransition");
            (getState()).InitToReadyEventDefTransition(*this);
            setTransition(NULL);
        };

        void InternalStateChange_To_AdditionClientServiceDef_additionClientFSM_InitTransition(JTS::InternalEvent* ie)
        {
            setTransition("InternalStateChange_To_AdditionClientServiceDef_additionClientFSM_InitTransition");
            (getState()).InternalStateChange_To_AdditionClientServiceDef_additionClientFSM_InitTransition(*this, ie);
            setTransition(NULL);
        };

        void InternalStateChange_To_AdditionClientServiceDef_additionClientFSM_ReadyTransition(JTS::InternalEvent* ie)
        {
            setTransition("InternalStateChange_To_AdditionClientServiceDef_additionClientFSM_ReadyTransition");
            (getState()).InternalStateChange_To_AdditionClientServiceDef_additionClientFSM_ReadyTransition(*this, ie);
            setTransition(NULL);
        };

        void ReportAdditionTransition()
        {
            setTransition("ReportAdditionTransition");
            (getState()).ReportAdditionTransition(*this);
            setTransition(NULL);
        };

        void ReportAdditionTransition(ReportAddition& msg)
        {
            setTransition("ReportAdditionTransition");
            (getState()).ReportAdditionTransition(*this, msg);
            setTransition(NULL);
        };

    private:

        AdditionClientServiceDef_additionClientFSM& _owner;
    };
}


/*
 * Local variables:
 *  buffer-read-only: t
 * End:
 */

#endif // _H_ADDITIONCLIENTSERVICEDEF_ADDITIONCLIENTFSM_SM

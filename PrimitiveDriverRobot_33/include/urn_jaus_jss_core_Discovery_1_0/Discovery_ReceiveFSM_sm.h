#ifndef _H_DISCOVERY_RECEIVEFSM_SM
#define _H_DISCOVERY_RECEIVEFSM_SM

/*
 * ex: set ro:
 * DO NOT EDIT.
 * generated by smc (http://smc.sourceforge.net/)
 * from file : Discovery_ReceiveFSM_sm.sm
 */


#define SMC_USES_IOSTREAMS

#include <statemap.h>

namespace urn_jaus_jss_core_Discovery_1_0
{
    // Forward declarations.
    class Discovery_ReceiveFSM_SM;
    class Discovery_ReceiveFSM_SM_Receiving_Ready;
    class Discovery_ReceiveFSM_SM_Internally_Generated_State_DO_NOT_USE;
    class Discovery_ReceiveFSM_SM_Default;
    class Discovery_ReceiveFSMState;
    class Discovery_ReceiveFSMContext;
    class Discovery_ReceiveFSM;

    class Discovery_ReceiveFSMState :
        public statemap::State
    {
    public:

        Discovery_ReceiveFSMState(const char *name, int stateId)
        : statemap::State(name, stateId)
        {};

        virtual void Entry(Discovery_ReceiveFSMContext&) {};
        virtual void Exit(Discovery_ReceiveFSMContext&) {};

        virtual void BroadcastGlobalTransition(Discovery_ReceiveFSMContext& context);
        virtual void BroadcastLocalTransition(Discovery_ReceiveFSMContext& context);
        virtual void CancelEventTransition(Discovery_ReceiveFSMContext& context);
        virtual void CreateEventTransition(Discovery_ReceiveFSMContext& context);
        virtual void EventErrorTransition(Discovery_ReceiveFSMContext& context);
        virtual void EventOccurredTransition(Discovery_ReceiveFSMContext& context);
        virtual void QueryConfigurationTransition(Discovery_ReceiveFSMContext& context);
        virtual void QueryEventsTransition(Discovery_ReceiveFSMContext& context);
        virtual void QueryIdentificationTransition(Discovery_ReceiveFSMContext& context);
        virtual void QueryServicesTransition(Discovery_ReceiveFSMContext& context);
        virtual void QuerySubsystemListTransition(Discovery_ReceiveFSMContext& context);
        virtual void ReceiveTransition(Discovery_ReceiveFSMContext& context);
        virtual void ReceiveTransition(Discovery_ReceiveFSMContext& context, QueryConfiguration& msg, Receive::Body::ReceiveRec& transportData);
        virtual void ReceiveTransition(Discovery_ReceiveFSMContext& context, QueryIdentification& msg, Receive::Body::ReceiveRec& transportData);
        virtual void ReceiveTransition(Discovery_ReceiveFSMContext& context, QueryServices& msg, Receive::Body::ReceiveRec& transportData);
        virtual void ReceiveTransition(Discovery_ReceiveFSMContext& context, QuerySubsystemList& msg, Receive::Body::ReceiveRec& transportData);
        virtual void ReceiveTransition(Discovery_ReceiveFSMContext& context, RegisterServices& msg, Receive::Body::ReceiveRec& transportData);
        virtual void RegisterServicesTransition(Discovery_ReceiveFSMContext& context);
        virtual void SendTransition(Discovery_ReceiveFSMContext& context);
        virtual void UpdateEventTransition(Discovery_ReceiveFSMContext& context);

    protected:

        virtual void Default(Discovery_ReceiveFSMContext& context);
    };

    class Discovery_ReceiveFSM_SM
    {
    public:

        static Discovery_ReceiveFSM_SM_Receiving_Ready Receiving_Ready;
        static Discovery_ReceiveFSM_SM_Internally_Generated_State_DO_NOT_USE Internally_Generated_State_DO_NOT_USE;
    };

    class Discovery_ReceiveFSM_SM_Default :
        public Discovery_ReceiveFSMState
    {
    public:

        Discovery_ReceiveFSM_SM_Default(const char *name, int stateId)
        : Discovery_ReceiveFSMState(name, stateId)
        {};

    };

    class Discovery_ReceiveFSM_SM_Receiving_Ready :
        public Discovery_ReceiveFSM_SM_Default
    {
    public:
        Discovery_ReceiveFSM_SM_Receiving_Ready(const char *name, int stateId)
        : Discovery_ReceiveFSM_SM_Default(name, stateId)
        {};

        void ReceiveTransition(Discovery_ReceiveFSMContext& context, QueryConfiguration& msg, Receive::Body::ReceiveRec& transportData);
        void ReceiveTransition(Discovery_ReceiveFSMContext& context, QueryIdentification& msg, Receive::Body::ReceiveRec& transportData);
        void ReceiveTransition(Discovery_ReceiveFSMContext& context, QueryServices& msg, Receive::Body::ReceiveRec& transportData);
        void ReceiveTransition(Discovery_ReceiveFSMContext& context, QuerySubsystemList& msg, Receive::Body::ReceiveRec& transportData);
        void ReceiveTransition(Discovery_ReceiveFSMContext& context, RegisterServices& msg, Receive::Body::ReceiveRec& transportData);
    };

    class Discovery_ReceiveFSM_SM_Internally_Generated_State_DO_NOT_USE :
        public Discovery_ReceiveFSM_SM_Default
    {
    public:
        Discovery_ReceiveFSM_SM_Internally_Generated_State_DO_NOT_USE(const char *name, int stateId)
        : Discovery_ReceiveFSM_SM_Default(name, stateId)
        {};

        void BroadcastGlobalTransition(Discovery_ReceiveFSMContext& context);
        void BroadcastLocalTransition(Discovery_ReceiveFSMContext& context);
        void CancelEventTransition(Discovery_ReceiveFSMContext& context);
        void CreateEventTransition(Discovery_ReceiveFSMContext& context);
        void EventErrorTransition(Discovery_ReceiveFSMContext& context);
        void EventOccurredTransition(Discovery_ReceiveFSMContext& context);
        void QueryConfigurationTransition(Discovery_ReceiveFSMContext& context);
        void QueryEventsTransition(Discovery_ReceiveFSMContext& context);
        void QueryIdentificationTransition(Discovery_ReceiveFSMContext& context);
        void QueryServicesTransition(Discovery_ReceiveFSMContext& context);
        void QuerySubsystemListTransition(Discovery_ReceiveFSMContext& context);
        void ReceiveTransition(Discovery_ReceiveFSMContext& context);
        void RegisterServicesTransition(Discovery_ReceiveFSMContext& context);
        void SendTransition(Discovery_ReceiveFSMContext& context);
        void UpdateEventTransition(Discovery_ReceiveFSMContext& context);
    };

    class Discovery_ReceiveFSMContext :
        public statemap::FSMContext
    {
    public:

        Discovery_ReceiveFSMContext(Discovery_ReceiveFSM& owner)
        : FSMContext(Discovery_ReceiveFSM_SM::Receiving_Ready),
          _owner(owner)
        {};

        Discovery_ReceiveFSMContext(Discovery_ReceiveFSM& owner, const statemap::State& state)
        : FSMContext(state),
          _owner(owner)
        {};

        virtual void enterStartState()
        {
            getState().Entry(*this);
            return;
        }

        Discovery_ReceiveFSM& getOwner() const
        {
            return (_owner);
        };

        Discovery_ReceiveFSMState& getState() const
        {
            if (_state == NULL)
            {
                throw statemap::StateUndefinedException();
            }

            return (dynamic_cast<Discovery_ReceiveFSMState&>(*_state));
        };

        void BroadcastGlobalTransition()
        {
            setTransition("BroadcastGlobalTransition");
            (getState()).BroadcastGlobalTransition(*this);
            setTransition(NULL);
        };

        void BroadcastLocalTransition()
        {
            setTransition("BroadcastLocalTransition");
            (getState()).BroadcastLocalTransition(*this);
            setTransition(NULL);
        };

        void CancelEventTransition()
        {
            setTransition("CancelEventTransition");
            (getState()).CancelEventTransition(*this);
            setTransition(NULL);
        };

        void CreateEventTransition()
        {
            setTransition("CreateEventTransition");
            (getState()).CreateEventTransition(*this);
            setTransition(NULL);
        };

        void EventErrorTransition()
        {
            setTransition("EventErrorTransition");
            (getState()).EventErrorTransition(*this);
            setTransition(NULL);
        };

        void EventOccurredTransition()
        {
            setTransition("EventOccurredTransition");
            (getState()).EventOccurredTransition(*this);
            setTransition(NULL);
        };

        void QueryConfigurationTransition()
        {
            setTransition("QueryConfigurationTransition");
            (getState()).QueryConfigurationTransition(*this);
            setTransition(NULL);
        };

        void QueryEventsTransition()
        {
            setTransition("QueryEventsTransition");
            (getState()).QueryEventsTransition(*this);
            setTransition(NULL);
        };

        void QueryIdentificationTransition()
        {
            setTransition("QueryIdentificationTransition");
            (getState()).QueryIdentificationTransition(*this);
            setTransition(NULL);
        };

        void QueryServicesTransition()
        {
            setTransition("QueryServicesTransition");
            (getState()).QueryServicesTransition(*this);
            setTransition(NULL);
        };

        void QuerySubsystemListTransition()
        {
            setTransition("QuerySubsystemListTransition");
            (getState()).QuerySubsystemListTransition(*this);
            setTransition(NULL);
        };

        void ReceiveTransition()
        {
            setTransition("ReceiveTransition");
            (getState()).ReceiveTransition(*this);
            setTransition(NULL);
        };

        void ReceiveTransition(QueryConfiguration& msg, Receive::Body::ReceiveRec& transportData)
        {
            setTransition("ReceiveTransition");
            (getState()).ReceiveTransition(*this, msg, transportData);
            setTransition(NULL);
        };

        void ReceiveTransition(QueryIdentification& msg, Receive::Body::ReceiveRec& transportData)
        {
            setTransition("ReceiveTransition");
            (getState()).ReceiveTransition(*this, msg, transportData);
            setTransition(NULL);
        };

        void ReceiveTransition(QueryServices& msg, Receive::Body::ReceiveRec& transportData)
        {
            setTransition("ReceiveTransition");
            (getState()).ReceiveTransition(*this, msg, transportData);
            setTransition(NULL);
        };

        void ReceiveTransition(QuerySubsystemList& msg, Receive::Body::ReceiveRec& transportData)
        {
            setTransition("ReceiveTransition");
            (getState()).ReceiveTransition(*this, msg, transportData);
            setTransition(NULL);
        };

        void ReceiveTransition(RegisterServices& msg, Receive::Body::ReceiveRec& transportData)
        {
            setTransition("ReceiveTransition");
            (getState()).ReceiveTransition(*this, msg, transportData);
            setTransition(NULL);
        };

        void RegisterServicesTransition()
        {
            setTransition("RegisterServicesTransition");
            (getState()).RegisterServicesTransition(*this);
            setTransition(NULL);
        };

        void SendTransition()
        {
            setTransition("SendTransition");
            (getState()).SendTransition(*this);
            setTransition(NULL);
        };

        void UpdateEventTransition()
        {
            setTransition("UpdateEventTransition");
            (getState()).UpdateEventTransition(*this);
            setTransition(NULL);
        };

    private:

        Discovery_ReceiveFSM& _owner;
    };
}


/*
 * Local variables:
 *  buffer-read-only: t
 * End:
 */

#endif // _H_DISCOVERY_RECEIVEFSM_SM

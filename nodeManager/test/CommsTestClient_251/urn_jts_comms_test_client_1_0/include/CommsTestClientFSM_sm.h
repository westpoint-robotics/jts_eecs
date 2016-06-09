/***********           LICENSE HEADER   *******************************
JAUS Tool Set
Copyright (c)  2010, United States Government
All rights reserved.

Redistribution and use in source and binary forms, with or without 
modification, are permitted provided that the following conditions are met:

       Redistributions of source code must retain the above copyright notice, 
this list of conditions and the following disclaimer.

       Redistributions in binary form must reproduce the above copyright 
notice, this list of conditions and the following disclaimer in the 
documentation and/or other materials provided with the distribution.

       Neither the name of the United States Government nor the names of 
its contributors may be used to endorse or promote products derived from 
this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" 
AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE 
IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE 
ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE 
LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR 
CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF 
SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS 
INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN 
CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) 
ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE 
POSSIBILITY OF SUCH DAMAGE.
*********************  END OF LICENSE ***********************************/

#ifndef _H_COMMSTESTCLIENTFSM_SM
#define _H_COMMSTESTCLIENTFSM_SM

/*
 * ex: set ro:
 * DO NOT EDIT.
 * generated by smc (http://smc.sourceforge.net/)
 * from file : CommsTestClientFSM.sm
 */


#define SMC_USES_IOSTREAMS

#include <statemap.h>

namespace urn_jts_comms_test_client_1_0
{
    // Forward declarations.
    class CommsTestClientFSM_SM;
    class CommsTestClientFSM_SM_Running;
    class CommsTestClientFSM_SM_Waiting;
    class CommsTestClientFSM_SM_Default;
    class CommsTestClientFSMState;
    class CommsTestClientFSMContext;
    class CommsTestClientFSM;

    class CommsTestClientFSMState :
        public statemap::State
    {
    public:

        CommsTestClientFSMState(const char *name, int stateId)
        : statemap::State(name, stateId)
        {};

        virtual void Entry(CommsTestClientFSMContext&) {};
        virtual void Exit(CommsTestClientFSMContext&) {};

        virtual void CommsTestMsgTransition(CommsTestClientFSMContext& context, CommsTestMsg msg, JausAddress sender);
        virtual void reportServicesTransition(CommsTestClientFSMContext& context, ReportServices msg, JausAddress sender);
        virtual void timeoutTransition(CommsTestClientFSMContext& context);

    protected:

        virtual void Default(CommsTestClientFSMContext& context);
    };

    class CommsTestClientFSM_SM
    {
    public:

        static CommsTestClientFSM_SM_Running Running;
        static CommsTestClientFSM_SM_Waiting Waiting;
    };

    class CommsTestClientFSM_SM_Default :
        public CommsTestClientFSMState
    {
    public:

        CommsTestClientFSM_SM_Default(const char *name, int stateId)
        : CommsTestClientFSMState(name, stateId)
        {};

    };

    class CommsTestClientFSM_SM_Running :
        public CommsTestClientFSM_SM_Default
    {
    public:
        CommsTestClientFSM_SM_Running(const char *name, int stateId)
        : CommsTestClientFSM_SM_Default(name, stateId)
        {};

        void CommsTestMsgTransition(CommsTestClientFSMContext& context, CommsTestMsg msg, JausAddress sender);
        void timeoutTransition(CommsTestClientFSMContext& context);
    };

    class CommsTestClientFSM_SM_Waiting :
        public CommsTestClientFSM_SM_Default
    {
    public:
        CommsTestClientFSM_SM_Waiting(const char *name, int stateId)
        : CommsTestClientFSM_SM_Default(name, stateId)
        {};

        void reportServicesTransition(CommsTestClientFSMContext& context, ReportServices msg, JausAddress sender);
        void timeoutTransition(CommsTestClientFSMContext& context);
    };

    class CommsTestClientFSMContext :
        public statemap::FSMContext
    {
    public:

        CommsTestClientFSMContext(CommsTestClientFSM& owner)
        : FSMContext(CommsTestClientFSM_SM::Waiting),
          _owner(owner)
        {};

        CommsTestClientFSMContext(CommsTestClientFSM& owner, const statemap::State& state)
        : FSMContext(state),
          _owner(owner)
        {};

        virtual void enterStartState()
        {
            getState().Entry(*this);
            return;
        }

        CommsTestClientFSM& getOwner() const
        {
            return (_owner);
        };

        CommsTestClientFSMState& getState() const
        {
            if (_state == NULL)
            {
                throw statemap::StateUndefinedException();
            }

            return (dynamic_cast<CommsTestClientFSMState&>(*_state));
        };

        void CommsTestMsgTransition(CommsTestMsg msg, JausAddress sender)
        {
            setTransition("CommsTestMsgTransition");
            (getState()).CommsTestMsgTransition(*this, msg, sender);
            setTransition(NULL);
        };

        void reportServicesTransition(ReportServices msg, JausAddress sender)
        {
            setTransition("reportServicesTransition");
            (getState()).reportServicesTransition(*this, msg, sender);
            setTransition(NULL);
        };

        void timeoutTransition()
        {
            setTransition("timeoutTransition");
            (getState()).timeoutTransition(*this);
            setTransition(NULL);
        };

    private:

        CommsTestClientFSM& _owner;
    };
}


/*
 * Local variables:
 *  buffer-read-only: t
 * End:
 */

#endif // _H_COMMSTESTCLIENTFSM_SM

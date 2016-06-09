

#include "urn_jaus_example_addition_server_1_0/AdditionServerServiceDefService.h"

using namespace JTS;

namespace urn_jaus_example_addition_server_1_0
{
	
AdditionServerServiceDefService::AdditionServerServiceDefService(JTS::JausRouter* jausRouter ) : Service()
{
	jausRouter->setTransportType(JausRouter::Version_1_0);
	
	pAdditionServerServiceDef_additionServerFSM = new AdditionServerServiceDef_additionServerFSM();
	pAdditionServerServiceDef_additionServerFSM->setHandlers(ieHandler, jausRouter);
	pAdditionServerServiceDef_additionServerFSM->setupNotifications();

}


AdditionServerServiceDefService::~AdditionServerServiceDefService()
{
	delete pAdditionServerServiceDef_additionServerFSM;

}

/**
 *	This is the function that will actually be run by the thread at start-up.
 *  We override it from EventReceiver in order to handle any entry
 *  actions defined by the initial state. 
 */
void AdditionServerServiceDefService::run()
{
	
	/// Perform any entry actions specified by the start state.
	pAdditionServerServiceDef_additionServerFSM->fsmStartedAction();

	
	/// Kick-off the receive loop...
	EventReceiver::run();
}

/**
 *	This is the function that will process an event either generated
 *  by the service, sent to it by another service on the same component,
 *  or as a message sent by a different component. 
 */
bool AdditionServerServiceDefService::processTransitions(InternalEvent* ie)
{
        bool done = false;

   // Since this function can be called from multiple threads,
   // we use a mutex to ensure only one state transition is
   // active at a time.
   mutex.lock();

			// Invoke the FSM transition for this event.
			try
			{
				if ((done == false) && (ie->getName().compare("Receive") == 0))
				{
					Receive* casted_ie = (Receive*) ie;
					unsigned short id = *((unsigned short*) casted_ie->getBody()->getReceiveRec()->getMessagePayload()->getData());

					if ((id != QueryAddition::ID))
						goto leave;
				}
			} catch (...) {}

			try
			{
				if ((done == false) && ie->getName().compare("Receive") == 0 && (ie->getSource().compare("AdditionServerServiceDef_additionServerFSM") != 0))
				{
					Receive* casted_ie = (Receive*) ie;
					unsigned short id = *((unsigned short*) casted_ie->getBody()->getReceiveRec()->getMessagePayload()->getData());
					id = JSIDL_v_1_0::correctEndianness(id);
					if ( id == QueryAddition::ID)
					{
						QueryAddition msg;
						msg.decode(casted_ie->getBody()->getReceiveRec()->getMessagePayload()->getData());
						// Unique identifier used to replace previous edits upon regeneration, do not delete this comment:c9ea0ef4-3450-3221-826e-e33c1f9c5bd4
						unsigned int sender =
(casted_ie->getBody()->getReceiveRec()->getSrcSubsystemID() << 16) +
(casted_ie->getBody()->getReceiveRec()->getSrcNodeID() << 8) +
(casted_ie->getBody()->getReceiveRec()->getSrcComponentID());
						pAdditionServerServiceDef_additionServerFSM->context->QueryAdditionTransition(msg, sender);
						done = true;
						goto leave;
					}
				}
			} catch (...) {}

			try
			{
				if ((done == false) && ie->getName().compare("InitToReadyEventDef") == 0 && (ie->getSource().compare("AdditionServerServiceDef_additionServerFSM") != 0))
				{
					InitToReadyEventDef* casted_ie = (InitToReadyEventDef*) ie;
						pAdditionServerServiceDef_additionServerFSM->context->InitToReadyEventDefTransition();
						done = true;
						goto leave;
				}
			} catch (...) {}

			try
			{
				if ((done == false) && ie->getName().compare("InternalStateChange_To_AdditionServerServiceDef_additionServerFSM_Ready") == 0 && (ie->getSource().compare("AdditionServerServiceDef_additionServerFSM") != 0))
				{
						pAdditionServerServiceDef_additionServerFSM->context->InternalStateChange_To_AdditionServerServiceDef_additionServerFSM_ReadyTransition(ie);
						done = true;
						goto leave;
				}
			} catch (...) {}

			try
			{
				if ((done == false) && ie->getName().compare("InternalStateChange_To_AdditionServerServiceDef_additionServerFSM_Init") == 0 && (ie->getSource().compare("AdditionServerServiceDef_additionServerFSM") != 0))
				{
						pAdditionServerServiceDef_additionServerFSM->context->InternalStateChange_To_AdditionServerServiceDef_additionServerFSM_InitTransition(ie);
						done = true;
						goto leave;
				}
			} catch (...) {}

			 
leave:
   mutex.unlock();
   return done;
}


/**
 *	This is the function that will check for default transitions if
 *  no other transitions were satisfied. 
 */
bool AdditionServerServiceDefService::defaultTransitions(InternalEvent* ie)
{
   bool done = false;

   // Since this function can be called from multiple threads,
   // we use a mutex to ensure only one state transition is
   // active at a time.
   mutex.lock();

			// Invoke the FSM transition for this event.
			try
			{
				if ((done == false) && ie->getName().compare("Receive") == 0 && (ie->getSource().compare("AdditionServerServiceDef_additionServerFSM") != 0))
				{
					Receive* casted_ie = (Receive*) ie;
					unsigned short id = *((unsigned short*) casted_ie->getBody()->getReceiveRec()->getMessagePayload()->getData());
					id = JSIDL_v_1_0::correctEndianness(id);
					if ( id == QueryAddition::ID)
					{
						QueryAddition msg;
						msg.decode(casted_ie->getBody()->getReceiveRec()->getMessagePayload()->getData());
						pAdditionServerServiceDef_additionServerFSM->context->QueryAdditionTransition();
						done = true;
						goto leave;
					}
				}
			} catch (...) {}

			try
			{
				if ((done == false) && ie->getName().compare("InitToReadyEventDef") == 0 && (ie->getSource().compare("AdditionServerServiceDef_additionServerFSM") != 0))
				{
					InitToReadyEventDef* casted_ie = (InitToReadyEventDef*) ie;
						pAdditionServerServiceDef_additionServerFSM->context->InitToReadyEventDefTransition();
						done = true;
						goto leave;
				}
			} catch (...) {}

	
leave:
   mutex.unlock();
   return done;
}


};

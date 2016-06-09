

#ifndef PRIMSERVER_PRIMSERVER_H
#define PRIMSERVER_PRIMSERVER_H

#include "JausUtils.h"
#include "InternalEvents/InternalEventHandler.h"
#include "Transport/JausTransport.h"
#include "JTSStateMachine.h"
#include "urn_jaus_jss_PrimServer_1_0/Messages/MessageSet.h"
#include "urn_jaus_jss_PrimServer_1_0/InternalEvents/InternalEventsSet.h"

typedef JTS::Receive_1_0 Receive;
typedef JTS::Send_1_0 Send;



#include "PrimServer_primServer_sm.h"

namespace urn_jaus_jss_PrimServer_1_0
{
	
class DllExport PrimServer_primServer : public JTS::StateMachine
{
public:
	PrimServer_primServer();
	virtual ~PrimServer_primServer();
	
	/// Handle notifications on parent state changes
	virtual void setupNotifications();

	/// Action Methods
	virtual void QueryWrenchEffortAction();
	virtual void SetWrenchEffortAction();
	virtual void startServiceAction();


	/// Guard Methods

	
	
	PrimServer_primServerContext *context;
	
protected:

    /// References to parent FSMs

    
};

};

#endif // PRIMSERVER_PRIMSERVER_H

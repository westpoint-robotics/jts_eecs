

#ifndef PRIMSERVERSERVICE_H
#define PRIMSERVERSERVICE_H

#include "Service.h"
#include "InternalEvents/InternalEventHandler.h"
#include "Transport/JausTransport.h"
#include "JConstants.h"
#include "urn_jaus_jss_PrimServer_1_0/Messages/MessageSet.h"
#include "urn_jaus_jss_PrimServer_1_0/InternalEvents/InternalEventsSet.h"
#include "Transport/OS.h"

#include "PrimServer_primServer.h"


namespace urn_jaus_jss_PrimServer_1_0
{
	
class DllExport PrimServerService : public JTS::Service
{
public:
	PrimServerService( JTS::JausRouter* jausRouter );
	virtual ~PrimServerService();
	
	virtual bool processTransitions(JTS::InternalEvent* ie);
	virtual bool defaultTransitions(JTS::InternalEvent* ie);
	
	// FSMs are public so that children services can access them
	PrimServer_primServer* pPrimServer_primServer;
	


	
protected:
	virtual void run();

};

};

#endif // PRIMSERVERSERVICE_H

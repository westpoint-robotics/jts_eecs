

#ifndef PRIMSERVER_H
#define PRIMSERVER_H

#include <vector>
#include "EventReceiver.h"
#include "Transport/JausTransport.h"
#include "InternalEvents/InternalEvent.h"
#include "urn_jaus_jss_PrimServer_1_0/PrimServerService.h"


class PrimServer : public JTS::EventReceiver
{
public:
	PrimServer(unsigned int subsystem, unsigned short node, unsigned short component);
	virtual ~PrimServer();
	
	void startComponent();
	void shutdownComponent();
	
protected:
	virtual void processInternalEvent(JTS::InternalEvent* ie);
	
	std::vector<JTS::Service*> serviceList;
	JTS::JausRouter* jausRouter;
	
};

#endif // PRIMSERVER_H

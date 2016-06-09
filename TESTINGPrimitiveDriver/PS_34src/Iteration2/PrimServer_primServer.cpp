

#include "urn_jaus_jss_PrimServer_1_0/PrimServer_primServer.h"




using namespace JTS;

namespace urn_jaus_jss_PrimServer_1_0
{



PrimServer_primServer::PrimServer_primServer()
{

	/*
	 * If there are other variables, context must be constructed last so that all 
	 * class variables are available if an EntryAction of the InitialState of the 
	 * statemachine needs them. 
	 */
	context = new PrimServer_primServerContext(*this);

}



PrimServer_primServer::~PrimServer_primServer() 
{
	delete context;
}

void PrimServer_primServer::setupNotifications()
{
	//might have to handle some events here, probably not, don't think so.
}

void PrimServer_primServer::QueryWrenchEffortAction()
{
	//send a QueryWrenchEffort message to the PrimitiveDriver component
	int var;
	QueryWrenchEffort msg;
	std::cout << "Press 1 to proceed ";
	std::cin >> var;
	JausAddress primDriver(jausRouter->getJausAddress()->getSubsystemID(),jausRouter->getJausAddress()->getNodeID(),33);
	sendJausMessage(msg,primDriver);
	printf("PrimServer(NotARobot) querying PrimitiveDriver(Robot)!\n");
}

void PrimServer_primServer::SetWrenchEffortAction()//goal is to send simple commands to robot.
{
	int linX;
	int rotZ;
	SetWrenchEffort msg;
	//set linear x effort to arbitrary value 
	std::cout << "Enter the Linear X in integer form ";
	std::cin >> linX;
	msg.getBody()->getWrenchEffortRec()->setPropulsiveLinearEffortX(linX);
	printf("Set Wrench X!\n");
	//set rotation in the Z axis to arbitrary value of 1
	std::cout << "Enter the Rotational Z in integer form ";
	std::cin >> rotZ;
	msg.getBody()->getWrenchEffortRec()->setPropulsiveRotationalEffortZ(rotZ);
	printf("Set Wrench Z-Rotate!\n");
	//send new message back to the driver, its componentID is 33
	//try this, define the address of the PrimDriver component using its component ID, then send message there. 
	JausAddress primDriver(jausRouter->getJausAddress()->getSubsystemID(),jausRouter->getJausAddress()->getNodeID(),33);
	sendJausMessage(msg,primDriver);
	printf("Sent Wrench Commands!\n");
}

void PrimServer_primServer::startServiceAction()
{
	//send the first QueryWrenchEffort here, will only happen once to trigger the reportwrencheffort which will be handled by the internal transition
	printf("PrimServer(NotARobot) starting service!\n");
	printf("Sending initial query\n");
	QueryWrenchEffort msg;
	JausAddress primDriver(jausRouter->getJausAddress()->getSubsystemID(),jausRouter->getJausAddress()->getNodeID(),33);
	sendJausMessage(msg,primDriver);
}





};

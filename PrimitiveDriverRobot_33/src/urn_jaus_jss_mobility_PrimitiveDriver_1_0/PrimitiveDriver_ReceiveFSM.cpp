

#include "urn_jaus_jss_mobility_PrimitiveDriver_1_0/PrimitiveDriver_ReceiveFSM.h"
//#include "urn_jts_examples_SkidSteerVehicleSim_1_0/Messages/SetWrenchEffort.h"
#include <math.h>
#define FIND_MAX(a,b) ((a<b) ? b: a)
#define FIND_MIN(a,b) ((a<b) ? a: b)



using namespace JTS;

namespace urn_jaus_jss_mobility_PrimitiveDriver_1_0
{

static int wrenchX;
static int wrenchRotZ;


PrimitiveDriver_ReceiveFSM::PrimitiveDriver_ReceiveFSM(urn_jaus_jss_core_Transport_1_0::Transport_ReceiveFSM* pTransport_ReceiveFSM, urn_jaus_jss_core_Events_1_0::Events_ReceiveFSM* pEvents_ReceiveFSM, urn_jaus_jss_core_AccessControl_1_0::AccessControl_ReceiveFSM* pAccessControl_ReceiveFSM, urn_jaus_jss_core_Management_1_0::Management_ReceiveFSM* pManagement_ReceiveFSM)
{

	/*
	 * If there are other variables, context must be constructed last so that all 
	 * class variables are available if an EntryAction of the InitialState of the 
	 * statemachine needs them. 
	 */
	context = new PrimitiveDriver_ReceiveFSMContext(*this);

	this->pTransport_ReceiveFSM = pTransport_ReceiveFSM;
	this->pEvents_ReceiveFSM = pEvents_ReceiveFSM;
	this->pAccessControl_ReceiveFSM = pAccessControl_ReceiveFSM;
	this->pManagement_ReceiveFSM = pManagement_ReceiveFSM;
}



PrimitiveDriver_ReceiveFSM::~PrimitiveDriver_ReceiveFSM() 
{
	delete context;
}

void PrimitiveDriver_ReceiveFSM::setupNotifications()
{
	pManagement_ReceiveFSM->registerNotification("Receiving_Ready_NotControlled_StateA_Standby", ieHandler, "InternalStateChange_To_PrimitiveDriver_ReceiveFSM_Receiving_Ready_NotControlled_StateA_Standby", "Management_ReceiveFSM");
	pManagement_ReceiveFSM->registerNotification("Receiving_Ready_NotControlled_StateA_Init", ieHandler, "InternalStateChange_To_PrimitiveDriver_ReceiveFSM_Receiving_Ready_NotControlled_StateA_Init", "Management_ReceiveFSM");
	pManagement_ReceiveFSM->registerNotification("Receiving_Ready_NotControlled_StateA_Failure", ieHandler, "InternalStateChange_To_PrimitiveDriver_ReceiveFSM_Receiving_Ready_NotControlled_StateA_Failure", "Management_ReceiveFSM");
	pManagement_ReceiveFSM->registerNotification("Receiving_Ready_NotControlled_StateA_Shutdown", ieHandler, "InternalStateChange_To_PrimitiveDriver_ReceiveFSM_Receiving_Ready_NotControlled_StateA_Shutdown", "Management_ReceiveFSM");
	pManagement_ReceiveFSM->registerNotification("Receiving_Ready_NotControlled_StateA_Emergency", ieHandler, "InternalStateChange_To_PrimitiveDriver_ReceiveFSM_Receiving_Ready_NotControlled_StateA_Emergency", "Management_ReceiveFSM");
	pManagement_ReceiveFSM->registerNotification("Receiving_Ready_NotControlled_StateA", ieHandler, "InternalStateChange_To_PrimitiveDriver_ReceiveFSM_Receiving_Ready_NotControlled_StateA_Init", "Management_ReceiveFSM");
	pManagement_ReceiveFSM->registerNotification("Receiving_Ready_NotControlled", ieHandler, "InternalStateChange_To_PrimitiveDriver_ReceiveFSM_Receiving_Ready_NotControlled_StateA_Init", "Management_ReceiveFSM");
	pManagement_ReceiveFSM->registerNotification("Receiving_Ready_Controlled_StateB_Standby", ieHandler, "InternalStateChange_To_PrimitiveDriver_ReceiveFSM_Receiving_Ready_Controlled_StateB_Standby", "Management_ReceiveFSM");
	pManagement_ReceiveFSM->registerNotification("Receiving_Ready_Controlled_StateB_Ready", ieHandler, "InternalStateChange_To_PrimitiveDriver_ReceiveFSM_Receiving_Ready_Controlled_StateB_Ready", "Management_ReceiveFSM");
	pManagement_ReceiveFSM->registerNotification("Receiving_Ready_Controlled_StateB_Emergency", ieHandler, "InternalStateChange_To_PrimitiveDriver_ReceiveFSM_Receiving_Ready_Controlled_StateB_Emergency", "Management_ReceiveFSM");
	pManagement_ReceiveFSM->registerNotification("Receiving_Ready_Controlled_StateB", ieHandler, "InternalStateChange_To_PrimitiveDriver_ReceiveFSM_Receiving_Ready_Controlled_StateB_Standby", "Management_ReceiveFSM");
	pManagement_ReceiveFSM->registerNotification("Receiving_Ready_Controlled", ieHandler, "InternalStateChange_To_PrimitiveDriver_ReceiveFSM_Receiving_Ready_Controlled_StateB_Standby", "Management_ReceiveFSM");
	pManagement_ReceiveFSM->registerNotification("Receiving_Ready", ieHandler, "InternalStateChange_To_PrimitiveDriver_ReceiveFSM_Receiving_Ready_NotControlled_StateA_Init", "Management_ReceiveFSM");
	pManagement_ReceiveFSM->registerNotification("Receiving", ieHandler, "InternalStateChange_To_PrimitiveDriver_ReceiveFSM_Receiving_Ready_NotControlled_StateA_Init", "Management_ReceiveFSM");
	registerNotification("Receiving_Ready_NotControlled_StateA_Standby", pManagement_ReceiveFSM->getHandler(), "InternalStateChange_To_Management_ReceiveFSM_Receiving_Ready_NotControlled_StateA_Standby", "PrimitiveDriver_ReceiveFSM");
	registerNotification("Receiving_Ready_NotControlled_StateA_Init", pManagement_ReceiveFSM->getHandler(), "InternalStateChange_To_Management_ReceiveFSM_Receiving_Ready_NotControlled_StateA_Init", "PrimitiveDriver_ReceiveFSM");
	registerNotification("Receiving_Ready_NotControlled_StateA_Failure", pManagement_ReceiveFSM->getHandler(), "InternalStateChange_To_Management_ReceiveFSM_Receiving_Ready_NotControlled_StateA_Failure", "PrimitiveDriver_ReceiveFSM");
	registerNotification("Receiving_Ready_NotControlled_StateA_Shutdown", pManagement_ReceiveFSM->getHandler(), "InternalStateChange_To_Management_ReceiveFSM_Receiving_Ready_NotControlled_StateA_Shutdown", "PrimitiveDriver_ReceiveFSM");
	registerNotification("Receiving_Ready_NotControlled_StateA_Emergency", pManagement_ReceiveFSM->getHandler(), "InternalStateChange_To_Management_ReceiveFSM_Receiving_Ready_NotControlled_StateA_Emergency", "PrimitiveDriver_ReceiveFSM");
	registerNotification("Receiving_Ready_NotControlled_StateA", pManagement_ReceiveFSM->getHandler(), "InternalStateChange_To_Management_ReceiveFSM_Receiving_Ready_NotControlled_StateA", "PrimitiveDriver_ReceiveFSM");
	registerNotification("Receiving_Ready_NotControlled", pManagement_ReceiveFSM->getHandler(), "InternalStateChange_To_Management_ReceiveFSM_Receiving_Ready_NotControlled", "PrimitiveDriver_ReceiveFSM");
	registerNotification("Receiving_Ready_Controlled_StateB_Standby", pManagement_ReceiveFSM->getHandler(), "InternalStateChange_To_Management_ReceiveFSM_Receiving_Ready_Controlled_StateB_Standby", "PrimitiveDriver_ReceiveFSM");
	registerNotification("Receiving_Ready_Controlled_StateB_Ready", pManagement_ReceiveFSM->getHandler(), "InternalStateChange_To_Management_ReceiveFSM_Receiving_Ready_Controlled_StateB_Ready", "PrimitiveDriver_ReceiveFSM");
	registerNotification("Receiving_Ready_Controlled_StateB_Emergency", pManagement_ReceiveFSM->getHandler(), "InternalStateChange_To_Management_ReceiveFSM_Receiving_Ready_Controlled_StateB_Emergency", "PrimitiveDriver_ReceiveFSM");
	registerNotification("Receiving_Ready_Controlled_StateB", pManagement_ReceiveFSM->getHandler(), "InternalStateChange_To_Management_ReceiveFSM_Receiving_Ready_Controlled_StateB", "PrimitiveDriver_ReceiveFSM");
	registerNotification("Receiving_Ready_Controlled", pManagement_ReceiveFSM->getHandler(), "InternalStateChange_To_Management_ReceiveFSM_Receiving_Ready_Controlled", "PrimitiveDriver_ReceiveFSM");
	registerNotification("Receiving_Ready", pManagement_ReceiveFSM->getHandler(), "InternalStateChange_To_Management_ReceiveFSM_Receiving_Ready", "PrimitiveDriver_ReceiveFSM");
	registerNotification("Receiving", pManagement_ReceiveFSM->getHandler(), "InternalStateChange_To_Management_ReceiveFSM_Receiving", "PrimitiveDriver_ReceiveFSM");

}

void PrimitiveDriver_ReceiveFSM::SendAction(std::string arg0, Receive::Body::ReceiveRec transportData)
{
	JausAddress sender(transportData.getSrcSubsystemID(),transportData.getSrcNodeID(),transportData.getSrcComponentID());
	//we only output ReportWrenchEffort
	if (arg0 == "ReportWrenchEffort")
	{
		ReportWrenchEffort wrenchEf_msg;
		//get the linear x and rotational z so we can see in the console
		//int wrenchX = wrenchEf_msg.getBody()->getWrenchEffortRec()->getPropulsiveLinearEffortX();
		//int wrenchRotZ = wrenchEf_msg.getBody()->getWrenchEffortRec()->getPropulsiveRotationalEffortZ();
		//sendJausMessage( wrenchEf_msg, sender);
		urn_jaus_jss_mobility_PrimitiveDriver_1_0::wrenchX = wrenchEf_msg.getBody()->getWrenchEffortRec()->getPropulsiveLinearEffortX();
		urn_jaus_jss_mobility_PrimitiveDriver_1_0::wrenchRotZ = wrenchEf_msg.getBody()->getWrenchEffortRec()->getPropulsiveRotationalEffortZ();
		sendJausMessage( wrenchEf_msg, sender);
		//the default output has been -100, which is the lower limit percent of maximum. 
		std::cout << " The Linear X is " << urn_jaus_jss_mobility_PrimitiveDriver_1_0::wrenchX << std::endl;
		std::cout << " The Rotational Z is " << urn_jaus_jss_mobility_PrimitiveDriver_1_0::wrenchRotZ << std::endl;
		std::cout << "sendAction completed!" << std::endl;
	}


}

void PrimitiveDriver_ReceiveFSM::setWrenchEffortAction(SetWrenchEffort msg)
{
	//SetWrenchEffort wrench_msg;
	//set the wrench values
	//int wrenchX = wrench_msg.getBody()->getWrenchEffortRec()->getPropulsiveLinearEffortX();
	//int wrenchRotZ =  wrench_msg.getBody()->getWrenchEffortRec()->getPropulsiveRotationalEffortZ();
	msg.getBody()->getWrenchEffortRec()->setPropulsiveLinearEffortX(urn_jaus_jss_mobility_PrimitiveDriver_1_0::wrenchX);
	msg.getBody()->getWrenchEffortRec()->setPropulsiveRotationalEffortZ(urn_jaus_jss_mobility_PrimitiveDriver_1_0::wrenchRotZ);
	//this output is not seen
	std::cout << " The Linear X is " << urn_jaus_jss_mobility_PrimitiveDriver_1_0::wrenchX << std::endl;
	std::cout << " The Rotational Z is " << urn_jaus_jss_mobility_PrimitiveDriver_1_0::wrenchRotZ << std::endl;

	//urn_jaus_jss_mobility_PrimitiveDriver_1_0::SetWrenchEffort(msg);

	JausAddress primDriverRobot(jausRouter->getJausAddress()->getSubsystemID(),jausRouter->getJausAddress()->getNodeID(),33);
	sendJausMessage(msg,primDriverRobot);

}



bool PrimitiveDriver_ReceiveFSM::isControllingClient(Receive::Body::ReceiveRec transportData)
{
	//// By default, inherited guards call the parent function.
	//// This can be replaced or modified as needed.
	return pAccessControl_ReceiveFSM->isControllingClient(transportData );
}



};

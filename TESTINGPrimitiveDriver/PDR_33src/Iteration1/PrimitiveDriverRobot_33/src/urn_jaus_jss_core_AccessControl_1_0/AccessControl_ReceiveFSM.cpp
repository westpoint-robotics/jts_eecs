

#include "urn_jaus_jss_core_AccessControl_1_0/AccessControl_ReceiveFSM.h"




using namespace JTS;

namespace urn_jaus_jss_core_AccessControl_1_0
{
	static JausAddress *currentController = NULL;
	static unsigned char currentAuthority = 0;
	static unsigned char defaultAuthority = 1;


AccessControl_ReceiveFSM::AccessControl_ReceiveFSM(urn_jaus_jss_core_Transport_1_0::Transport_ReceiveFSM* pTransport_ReceiveFSM, urn_jaus_jss_core_Events_1_0::Events_ReceiveFSM* pEvents_ReceiveFSM)
{

	/*
	 * If there are other variables, context must be constructed last so that all 
	 * class variables are available if an EntryAction of the InitialState of the 
	 * statemachine needs them. 
	 */
	context = new AccessControl_ReceiveFSMContext(*this);

	this->pTransport_ReceiveFSM = pTransport_ReceiveFSM;
	this->pEvents_ReceiveFSM = pEvents_ReceiveFSM;
}



AccessControl_ReceiveFSM::~AccessControl_ReceiveFSM() 
{
	delete context;
}

void AccessControl_ReceiveFSM::setupNotifications()
{
	pEvents_ReceiveFSM->registerNotification("Receiving_Ready", ieHandler, "InternalStateChange_To_AccessControl_ReceiveFSM_Receiving_Ready_NotControlled", "Events_ReceiveFSM");
	pEvents_ReceiveFSM->registerNotification("Receiving", ieHandler, "InternalStateChange_To_AccessControl_ReceiveFSM_Receiving_Ready_NotControlled", "Events_ReceiveFSM");
	registerNotification("Receiving_Ready_NotControlled", pEvents_ReceiveFSM->getHandler(), "InternalStateChange_To_Events_ReceiveFSM_Receiving_Ready", "AccessControl_ReceiveFSM");
	registerNotification("Receiving_Ready_Controlled", pEvents_ReceiveFSM->getHandler(), "InternalStateChange_To_Events_ReceiveFSM_Receiving_Ready", "AccessControl_ReceiveFSM");
	registerNotification("Receiving_Ready", pEvents_ReceiveFSM->getHandler(), "InternalStateChange_To_Events_ReceiveFSM_Receiving_Ready", "AccessControl_ReceiveFSM");
	registerNotification("Receiving", pEvents_ReceiveFSM->getHandler(), "InternalStateChange_To_Events_ReceiveFSM_Receiving", "AccessControl_ReceiveFSM");

}

void AccessControl_ReceiveFSM::ResetTimerAction()
{
	/// Insert User Code HERE
}

void AccessControl_ReceiveFSM::SendAction(std::string arg0, Receive::Body::ReceiveRec transportData)
{
	/// Insert User Code HERE
}

void AccessControl_ReceiveFSM::SendAction(std::string arg0, std::string arg1)
{
	/// Insert User Code HERE
}

void AccessControl_ReceiveFSM::SendAction(std::string arg0, std::string arg1, Receive::Body::ReceiveRec transportData)
{
	//Extract the sender information
	JausAddress sender(transportData.getSrcSubsystemID(), transportData.getSrcNodeID(),transportData.getSrcComponentID());
	

	if (arg0 == "RejectControl")
	{
		std::cout << "Sending RejectControl with an argument " << arg1 << std::endl;
		RejectControl reject_msg;
		if (arg1 == "CONTROL_RELEASED") reject_msg.getBody()->getRejectControlRec()->setResponseCode(0);
		if (arg1 == "NOT_ACCEPTED") reject_msg.getBody()->getRejectControlRec()->setResponseCode(1);

		sendJausMessage(reject_msg,sender);
	}
	else if (arg0 == "ConfirmControl")
	{
		ConfirmControl confirm_msg;
		unsigned char responseCode = 0;
		if (arg1 == "CONTROL_ACCEPTED") responseCode = 0;
		if (arg1 =="NOT_AVAILABLE") responseCode = 1;
		if (arg1 =="INSUFFICIENT_AUTHORITY") responseCode = 2;
		confirm_msg.getBody()->getConfirmControlRec()->setResponseCode(responseCode);
		std::cout << "Sending ConfirmControl with argument " << arg1 << std::endl;

		sendJausMessage(confirm_msg, sender);
	
	}
	else if (arg0 == "ReportControl")
	{
		ReportControl control_msg;
		control_msg.getBody()->getReportControlRec()->setSubsystemID(
											(currentController == NULL) ? 0 : currentController->getSubsystemID() );
		control_msg.getBody()->getReportControlRec()->setSubsystemID(
			(currentController == NULL) ? 0 : currentController->getNodeID() );
		control_msg.getBody()->getReportControlRec()->setSubsystemID(
			(currentController == NULL) ? 0 : currentController->getComponentID() );
	}
}

void AccessControl_ReceiveFSM::SetAuthorityAction(RequestControl msg)
{
	//// Insert User Code HERE
	std::cout << "Storing authority code of controller as " <<
		(unsigned short) msg.getBody()->getRequestControlRec()->getAuthorityCode() << std::endl;

	currentAuthority = msg.getBody()->getRequestControlRec()->getAuthorityCode();
}

void AccessControl_ReceiveFSM::SetAuthorityAction(SetAuthority msg)
{
	/// Insert User Code HERE
}

void AccessControl_ReceiveFSM::StoreAddressAction(Receive::Body::ReceiveRec transportData)
{
	std::cout << "Storing address of controlling component as " << 
		(unsigned short)transportData.getSrcSubsystemID() << "." << 
		(unsigned short)transportData.getSrcNodeID() << "." <<
		(unsigned short)transportData.getSrcComponentID() << std::endl;

	if (currentController) delete currentController;
	currentController = new JausAddress(transportData.getSrcSubsystemID(),
		transportData.getSrcNodeID(), transportData.getSrcComponentID());

}

void AccessControl_ReceiveFSM::initAction()
{
	/// Insert User Code HERE
}



bool AccessControl_ReceiveFSM::isAuthorityValid(SetAuthority msg)
{
	/// Insert User Code HERE
	return false;
}

bool AccessControl_ReceiveFSM::isControlAvailable()
{
	/// Insert User Code HERE
	return false;
}

bool AccessControl_ReceiveFSM::isControllingClient(Receive::Body::ReceiveRec transportData)
{
	JausAddress requester(transportData.getSrcSubsystemID(), transportData.getSrcNodeID(), transportData.getSrcComponentID());
	if ((currentController != NULL) && (requester == *currentController)) return true;
	return false;
}

bool AccessControl_ReceiveFSM::isCurrentAuthorityLess(RequestControl msg)
{
	return (currentAuthority < msg.getBody()->getRequestControlRec()->getAuthorityCode());
}

bool AccessControl_ReceiveFSM::isDefaultAuthorityGreater(RequestControl msg)
{
	if (defaultAuthority > msg.getBody()->getRequestControlRec()->getAuthorityCode())
		return true;

	return false;
}



};

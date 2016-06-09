

#include "urn_jaus_example_addition_server_1_0/AdditionServerServiceDef_additionServerFSM.h"




using namespace JTS;

namespace urn_jaus_example_addition_server_1_0
{



AdditionServerServiceDef_additionServerFSM::AdditionServerServiceDef_additionServerFSM()
{

	/*
	 * If there are other variables, context must be constructed last so that all 
	 * class variables are available if an EntryAction of the InitialState of the 
	 * statemachine needs them. 
	 */
	context = new AdditionServerServiceDef_additionServerFSMContext(*this);

}



AdditionServerServiceDef_additionServerFSM::~AdditionServerServiceDef_additionServerFSM() 
{
	delete context;
}

void AdditionServerServiceDef_additionServerFSM::setupNotifications()
{

}

void AdditionServerServiceDef_additionServerFSM::fsmStartedAction()
{
	/// We now generate an internal event,which will be handled up
	/// above, resulting in a transition call to move us from Init to Ready
	std::cout << "Calculation server started\n";
	ieHandler->invoke(new InitToReadyEventDef());
	std::cout << "Sent internal event to transition of Ready\n";
}

void AdditionServerServiceDef_additionServerFSM::sendReportAdditionAction(QueryAddition msg, unsigned int sender)
{
	/// Insert User Code HERE
	int A1=msg.getAdditionInputBody()->getAdditionInput()->getA1();
	int A2=msg.getAdditionInputBody()->getAdditionInput()->getA2();
	int op = msg.getAdditionInputBody()->getAdditionInput()->getOperator();
	int answer;
	if (op == 1){//add
		std::cout << "Need to add "  << A1 << " + " << A2 << std::endl;
		answer = A1 + A2;
	}
	else if (op == 2){//subtract
		std::cout << "Need to subtract "  << A1 << " - " << A2 << std::endl;
		answer = A1 - A2;
	}
	else if (op == 3) {//divide
		std::cout << "Need to divide "  << A1 << " / " << A2 << std::endl;
		answer = A1 / A2;
	}
	else if (op == 4) {//multiply
	
	std::cout << "Need to multiply "  << A1 << " * " << A2 << std::endl;
	answer = A1 * A2;
	}
	
	
	//answer = A1 + A2;
	ReportAddition theAnswer;
	theAnswer.getAdditionOutputBody()->getAdditionOutput()->setAdditionResult(answer);

	sendJausMessage( theAnswer, JausAddress(sender));

	std::cout << answer <<" sent to client\n" << std::endl;

}

void AdditionServerServiceDef_additionServerFSM::serverInitializedAction()
{
	std::cout << "Transitioned from Init to Ready. Ready to begin calculating!\n:";

}





};

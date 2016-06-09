

#include "urn_jaus_example_addition_client_1_0/AdditionClientServiceDef_additionClientFSM.h"




using namespace JTS;

namespace urn_jaus_example_addition_client_1_0
{



AdditionClientServiceDef_additionClientFSM::AdditionClientServiceDef_additionClientFSM()
{

	/*
	 * If there are other variables, context must be constructed last so that all 
	 * class variables are available if an EntryAction of the InitialState of the 
	 * statemachine needs them. 
	 */
	context = new AdditionClientServiceDef_additionClientFSMContext(*this);

}



AdditionClientServiceDef_additionClientFSM::~AdditionClientServiceDef_additionClientFSM() 
{
	delete context;
}

void AdditionClientServiceDef_additionClientFSM::setupNotifications()
{

}

void AdditionClientServiceDef_additionClientFSM::printAnswerToScreenAction(ReportAddition msg)
{
	/// Insert User Code HERE
	std::cout << "Transitioned back to Ready\n";
	std::cout << " The answer is "
		<< msg.getAdditionOutputBody()->getAdditionOutput()->getAdditionResult() << std::endl;
	AdditionClientServiceDef_additionClientFSM::serviceInitializedAction();

}

void AdditionClientServiceDef_additionClientFSM::serviceInitializedAction()
{
	/// Insert User Code HERE
  int var;
  //do {
	std::cout << "In Ready State. Let's start calculating...\n";
	QueryAddition query;
	//int var;
	int a1;
	int a2;
	std::cout << "Enter 1 to add\n";
	std::cout << "Enter 2 to subtract\n";
	std::cout << "Enter 3 to divide\n";
	std::cout << "Enter 4 to multiply\n";
	std::cin >> var;
	std::cout << "Enter first integer operand\n";
	std::cin >> a1;
	std::cout << "Enter second operand\n";
	std::cin >> a2;
	query.getAdditionInputBody()->getAdditionInput()->setOperator(var);
	query.getAdditionInputBody()->getAdditionInput()->setA1(a1);
	query.getAdditionInputBody()->getAdditionInput()->setA2(a2);
	
	JausAddress server(jausRouter->getJausAddress()->getSubsystemID(),jausRouter->getJausAddress()->getNodeID(),150);
	sendJausMessage(query,server);
	std::cout << "Send addition request\n";
 // } while (var != 5);

}

void AdditionClientServiceDef_additionClientFSM::serviceStartedAction()
{
	/// Insert User Code HERE
	std::cout << "Calculation client started\n";

	ieHandler->invoke(new InitToReadyEventDef());
	std::cout << "Sent internal event to transition to Ready\n";
}





};

#include "CppPractice/headers/Topics.h"

//include this to study pointers to other classes
#include "CppPractice/headers/StudyConst.h"
#include "CppPractice/headers/StudyPointers.h"

Topics::Topics(){}

void Topics::topicPointers(){

	int inputMax = 2;
	int input = inputMax;
	enum subTopic { pointers = 0, references };
	std::cout << "What topic of const do you want to see ?\n"
				 "0 = pointers,\n"
				 "1 = references" << std::endl;
	std::cin >> input;

	StudyPointers obj;

	if(std::cin.good() && input < inputMax){
		switch(input)
		{
			case pointers:
				obj.printPointersCode();
				obj.pointers();			
			break;
			case references:
				obj.printReferencesCode();
				obj.references();
			break;
			default:
				std::cout << "Code will never get here :)" << std::endl;
		}
	}else {
		std::cout << "Invalid input" << std::endl;	
	}
}

void Topics::topicConstant(){

	int inputMax = 2;
	int input = inputMax;
	enum subTopic { constAddress, constContents };
	std::cout << "What topic of const do you want to see ?\n"
				 "0 = constAddress,\n"
				 "1 = constContents" << std::endl;
	std::cin >> input;

	StudyConst obj;

	if(std::cin.good() && input < inputMax){
		switch(input)
		{
			case constAddress:
				obj.printConstAddressCode();
				obj.constAddress();			
			break;
			case constContents:
				obj.printConstContentsCode();
				obj.constContents();
			break;
			default:
				std::cout << "Code will never get here :)" << std::endl;
		}
	}else {
		std::cout << "Invalid input" << std::endl;	
	}
}

Topics::~Topics(){}
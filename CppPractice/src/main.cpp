
#include "CppPractice/headers/StudyConst.h"
#include "CppPractice/headers/StudyPointers.h"
#include "CppPractice/headers/Topics.h"

using namespace std;
#include <exception>
#include <iostream>

bool promptForTopic();

int main() {
	promptForTopic();
}

bool promptForTopic(){

	Topics studyTopic;

	enum topic { constTopic = 0, pointersTopic, noTopic };
	int input = 1;
	int inputMax = 2;

	// Prompt for topic
	std::cout << "Enter topic #: 0 = const, 1 = pointers, 2 = none" << std::endl;
	std::cin >> input;

	// valid input recieved
	if(std::cin.good() && input < inputMax){
		switch(input)
		{
			case constTopic:
				studyTopic.topicConstant();
			case pointersTopic:
				studyTopic.topicPointers();
			break;
			default:
				std::cout << "Code will never get here :)" << std::endl;
		}
	} else {
			std::cout << "Invalid input" << std::endl;
			return false;
	}

	return true;
}

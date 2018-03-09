#include "CppPractice/headers/StudyPointers.h"

//include this to study pointers to other classes
#include "CppPractice/headers/StudyConst.h"

StudyPointers::StudyPointers(){};

void StudyPointers::pointers(){

	StudyConst* constObj = new StudyConst();
	constObj->constAddress();

}

void StudyPointers::printPointersCode(){
	std::cout << "\n**************** printPointersCode ****************" << std::endl;
	std::cout << "\n";
	std::cout << "\n**************** printPointersCode ****************" << std::endl;
}

void StudyPointers::references(){

}

void StudyPointers::printReferencesCode(){
	std::cout << "\n**************** printReferencesCode ****************" << std::endl;
	std::cout << "\n";
	std::cout << "\n**************** printReferencesCode ****************" << std::endl;
}

StudyPointers::~StudyPointers(){};

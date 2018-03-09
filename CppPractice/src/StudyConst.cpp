#include "CppPractice/headers/StudyConst.h"


StudyConst::StudyConst(){

}

void StudyConst::constAddress(){

	int varConst = 9;
	// We are making the address cont here by puting the const to the right
	int *const p1  = &varConst;
	printf("constAddressOutPut: Adress = %p, Contents = %d\n", p1, *p1);

	/****************output******************/
	// Adress = 0x7fff5ee1c61c, Contents = 9
	/****************output******************/

	/***************************************************************
	* since the const was after the * we cannot change the address
	* we can't compile the following code
	***************************************************************/

	//error: read-only variable is not assignable
	//   -->   p1++; // we recieve an error for trying to change the address
	//printf("Adress = %p, Contents = %d\n", p1, *p1);
}

void StudyConst::printConstAddressCode(){
	std::cout << "\n**************** printConstAddressCode ****************" << std::endl;
	std::cout << "\n"
	"int varConst = 9; \n"
	"int *const p1 = &varConst; \n"
	"printf(\"Adress = %p, Contents = %d\", p1, *p1); \n" << std::endl;
	std::cout << "\n**************** printConstAddressCode ****************" << std::endl;
}

void StudyConst::constContents(){
	/*
	*	here we are declaring a const int and giving it's address to a pointer
	* 	note: we can only feed *p1 a constant i.e varConst, otherwise the compiler complains
	*/

	const int varConst = 9;
	// varConst = 6;  --> this will fail duriing compile time
	// however we can save the address in a pointer
	const int *p1 = &varConst;

	// The data in p1 is constant, but we can still move the address

	printf("constContentsOutput: Adress = %p, Contents = %d\n", p1, *p1);
	// The contents in the address are const but not the address itself
	p1++; // we were able to move the pointers address here
	printf("constContentsOutput: Adress = %p, Contents = %d\n", p1, *p1);

	// When the const is to the left of the pointer we cannot change the contents
	//*p1 = 7;  // <-- this makes the compiler complain	

	/*
	 * 	output
	 *	Adress = 0x7fff5bf8063c, Contents = 9
	 *	Adress = 0x7fff5bf80640, Contents = 1542981200
	 */
}

void StudyConst::printConstContentsCode(){
	std::cout << "\n**************** printConstContentsCode ****************" << std::endl;
	std::cout << "\n"
	"const int varConst = 9; \n"
	"const int *p1 = &varConst; \n"
	"printf(\"Adress = %p, Contents = %d\", p1, *p1); \n"
	"p1++;\n"
	"printf(\"Adress = %p, Contents = %d\", p1, *p1); \n" << std::endl;
	std::cout << "\n**************** printConstContentsCode ****************" << std::endl;
}

StudyConst::~StudyConst(){

}
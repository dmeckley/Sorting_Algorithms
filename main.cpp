/*****************************************************
*	main.cpp
*
*	Dustin Meckley
*	ciss350
*	7/09/15
*****************************************************/
#include <iostream>

#include "Sort.h"

/*****************************************************
*	main()
*
*	Test Driver for execution of program.
*/
int main()
{
	try
	{
		Sort s;	
	}
	catch(Sort::ChoiceException e)
	{
		e.message();
	}
	catch(Sort::OutOfBoundsException e)
	{
		e.message();
	}

	return 0;
}
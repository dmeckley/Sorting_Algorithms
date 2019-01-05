/*****************************************************
*	Sort.h
*
*	Dustin Meckley
*	ciss350
*	7/09/15
*****************************************************/
#ifndef SORT_H_
#define SORT_H_

#include <iostream>
#include <cstddef>

class Sort
{
	// -----------------------------------------------------
	//                         Class Methods: 
	// -----------------------------------------------------
public:
	// Exception Handler Class:
	class ChoiceException
	{
	public: 
		void message()
		{
			std::cerr << "User Choice Input Exception Thrown! " 
			<< std::endl << std::endl;
		}
	};

	class OutOfBoundsException
	{
	public: 
		void message()
		{
			std::cerr << "Out of Bounds Exception Thrown! " 
			<< std::endl << std::endl;
		}
	};
	
	// Constructor and Destructors:
	Sort();
	~Sort();

	// mergeSort Sort Class Object Function Methods:
	void merge(int[], int, int, int);
	void mergeSort(int[], int, int);

	// quickSort Sort Class Object Function Methods:
	void quickSort(int[], int , int);
	int pivot(int[], int , int);
	void swap(int&, int&);

	// quickMergeSort Sort Class Object Function Methods:
	void quickMergeSort(int[], int , int, int);

	// miscellanous Sort Class Object Function Methods:
	void printList(int[], const int) const;
	void displayMenu() const;
	void setChoice();
	int getChoice() const;
	void selectOp(int[]);

	// ----------------------------------------------------
	//                         Class Members:
	// ----------------------------------------------------
private:
	int choice;
	const static int SIZE = 10;
	const static int MAX_SIZE = SIZE - 1;
	const static int CUTOFF = 5;
};

#endif
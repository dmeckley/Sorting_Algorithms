/*****************************************************
*	Sort.cpp
*
*	Dustin Meckley
*	ciss350
*	7/09/15
*****************************************************/
#ifndef SORT_CPP_
#define SORT_CPP_

#include "Sort.h"

/*****************************************************
*	Sort()  
*
*	Constructor for Sort class.
*/
Sort::Sort() 
{
	int test[] = {7, 4, 2, 5, 25, 0, -3, 9, 45, -69};
	displayMenu();
	setChoice();
	selectOp(test);
}

/*****************************************************
*	~Sort()
*
*	Destructor for Sort class. 
*/
Sort::~Sort()
{

}

/*****************************************************
*	merge()
*
*	merge for Sort class. 
*/
void Sort::merge(int list[], int first, int last, int middle)
{
	// The merge function is utilized by the mergeSort function 
	// in order to merge the two sorted halves of the array based
	// list back into one array based list.

	// Pointers to indicate the current position of the left half
	// and the right half of the array based list.
	int* leftArray = NULL;
	int* rightArray = NULL;

	// Counter Indexes:
	int i = 0;			// Left Sublist Index.
	int j = 0;			// Right Sublist Index.
	int k = 0;			// List Index. 

	// Determining the range of the two halves of the array based list:
	int firstHalf = middle - first + 1;
	int secondHalf = last - middle;

	// Allocating memory necessary for the new two half arrays:
	leftArray = new int[firstHalf];
	rightArray = new int[secondHalf];

	// Create the two half sublists of the array based list.
	for(i = 0; i < firstHalf; i++)
	{
		leftArray[i] = list[first + i];
	}
	for(j -= 0; j < secondHalf; j++)
	{
		rightArray[j] = list[middle + 1 + j];
	}

	// Resetting the counter Indexes:
	i = 0;				// Left Sublist Index.
	j = 0;				// Right Sublist Index.
	k = first;			// List Index. 

	// While there are still more items in the left half
	// and right half of the array based list halves then:
	while(i < firstHalf && j < secondHalf)
	{
		// Set list[k] to leftArray[i]
		if(leftArray[i] <= rightArray[j])
		{
			list[k] = leftArray[i];
			i++;
		}
		// Set list[k] to leftArray[j]
		else
		{
			list[k] = rightArray[j];
			j++;
		}
		// Increment index.
		k++;
	}

	// Copies remaining elements from the left half 
	// of the array based list half.
	while(i < firstHalf)
	{
		list[k] = leftArray[i];
		i++;
		k++;
	}

	// Copies remaining elements from the right half 
	// of the array based list half.
	while(j < secondHalf)
	{
		list[k] = rightArray[j];
		j++;
		k++;
	}

	// Deallocating memory for the two halfs of allocated arrays:
	delete [] leftArray;
	delete [] rightArray;
}

/*****************************************************
*	mergeSort()
*
*	mergeSort for Sort class. 
*/
void Sort::mergeSort(int list[], int first, int last)
{
	// The mergeSort function splits the original array
	// based list into two half array based lists, then
	// it sorts the first half of the array based list and 
	// then it sorts the last half of the array based list. 
	int middle;
	if (last > first)
	{
		middle = (first + last) / 2;
		mergeSort(list, first, middle);
		mergeSort(list, middle + 1, last);
		merge(list, first, last, middle);
	}
}

/*****************************************************
*	quickSort()
*
*	quickSort for Sort class. 
*/
void Sort::quickSort(int list[], int first, int last)
{
	// Sorts the array based list recursively by dividing 
	// the list into two different sublists utilizing a 
	// pivot for the division of the two sublist.
	int pivotElement;

	if(first < last)
	{
		pivotElement = pivot(list, first, last);
		quickSort(list, first, pivotElement - 1);
		quickSort(list, pivotElement + 1, last);
	}
}

/*****************************************************
*	pivot()
*
*	pivot for Sort class. 
*/
int Sort::pivot(int list[], int first, int last)
{
	// Determines the element of the pivot as well as
	// rearranges the values within the array based list. 
	int pivot = first;
	int pivotElement = list[first];

	for(int index = first + 1; index <= last; index++)
	{
		if(list[index] <= pivotElement)
		{
			pivot++;
			swap(list[index], list[pivot]);
		}
	}
	swap(list[pivot], list[first]);

	return pivot;
}

/*****************************************************
*	swap()
*
*	swap for Sort class. 
*/
void Sort::swap(int& temp1, int& temp2)
{
	// swaps the order of values found in any two 
	// elements of the array based list.
	int temp = temp1;
	temp1 = temp2;
	temp2 = temp;
}

/*****************************************************
*	quickMergeSort()
*
*	quickMergeSort for Sort class. 
*/
void Sort::quickMergeSort(int list[], int first, int last, int CUTOFF)
{
	// This functon performs a mergeSort on the upper half of the 
	// overall list sorting the element values and then it finishes 
	// the sorting process off with the quickSort.
	if ((last - first) >= CUTOFF)
		mergeSort(list, CUTOFF, last);
	quickSort(list, first, last);
}

/*****************************************************
*	displayMenu()
*
*	displayMenu for Sort class. 
*/
void Sort::displayMenu() const
{
	// Displays a user choice menu for input selection.
	std::cout << std::endl << "Users Choices:" << std::endl;
	for(int i = 0; i < SIZE + 4; i++)
		std::cout << '-';
	std::cout << std::endl;
	std::cout << "1 for mergeSort" << std::endl;
	std::cout << "2 for quickSort" << std::endl;
	std::cout << "3 for quickMergeSort" << std::endl << std::endl;
}

/*****************************************************
*	setChoice()
*
*	setChoice for Sort class. 
*/
void Sort::setChoice()
{
	// Sets the choice based off of what the user selects.
	// Throws an exception, if the user inserts a invalid input.
	int choice = 0;
	std::cout << "Please enter the users choice: ";
	std::cin >> choice;
	if(choice != 1 && choice != 2 && choice != 3)
		throw ChoiceException();	
	else
		this->choice = choice;
}

/*****************************************************
*	getChoice()
*
*	getChoice for Sort class. 
*/
int Sort::getChoice() const
{
	// Returns the value of the choice that the user entered.
	return this->choice;
}

/*****************************************************
*	selectOp()
*
*	selectOp for Sort class. 
*/
void Sort::selectOp(int list[]) 
{
	// If the user enters 1, then it executes the mergeSort program
	// to sort the array based list. Else if the user enters 2, then
	// it executes the quickSort program to sort the array based list.
	// Else if the user enters 3, then it executes the quickMergeSort 
	// program to sort the array based list. Else if the user enters 
	// any other value, then it throws an exception error for double
	// redundancy.
	if(getChoice() == 1)
	{

		// mergeSort:
		std::cout << std::endl;
		std::cout << "Before sorting: " << std::endl;
		printList(list, SIZE);
		std::cout << std::endl;

		mergeSort(list, 0, MAX_SIZE);

		std::cout << "After sorting: " << std::endl;
		printList(list, SIZE);
		std::cout << std::endl;
	}
	else if(getChoice() == 2)
	{
		// quickSort:
		std::cout << std::endl;
		std::cout << "Before sorting: " << std::endl;
		printList(list, SIZE);
		std::cout << std::endl;

		quickSort(list, 0, MAX_SIZE);

		std::cout << "After sorting: " << std::endl;
		printList(list, SIZE);
		std::cout << std::endl;
	}
	else if(getChoice() == 3)
	{
		// quickMergeSort:
		std::cout << std::endl;
		std::cout << "Before sorting: " << std::endl;
		printList(list, SIZE);
		std::cout << std::endl;

		quickMergeSort(list, 0, MAX_SIZE, CUTOFF); 

		std::cout << "After sorting: " << std::endl;
		printList(list, SIZE);
		std::cout << std::endl;	
	}
	else
	{
		throw ChoiceException();
	}
}

/*****************************************************
*	printList()
*
*	printList for Sort class. 
*/
void Sort::printList(int list[], const int SIZE) const
{
	for(int i = 0; i < SIZE; i++)
	{
		if(i > MAX_SIZE)
			throw OutOfBoundsException();
		else
			std::cout << list[i] << std::endl;
	}
}

#endif
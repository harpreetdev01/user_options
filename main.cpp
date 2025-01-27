/*
	Objective:

	Use a list of integers and allow the user to select an
	option from a menu to perform an operation from the list

	Program should display a menu option from the following:

	P - Print numbers
	A - Add a number
	M - Display mean of the numbers
	S - Display the smallest number
	L - Display the largest number
	Q - Quit

	Enter your choice:

	The program should only accept valid choices from the user,
	both upper and lowercase selections should be allowed.
	If an illegal choice is made, you should display,
	"Unknown selection, please try again" and the menu options should be
	displayed again.

	If the user enters "P" or 'p', you should display alll of the elements(ints) in the list.
	If the list is empty you should display "[] - the list is empty"
	If the list is not empty then all the list element should displayed inside
	square brackets seperated by a space.
	For example, [ 1 2 3 4 5 ]

	If the user enters 'A' or 'a' then you should prompt the user for an integer to add to the list
	which you will add to the list and then display it was added. For example, if the user enters 5
	You should display, "5 added".
	Duplicate list enteries are OK

	If the user enters "M" or 'm' you should calculate the mean or average of
	the elements in the list and display it.
	If the list is empty you should display, "Unable to calculate the mean - no data"

	If the user enters "S" or 's' you should display the smallest element in the list.
	For example, if the list contains[2 4 5 1], you should display, "The smallest number is 1"
	If the list is empty you should display, "Unable to determine the smallest number - list is empty"

	If the user enters "L" or 'l' you should display the largest element in the list
	For example, if the list contains [2 4 5 1], you should display, "The largest number is 5"
	If the list is empty you should display, "Unable to determine the largest number - list is empty"

	If the user enters 'Q' or 'q' then you should display "Goodbye" and the
	program should terminate.

	Tip: write steps and which order to do this
*/



#include <iostream>
#include <string>
#include <vector>
#include <cctype>

using namespace std;

/*
	Steps:
	1. create a list of integers
	2. Menu - establish menu options and how to perform
	   a: create a char array with menu options
	   b: have user pick an option
	   c: loop through and check which option the user has picked and perform a task - use a while loop because 'q' needs to end the loop only - done
	   d: check if user sent the right char if not then provide an error message and prompt user again: 
	      - for loop and check - for loop did not work, switch statement works better

	3. Print out all elements in from the integers_data array
	   - loop through the array using a for loop and print out each element onto the console: [ 1 2 3 4 ]
	4. Largest number:
		- loop through the integers data vector
		- 
	
*/ 

vector<int> integers_data = { 1, 20, 3, 40, 5 , -9};

char user_prompt();
void menu_options();
void print_numbers();
void add_integer_to_list();
void calculate_mean();
void largest_number();
void smallest_number();
void invalid_entry();

int main()
{
	menu_options();

	return 0;
};

void menu_options()
{
	char user_choice = user_prompt();

	switch (user_choice)
	{
	case 'P':
	{
		print_numbers();
		break;
	}
	case 'A':
	{
		add_integer_to_list();
		break;
	}
	case 'M':
	{
		calculate_mean();
		break;
	}
	case 'L':
	{
		largest_number();
		break;
	}
	case 'S' :
	{
		smallest_number();
		break;
	}
	case 'Q':
	{
		cout << "Thank you, program will now be terminated. " << endl;
		break;
	}
	default:
		cout << "No, " << user_choice << "is not in the list" << endl;
		// TODO: 
		// 1. prompt user again
		// 2. give user 3 chances max - if 3 failed attempts then terminate the program
		invalid_entry(); //TODO: issue here, can't enter back into the menu options when 1 or more wrong entry made
		break;
	}
};
char user_prompt()
{
	cout << "Menu options: " << endl;
	cout << "\nP - Print numbers" << endl;
	cout << "A - Add a number" << endl;
	cout << "M - Display mean of numbers" << endl;
	cout << "S - Display the smallest number" << endl;
	cout << "L - Display the largest number" << endl;
	cout << "Q - Quit the program" << endl;

	char user_choice;
	cin >> user_choice;

	char user_choice_captialized = toupper(user_choice);

	return user_choice_captialized;
}
void print_numbers()
{
	string print_data{ "[ " };

	for (int i = 0; i < integers_data.size(); i++)
	{
		print_data += to_string(integers_data[i]) + " ";
	}
	print_data += " ]";

	cout << print_data;
};
void add_integer_to_list()
{
	cout << "Please add an integer to the list: " << endl;

	size_t initial_vector_size = integers_data.size();

	int integer_to_add{ 0 };
	cin >> integer_to_add;

	integers_data.push_back(integer_to_add);

	if (integers_data.size() > initial_vector_size)
	{
		cout << integer_to_add << " added";
		cout << "\nHere are the values in the vector: " << endl;

		for (int i = 0; i < integers_data.size(); i++)
		{
			cout << integers_data[i] << ", ";
		}
	}
	else
	{
		cout << "Your number was not added";
	}
};
void calculate_mean()
{
	int sum{ 0 };
	double average{ 0.0 };

	size_t integers_data_size = integers_data.size();

	for (int i = 0; i < integers_data.size(); i++) // ask
	{
		sum += integers_data[i];
	};

	average = static_cast<double>(sum) / integers_data.size();

	cout << "The average is: " << average;
};
void largest_number()
{
	int largest{ integers_data[0]};

	for (int i = 0; i < integers_data.size(); i++)
	{
		if (largest < integers_data[i])
		{
			largest = integers_data[i];
		}
	}

	cout << "largest number: " << largest;
};
void smallest_number() {

	int min_number{integers_data[0]};

	for (int i = 0; i < integers_data.size(); i++)
	{
		if (min_number > integers_data[i])
		{
			min_number = integers_data[i];
		}
	};

	cout << "The smallest number is: " << min_number << endl;
};
void invalid_entry()
{
	int error_count{ 0 };

	while (error_count < 3)
	{
		cout << error_count << ", error" << endl;

		char user_value = user_prompt();

		error_count++;

	};

	cout << "You have exceeded the amount of wrong entries, program will not terminate";
	
	return;
}

#include "MyExeption.h"

MyExeption::MyExeption(int c_state) : state(c_state) {}

const char* MyExeption::get_messag_of_error(int m_state) const
{
	switch (m_state)
	{
	case 1:
		return "Lenght of array cannot be less 0";
	case 2:
		return "You are trying to look at an element outside the array";
	case 3:
		return "Reducing the length of the array can lead to data loss";
	case 4:
		return "The value of the array index cannot be negative";
	case 5:
		return "You are trying to delete an element outside the array";
	}

}
int MyExeption::get_code_of_state()
{
	return state;
}

const char* MyExeption::what() const noexcept 
{
	return  this->get_messag_of_error(state);
}
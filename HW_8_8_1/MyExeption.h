#pragma once
#include <exception>


class MyExeption : public std::exception
{
private:
	int state;

public:
	MyExeption(int c_state);

	const char* get_messag_of_error(int m_state) const;

	int get_code_of_state();

	const char* what() const noexcept override;
};





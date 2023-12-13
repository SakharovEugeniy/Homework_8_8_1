#include "IntegerArray.h"


int main()
{
	try
	{
		//MyArray empty_arr();
		MyArray<double> arr_1(4);
		arr_1.show();
		//MyArray<double> arr_wrong_constructor(-4);
		arr_1.set_data(3, 30);
		arr_1.show();
		MyArray<double> arr_constructor_copy(arr_1);
		arr_constructor_copy.show();
		MyArray<double> arr_assignment_operator = arr_1;
		arr_assignment_operator.show();
		std::cout << arr_1.get_data(3) << '\n';
		//std::cout << arr_1.get_data(-1) << '\n';
		//std::cout << arr_1.get_data(4) << '\n';
		//arr_1.resize(-1);
		//arr_1.resize(3);
		arr_1.resize(4);               
		arr_1.show();
		arr_1.resize(6);
		arr_1.show();
		//arr_1.set_data(-1, 40);
		arr_1.set_data(7, 77);
		arr_1.show();
		arr_1.add_data(7, 70);
		arr_1.show();
		//arr_1.add_data(-100, 70);
		arr_1.add_data(12, 122);
		arr_1.show();
		arr_1.del_data(7);
		arr_1.show();
		std::cout << arr_1.has_an_element(77) << '\n';
		std::cout << arr_1.has_an_element(777) << '\n';
	}

	catch (MyExeption e)
	{
		std::cout << "MyExeption catch with code " << e.get_code_of_state() << std::endl;
		std::cout << e.what() << std::endl;
	}
	return 0;
}
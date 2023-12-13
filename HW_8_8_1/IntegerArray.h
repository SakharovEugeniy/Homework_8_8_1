#pragma once
#include <iostream>
#include <typeinfo>
#include "MyExeption.h"


template <class T>
class MyArray 
{
private:
	int length;
	T* data;

public:
	/*MyArray()
	{
		length = 0;
		data = new T[0];
	}*/

	MyArray(int lenght)
	{
		{
			if (lenght < 0)
			{
				throw MyExeption(1);
			}

			this->length = lenght;
			data = new T[length] {};
		}
	}

	MyArray(const MyArray& other)
	{

		if (other.length < 0)
		{
			throw MyExeption(1);
		}
		length = other.length;
		data = new T[length];

		for (int i = 0; i < length; i++)
		{
			data[i] = other.data[i];
		}
	}

	~MyArray()
	{
		if (data)
			delete[] data;
	}

	MyArray& operator=(const MyArray& other)
	{
		if (&other != this)
		{
			if (other.length < 0)
			{
				throw MyExeption(1);
			}
			length = other.length;
			data = new T[length];

			for (int i = 0; i < length; i++)
			{
				data[i] = other.data[i];
			}
		}
		return *this;
	}

	int get_data(int index)
	{
		if (0 > index || index >= length)
		{
			throw MyExeption(2);
		}
		return data[index];
	}

	void resize(int lenght_tmp)
	{
		if (lenght_tmp < 0)
		{
			throw MyExeption(1);
		}
		else if (lenght_tmp < this->length)
		{
			throw MyExeption(3);
		}
		else if (lenght_tmp == this->length)
		{
			return;
		}

		MyArray<T> tmp_array(lenght_tmp);       
		for (int i = 0; i < length; i++)
		{
			tmp_array.data[i] = data[i];
		}
		length = lenght_tmp;
		delete[] data;
		data = tmp_array.data;
		tmp_array.data = nullptr;
	}

	void set_data(int index, T value)
	{
		if (index < 0)
		{
			throw MyExeption(4);
		}

		else if (0 <= index && index < length)
		{
			data[index] = value;
		}

		else
		{
			resize(index + index / 2);
			data[index] = value;
		}
	}

	void add_data(int index, T value)
	{
		if (index < 0)
		{
			throw MyExeption(4);
		}

		if (index >= length)
		{
			set_data(index, value);
			return;
		}

		MyArray<T> tmp_array(this->length + 1);

		for (int i = 0; i < index; i++)
		{
			tmp_array.data[i] = data[i];
		}

		tmp_array.data[index] = value;

		for (int i = index + 1; i < tmp_array.length; i++)
		{
			tmp_array.data[i] = data[i - 1];
		}

		length = tmp_array.length;
		delete[] data;
		data = tmp_array.data;
		tmp_array.data = nullptr;
	}

	void del_data(int index)
	{
		if (index < 0)
		{
			throw MyExeption(4);
		}

		if (index >= length)
		{
			throw MyExeption(5);
		}

		MyArray tmp_array(this->length - 1);

		for (int i = 0; i < index; i++)
		{
			tmp_array.data[i] = data[i];
		}

		for (int i = index; i < tmp_array.length; i++)
		{
			tmp_array.data[i] = data[i + 1];
		}

		length = tmp_array.length;
		delete[] data;
		data = tmp_array.data;
		tmp_array.data = nullptr;
	}

	bool has_an_element(T element)
	{
		for (int i = 0; i < length; i++)
		{
			if (data[i] == element)
			{
				std::cout << "Index of element " << element << " is " << i << '\n';
				return true;
			}
		}
		std::cout << "The element " << element << " not found" << '\n';
		return false;
	}

	void show()
	{
		for (int i = 0; i < length; i++)
		{
			std::cout << data[i] << '\t';
		}
		std::cout << '\n';
	}
};


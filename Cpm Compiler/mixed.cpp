#include "mixed.h"

mixed::mixed(long long data)
{
	this->data = new int_mixed(data);
}

mixed::mixed(double data)
{
	this->data = new float_mixed(data);
}

mixed::mixed(const std::string& data)
{
	this->data = new string_mixed(data);
}

mixed mixed::copy()
{
	return mixed(data->copy());
}

mixed mixed::operator+() const
{
	return mixed(data->operator+()->copy());
}

mixed mixed::operator+(const mixed& right_mixed) const
{
	return mixed(*(data->operator+()) + right_mixed.data->operator+());
}

mixed mixed::operator-() const
{
	return mixed(data->operator-()->copy());
}

mixed mixed::operator-(const mixed& right_mixed) const
{
	return mixed(*(data->operator+()) - right_mixed.data->operator+());
}

void mixed::operator=(const mixed& right_mixed)
{
	delete(data);
	data = right_mixed.data->copy();
}

mixed::~mixed(){
	delete(data);
}

int_mixed* int_mixed::operator+() const
{
	return new int_mixed(this->get_data());
}

virtual_mixed* int_mixed::operator+(const virtual_mixed* right_mixed) const
{
	return *this + right_mixed->operator+();
}

virtual_mixed* int_mixed::operator+(const int_mixed& right_mixed) const
{
	return new int_mixed(this->get_data() + right_mixed.get_data());
}

virtual_mixed* int_mixed::operator+(const float_mixed& right_mixed) const
{
	return new float_mixed(this->get_data() + right_mixed.get_data());
}

virtual_mixed* int_mixed::operator+(const string_mixed& right_mixed) const
{
	return new string_mixed(std::to_string(this->get_data()) + right_mixed.get_data());
}

int_mixed* int_mixed::operator-() const
{
	return new int_mixed(-this->get_data());
}

virtual_mixed* int_mixed::operator-(const virtual_mixed* right_mixed) const
{
	return *(this) + right_mixed->operator-();
}

virtual_mixed* int_mixed::operator-(const int_mixed& right_mixed) const
{
	return new int_mixed(this->get_data() - right_mixed.get_data());
}

virtual_mixed* int_mixed::operator-(const float_mixed& right_mixed) const
{
	return new float_mixed(this->get_data() - right_mixed.get_data());
}

virtual_mixed* int_mixed::operator-(const string_mixed& right_mixed) const
{
	try {
		return new int_mixed(this->get_data() - std::stoll(right_mixed.get_data()));
	}
	catch (std::exception) {
		try {
			return new int_mixed(this->get_data() - std::stod(right_mixed.get_data()));
		}
		catch(std::exception) {
		}
	}
	return new int_mixed(this->get_data());
}

long long int_mixed::get_data() const
{
	return data;
}

virtual_mixed* int_mixed::copy()
{
	return new int_mixed(this->get_data());
}


float_mixed* float_mixed::operator+() const
{
	return new float_mixed(this->get_data());
}

virtual_mixed* float_mixed::operator+(const virtual_mixed* right_mixed) const
{
	return *(this) + right_mixed->operator+();
}

virtual_mixed* float_mixed::operator+(const int_mixed& right_mixed) const
{
	return new float_mixed(this->get_data() + right_mixed.get_data());
}

virtual_mixed* float_mixed::operator+(const float_mixed& right_mixed) const
{
	return new float_mixed(this->get_data() + right_mixed.get_data());
}

virtual_mixed* float_mixed::operator+(const string_mixed& right_mixed) const
{
	return new string_mixed(std::to_string(this->get_data()) + right_mixed.get_data());
}

float_mixed* float_mixed::operator-() const
{
	return new float_mixed(-this->get_data());
}

virtual_mixed* float_mixed::operator-(const virtual_mixed* right_mixed) const
{
	return *(this) + right_mixed->operator-();
}

virtual_mixed* float_mixed::operator-(const int_mixed& right_mixed) const
{
	return new float_mixed(this->get_data() - right_mixed.get_data());
}

virtual_mixed* float_mixed::operator-(const float_mixed& right_mixed) const
{
	return new float_mixed(this->get_data() - right_mixed.get_data());
}

virtual_mixed* float_mixed::operator-(const string_mixed& right_mixed) const
{
	try {
		return new float_mixed(this->get_data() - std::stoll(right_mixed.get_data()));
	}
	catch (std::exception) {
		try {
			return new float_mixed(this->get_data() - std::stod(right_mixed.get_data()));
		}
		catch (std::exception) {
		}
	}
	return new int_mixed(this->get_data());
}

double float_mixed::get_data() const
{
	return data;
}

virtual_mixed* float_mixed::copy()
{
	return new float_mixed(this->get_data());
}

string_mixed* string_mixed::operator+() const
{
	return new string_mixed(this->get_data());
}

virtual_mixed* string_mixed::operator+(const virtual_mixed* right_mixed) const
{
	return *(this) + right_mixed->operator+();
}

virtual_mixed* string_mixed::operator+(const int_mixed& right_mixed) const
{
	return new string_mixed(this->get_data() + std::to_string(right_mixed.get_data()));
}

virtual_mixed* string_mixed::operator+(const float_mixed& right_mixed) const
{
	return new string_mixed(this->get_data() + std::to_string(right_mixed.get_data()));
}

virtual_mixed* string_mixed::operator+(const string_mixed& right_mixed) const
{
	return new string_mixed(this->get_data() + right_mixed.get_data());
}

float_mixed* string_mixed::operator-() const
{
	try {
		return new float_mixed(-std::stod(this->get_data()));
	}
	catch (std::exception) {
	}
	return new float_mixed(0.0);
}

virtual_mixed* string_mixed::operator-(const virtual_mixed* right_mixed) const
{
	return *(this) + right_mixed->operator-();
}

virtual_mixed* string_mixed::operator-(const int_mixed& right_mixed) const
{
	try {
		return new int_mixed(std::stoll(this->get_data()) - right_mixed.get_data());
	}
	catch (std::exception) {
		try {
			return new float_mixed(std::stod(this->get_data()) - right_mixed.get_data());
		}
		catch (std::exception) {
		}
	}
	return new int_mixed(-right_mixed.get_data());
}

virtual_mixed* string_mixed::operator-(const float_mixed& right_mixed) const
{
	try {
		return new float_mixed(std::stoll(this->get_data()) - right_mixed.get_data());
	}
	catch (std::exception) {
		try {
			return new float_mixed(std::stod(this->get_data()) - right_mixed.get_data());
		}
		catch (std::exception) {
		}
	}
	return new float_mixed(-right_mixed.get_data());
}

virtual_mixed* string_mixed::operator-(const string_mixed& right_mixed) const
{
	try {
		return new int_mixed(std::stoll(this->get_data()) - std::stoll(right_mixed.get_data()));
	}
	catch (std::exception) {
		try {
			return new float_mixed(std::stoll(this->get_data()) - std::stod(right_mixed.get_data()));
		}
		catch (std::exception) {
			try {
				return new float_mixed(std::stod(this->get_data()) - std::stoll (right_mixed.get_data()));
			}
			catch (std::exception) {
				try {
					return new float_mixed(std::stod(this->get_data()) - std::stod(right_mixed.get_data()));
				}
				catch (std::exception) {
				}
			}
		}
	}
	return new int_mixed(0);
}

std::string string_mixed::get_data() const
{
	return data;
}

virtual_mixed* string_mixed::copy()
{
	return new string_mixed(this->get_data());
}


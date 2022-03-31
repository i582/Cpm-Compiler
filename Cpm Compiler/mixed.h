#pragma once

#include <string>
#include <iostream>

class virtual_mixed;
class int_mixed;
class float_mixed;
class string_mixed;
class mixed;

class virtual_mixed {

public:
	virtual virtual_mixed* operator+ () const = 0;
	virtual virtual_mixed* operator+ (const virtual_mixed* right_mixed) const = 0;
	virtual virtual_mixed* operator+ (const int_mixed& right_mixed) const = 0;
	virtual virtual_mixed* operator+ (const float_mixed& right_mixed) const = 0;
	virtual virtual_mixed* operator+ (const string_mixed& right_mixed) const = 0;

	virtual virtual_mixed* operator- () const = 0;
	virtual virtual_mixed* operator- (const virtual_mixed* right_mixed) const = 0;
	virtual virtual_mixed* operator- (const int_mixed& right_mixed) const = 0;
	virtual virtual_mixed* operator- (const float_mixed& right_mixed) const = 0;
	virtual virtual_mixed* operator- (const string_mixed& right_mixed) const = 0;
	virtual std::ostream& operator<< (std::ostream& out) const = 0;

	virtual virtual_mixed* copy() const = 0;

};

class int_mixed : public virtual_mixed {
protected:
	long long data;

public:
	int_mixed(long long data) : data(data) {}

	int_mixed* operator+ () const override;
	virtual_mixed* operator+ (const virtual_mixed* right_mixed) const override;
	virtual_mixed* operator+ (const int_mixed& right_mixed) const override;
	virtual_mixed* operator+ (const float_mixed& right_mixed) const override;
	virtual_mixed* operator+ (const string_mixed& right_mixed) const override;

	int_mixed* operator- () const override;
	virtual_mixed* operator- (const virtual_mixed* right_mixed) const override;
	virtual_mixed* operator- (const int_mixed& right_mixed) const override;
	virtual_mixed* operator- (const float_mixed& right_mixed) const override;
	virtual_mixed* operator- (const string_mixed& right_mixed) const override;

	std::ostream& operator<< (std::ostream& out) const override;

	long long get_data() const;

	virtual_mixed* copy() const override;

};

class float_mixed : public virtual_mixed {
protected:
	double data;

public:
	float_mixed(double data) : data(data) {}

	float_mixed* operator+ () const override;
	virtual_mixed* operator+ (const virtual_mixed* right_mixed) const override;
	virtual_mixed* operator+ (const int_mixed& right_mixed) const override;
	virtual_mixed* operator+ (const float_mixed& right_mixed) const override;
	virtual_mixed* operator+ (const string_mixed& right_mixed) const override;

	float_mixed* operator- () const override;
	virtual_mixed* operator- (const virtual_mixed* right_mixed) const override;
	virtual_mixed* operator- (const int_mixed& right_mixed) const override;
	virtual_mixed* operator- (const float_mixed& right_mixed) const override;
	virtual_mixed* operator- (const string_mixed& right_mixed) const override;

	std::ostream& operator<< (std::ostream& out) const override;

	double get_data() const;

	virtual_mixed* copy() const override;

};

class string_mixed : public virtual_mixed {
protected:
	std::string data;

public:
	string_mixed(const std::string& data) : data(data) {}

	string_mixed* operator+ () const override;
	virtual_mixed* operator+ (const virtual_mixed* right_mixed) const override;
	virtual_mixed* operator+ (const int_mixed& right_mixed) const override;
	virtual_mixed* operator+ (const float_mixed& right_mixed) const override;
	virtual_mixed* operator+ (const string_mixed& right_mixed) const override;

	float_mixed* operator- () const override;
	virtual_mixed* operator- (const virtual_mixed* right_mixed) const override;
	virtual_mixed* operator- (const int_mixed& right_mixed) const override;
	virtual_mixed* operator- (const float_mixed& right_mixed) const override;
	virtual_mixed* operator- (const string_mixed& right_mixed) const override;

	std::ostream& operator<< (std::ostream& out) const override;

	std::string get_data() const;

	virtual_mixed* copy() const override;
};

class mixed {

	virtual_mixed* data;

public:
	mixed() : data(nullptr) {}
	mixed(long long data);
	mixed(double data);
	mixed(const std::string& data);
	mixed(virtual_mixed* data) : data(data) {}

	mixed copy() const;

	mixed operator+ () const;
	mixed operator+ (const mixed& right_mixed) const;

	mixed operator- () const;
	mixed operator- (const mixed& right_mixed) const;

	void operator= (const mixed& right_mixed);

	std::ostream& operator<<(std::ostream& out) const;
	void operator>>(std::istream& in);

	friend std::ostream& operator<<(std::ostream& out, const mixed& mix);
	friend std::istream& operator>>(std::istream& in, mixed& mix);

	~mixed();
};
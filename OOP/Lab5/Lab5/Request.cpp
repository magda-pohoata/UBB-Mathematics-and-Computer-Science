#include "Request.h"


int Request::idGenerator = 0;


Request::Request(const Request& other)
{
	this->m_id = other.m_id;
	this->m_subject = new char[20];
	memcpy(this->m_subject, other.m_subject, strlen(other.m_subject) + 1);
	this->m_dueDate = other.m_dueDate;
	this->m_status = other.m_status;
	this->m_price = other.m_price;
}

Request& Request::operator=(const Request& other)
{
	if (this == &other)
	{
		return *this;
	}
	else
	{
		this->m_id = other.m_id;
		delete[] this->m_subject;
		this->m_subject = new char[20];
		memcpy(this->m_subject, other.m_subject,strlen(other.m_subject)+1);
		this->m_dueDate = other.m_dueDate;
		this->m_status = other.m_status;
		this->m_price = other.m_price;
		return *this;
	}
}

Request::~Request()
{
	delete[] this->m_subject;
}


ostream& operator<<(ostream& os, Date& d)
{
	os << d.day << "/" << d.month << "/" << d.year;
	os << endl;
	return os;
}

ostream& operator<<(ostream& os, const Request& r)
{
	os << r.m_id << " - " <<  r.m_subject << " - " << r.m_dueDate.day << "/" << r.m_dueDate.month << "/" << r.m_dueDate.year << " - " << r.m_status << " - " << r.m_price;
	os << endl;
	return os;
}

istream& operator>>(istream& is, Date& d)
{
	try
	{
		is >> d.day >> d.month >> d.year;
		if (d.day > 31)
			throw(d.day);
		if (d.month > 12)
			throw(d.month);
		if (d.year > 2022)
			throw(d.year);
	}
	catch(int date){
		cout << "Please type a valid date" << endl << endl;
	}
	return is;
}

istream& operator>>(istream& is, Request& r)
{
	is >> r.m_subject >> r.m_dueDate >> r.m_price;

	return is;
}

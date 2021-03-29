#include "OnlineLesson.h"



//daca pun const nu mi vede getId-ul :)
ostream& operator<<(ostream& os, OnlineLesson& o)
{
	os <<o.getId()<< " - " << o.m_subject << " - " << o.m_dueDate.day << "/" << o.m_dueDate.month << "/" << o.m_dueDate.year << " - " << o.m_status << " - " << o.m_price << " - " << o.m_time << " - " << o.m_url;
	os << endl;
	return os;
}


istream& operator>>(istream& is, OnlineLesson& o)
{
	is >> o.m_subject >> o.m_dueDate.day >> o.m_dueDate.month >> o.m_dueDate.year >> o.m_price >> o.m_time >> o.m_url;
	return is;
}
#include "Church.h"

string Church::getReligion() const
{
	return this->m_religion;
}

void Church::setReligion(string religion)
{
	this->m_religion = religion;
}

Style Church::getStyle() const
{
	return this->m_style;
}

void Church::setStyle(Style style)
{
	this->m_style = style;
}

void Church::display(ostream& os)
{
	os << "Church: ";
	ArchitecturalStructure::display(os);
	
	os <<" - "<< m_religion << " - " << m_style <<" ";

	os << " with the purpose(s): ";
	for (int i = 0; i < m_purpose.size(); i++)
	{
		os << m_purpose[i] << " ";
	}
}

istream& operator>>(istream& is, Church& c)
{
	int style;
	is >> c.m_name >> c.m_architect >> c.m_yearOfConstruction >> c.m_height >> c.m_country >> c.m_religion >> style;
	c.setStyle(Style(style));
	return is;
}

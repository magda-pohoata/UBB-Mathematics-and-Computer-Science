#include "Castle.h"

string Castle::getRoyal() const
{
	return m_royalty;
}

void Castle::setRoyal(string royal)
{
	this->m_royalty = royal;
}

void Castle::display(ostream& os)
{
	os << "Castle: ";
	ArchitecturalStructure::display(os);
	os << " - " << m_royalty;

	os << " with the purpose(s): ";
	for (int i = 0; i < m_purpose.size(); i++)
	{
		os << m_purpose[i] << " ";
	}
}

istream& operator>>(istream& is, Castle& c)
{
	is >> c.m_name >> c.m_architect >> c.m_yearOfConstruction >> c.m_height >> c.m_country >> c.m_royalty;
	return is;

}

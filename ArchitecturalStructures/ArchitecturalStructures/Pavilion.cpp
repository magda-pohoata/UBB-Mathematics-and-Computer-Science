#include "Pavilion.h"

Materials Pavilion::getMaterial() const
{
	return this->m_material;
}

void Pavilion::setMaterial(Materials m)
{
	this->m_material = m;
}

void Pavilion::display(ostream& os)
{
	os << "Pavilion: ";
	ArchitecturalStructure::display(os);
	
	os << " - " << m_material;

	os << " with the purpose(s): ";
	for (int i = 0; i < m_purpose.size(); i++)
	{
		os << m_purpose[i] << " ";
	}
}

istream& operator>>(istream& is, Pavilion& p)
{
	int materials;
	is >> p.m_name >> p.m_architect >> p.m_yearOfConstruction >> p.m_height >> p.m_country >> materials;
	p.setMaterial(Materials(materials));
	return is;
}

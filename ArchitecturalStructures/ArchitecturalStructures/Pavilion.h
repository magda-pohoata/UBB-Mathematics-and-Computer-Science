#pragma once
#include "ArchitecturalStructure.h"


typedef enum
{
	NO_MATERIALS,
	WOOD,
	STONE,
	GLASS,
	STEEL,
	PLASTIC,
	CONCRETE,
	BAMBOO
}Materials;


class Pavilion : public ArchitecturalStructure
{
public:
	Pavilion():ArchitecturalStructure() {
		m_purpose.push_back(RECREATIONAL_SPACE);
		m_purpose.push_back(ENTERTAINMENT);
		m_purpose.push_back(EXPOSITIONS);

		m_material = Materials(0);
	}

	Pavilion(string name, string architect, int year, int height, string country, Materials material) :ArchitecturalStructure(name, architect, year, height, country)
	{
		m_purpose.push_back(RECREATIONAL_SPACE);
		m_purpose.push_back(ENTERTAINMENT);
		m_purpose.push_back(EXPOSITIONS);

		this->m_material = material;
	}

	Materials getMaterial() const;
	void setMaterial(Materials m);

	void display(ostream& os) override;
	friend istream& operator>>(istream& is, Pavilion&);

private:
	Materials m_material;
};


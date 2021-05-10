#include "Castle.h"
#include <sstream>

string Castle::getRoyal() const
{
	return m_royalty;
}

void Castle::setRoyal(string royal)
{
	this->m_royalty = royal;
}

void Castle::display(ostream& os) const
{
	os << "Castle: ";
	ArchitecturalStructure::display(os);
	os << "," << m_royalty;
	os << endl;
}

/*
vector<string> tokenize(string str, char delimiter)
{
	vector<string> result;
	stringstream ss(str);
	string token;
	while (getline(ss, token, delimiter))
		result.push_back(token);

	return result;
}
*/

istream& operator>>(istream& is, Castle& c)
{
	
	is >> c.m_name >> c.m_architect >> c.m_yearOfConstruction >> c.m_height >> c.m_country >> c.m_royalty;
	return is;
	

	/*
	string line;
	getline(is, line);

	vector<string> tokens = tokenize(line, ',');
	if (tokens.size() != 5)
		return is;

	c.m_name = tokens[1];
	c.m_architect = tokens[2];
	c.m_country = tokens[5];
	int year, height;
	std::istringstream(tokens[3]) >> year;
	std::istringstream(tokens[4]) >> height;

	c.m_yearOfConstruction = year;
	c.m_height = height;
	c.m_royalty = tokens[6];

	return is;
	*/

}

#ifndef MatAtt
#define MatAtt

#include <iostream>


struct AttributeSubNode
{
	std::string name;
};
struct AttributeSubNodeData
{
	std::string type;
};
class AttributeMasterNode //Grab Bar| Walls| Tubs | Cabinets | Vanity | Trim Kits
{
	std::string name;
	AttributeMasterNode* branch = nullptr;
	AttributeSubNode* attributes = nullptr;
};

class MatAttribute
{
private:
	AttributeMasterNode* head;

public:
	bool BuildMasterNode(std::string);
	bool RemoveMasterNode(std::string);
	AttributeMasterNode* FindMasterNode(std::string); //Find a Material Type ie, Tubs, Walls
	bool AddAttribute(AttributeMasterNode); //Add attribute to a Node ie, Color, Size
};
#endif
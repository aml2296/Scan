#include "MatAttribute.h"

inline bool
MatAttribute::BuildMasterNode(std::string nodeName)
{
	if (FindMasterNode(nodeName) == nullptr)
	{
		//Add Master Node to binary tree
	}
	else
		return false;
}

inline bool
MatAttribute::RemoveMasterNode(std::string nodeName)
{
	AttributeMasterNode* ptr = FindMasterNode(nodeName);
	if (ptr != nullptr)
	{
		//Remove Node ptr
		return true;
	}
	return false;
}

inline AttributeMasterNode*
MatAttribute::FindMasterNode(std::string nodeName)
{
	return nullptr;
}

inline bool
MatAttribute::AddAttribute(AttributeMasterNode mNode)
{
	return false;
}
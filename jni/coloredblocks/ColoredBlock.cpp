#include "ColoredBlock.h"

ColoredBlock::ColoredBlock(short id, const std::string &descriptionName, std::string blockName, MaterialType material) : Block(descriptionName, id, Material::getMaterial(material)) {
	init();
	creativeCategory = CreativeItemCategory::Blocks;
	this->blockName = blockName;
}

std::string ColoredBlock::buildDescriptionName(unsigned char aux) const
{
	if(aux == 0)
		return "Black " + blockName;
	else if (aux == 1)
		return "Red " + blockName;
	else if (aux == 2)
		return "Green " + blockName;
	else if (aux == 3)
		return "Brown " + blockName;
	else if (aux == 4)
		return "Blue " + blockName;
	else if (aux == 5)
		return "Purple " + blockName;
	else if (aux == 6)
		return "Cyan " + blockName;
	else if (aux == 7)
		return "Light Gray " + blockName;
	else if (aux == 8)
		return "Gray " + blockName;
	else if (aux == 9)
		return "Pink " + blockName;
	else if (aux == 10)
		return "Lime " + blockName;
	else if (aux == 11)
		return "Yellow " + blockName;
	else if (aux == 12)
		return "Light Blue " + blockName;
	else if (aux == 13)
		return "Magenda " + blockName;
	else if (aux == 14)
		return "Orange " + blockName;
	else if (aux == 15)
		return "White " + blockName;
}


#include "StainedGlass.h"

StainedGlass::StainedGlass(short id, const std::string &descriptionName) : HalfTransparentBlock(descriptionName, id, Material::getMaterial(MaterialType::GLASS), true) {
	init();
	creativeCategory = CreativeItemCategory::Blocks;
}

std::string StainedGlass::buildDescriptionName(unsigned char aux) const
{
	if(aux == 0)
		return "Black Stained Glass";
	else if (aux == 1)
		return "Red Stained Glass";
	else if (aux == 2)
		return "Green Stained Glass";
	else if (aux == 3)
		return "Brown Stained Glass";
	else if (aux == 4)
		return "Blue Stained Glass";
	else if (aux == 5)
		return "Purple Stained Glass";
	else if (aux == 6)
		return "Cyan Stained Glass";
	else if (aux == 7)
		return "Light Gray Stained Glass";
	else if (aux == 8)
		return "Gray Stained Glass";
	else if (aux == 9)
		return "Pink Stained Glass";
	else if (aux == 10)
		return "Lime Stained Glass";
	else if (aux == 11)
		return "Yellow Stained Glass";
	else if (aux == 12)
		return "Light Blue Stained Glass";
	else if (aux == 13)
		return "Magenda Stained Glass";
	else if (aux == 14)
		return "Orange Stained Glass";
	else if (aux == 15)
		return "White Stained Glass";
}


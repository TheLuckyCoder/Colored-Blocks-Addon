#pragma once

#include "minecraftpe/world/level/block/Block.h"

class ColoredBlock : public Block
{
private:
	std::string blockName;
public:
	ColoredBlock(short id, const std::string &descriptionName, const std::string blockName, MaterialType material);

	virtual std::string buildDescriptionName(unsigned char aux) const;
};


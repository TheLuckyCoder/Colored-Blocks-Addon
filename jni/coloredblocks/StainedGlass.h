#pragma once

#include "minecraftpe/world/level/block/HalfTransparentBlock.h"

class StainedGlass : public HalfTransparentBlock
{
public:
	StainedGlass(short id, const std::string &descriptionName);

	virtual std::string buildDescriptionName(unsigned char aux) const;
};


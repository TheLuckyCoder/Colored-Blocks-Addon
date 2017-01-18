#include <jni.h>
#include <dlfcn.h>
#include <stdlib.h>
#include "Substrate.h"

#include "minecraftpe/world/item/AuxDataBlockItem.h"
#include "minecraftpe/client/renderer/block/BlockGraphics.h"

#include "coloredblocks/ColoredRecipes.h"
#include "coloredblocks/ColoredBlock.h"
#include "coloredblocks/StainedGlass.h"

void (*_registerItems)();
void registerItems()
{
	_registerItems();
	
	Item::mItems[210] = new AuxDataBlockItem("coloredStone", 210 - 256, Block::mBlocks[210]);
	Item::mItems[211] = new AuxDataBlockItem("coloredBrick", 211 - 256, Block::mBlocks[211]);
	Item::mItems[212] = new AuxDataBlockItem("coloredStoneBrick", 212 - 256, Block::mBlocks[212]);
	Item::mItems[213] = new AuxDataBlockItem("coloredCobblestone", 213 - 256, Block::mBlocks[213]);
	Item::mItems[214] = new AuxDataBlockItem("coloredIron", 214 - 256, Block::mBlocks[214]);
	Item::mItems[215] = new AuxDataBlockItem("coloredPlanks", 215 - 256, Block::mBlocks[215]);
	Item::mItems[216] = new AuxDataBlockItem("coloredPlanks", 216 - 256, Block::mBlocks[216]);
}

void (*_initCreativeItems)();
void initCreativeItems()
{
	_initCreativeItems();
	for (int id = 210; id <= 216; id++) {
		for (int aux = 0; aux <= 15; aux++)
			Item::addCreativeItem(id, aux);
	}
}

void (*_initBlockGraphics)();
void initBlockGraphics()
{
	_initBlockGraphics();
	
	BlockGraphics::mBlocks[210] = new BlockGraphics("dirt");
	BlockGraphics::mBlocks[210]->setTextureItem("colored_stone");
	BlockGraphics::mBlocks[211] = new BlockGraphics("dirt");
	BlockGraphics::mBlocks[211]->setTextureItem("colored_stone_brick");
	BlockGraphics::mBlocks[212] = new BlockGraphics("dirt");
	BlockGraphics::mBlocks[212]->setTextureItem("colored_brick");
	BlockGraphics::mBlocks[213] = new BlockGraphics("dirt");
	BlockGraphics::mBlocks[213]->setTextureItem("colored_cobblestone");
	BlockGraphics::mBlocks[214] = new BlockGraphics("dirt");
	BlockGraphics::mBlocks[214]->setTextureItem("colored_iron");
	BlockGraphics::mBlocks[215] = new BlockGraphics("dirt");
	BlockGraphics::mBlocks[215]->setTextureItem("colored_planks");
	BlockGraphics::mBlocks[216] = new BlockGraphics("glass");
	BlockGraphics::mBlocks[216]->setTextureItem("stained_glass");
}

void (*_initBlocks)();
void initBlocks()
{
	_initBlocks();
	
	Block::mBlocks[210] = new ColoredBlock(210, "coloredStone", "Stone", MaterialType::STONE);
	Block::mBlocks[211] = new ColoredBlock(211, "coloredBrick", "Brick", MaterialType::STONE);
	Block::mBlocks[212] = new ColoredBlock(212, "coloredStoneBrick", "Stone Brick", MaterialType::STONE);
	Block::mBlocks[213] = new ColoredBlock(213, "coloredCobblestone", "Cobblestone", MaterialType::STONE);
	Block::mBlocks[214] = new ColoredBlock(214, "coloredIron", "Iron", MaterialType::METAL);
	Block::mBlocks[215] = new ColoredBlock(215, "coloredPlanks", "Planks", MaterialType::WOOD);
	Block::mBlocks[216] = new StainedGlass(216, "stainedGlass");
}

void (*_initRecipes)(Recipes*);
void initRecipes(Recipes *self)
{
	_initRecipes(self);

	ColoredRecipes::initRecipes(self);
}

JNIEXPORT jint JNI_OnLoad(JavaVM*,void*)
{
	MSHookFunction((void*) &Item::registerItems, (void*) &registerItems, (void**) &_registerItems);
	MSHookFunction((void*) &Item::initCreativeItems, (void*) &initCreativeItems, (void**) &_initCreativeItems);
	MSHookFunction((void*) &Block::initBlocks, (void*) &initBlocks, (void**) &_initBlocks);
	MSHookFunction((void*) &BlockGraphics::initBlocks, (void*) &initBlockGraphics, (void**) &_initBlockGraphics);
	MSHookFunction((void*) &Recipes::init, (void*) &initRecipes, (void**) &_initRecipes);
	
	return JNI_VERSION_1_6;
}


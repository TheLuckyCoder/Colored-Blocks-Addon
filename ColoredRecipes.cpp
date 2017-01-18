#include "ColoredRecipes.h"

Recipes* ColoredRecipes::_Instance;
std::vector<Recipes::Type> ColoredRecipes::_ingredients;

void ColoredRecipes::initFurnaceRecipes(FurnaceRecipes *instance) {
	for(int data = 0; data < 16; data++)
		instance->addFurnaceRecipeAuxData(ColoredBlocks::mColoredStone->blockId, 0, ItemInstance(ColoredBlocks::mColoredCobblestone->blockId, 1, 0));
}

void ColoredRecipes::initRecipes(Recipes *instance) {	
	_Instance = instance;		
	
	for(int data = 0; data <= 15; data++) {
		pushIngredient(1, 0, 'b');
		pushIngredient(351, data, 'd');
		addRecipe(ColoredBlocks::mColoredStone->blockId, 1, data, {"bd", "  "});
		
		pushIngredient(4, 0, 'b');
		pushIngredient(351, data, 'd');
		addRecipe(ColoredBlocks::mColoredCobblestone->blockId, 1, data, {"bd", "  "});
		
		pushIngredient(98, 0, 'b');
		pushIngredient(351, data, 'd');
		addRecipe(ColoredBlocks::mColoredStoneBrick->blockId, 1, data, {"bd", "  "});
		
		pushIngredient(45, 0, 'b');
		pushIngredient(351, data, 'd');
		addRecipe(ColoredBlocks::mColoredBrick->blockId, 1, data, {"bd", "  "});
		
		pushIngredient(42, 0, 'b');
		pushIngredient(351, data, 'd');
		addRecipe(ColoredBlocks::mColoredIron->blockId, 1, data, {"bd", "  "});
		
		//pushIngredient(42, 0, 'b');
		//pushIngredient(351, data, 'd');
		//addRecipe(ColoredBlocks::mStainedGlass->blockId, 1, data, {"bd", "  "});
		
		//Stone to Stone Brick
		pushIngredient(ColoredBlocks::mColoredStone->blockId, data, 'b');
		addRecipe(ColoredBlocks::mColoredStoneBrick->blockId, 1, data, {"bb", "bb"});
	}
} 

void ColoredRecipes::pushIngredient(int id, int data, char letter) {
	Recipes::Type type {NULL, NULL, ItemInstance(id, 1, data), letter};
	_ingredients.push_back(type);
} 

void ColoredRecipes::addRecipe(int outputID, int outputCount, int outputData, const std::vector<std::string>& shape) {
	ItemInstance output(outputID, 1, outputData);
	output.count = outputCount;
	_Instance->addShapedRecipe(output, shape, _ingredients);	
	_ingredients.clear();
}


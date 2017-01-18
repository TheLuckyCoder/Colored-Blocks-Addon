#include "ColoredRecipes.h"

Recipes* ColoredRecipes::_Instance;
std::vector<Recipes::Type> ColoredRecipes::_ingredients;

void ColoredRecipes::initRecipes(Recipes *instance) {	
	_Instance = instance;		
	
	for(int data = 0; data <= 15; data++) {
		// Stone
		pushIngredient(1, 0, 'b');
		pushIngredient(351, data, 'd');
		addRecipe(210, 1, data, {"bd"});
		
		// Cobblestone
		pushIngredient(4, 0, 'b');
		pushIngredient(351, data, 'd');
		addRecipe(213, 1, data, {"bd"});
		
		// Stone Brick
		pushIngredient(98, 0, 'b');
		pushIngredient(351, data, 'd');
		addRecipe(212, 1, data, {"bd"});
		
		// Brick
		pushIngredient(45, 0, 'b');
		pushIngredient(351, data, 'd');
		addRecipe(211, 1, data, {"bd"});
		
		// Iron
		pushIngredient(42, 0, 'b');
		pushIngredient(351, data, 'd');
		addRecipe(214, 1, data, {"bd"});
		
		// Planks
		pushIngredient(5, 0, 'b');
		pushIngredient(351, data, 'd');
		addRecipe(215, 1, data, {"bd"});
		
		// Glass
		pushIngredient(42, 0, 'b');
		pushIngredient(351, data, 'd');
		addRecipe(216, 1, data, {"bd"});
		
		// Stone to Stone Brick
		pushIngredient(210, data, 'b');
		addRecipe(212, 1, data, {"bb", "bb"});
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


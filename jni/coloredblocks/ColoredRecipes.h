#pragma once 

#include "minecraftpe/world/item/recipes/Recipes.h"
#include "minecraftpe/world/item/recipes/FurnaceRecipes.h"

class ColoredRecipes
{
public: 
	static void initRecipes(Recipes *instance);
private: 	
	static Recipes* _Instance; 	
	static std::vector<Recipes::Type> _ingredients; 	 	
	static void pushIngredient(int id, int data, char letter); 
	static void addRecipe(int, int, int, const std::vector<std::string>&); 
};


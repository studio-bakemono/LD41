#pragma once

#include <iostream>
#include <vector>
#include "SDL.h"

#include "Component.h"

#include "GraphicsComponent.h"
#include <map>
#include <utility>

enum EntityType {
	Player
};


class Entity
{
public:

	int typeID;

	std::string u_tag;

	void cleanup();

	Entity();



	~Entity();
};


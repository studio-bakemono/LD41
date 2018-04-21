
#include "Component.h"


Component::Component()
{
}


Component::~Component()
{
}

void Component::update(App* game)
{
	onUpdate(game);
}

void Component::cleanup()
{
	onCleanup();
}


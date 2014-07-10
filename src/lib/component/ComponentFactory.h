#ifndef COMPONENT_FACTORY_H
#define COMPONENT_FACTORY_H

#include <memory>

#include "data/access/LocationAccess.h"
#include "data/access/GraphAccess.h"

class Component;
class GuiFactory;
class ViewLayout;

class ComponentFactory
{
public:
	static std::shared_ptr<ComponentFactory> create(
		GuiFactory* guiFactory, ViewLayout* viewLayout, GraphAccess* graphAccess, LocationAccess* locationAccess
	);

	~ComponentFactory();

	std::shared_ptr<Component> createCodeComponent();
	std::shared_ptr<Component> createGraphComponent();
	std::shared_ptr<Component> createSearchComponent();

private:
	ComponentFactory();
	ComponentFactory(const ComponentFactory&);

	GuiFactory* m_guiFactory;
	ViewLayout* m_viewLayout;

	GraphAccess* m_graphAccess;
	LocationAccess* m_locationAccess;
};


#endif // COMPONENT_FACTORY_H

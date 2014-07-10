#include "component/ComponentFactory.h"

#include "component/Component.h"
#include "component/controller/CodeController.h"
#include "component/controller/GraphController.h"
#include "component/controller/SearchController.h"
#include "component/view/CodeView.h"
#include "component/view/GraphView.h"
#include "component/view/SearchView.h"
#include "component/view/ViewLayout.h"
#include "gui/GuiFactory.h"

std::shared_ptr<ComponentFactory> ComponentFactory::create(
	GuiFactory* guiFactory, ViewLayout* viewLayout, GraphAccess* graphAccess, LocationAccess* locationAccess
){
	std::shared_ptr<ComponentFactory> ptr(new ComponentFactory());
	ptr->m_guiFactory = guiFactory;
	ptr->m_viewLayout = viewLayout;
	ptr->m_graphAccess = graphAccess;
	ptr->m_locationAccess = locationAccess;
	return ptr;
}

ComponentFactory::~ComponentFactory()
{
}

std::shared_ptr<Component> ComponentFactory::createCodeComponent()
{
	std::shared_ptr<CodeView> view = m_guiFactory->createCodeView(m_viewLayout);
	std::shared_ptr<CodeController> controller = std::make_shared<CodeController>(m_locationAccess);

	std::shared_ptr<Component> component = std::make_shared<Component>(view, controller);
	return component;
}

std::shared_ptr<Component> ComponentFactory::createGraphComponent()
{
	std::shared_ptr<View> view = m_guiFactory->createGraphView(m_viewLayout);
	std::shared_ptr<GraphController> controller = std::make_shared<GraphController>(m_graphAccess);

	std::shared_ptr<Component> component = std::make_shared<Component>(view, controller);
	return component;
}

std::shared_ptr<Component> ComponentFactory::createSearchComponent()
{
	std::shared_ptr<SearchView> view = m_guiFactory->createSearchView(m_viewLayout);
	std::shared_ptr<SearchController> controller = std::make_shared<SearchController>(m_graphAccess);

	std::shared_ptr<Component> component = std::make_shared<Component>(view, controller);
	return component;
}

ComponentFactory::ComponentFactory()
{
}

#include "entitymanager.h"

namespace GE_Model {

	EntityManager::EntityManager() {}

	EntityManager::EntityManager(GE_View::RepresentationManager* reprManager) {
		_reprManager = reprManager;
	}

	void EntityManager::addEntity(EntityPtr entity) {
		_entities.push_back(entity);
		_reprManager->addRepr(ReprPtr(entity->getRepresentation()));
	}

	void EntityManager::updateAll() {
		for(EntityPtr entity : _entities) {
			entity->update();
		}
	}

	void EntityManager::resolveInput(GE_Controller::ki::KeyInput input) {
		for (EntityPtr entity : _entities) {
			entity->resolveInput(input);
		}
	}
}

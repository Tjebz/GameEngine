#pragma once

#include <vector>
#include <memory>
#include "entity.h"
#include "../View/RepresentationManager.h"
#include "../Controller/KeyInput.h"

namespace GE_Model {

	using EntityPtr = std::shared_ptr<Entity>;

	/*
	Manager class for Entities
	*/

	class EntityManager {

	private:
		std::vector<EntityPtr> _entities;
		GE_View::RepresentationManager* _reprManager;

	public:
		EntityManager();
		EntityManager(GE_View::RepresentationManager* reprManager);

		void addEntity(EntityPtr entity);
		void updateAll();
		void resolveInput(GE_Controller::ki::KeyInput input);
	};
}

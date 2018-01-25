#pragma once

#include <memory>
#include "Rect.h"
#include "../View/Representation.h"
#include "../Controller/Controller.h"

namespace GE_Model {

	using CtrlPtr = std::shared_ptr<GE_Controller::Controller>;
	using ReprPtr = std::shared_ptr<GE_View::Representation>;
	/*
	Abstract base class for entities in the engine
	*/

	class Entity {
	private:
		Rect _rect;
		ReprPtr _repr;
		CtrlPtr _controller;

	public:
		Entity();
		Entity(Rect rect);
		Entity(double x, double y, double width, double heigth);

		void offsetPos(Vect offset);
		void offsetSize(Vect offset);
		void setPos(Vect pos);
		void setSize(Vect size);
		void setRepresentation(ReprPtr repr);
		void setController(CtrlPtr controller);

		Vect getPos();
		Vect getSize();
		Rect getRect();
		ReprPtr getRepresentation();
		CtrlPtr getController();

		virtual void update() = 0;
		virtual void resolveInput(GE_Controller::ki::KeyInput input) = 0;
	};
}

#include "Entity.h"

namespace GE_Model {

	Entity::Entity() {
		_rect = Rect();
		_controller = nullptr;
		_repr = nullptr;
	}

	Entity::Entity(Rect rect) {
		_rect.setAll(rect.getX(), rect.getY(), rect.getWidth(), rect.getHeigth());
	}

	Entity::Entity(double x, double y, double width, double heigth) {
		_rect.setAll(x, y, width, heigth);
	}

	void Entity::offsetPos(Vect offset) {
		_rect.setPos(_rect.getPos() + offset);
		if (_repr) {
			_repr->setRect(getRect());
		}
	}

	void Entity::offsetSize(Vect offset) {
		_rect.setSize(_rect.getSize() + offset);
		if (_repr) {
			_repr->setRect(getRect());
		}
	}

	void Entity::setPos(Vect pos) {
		_rect.setPos(pos);
		if (_repr) {
			_repr->setRect(getRect());
		}
	}

	void Entity::setSize(Vect size) {
		_rect.setSize(size);
		if (_repr) {
			_repr->setRect(getRect());
		}
	}

	void Entity::setRepresentation(ReprPtr repr) {
		_repr = repr;
	}

	void Entity::setController(CtrlPtr controller) {
		_controller = controller;
	}

	Vect Entity::getPos() {
		return _rect.getPos();
	}

	Vect Entity::getSize() {
		return _rect.getSize();
	}

	Rect Entity::getRect() {
		return _rect;
	}

	ReprPtr Entity::getRepresentation() {
		return _repr;
	}

	CtrlPtr Entity::getController() {
		return _controller;
	}
}

#include "MovableEntity.h"

namespace GE_Model {

	MovableEntity::MovableEntity() : Entity() {}
	MovableEntity::MovableEntity(Rect rect) : Entity(rect) {}
	MovableEntity::MovableEntity(double x, double y, double width, double heigth) : Entity(x, y, width, heigth) {}

	void MovableEntity::setMaxSpeed(double maxSpeed) {
		_maxSpeed = maxSpeed;
	}

	void MovableEntity::setAcceleration(Vect acceleration) {
		_acceleration = acceleration;
	}

	void MovableEntity::setVelocity(Vect velocity) {
		_velocity = velocity;
	}

	double MovableEntity::getMaxSpeed() {
		return _maxSpeed;
	}

	Vect MovableEntity::getAcceleration() {
		return _acceleration;
	}

	Vect MovableEntity::getVelocity() {
		return _velocity;
	}

	void MovableEntity::accelerateUp() {
		_velocity.setY(getVelocity().getY() - getAcceleration().getY());
	}
	
	void MovableEntity::accelerateDown() {
		_velocity.setY(getVelocity().getY() + getAcceleration().getY());
	}
	
	void MovableEntity::accelerateRight() {
		_velocity.setX(getVelocity().getX() + getAcceleration().getX());
	}

	void MovableEntity::accelerateLeft() {
		_velocity.setX(getVelocity().getX() - getAcceleration().getX());
	}

	void MovableEntity::stop(bool horizontal, bool vertical) {
		if (horizontal) {
			_velocity.setX(0);
		}
		if (vertical) {
			_velocity.setY(0);
		}
	}

	void MovableEntity::update() {
		std::cout << getVelocity().getX() << ", " << getVelocity().getY() << std::endl;
		std::cout << getPos().getX() << ", " << getPos().getY() << std::endl;
		offsetPos(getVelocity());
	}

	void MovableEntity::resolveInput(GE_Controller::ki::KeyInput input) {
		GE_Controller::com::Command command = getController()->getCommand(input);
		switch (command) {
		case GE_Controller::com::AccUp:
			accelerateUp();
			break;
		case GE_Controller::com::AccDown:
			accelerateDown();
			break;
		case GE_Controller::com::AccLeft:
			accelerateLeft();
			break;
		case GE_Controller::com::AccRight:
			accelerateRight();
			break;
		case GE_Controller::com::DeccUp:
			stop(false, true);
			break;
		case GE_Controller::com::DeccDown:
			stop(false, true);
			break;
		case GE_Controller::com::DeccLeft:
			stop(true, false);
			break;
		case GE_Controller::com::DeccRight:
			stop(true, false);
			break;
		}
	}
}
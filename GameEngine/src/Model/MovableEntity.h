#pragma once

#include "Entity.h"

namespace GE_Model {

/*
Entity with the ability to move
*/

	class MovableEntity : public Entity {

	private:
		double _maxSpeed;
		Vect _acceleration;
		Vect _velocity;

	public:
		MovableEntity();
		MovableEntity(Rect rect);
		MovableEntity(double x, double y, double width, double heigth);

		void setMaxSpeed(double maxSpeed);
		void setAcceleration(Vect acceleration);
		void setVelocity(Vect velocity);

		double getMaxSpeed();
		Vect getAcceleration();
		Vect getVelocity();

		void accelerateUp();
		void accelerateDown();
		void accelerateLeft();
		void accelerateRight();
		void stop(bool horizontal, bool vertical);
		virtual void update();
		virtual void resolveInput(GE_Controller::ki::KeyInput input);
	};
}


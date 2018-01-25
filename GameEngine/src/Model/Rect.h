#pragma once

#include "vect.h"

namespace GE_Model {

	/*
	Rectangle class, stores a Rect for position and a Rect for size
	*/

	class Rect{
	private:
		Vect _pos;
		Vect _size;

	public:
		Rect();
		Rect(double x, double y, double width, double heigth);
		Rect(Vect coords, Vect size);

		void setX(double x);
		void setY(double y);
		void setPos(double x, double y);
		void setPos(Vect pos);
		void setWidth(double width);
		void setHeigth(double heigth);
		void setSize(double width, double heigth);
		void setSize(Vect size);
		void setAll(double x, double y, double width, double heigth);

		double getX();
		double getY();
		double getWidth();
		double getHeigth();
		Vect getPos();
		Vect getSize();
	};
}

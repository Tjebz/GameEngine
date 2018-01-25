#include "vect.h"

namespace GE_Model {

	Vect::Vect() {
		_x = 0;
		_y = 0;
		_initX = false;
		_initY = false;
	}

	Vect::Vect(double x, double y) {
	   setX(x);
	   setY(y);
	}

	void Vect::setX(double x) {
		_x = x;
		_initX = true;
	}

	void Vect::setY(double y) {
		_y = y;
		_initY = true;
	}

	void Vect::setAll(double x, double y) {
		setX(x);
		setY(y);
	}

	double Vect::getX() const{
		return _x;
	}

	double Vect::getY() const{
		return _y;
	}

	Vect Vect::operator+(const Vect& vect) const{
		return Vect(getX() + vect.getX(), getY() + vect.getY());
	}

	Vect& Vect::operator+=(const Vect& vect){
		setAll(getX() + vect.getX(), getY() + vect.getY());
		return *this;
	}

	Vect Vect::operator-(const Vect& vect) const {
		return Vect(getX() - vect.getX(), getY() - vect.getY());
	}

	Vect& Vect::operator-=(const Vect& vect) {
		setAll(getX() - vect.getX(), getY() - vect.getY());
		return *this;
	}
}

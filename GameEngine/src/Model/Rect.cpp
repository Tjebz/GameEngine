#include "rect.h"

namespace GE_Model {

	Rect::Rect() {
		_pos = Vect();
		_size = Vect();
	}

	Rect::Rect(double x, double y, double width, double heigth) {
		_pos.setAll(x, y);
		_size.setAll(width, heigth);
	}

	Rect::Rect(Vect pos, Vect size) {
		_pos = pos;
		_size = size;
	}

	void Rect::setX(double x) {
		_pos.setX(x);
	}

	void Rect::setY(double y) {
		_pos.setY(y);
	}

	void Rect::setPos(double x, double y) {
		_pos.setAll(x, y);
	}

	void Rect::setPos(Vect pos) {
		_pos = pos;
	}

	void Rect::setWidth(double width) {
		_size.setX(width);
	}

	void Rect::setHeigth(double heigth) {
		_size.setY(heigth);
	}

	void Rect::setSize(double width, double heigth) {
		_size.setAll(width, heigth);
	}

	void Rect::setSize(Vect size) {
		_size = size;
	}

	void Rect::setAll(double x, double y, double width, double heigth) {
		_pos.setAll(x, y);
		_size.setAll(width, heigth);
	}

	double Rect::getX() {
		return _pos.getX();
	}

	double Rect::getY() {
		return _pos.getY();
	}

	double Rect::getWidth() {
		return _size.getX();
	}

	double Rect::getHeigth() {
		return _size.getY();
	}

	Vect Rect::getPos() {
		return _pos;
	}

	Vect Rect::getSize() {
		return _size;
	}
}

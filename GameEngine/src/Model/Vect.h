#pragma once

namespace GE_Model {

	/*
	Vector class, stores two values and a boolean for each one indictating wheter it has been initialized
	*/

	class Vect
	{
	private:
		double _x;
		double _y;
		bool _initX;
		bool _initY;

	public:
		Vect();
		Vect(double x, double y);

		void setX(double x);
		void setY(double y);
		void setAll(double x, double y);

		double getX() const;
		double getY() const;

		Vect operator+(const Vect& vect) const;
		Vect& operator+=(const Vect& vect);
		Vect operator-(const Vect& vect) const;
		Vect& operator-=(const Vect& vect);
	};
}

#pragma once

#include <iostream>
#include "../Model/Rect.h"

namespace GE_View {

	/*
	Abstract class to 
	*/
	class Representation {
	private:
		GE_Model::Rect _rect;

	public:
		Representation();

		void setRect(GE_Model::Rect rect);

		GE_Model::Rect getRect();

		virtual void draw()=0;
	};
}
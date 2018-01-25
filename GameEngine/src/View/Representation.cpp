#include "Representation.h"

namespace GE_View {
	Representation::Representation() {
		_rect = GE_Model::Rect();
	}

	void Representation::setRect(GE_Model::Rect rect) {
		_rect = rect;
	}

	GE_Model::Rect Representation::getRect() {
		return _rect;
	}
}
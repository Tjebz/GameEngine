#include "RepresentationManager.h"

namespace GE_View {

	RepresentationManager::RepresentationManager() {
	}

	std::vector<ReprPtr>& RepresentationManager::List() {
		return _reprList;
	}

	void RepresentationManager::addRepr(ReprPtr repr) {
		_reprList.push_back(repr);
	}

	void RepresentationManager::updateList() {
		for (std::vector<ReprPtr>::iterator it = _reprList.begin(); it != _reprList.end();) {
			if (it->unique()) {
				it = _reprList.erase(it);
			}
			else {
				it++;
			}
		}
	}
}
#pragma once

#include <vector>
#include <memory>
#include "Representation.h"
#include <SDL.h>

namespace GE_View {

	using ReprPtr = std::shared_ptr<Representation>;

	class RepresentationManager {

	private:
		std::vector<ReprPtr> _reprList;

	public:
		RepresentationManager();

		std::vector<ReprPtr>& List();

		void addRepr(ReprPtr repr);
		void updateList();

		virtual void drawAll()=0;
	};
}


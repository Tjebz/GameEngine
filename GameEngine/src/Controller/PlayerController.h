#pragma once

#include <map>
#include "Controller.h"
#include "KeyInput.h"

namespace GE_Controller {

	class PlayerController : public Controller {
	public:
		PlayerController();

		virtual com::Command getCommand(ki::KeyInput input);

	private:
		std::map<ki::KeyInput, bool> _pressed;

	};
}


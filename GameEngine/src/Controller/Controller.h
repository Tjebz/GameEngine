#pragma once

#include "Command.h"
#include "KeyInput.h"

namespace GE_Controller {

	class Controller {

	public:
		Controller() {}
		virtual com::Command getCommand(ki::KeyInput input) = 0;
	};
}


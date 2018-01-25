#pragma once

namespace GE_Controller {
	namespace com {
		enum Command {
			None = 0,
			AccUp,
			AccDown,
			AccLeft,
			AccRight,
			DeccUp = 5,
			DeccDown,
			DeccLeft,
			DeccRight
		};
	}
}
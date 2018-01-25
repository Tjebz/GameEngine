#include "PlayerController.h"


namespace GE_Controller {
PlayerController::PlayerController() {
	_pressed.insert(std::make_pair(ki::UpPressed, false));
	_pressed.insert(std::make_pair(ki::DownPressed, false));
	_pressed.insert(std::make_pair(ki::RightPressed, false));
	_pressed.insert(std::make_pair(ki::LeftPressed, false));
}

com::Command PlayerController::getCommand(ki::KeyInput input) {
	switch (input) {
	case(ki::UpPressed):
		if (_pressed.find(ki::UpPressed)->second) {
			return com::None;
		}
		_pressed.find(ki::UpPressed)->second = true;
		return com::AccUp;
	case(ki::UpReleased):
		_pressed.find(ki::UpPressed)->second = false;
		return com::DeccUp;
	case(ki::DownPressed):
		if (_pressed.find(ki::DownPressed)->second) {
			return com::None;
		}
		_pressed.find(ki::DownPressed)->second = true;
		return com::AccDown;
	case(ki::DownReleased):
		_pressed.find(ki::DownPressed)->second = false;
		return com::DeccDown;
	case(ki::LeftPressed):
		if (_pressed.find(ki::LeftPressed)->second) {
			return com::None;
		}
		_pressed.find(ki::LeftPressed)->second = true;
		return com::AccLeft;
	case(ki::LeftReleased):
		_pressed.find(ki::LeftPressed)->second = false;
		return com::DeccLeft;
	case(ki::RightPressed):
		if (_pressed.find(ki::RightPressed)->second) {
			return com::None;
		}
		_pressed.find(ki::RightPressed)->second = true;
		return com::AccRight;
	case(ki::RightReleased):
		_pressed.find(ki::RightPressed)->second = false;
		return com::DeccRight;
	}
	return com::None;
}
}

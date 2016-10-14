/*
 * cntl.cpp
 *
 *  Created on: Oct 6, 2016
 *      Author: Lunar Dust
 */
#include "controller.h"

//For practicality
enum btnNums {
	_bA,
	_bB,
	_bX,
	_bY,
	_bLB,
	_bRB,
	_bBack,
	_bStart,
	_bLS,
	_bRS
};

void cntl::InitCntl(int stickCount) {
	stick = new Joystick(stickCount);
	//TODO: find a better way to do this
	//UPDATE: it's a bit nicer but I can do better
	std::vector<newBtn> vec;
	for (int i = 0; i < 9; i++) {
		vec.push_back(newBtn{new JoystickButton(stick, i), i, false, false, false});
	}

	cntl::bA = vec[0];
	cntl::bX = vec[1];
	cntl::bX = vec[2];
	cntl::bY = vec[3];
	cntl::bLB = vec[4];
	cntl::bRB = vec[5];
	cntl::bBack = vec[6];
	cntl::bStart = vec[7];
	cntl::bLS = vec[8];
	cntl::bRS = vec[9];
}

/*cntl::newBtn cntl::CreateBtn(struct strct, Joystick *s, int num) {
	cntl::newBtn btn;
	//btn.raw = JoystickButton(s, num);
	btn.num = num;
	btn.RE = false;
	btn.State = false;
	btn.Hld = false;
	return btn;
}*/

void cntl::UpdateCntl(Joystick s) {
	bA = cntl::bA;
	bA.Hld = bA.State;
	bA.State = bA.raw->Grab();
	if(bA.Hld != bA.State && bA.Hld) {
		bA.RE = true;
	}
	cntl::bA = bA;
	//bA.State = bA.raw.
}

/*
 *  cntl.cpp
 *
 *  Created on: Oct 6, 2016
 *      Author: Lunar Dust
 */
#include "cntl.h"

btn::btn(int button, frc::Joystick **s) {
	M_raw = new Btn_t(*s, button);
	Hld = false;
	State = false;
	RE = false;
}

void btn::Update() {
	Hld = State;
	State = M_raw->Grab();
	RE = false;
	if(Hld != State && !Hld) {
		RE = true;
	}
}

cntl::cntl(int port, double deadzone) {
	M_stick = new frc::Joystick(port);
	RX = 0.0;
	RY = 0.0;
	LX = 0.0;
	LY = 0.0;
	RTrig = 0.0;
	LTrig = 0.0;

	M_deadzone = deadzone;

	bA = new btn(_bA, &M_stick);
	bB = new btn(_bB, &M_stick);
	bX = new btn(_bX, &M_stick);
	bY = new btn(_bY, &M_stick);
	bLB = new btn(_bLB, &M_stick);
	bRB = new btn(_bRB, &M_stick);
	bBack = new btn(_bBack, &M_stick);
	bStart = new btn(_bStart, &M_stick);
	bLS = new btn(_bLS, &M_stick);
	bRS = new btn(_bRS, &M_stick);
}

double applyDeadzone(double input, double zone) {
	double o = fabs(input) - zone;
	o /= (1 - zone);
	if(o < 0) {
		o = 0;
	}
	if(input < 0) {
		o *= -1;
	}
	if((o + 0.0) == 0.0) {
		o = 0.0;
	}
	return o;
}

void cntl::UpdateCntl() {
	LX = applyDeadzone(M_stick->GetX(), M_deadzone);
	LY = applyDeadzone(M_stick->GetY(), M_deadzone);
	RX = applyDeadzone(M_stick->GetRawAxis(4), M_deadzone);
	RY = applyDeadzone(M_stick->GetRawAxis(5), M_deadzone);
	RTrig = applyDeadzone(M_stick->GetRawAxis(3), M_deadzone);
	LTrig = applyDeadzone(M_stick->GetRawAxis(2), M_deadzone);
	RY *= -1;
	LY *= -1;

	bA->Update();
	bB->Update();
	bX->Update();
	bY->Update();
	bLB->Update();
	bRB->Update();
	bBack->Update();
	bStart->Update();
	bLS->Update();
	bRS->Update();
}


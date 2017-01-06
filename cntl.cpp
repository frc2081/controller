/*
 *  cntl.cpp
 *
 *  Created on: Oct 6, 2016
 *      Author: Lunar Dust
 */
#include "cntl.h"

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

btn::btn(int button, Joystick **s) {
	raw = new JoystickButton(*s, button);
	Hld = false;
	State = false;
	RE = false;
}

void btn::Update() {
	this->Hld = this->State;
		this->State = this->raw->Grab();
		if(this->Hld != this->State && this->Hld) {
			this->RE = true;
		}
}

cntl::cntl(int port) {
	stick = new Joystick(port);

	this->bA = new btn(1, &stick);
	this->bB = new btn(2, &stick);
	this->bX = new btn(3, &stick);
	this->bY = new btn(4, &stick);
	this->bLB = new btn(5, &stick);
	this->bRB = new btn(6, &stick);
	this->bBack = new btn(7, &stick);
	this->bStart = new btn(8, &stick);
	this->bLS = new btn(9, &stick);
	this->bRS = new btn(10, &stick);
}

void cntl::UpdateCntl() {
	this->bA->Update();
	this->bB->Update();
	this->bX->Update();
	this->bY->Update();
}


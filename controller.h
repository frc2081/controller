/*
 * 	WPILib Controller library
 *
 * 	Organization: FRC2081
 *  Author: Lunar Dust
 *
 *  Do not redistribute this library without the permission of the author.
 */

#ifndef CONTROLLER_H_
#define CONTROLLER_H_

#include "WPILib.h"

class cntl
{
private:
	typedef JoystickButton Btn_t;

	//Joystick object to be used for some operations
	Joystick *stick;

	//Struct that hold the values of the button state, rising edge, and held
	struct newBtn {
		Btn_t *raw;
		int num;
		bool State;
		bool RE;
		bool Hld;
	} bA, bB, bX, bY, bLB, bRB, bBack, bStart, bLS, bRS;


public:
	cntl();
	//This returns a struct which will contain button values for a given joystick(cntl number)              LIES TODO: rewrite comments
	void InitCntl(int);

	//Should be called twice at the beginning of every cycle, once for each controller
	void UpdateCntl(Joystick);
};

#endif /* CONTROLLER_H_ */

/*
 * 	WPILib Controller library
 *
 * 	Organization: FRC2081
 *  Author: Lunar Dust
 *
 *  Do not redistribute this library without the permission of the author.
 */

#ifndef CNTL_H_
#define CNTL_H_

#include "WPILib.h"

typedef JoystickButton Btn_t;

class btn
{
	private:
		Btn_t *raw;

	public:
		bool State;
		bool RE;
		bool Hld;

		//Called for all buttons on a controller by calling UpdateCntl()
		void Update();

		btn(int, Joystick**);
		virtual ~btn() = default;
};

class cntl
{
	private:
		Joystick *stick;

	public:
		//Returns controller object, takes controller number as argument
		cntl(int);

		//Should be called twice at the beginning of every cycle, once for each controller
		void UpdateCntl();


		btn *bA;
		btn *bB;
		btn *bX;
		btn *bY;
		btn *bLB;
		btn *bRB;
		btn *bBack;
		btn *bStart;
		btn *bLS;
		btn *bRS;
};

#endif /* CNTL_H_ */

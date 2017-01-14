# Controller
A library to simplify usage of the WPILib controller class

## Adding it to your project 
Luckily, including it into your robot code is as simple as copying the `cntl.h` and `cntl.cpp` files into the same folder as the main code and including it with `#include "cntl.h"`

## Usage
### Initialization
`cntl *stick1;`

The constructor takes the port of the controller and the deadzone (value of 0 to 1)
`stick1 = new cntl(0, 0.2);`

### Updating the values
This updates all of the joystick values using voodoo magic
`stick1->UpdateCntl();`

### Using the values
One helpful feature is that some special cases of the button's state are kept track of.
For example, if you wanted to only do something on the first loop that a button is pressed.
`if(stick1->bA->RE) { /* Call a function for grabbing a ball or something */ };`

Or if you wanted to do something as long as a button is held.
`while(stick1->bX->Hld) { /* Do something and update the controller at the end of the loop */ };`

Or if you want to use the current state as it is for something.
`if(stick1->bLS->State) { /* Do something fun... Or maybe boring :c */ };`

## Useful values
### Buttons
| Variable name | Controller button |
| --- | --- |
| bA | A button |
| bB | B button |
| bX | X button |
| bY | Y button |
| bLB | Left Bumper |
| bRB | Right Bumper |
| bBack | Back button |
| bStart | Start button |
| bLS | Left Shoulder |
| bRS | Right Shoulder |

### Joysticks
| Variable name | Joystick axis |
| --- | --- |
| LX | Left joystick X axis |
| LY | Left joystick Y axis |
| RX | Right joystick X axis |
| RY | Right joystick Y axis |
| RTrig | Right trigger |
| LTrig | Left trigger |

## Notes
### Troubleshooting
If you run into any difficulties, your controller may be incompatible. This code was developed using a standard XBox 360 Controller made by Microsoft.
I will add compatibilty for other controllers in the future, but for now this is the only supported controller.

If you are sure that your controller is compatible, but you still have issues, feel free to contact me and I'll help you as much as I can.

### "What's the btn class in the header for?"
In the early stages of development, I quickly realized that having 3 variables for every button would be a mess. So I decided to add a class for button objects. This made it much easier to track and update each button's values.
I was considering removing it because it wouldn't be needed much by the standard user, then I considered that FIRST may allow for different controllers in the future(however unlikely it may be). Additionally, it lets the user take a little peek at how it all works if they really want(or they could look in the .cpp file).

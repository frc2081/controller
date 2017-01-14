# Controller
A library to simplify usage of the WPILib controller class

## Usage
### Initialization
In your header file
`cntl *stick1;`

In your RobotInit function
`stick1 = new cntl(0, 0.2);`

### Updating the values
In the beginning of your TeleopPeriodic function
`stick1->UpdateCntl();`

### Using the values
One nice feature is that some special cases of the button states are kept track of.
For example, if you wanted to only do something on the first loop that a button is pressed
`if(stick1->bA->RE) { /* Call a function for grabbing a ball or something */ };`

Or if you wanted to do something as long as a button is held
`while(stick1->bX->Hld) { /* Do something and update the controller at the end of the loop */ };`

Or if you want to use the current state as it is for something
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

#Team programming to-do list:
----------------------------

#IMPORTANT!!!
###TEST ALL COMPLETED API SYSTEMS ON OLD ROBOT!!!

#General:
* ~~Write wait for distance functions~~ (Needs checking)
* ~~Write move/turn for distance functions~~ (Needs checking)
* Write API wiki
* ~~Update header file for encoder.c and ruler.c with all functions~~
* Add tick to measurement functions to the ruler system
* ~~Add system timer in timer.c~~
* ~~Add move for time functions to simplemovement.c~~
* Add prefix and suffix compatability to the debug stream
* ~~Make sure all instances of stop() are replaced with halt()~~
* ~~Remove POLARITY() and replace all instances with the built-in sgn()~~
* Add a move arc function
* Add support for a setting_noEncoders macro, as well as twoMotors and noMotors

#Post-Competition Cleanup:
* ~~Fix the spelling of "guard" in all include guards (probably best done with a script)~~
* ~~Change the initialization of the grab motor in background.c to a function in functions.c~~
* ~~Change the grabbed bool to static, and add getter/setter functions~~
* ~~Change the turn constant to subtract the actual sign of power, not add the negative of it~~
* ~~Change setMovement to use the inverse of the power, so that a positive argument is actually forward~~
* ~~Change all functions in simplemovement to use the positive default power~~
* Add polarity for move seconds and move distance
* Update the config copypasta from the teleop
* Add backboard base and backboard move to settings.c as constant integers

#Long term goals:
* Remove all constants from encoder system and replace with only math, while still retaining full functionality.
* Implement a PID controller to functions in simplemovement

--------------------
###Tutorial on how to edit this list:
-------------------------
Add your required task to the section in which it should go, using the format shown in that section.
Ex.
####Long term goals:
* make the robot fly

When goals are complete, mark them with a strikethrough, several people will check that they are complete,
and then they will be removed from the list.
Ex.
####Long term goals:
* ~~make the robot fly~~

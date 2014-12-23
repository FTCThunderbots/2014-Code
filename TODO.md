#Team programming to-do list:
----------------------------

#General:

* Write wait for distance functions
* Write move/turn for distance functions
* Add tick to measurement functions to the ruler system
* Add prefix and suffix compatability to the debug stream
* Add a move arc function
* Add support for a setting_noEncoders macro, as well as twoMotors and noMotors

#Code cleanup:
* Alphabetize includes list
* Move settings.c to root folder so it's easier to access
* Reorganize unused constants in settings.c
* Rewrite or remove the debug stream system
* Fix include statements in encoders.h and simplemovement.h
* Implement differing up/down times for the grab motor
* Examine legitimacy and neccessity of many of the functions in math.c
* Ruler system?
* Rewrite setAutoDelay to be better
* Re-implement the custom wait for start system
* Delete sensors.c / sensors.h
* (?) Add function files to a subfolder of /api/
* Clean up the mess that simplemovement has become

#Post-Competition Cleanup:
* Add polarity for move seconds and move distance

#Long term goals:
* Remove all constants from encoder system and replace with only math, while still retaining full functionality.
* Implement a PID controller to functions in simplemovement
* Add ruler system
* Write API wiki

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

#Team programming to-do list:
----------------------------

#General:

* Add a move arc function
* Add documentation about where the robot needs to start
* Rewrite the coordinate system to listen to the motors, instead of needing to be updated
* Write machine learning code for autonomous
* Write autonomous sequencing program

#Code cleanup:
###API
* Implement grab_is_motor and related macros
* Move for time/distance only and default power
* Try to condense initializeAPI and initializeRobot
###Autonomous
* Add more documentation to files that dictate where to start, and the path of the program
* Document start positions to a great degree of detail! They should be detailed enough that someone from another team could correctly operate the program after reading.
* Rewrite files to use distance instead of time:
 * backOffRamp.c
 * doubleFloorAuto.c
 * floorAuto.c

#Long term goals:
* Write API wiki
* Ruler system?

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

Just as a note, our robot does not actually fly. It will someday, but not today.